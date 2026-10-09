#include "CreoQuoteMetrics.h"
#include "CreoQuoteAssemblyComponents.h"
#include "CreoQuoteExpressionCounter.h"

#include <windows.h>

#include <ProArray.h>
#include <ProDimension.h>
#include <ProDrawing.h>
#include <ProDtlnote.h>
#include <ProDwgtable.h>
#include <ProFamtable.h>
#include <ProFaminstance.h>
#include <ProFeature.h>
#include <ProFeatType.h>
#include <ProMdl.h>
#include <ProModelitem.h>
#include <ProPattern.h>
#include <ProSection.h>
#include <ProSolid.h>
#include <ProToolkit.h>
#include <ProUtil.h>
#include <ProWindows.h>

#include <algorithm>
#include <cstdio>
#include <cwchar>
#include <cwctype>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

namespace
{
    const wchar_t* MetricsEnvironmentVariable = L"IPX_QUOTE_CREO_METRICS";
    const wchar_t* DefaultMetricsFolder = L"IPXQuoteCreoPlugin";
    const wchar_t* DefaultMetricsFileName = L"last-result.json";

    std::string WideToUtf8(const std::wstring& value)
    {
        if (value.empty())
        {
            return std::string();
        }

        int count = WideCharToMultiByte(CP_UTF8, 0, value.c_str(), -1, nullptr, 0, nullptr, nullptr);
        if (count <= 1)
        {
            return std::string();
        }

        std::string result(static_cast<size_t>(count - 1), '\0');
        WideCharToMultiByte(CP_UTF8, 0, value.c_str(), -1, &result[0], count, nullptr, nullptr);
        return result;
    }

    std::string JsonEscape(const std::string& value)
    {
        std::ostringstream output;
        for (size_t i = 0; i < value.size(); ++i)
        {
            const unsigned char ch = static_cast<unsigned char>(value[i]);
            switch (ch)
            {
            case '\\': output << "\\\\"; break;
            case '"': output << "\\\""; break;
            case '\b': output << "\\b"; break;
            case '\f': output << "\\f"; break;
            case '\n': output << "\\n"; break;
            case '\r': output << "\\r"; break;
            case '\t': output << "\\t"; break;
            default:
                if (ch < 0x20)
                {
                    output << "\\u" << std::hex << std::setw(4) << std::setfill('0') << static_cast<int>(ch) << std::dec;
                }
                else
                {
                    output << static_cast<char>(ch);
                }
                break;
            }
        }

        return output.str();
    }

    std::string JsonString(const std::string& value)
    {
        return std::string("\"") + JsonEscape(value) + "\"";
    }

    std::string JsonString(const std::wstring& value)
    {
        return JsonString(WideToUtf8(value));
    }

    std::wstring FileNameFromPath(const std::wstring& filePath)
    {
        size_t index = filePath.find_last_of(L"\\/");
        return index == std::wstring::npos ? filePath : filePath.substr(index + 1);
    }

    bool HasCreoExtension(const std::wstring& lowerPath, const wchar_t* extension)
    {
        const std::wstring ext(extension);
        size_t index = lowerPath.rfind(ext);
        if (index == std::wstring::npos)
        {
            return false;
        }

        size_t after = index + ext.size();
        return after == lowerPath.size() || lowerPath[after] == L'.';
    }

    ProMdlfileType GetFileTypeFromPath(const std::wstring& filePath)
    {
        std::wstring lowerPath = filePath;
        for (size_t i = 0; i < lowerPath.size(); ++i)
        {
            lowerPath[i] = static_cast<wchar_t>(std::towlower(lowerPath[i]));
        }

        if (HasCreoExtension(lowerPath, L".asm")) return PRO_MDLFILE_ASSEMBLY;
        if (HasCreoExtension(lowerPath, L".prt")) return PRO_MDLFILE_PART;
        if (HasCreoExtension(lowerPath, L".drw")) return PRO_MDLFILE_DRAWING;
        return PRO_MDLFILE_UNUSED;
    }

    std::string DocumentKindFromType(ProMdlType modelType)
    {
        switch (modelType)
        {
        case PRO_MDL_PART: return "Part";
        case PRO_MDL_ASSEMBLY: return "Assembly";
        case PRO_MDL_DRAWING: return "Drawing";
        default: return "Unknown";
        }
    }

    std::string ToolkitErrorMessage(ProError status)
    {
        std::ostringstream output;
        output << "Creo Toolkit error " << static_cast<int>(status);
        return output.str();
    }

    void FillModelIdentity(ProMdl model, CreoQuotePlugin::CreoQuoteMetrics& metrics)
    {
        ProMdlType modelType = PRO_MDL_UNUSED;
        if (ProMdlTypeGet(model, &modelType) == PRO_TK_NO_ERROR)
        {
            metrics.documentKind = DocumentKindFromType(modelType);
        }

        ProName modelName;
        modelName[0] = L'\0';
        if (ProMdlNameGet(model, modelName) == PRO_TK_NO_ERROR)
        {
            metrics.modelName = modelName;
        }

        ProMdlExtension extension;
        extension[0] = L'\0';
        if (ProMdlExtensionGet(model, extension) == PRO_TK_NO_ERROR)
        {
            metrics.modelExtension = extension;
        }

        ProMdlFileName displayName;
        displayName[0] = L'\0';
        if (ProMdlDisplaynameGet(model, PRO_B_TRUE, displayName) == PRO_TK_NO_ERROR)
        {
            metrics.fileName = displayName;
        }
        else if (!metrics.modelName.empty())
        {
            metrics.fileName = metrics.modelName;
            if (!metrics.modelExtension.empty())
            {
                metrics.fileName += L".";
                metrics.fileName += metrics.modelExtension;
            }
        }
    }

    bool IsCountableModelTreeFeature(ProFeature* feature)
    {
        if (feature == nullptr)
        {
            return false;
        }

        int featureNumber = -1;
        if (ProFeatureNumberGet(feature, &featureNumber) != PRO_TK_NO_ERROR || featureNumber < 0)
        {
            return false;
        }

        ProBoolean visible = PRO_B_FALSE;
        if (ProFeatureVisibilityGet(feature, &visible) != PRO_TK_NO_ERROR || visible != PRO_B_TRUE)
        {
            return false;
        }

        ProFeatStatus status = PRO_FEAT_INVALID;
        if (ProFeatureStatusGet(feature, &status) != PRO_TK_NO_ERROR)
        {
            return false;
        }

        return status == PRO_FEAT_ACTIVE || status == PRO_FEAT_UNREGENERATED;
    }

    bool TryGetFeatureType(ProFeature* feature, ProFeattype& featureType)
    {
        return feature != nullptr && ProFeatureTypeGet(feature, &featureType) == PRO_TK_NO_ERROR;
    }

    bool IsPartNonQuoteAuxiliaryFeature(ProFeature* feature, ProFeattype featureType);
    std::wstring GetFeatureName(ProFeature* feature);
    bool StartsWithIgnoreCase(const std::wstring& value, const wchar_t* prefix);

    bool IsReferenceFeature(ProFeattype featureType)
    {
        switch (featureType)
        {
        case PRO_FEAT_DATUM:
        case PRO_FEAT_DATUM_AXIS:
        case PRO_FEAT_DATUM_POINT:
        case PRO_FEAT_DATUM_SURF:
        case PRO_FEAT_DATUM_QUILT:
        case PRO_FEAT_CSYS:
        case PRO_FEAT_CURVE:
        case PRO_FEAT_REFERENCE:
        case PRO_FEAT_ANNOTATION:
            return true;
        default:
            return false;
        }
    }

    bool IsPartStaticFeature(ProFeattype featureType)
    {
        if (IsReferenceFeature(featureType))
        {
            return true;
        }

        switch (featureType)
        {
        case PRO_FEAT_COMPONENT:
        case PRO_FEAT_IMPORT:
        case PRO_FEAT_ANALYSIS:
        case PRO_FEAT_MEASURE:
        case PRO_FEAT_DECLARE:
        case PRO_FEAT_OLE:
        case PRO_FEAT_SENSOR:
        case PRO_FEAT_ROUTE_MANAGER:
        case PRO_FEAT_TERMINATOR:
        case PRO_FEAT_BULK_OBJECT:
        case PRO_FEAT_AUXILIARY:
        case PRO_FEAT_KERNEL:
        case PRO_FEAT_CUSTOM:
        case PRO_FEAT_CUSTOM_GRANITE:
            return true;
        default:
            return false;
        }
    }

    bool IsPartAlwaysIgnoredFeatureType(ProFeattype featureType)
    {
        switch (featureType)
        {
        case PRO_FEAT_COMPONENT:
        case PRO_FEAT_TERMINATOR:
            return true;
        default:
            return false;
        }
    }

    bool IsPartAlwaysCountedBusinessFeatureType(ProFeattype featureType)
    {
        switch (featureType)
        {
        case PRO_FEAT_FLATTEN:
            return true;
        default:
            return false;
        }
    }

    ProPatternStatus GetPatternStatus(ProFeature* feature)
    {
        ProPatternStatus patternStatus = PRO_PATTERN_NONE;
        if (feature != nullptr)
        {
            ProFeaturePatternStatusGet(feature, &patternStatus);
        }

        return patternStatus;
    }

    ProGrppatternStatus GetGroupPatternStatus(ProFeature* feature)
    {
        ProGrppatternStatus groupPatternStatus = PRO_GRP_PATTERN_NONE;
        if (feature != nullptr)
        {
            ProFeatureGrppatternStatusGet(feature, &groupPatternStatus);
        }

        return groupPatternStatus;
    }

    bool IsPatternMemberFeature(ProFeature* feature)
    {
        ProPatternStatus patternStatus = GetPatternStatus(feature);
        ProGrppatternStatus groupPatternStatus = GetGroupPatternStatus(feature);
        return patternStatus == PRO_PATTERN_MEMBER ||
               groupPatternStatus == PRO_GRP_PATTERN_MEMBER;
    }
    bool IsPatternHeaderFeature(ProFeature* feature, ProFeattype featureType)
    {
        if (featureType == PRO_FEAT_PATTERN_HEAD)
        {
            return true;
        }

        ProPatternStatus patternStatus = GetPatternStatus(feature);
        ProGrppatternStatus groupPatternStatus = GetGroupPatternStatus(feature);
        return patternStatus == PRO_PATTERN_HEADER ||
               groupPatternStatus == PRO_GRP_PATTERN_HEADER;
    }

    bool IsPatternLeaderFeature(ProFeature* feature)
    {
        ProPatternStatus patternStatus = GetPatternStatus(feature);
        ProGrppatternStatus groupPatternStatus = GetGroupPatternStatus(feature);
        return patternStatus == PRO_PATTERN_LEADER ||
               groupPatternStatus == PRO_GRP_PATTERN_LEADER;
    }

    bool IsPatternMemberOrLeaderFeature(ProFeature* feature)
    {
        return IsPatternLeaderFeature(feature) || IsPatternMemberFeature(feature);
    }

    bool TryGetPattern(ProFeature* feature, ProPattern& pattern)
    {
        if (feature == nullptr)
        {
            return false;
        }

        ProError status = ProFeaturePatternGet(feature, PRO_FEAT_PATTERN, &pattern);
        if (status == PRO_TK_NO_ERROR)
        {
            return true;
        }

        status = ProFeaturePatternGet(feature, PRO_GROUP_PATTERN, &pattern);
        return status == PRO_TK_NO_ERROR;
    }

    bool IsSameFeature(const ProFeature& left, const ProFeature& right)
    {
        return left.id == right.id && left.owner == right.owner;
    }

    bool IsFirstCountablePatternMember(ProFeature* feature)
    {
        if (feature == nullptr)
        {
            return false;
        }

        ProPattern pattern = {};
        if (!TryGetPattern(feature, pattern))
        {
            return IsPatternLeaderFeature(feature);
        }

        ProFeature* members = nullptr;
        ProError status = ProPatternMembersGet(&pattern, &members);
        if (status != PRO_TK_NO_ERROR || members == nullptr)
        {
            return IsPatternLeaderFeature(feature);
        }

        bool result = false;
        int memberCount = 0;
        if (ProArraySizeGet(members, &memberCount) == PRO_TK_NO_ERROR)
        {
            for (int i = 0; i < memberCount; ++i)
            {
                ProFeature& member = members[i];
                if (!IsCountableModelTreeFeature(&member))
                {
                    continue;
                }

                ProFeattype memberType = 0;
                if (!TryGetFeatureType(&member, memberType) || IsPartNonQuoteAuxiliaryFeature(&member, memberType))
                {
                    continue;
                }

                result = IsSameFeature(member, *feature);
                break;
            }
        }

        ProArrayFree(reinterpret_cast<ProArray*>(&members));
        return result;
    }

    bool ShouldCountOwnedSections(ProFeattype featureType)
    {
        switch (featureType)
        {
        case PRO_FEAT_CURVE:
        case PRO_FEAT_PATTERN_HEAD:
        case PRO_FEAT_XSEC:
        case PRO_FEAT_WALL:
            return false;
        default:
            return true;
        }
    }

    bool IsVisibleSectionFeature(ProFeature* feature, ProFeattype featureType)
    {
        if (feature == nullptr || IsPartNonQuoteAuxiliaryFeature(feature, featureType))
        {
            return false;
        }

        if (featureType == PRO_FEAT_XSEC || featureType == PRO_FEAT_DRV_TOOL_SKETCH)
        {
            return true;
        }

        std::wstring featureName = GetFeatureName(feature);
        return StartsWithIgnoreCase(featureName, L"??") ||
               StartsWithIgnoreCase(featureName, L"SECTION");
    }

    bool HasVisibleSectionChild(ProFeature* feature)
    {
        if (feature == nullptr)
        {
            return false;
        }

        int* childIds = nullptr;
        int childCount = 0;
        ProError status = ProFeatureChildrenGet(feature, &childIds, &childCount);
        if (status != PRO_TK_NO_ERROR || childIds == nullptr || childCount <= 0)
        {
            if (childIds != nullptr)
            {
                ProArrayFree(reinterpret_cast<ProArray*>(&childIds));
            }
            return false;
        }

        bool hasVisibleSectionChild = false;
        for (int i = 0; i < childCount; ++i)
        {
            ProFeature child = {};
            if (ProFeatureInit(reinterpret_cast<ProSolid>(feature->owner), childIds[i], &child) != PRO_TK_NO_ERROR)
            {
                continue;
            }

            if (!IsCountableModelTreeFeature(&child))
            {
                continue;
            }

            ProFeattype childType = 0;
            if (TryGetFeatureType(&child, childType) && IsVisibleSectionFeature(&child, childType))
            {
                hasVisibleSectionChild = true;
                break;
            }
        }

        ProArrayFree(reinterpret_cast<ProArray*>(&childIds));
        return hasVisibleSectionChild;
    }

    int CountOwnedSections(ProFeature* feature, ProFeattype featureType)
    {
        if (feature == nullptr || !ShouldCountOwnedSections(featureType) || HasVisibleSectionChild(feature))
        {
            return 0;
        }

        int sectionCount = 0;
        ProError status = ProFeatureNumSectionsGet(feature, &sectionCount);
        if (status != PRO_TK_NO_ERROR || sectionCount <= 0)
        {
            return 0;
        }

        int count = 0;
        for (int i = 0; i < sectionCount; ++i)
        {
            ProSection section = nullptr;
            status = ProFeatureSectionCopy(feature, i, &section);
            if (status == PRO_TK_NO_ERROR && section != nullptr)
            {
                ++count;
            }

            if (section != nullptr)
            {
                ProSectionFree(&section);
            }
        }

        return count;
    }

    std::wstring GetFeatureName(ProFeature* feature)
    {
        if (feature == nullptr)
        {
            return std::wstring();
        }

        ProName name;
        name[0] = L'\0';
        if (ProModelitemNameGet(feature, name) == PRO_TK_NO_ERROR && name[0] != L'\0')
        {
            return name;
        }

        name[0] = L'\0';
        if (ProModelitemDefaultnameGet(feature, name) == PRO_TK_NO_ERROR && name[0] != L'\0')
        {
            return name;
        }

        return std::wstring();
    }

    bool StartsWithIgnoreCase(const std::wstring& value, const wchar_t* prefix)
    {
        if (prefix == nullptr)
        {
            return false;
        }

        size_t index = 0;
        while (prefix[index] != L'\0')
        {
            if (index >= value.size() || towupper(value[index]) != towupper(prefix[index]))
            {
                return false;
            }

            ++index;
        }

        return true;
    }

    bool IsCreoGeneratedCrossSectionFeature(ProFeature* feature, ProFeattype featureType)
    {
        if (featureType != PRO_FEAT_XSEC)
        {
            return false;
        }

        std::wstring featureName = GetFeatureName(feature);
        return StartsWithIgnoreCase(featureName, L"XSEC");
    }

    bool IsPartNonQuoteAuxiliaryFeature(ProFeature* feature, ProFeattype featureType)
    {
        return IsPartAlwaysIgnoredFeatureType(featureType) ||
               IsCreoGeneratedCrossSectionFeature(feature, featureType);
    }

    void AddFeatureDiagnostic(CreoQuotePlugin::CreoQuoteMetrics& metrics, ProFeature* feature, ProFeattype featureType, const std::string& category, bool counted, int constraintCount)
    {
        CreoQuotePlugin::CreoQuoteFeatureDiagnostic diagnostic;
        diagnostic.id = feature == nullptr ? 0 : feature->id;
        diagnostic.type = static_cast<int>(featureType);
        diagnostic.name = GetFeatureName(feature);
        diagnostic.category = category;
        diagnostic.counted = counted;
        diagnostic.constraintCount = constraintCount;
        diagnostic.patternStatus = static_cast<int>(GetPatternStatus(feature));
        diagnostic.groupPatternStatus = static_cast<int>(GetGroupPatternStatus(feature));
        metrics.featureDiagnostics.push_back(diagnostic);
    }

    void AddComponentDiagnostic(CreoQuotePlugin::CreoQuoteMetrics& metrics, const CreoQuotePlugin::CreoQuoteAssemblyComponent& component)
    {
        AddFeatureDiagnostic(metrics, const_cast<ProFeature*>(&component.feature), component.featureType, component.category, true, component.constraintCount);
        CreoQuotePlugin::CreoQuoteFeatureDiagnostic& diagnostic = metrics.featureDiagnostics.back();
        diagnostic.placed = component.placed;
        diagnostic.packaged = component.packaged;
        diagnostic.unplaced = component.unplaced;
        diagnostic.frozen = component.frozen;
        diagnostic.bulkItem = component.bulkItem;
        diagnostic.substitute = component.substitute;
        diagnostic.underconstrained = component.underconstrained;
        diagnostic.readOnly = component.readOnly;
        diagnostic.incomplete = component.incomplete;
        diagnostic.statusFlagsAvailable = component.statusFlagsAvailable;
        diagnostic.statusFlags = component.statusFlags;
        diagnostic.componentType = static_cast<int>(component.componentType);
        diagnostic.modelType = static_cast<int>(component.modelType);
        diagnostic.placementDefinitionFilterReason = component.placementDefinitionFilterReason;
        diagnostic.componentMiscAttributesAvailable = component.componentMiscAttributesAvailable;
        diagnostic.componentMiscAttributes = component.componentMiscAttributes;
        diagnostic.constraintSource = component.constraintSource;
    }

    typedef ProError (*FeatureAction)(ProFeature*, ProError, ProAppData);

    ProError VisitDirectSolidFeatures(ProSolid solid, FeatureAction action, ProAppData data)
    {
        ProError status = ProSolidFeatVisit(solid, action, nullptr, data);
        return status == PRO_TK_E_NOT_FOUND ? PRO_TK_NO_ERROR : status;
    }

    ProError VisitActiveModelTreeFeatures(ProSolid solid, FeatureAction action, ProAppData data)
    {
        int* featureIds = nullptr;
        unsigned int* statusFlags = nullptr;
        ProError status = ProSolidFeatstatusflagsGet(solid, &featureIds, &statusFlags);
        if (status != PRO_TK_NO_ERROR)
        {
            return status;
        }

        if (featureIds == nullptr)
        {
            if (statusFlags != nullptr)
            {
                ProArrayFree(reinterpret_cast<ProArray*>(&statusFlags));
            }
            return PRO_TK_NO_ERROR;
        }

        int featureCount = 0;
        status = ProArraySizeGet(featureIds, &featureCount);
        if (status != PRO_TK_NO_ERROR)
        {
            ProArrayFree(reinterpret_cast<ProArray*>(&featureIds));
            if (statusFlags != nullptr)
            {
                ProArrayFree(reinterpret_cast<ProArray*>(&statusFlags));
            }
            return status;
        }

        for (int i = 0; i < featureCount; ++i)
        {
            ProFeature feature = {};
            if (ProFeatureInit(solid, featureIds[i], &feature) != PRO_TK_NO_ERROR)
            {
                continue;
            }

            ProError actionStatus = action(&feature, PRO_TK_NO_ERROR, data);
            if (actionStatus != PRO_TK_NO_ERROR)
            {
                status = actionStatus;
                break;
            }
        }

        ProArrayFree(reinterpret_cast<ProArray*>(&featureIds));
        if (statusFlags != nullptr)
        {
            ProArrayFree(reinterpret_cast<ProArray*>(&statusFlags));
        }
        return status;
    }

    struct FamilyTableColumnCounter
    {
        int columnCount = 0;
        std::vector<std::wstring> columnNames;
    };

    ProError CountFamilyTableColumnAction(ProFamtableItem* item, ProError status, ProAppData data)
    {
        if (item != nullptr && status == PRO_TK_NO_ERROR)
        {
            FamilyTableColumnCounter* counter = reinterpret_cast<FamilyTableColumnCounter*>(data);
            ++counter->columnCount;
            if (item->string[0] != L'\0')
            {
                counter->columnNames.push_back(item->string);
            }
        }

        return PRO_TK_NO_ERROR;
    }

    std::wstring BuildConfigurationProbeMessage(const wchar_t* source, ProError initStatus, ProError checkStatus)
    {
        std::wostringstream output;
        output << source << L": init=" << static_cast<int>(initStatus);
        if (initStatus == PRO_TK_NO_ERROR)
        {
            output << L", check=" << static_cast<int>(checkStatus);
        }
        return output.str();
    }

    bool CountFamilyTableColumnsFromModel(ProMdl model, CreoQuotePlugin::CreoQuoteMetrics& metrics, const wchar_t* source)
    {
        if (model == nullptr)
        {
            return false;
        }

        ProFamtable familyTable;
        ProError initStatus = ProFamtableInit(model, &familyTable);
        ProError checkStatus = PRO_TK_GENERAL_ERROR;
        if (initStatus == PRO_TK_NO_ERROR)
        {
            checkStatus = ProFamtableCheck(&familyTable);
        }

        metrics.configurationProbeMessages.push_back(BuildConfigurationProbeMessage(source, initStatus, checkStatus));
        if (initStatus != PRO_TK_NO_ERROR || checkStatus != PRO_TK_NO_ERROR)
        {
            return false;
        }

        FamilyTableColumnCounter counter;
        ProError visitStatus = ProFamtableItemVisit(&familyTable, CountFamilyTableColumnAction, nullptr, &counter);
        metrics.configurationProbeMessages.push_back(std::wstring(source) + L": columns=" + std::to_wstring(counter.columnCount) + L", visit=" + std::to_wstring(static_cast<int>(visitStatus)));
        if (visitStatus != PRO_TK_NO_ERROR && visitStatus != PRO_TK_E_NOT_FOUND)
        {
            return false;
        }

        metrics.configurationSource = source;
        metrics.configurationCount = counter.columnCount;
        metrics.familyInstanceNames.assign(counter.columnNames.begin(), counter.columnNames.end());
        return true;
    }

    void PopulateConfigurationCount(ProMdl model, CreoQuotePlugin::CreoQuoteMetrics& metrics)
    {
        metrics.configurationCount = 0;
        metrics.familyInstanceNames.clear();
        metrics.configurationSource.clear();
        metrics.configurationProbeMessages.clear();

        if (CountFamilyTableColumnsFromModel(model, metrics, L"DisplayedFamilyTable"))
        {
            return;
        }

        ProMdl displayedTableOwner = nullptr;
        ProError ownerStatus = ProFaminstanceGenericGet(model, PRO_B_TRUE, &displayedTableOwner);
        metrics.configurationProbeMessages.push_back(L"DisplayedFamilyTableOwnerGet=" + std::to_wstring(static_cast<int>(ownerStatus)));
        if (ownerStatus == PRO_TK_NO_ERROR)
        {
            CountFamilyTableColumnsFromModel(displayedTableOwner, metrics, L"DisplayedFamilyTableOwner");
        }
    }

    ProError CountPartFeatureAction(ProFeature* feature, ProError, ProAppData data)
    {
        CreoQuotePlugin::CreoQuoteMetrics* metrics = reinterpret_cast<CreoQuotePlugin::CreoQuoteMetrics*>(data);
        if (!IsCountableModelTreeFeature(feature))
        {
            return PRO_TK_NO_ERROR;
        }

        ProFeattype featureType = 0;
        if (!TryGetFeatureType(feature, featureType))
        {
            AddFeatureDiagnostic(*metrics, feature, featureType, "UnknownFeature", false, 0);
            return PRO_TK_NO_ERROR;
        }

        if (IsPartNonQuoteAuxiliaryFeature(feature, featureType))
        {
            AddFeatureDiagnostic(*metrics, feature, featureType, "PartNonQuoteAuxiliaryFeature", false, 0);
            return PRO_TK_NO_ERROR;
        }

        if (IsPartAlwaysCountedBusinessFeatureType(featureType))
        {
            int sectionCount = CountOwnedSections(feature, featureType);
            metrics->featureCount += 1 + sectionCount;
            AddFeatureDiagnostic(*metrics, feature, featureType, "PartBusinessFeature", true, sectionCount);
            return PRO_TK_NO_ERROR;
        }

        if (IsPatternHeaderFeature(feature, featureType))
        {
            ++metrics->featureCount;
            AddFeatureDiagnostic(*metrics, feature, featureType, "PartPatternHeadFeature", true, 0);
            return PRO_TK_NO_ERROR;
        }

        if (IsPatternMemberOrLeaderFeature(feature))
        {
            if (IsFirstCountablePatternMember(feature))
            {
                ++metrics->featureCount;
                AddFeatureDiagnostic(*metrics, feature, featureType, "PartPatternFirstMemberFeature", true, 0);
            }
            else
            {
                AddFeatureDiagnostic(*metrics, feature, featureType, "PartPatternOtherMemberFeature", false, 0);
            }
            return PRO_TK_NO_ERROR;
        }

        int sectionCount = CountOwnedSections(feature, featureType);
        metrics->featureCount += 1 + sectionCount;
        AddFeatureDiagnostic(*metrics, feature, featureType, "PartVisibleModelTreeFeature", true, sectionCount);
        return PRO_TK_NO_ERROR;
    }

    void MarkMetricFailure(CreoQuotePlugin::CreoQuoteMetrics& metrics, const char* context, ProError status)
    {
        metrics.status = status == PRO_TK_NO_ERROR ? PRO_TK_GENERAL_ERROR : status;
        metrics.errorMessage = std::string(context) + " " + ToolkitErrorMessage(metrics.status);
    }

    bool IsEmptyCollectionStatus(ProError status)
    {
        return status == PRO_TK_E_NOT_FOUND;
    }

    int CountProArrayItems(void* items)
    {
        int count = 0;
        if (items != nullptr && ProArraySizeGet(items, &count) == PRO_TK_NO_ERROR && count > 0)
        {
            return count;
        }

        return 0;
    }

    ProError CountDrawingSheets(ProDrawing drawing, int& count)
    {
        count = 0;
        int sheetCount = 0;
        ProError status = ProDrawingSheetsCount(drawing, &sheetCount);
        if (status != PRO_TK_NO_ERROR)
        {
            return status;
        }

        count = sheetCount;
        return PRO_TK_NO_ERROR;
    }

    ProError CountDrawingViews(ProDrawing drawing, int& count)
    {
        count = 0;
        ProView* views = nullptr;
        ProError status = ProDrawingViewsCollect(drawing, &views);
        if (IsEmptyCollectionStatus(status))
        {
            return PRO_TK_NO_ERROR;
        }
        if (status != PRO_TK_NO_ERROR)
        {
            return status;
        }

        count = CountProArrayItems(views);
        ProArrayFree(reinterpret_cast<ProArray*>(&views));
        return PRO_TK_NO_ERROR;
    }

    struct DrawingDimensionCounter
    {
        ProDrawing drawing = nullptr;
        int count = 0;
    };

    ProError CountDisplayedDimensionAction(ProDimension* dimension, ProError status, ProAppData data)
    {
        if (dimension == nullptr || status != PRO_TK_NO_ERROR || data == nullptr)
        {
            return PRO_TK_NO_ERROR;
        }

        DrawingDimensionCounter* counter = reinterpret_cast<DrawingDimensionCounter*>(data);
        ProView view = nullptr;
        if (ProDrawingDimensionViewGet(counter->drawing, dimension, &view) == PRO_TK_NO_ERROR && view != nullptr)
        {
            ++counter->count;
        }

        return PRO_TK_NO_ERROR;
    }

    ProError VisitDisplayedDimensionsFromDrawing(ProDrawing drawing, ProType type, DrawingDimensionCounter& counter)
    {
        ProError status = ProDrawingDimensionVisit(drawing, type, CountDisplayedDimensionAction, nullptr, &counter);
        return IsEmptyCollectionStatus(status) ? PRO_TK_NO_ERROR : status;
    }

    ProError VisitDisplayedDimensionsFromSolids(ProDrawing drawing, ProType type, DrawingDimensionCounter& counter)
    {
        ProSolid* solids = nullptr;
        ProError status = ProDrawingSolidsCollect(drawing, &solids);
        if (IsEmptyCollectionStatus(status))
        {
            return PRO_TK_NO_ERROR;
        }
        if (status != PRO_TK_NO_ERROR)
        {
            return status;
        }

        int solidCount = CountProArrayItems(solids);
        ProBoolean includeReferenceDimensions = type == PRO_REF_DIMENSION ? PRO_B_TRUE : PRO_B_FALSE;
        for (int i = 0; i < solidCount; ++i)
        {
            status = ProSolidDimensionVisit(solids[i], includeReferenceDimensions, CountDisplayedDimensionAction, nullptr, &counter);
            if (status != PRO_TK_NO_ERROR && !IsEmptyCollectionStatus(status))
            {
                ProArrayFree(reinterpret_cast<ProArray*>(&solids));
                return status;
            }
        }

        ProArrayFree(reinterpret_cast<ProArray*>(&solids));
        return PRO_TK_NO_ERROR;
    }

    ProError CountDisplayedDrawingDimensions(ProDrawing drawing, ProType type, int& count)
    {
        DrawingDimensionCounter counter;
        counter.drawing = drawing;

        ProError status = VisitDisplayedDimensionsFromDrawing(drawing, type, counter);
        if (status != PRO_TK_NO_ERROR)
        {
            return status;
        }

        status = VisitDisplayedDimensionsFromSolids(drawing, type, counter);
        if (status != PRO_TK_NO_ERROR)
        {
            return status;
        }

        count = counter.count;
        return PRO_TK_NO_ERROR;
    }

    ProError CountDrawingNotes(ProDrawing drawing, int sheetCount, int& count)
    {
        count = 0;
        for (int sheet = 1; sheet <= sheetCount; ++sheet)
        {
            ProDtlnote* notes = nullptr;
            ProError status = ProDrawingDtlnotesCollect(drawing, nullptr, sheet, &notes);
            if (IsEmptyCollectionStatus(status))
            {
                continue;
            }
            if (status != PRO_TK_NO_ERROR)
            {
                return status;
            }

            count += CountProArrayItems(notes);
            ProArrayFree(reinterpret_cast<ProArray*>(&notes));
        }

        return PRO_TK_NO_ERROR;
    }

    ProError GetDrawingTableSheet(ProDwgtable* table, int& sheet)
    {
        sheet = 0;
        int segmentCount = 0;
        int segmentId = -1;
        if (ProDwgtableSegCount(table, &segmentCount) == PRO_TK_NO_ERROR && segmentCount > 1)
        {
            segmentId = 1;
        }

        ProError status = ProDwgtableSegSheetGet(table, segmentId, &sheet);
        if (status == PRO_TK_BAD_CONTEXT && segmentId == -1)
        {
            status = ProDwgtableSegSheetGet(table, 1, &sheet);
        }

        return status;
    }

    ProError CountDrawingTables(ProDrawing drawing, int sheetCount, int& count)
    {
        count = 0;
        ProDwgtable* tables = nullptr;
        ProError status = ProDrawingTablesCollect(drawing, &tables);
        if (IsEmptyCollectionStatus(status))
        {
            return PRO_TK_NO_ERROR;
        }
        if (status != PRO_TK_NO_ERROR)
        {
            return status;
        }

        int tableCount = CountProArrayItems(tables);
        for (int i = 0; i < tableCount; ++i)
        {
            int tableSheet = 0;
            status = GetDrawingTableSheet(&tables[i], tableSheet);
            if (status == PRO_TK_NO_ERROR && tableSheet >= 1 && (sheetCount <= 0 || tableSheet <= sheetCount))
            {
                ++count;
            }
            else if (status != PRO_TK_NO_ERROR)
            {
                ProArrayFree(reinterpret_cast<ProArray*>(&tables));
                return status;
            }
        }

        ProArrayFree(reinterpret_cast<ProArray*>(&tables));
        return PRO_TK_NO_ERROR;
    }

    void PopulateDrawingCounts(ProMdl model, CreoQuotePlugin::CreoQuoteMetrics& metrics)
    {
        ProDrawing drawing = reinterpret_cast<ProDrawing>(model);

        ProError status = CountDrawingSheets(drawing, metrics.drawingSheetCount);
        if (status != PRO_TK_NO_ERROR)
        {
            MarkMetricFailure(metrics, "Failed to collect Creo drawing sheets.", status);
            return;
        }

        status = CountDrawingViews(drawing, metrics.viewCount);
        if (status != PRO_TK_NO_ERROR)
        {
            MarkMetricFailure(metrics, "Failed to collect Creo drawing views.", status);
            return;
        }

        int regularDimensionCount = 0;
        status = CountDisplayedDrawingDimensions(drawing, PRO_DIMENSION, regularDimensionCount);
        if (status != PRO_TK_NO_ERROR)
        {
            MarkMetricFailure(metrics, "Failed to collect Creo drawing dimensions.", status);
            return;
        }

        int referenceDimensionCount = 0;
        status = CountDisplayedDrawingDimensions(drawing, PRO_REF_DIMENSION, referenceDimensionCount);
        if (status != PRO_TK_NO_ERROR)
        {
            MarkMetricFailure(metrics, "Failed to collect Creo drawing reference dimensions.", status);
            return;
        }
        metrics.dimensionCount = regularDimensionCount + referenceDimensionCount;

        status = CountDrawingNotes(drawing, metrics.drawingSheetCount, metrics.noteCount);
        if (status != PRO_TK_NO_ERROR)
        {
            MarkMetricFailure(metrics, "Failed to collect Creo drawing notes.", status);
            return;
        }

        status = CountDrawingTables(drawing, metrics.drawingSheetCount, metrics.tableCount);
        if (status != PRO_TK_NO_ERROR)
        {
            MarkMetricFailure(metrics, "Failed to collect Creo drawing tables.", status);
        }
    }
    void PopulatePartCounts(ProMdl model, CreoQuotePlugin::CreoQuoteMetrics& metrics)
    {
        ProSolid solid = reinterpret_cast<ProSolid>(model);
        VisitDirectSolidFeatures(solid, CountPartFeatureAction, &metrics);
    }

    void PopulateAssemblyCounts(ProMdl model, CreoQuotePlugin::CreoQuoteMetrics& metrics)
    {
        ProSolid solid = reinterpret_cast<ProSolid>(model);
        CreoQuotePlugin::CreoQuoteAssemblyCounts assemblyCounts = CreoQuotePlugin::CollectQuoteAssemblyCounts(solid);
        metrics.componentCount = assemblyCounts.componentCount;
        metrics.mateCount = assemblyCounts.constraintCount;
        metrics.assemblyFeatureCount = assemblyCounts.assemblyFeatureCount;

        for (size_t i = 0; i < assemblyCounts.components.size(); ++i)
        {
            const CreoQuotePlugin::CreoQuoteAssemblyComponent& component = assemblyCounts.components[i];
            AddComponentDiagnostic(metrics, component);
        }

        for (size_t i = 0; i < assemblyCounts.assemblyFeatures.size(); ++i)
        {
            const CreoQuotePlugin::CreoQuoteAssemblyFeature& assemblyFeature = assemblyCounts.assemblyFeatures[i];
            AddFeatureDiagnostic(metrics, const_cast<ProFeature*>(&assemblyFeature.feature), assemblyFeature.featureType, assemblyFeature.category, true, 0);
        }
    }

    void AppendStringArray(std::ostringstream& output, const char* name, const std::vector<std::wstring>& values, int indent, bool trailingComma)
    {
        for (int i = 0; i < indent; ++i) output << ' ';
        output << JsonString(name) << ": [";
        for (size_t i = 0; i < values.size(); ++i)
        {
            if (i > 0) output << ", ";
            output << JsonString(values[i]);
        }
        output << "]" << (trailingComma ? "," : "") << "\n";
    }

    void AppendFeatureDiagnostics(std::ostringstream& output, const std::vector<CreoQuotePlugin::CreoQuoteFeatureDiagnostic>& features, int indent)
    {
        for (int i = 0; i < indent; ++i) output << ' ';
        output << "\"FeatureItems\": [";
        if (!features.empty()) output << "\n";

        for (size_t i = 0; i < features.size(); ++i)
        {
            const CreoQuotePlugin::CreoQuoteFeatureDiagnostic& feature = features[i];
            for (int j = 0; j < indent + 2; ++j) output << ' ';
            output << "{\"Id\": " << feature.id
                   << ", \"Type\": " << feature.type
                   << ", \"Name\": " << JsonString(feature.name)
                   << ", \"Category\": " << JsonString(feature.category)
                   << ", \"Counted\": " << (feature.counted ? "true" : "false")
                   << ", \"ConstraintCount\": " << feature.constraintCount
                   << ", \"PatternStatus\": " << feature.patternStatus
                   << ", \"GroupPatternStatus\": " << feature.groupPatternStatus
                   << ", \"Placed\": " << (feature.placed ? "true" : "false")
                   << ", \"Packaged\": " << (feature.packaged ? "true" : "false")
                   << ", \"Unplaced\": " << (feature.unplaced ? "true" : "false")
                   << ", \"Frozen\": " << (feature.frozen ? "true" : "false")
                   << ", \"BulkItem\": " << (feature.bulkItem ? "true" : "false")
                   << ", \"Substitute\": " << (feature.substitute ? "true" : "false")
                   << ", \"Underconstrained\": " << (feature.underconstrained ? "true" : "false")
                   << ", \"ReadOnly\": " << (feature.readOnly ? "true" : "false")
                   << ", \"Incomplete\": " << (feature.incomplete ? "true" : "false")
                   << ", \"StatusFlagsAvailable\": " << (feature.statusFlagsAvailable ? "true" : "false")
                   << ", \"StatusFlags\": " << feature.statusFlags
                   << ", \"ComponentType\": " << feature.componentType
                   << ", \"ModelType\": " << feature.modelType
                   << ", \"PlacementDefinitionFilterReason\": " << JsonString(feature.placementDefinitionFilterReason)
                   << ", \"ComponentMiscAttributesAvailable\": " << (feature.componentMiscAttributesAvailable ? "true" : "false")
                   << ", \"ComponentMiscAttributes\": " << feature.componentMiscAttributes
                   << ", \"ConstraintSource\": " << JsonString(feature.constraintSource)
                   << "}";
            if (i + 1 < features.size()) output << ",";
            output << "\n";
        }

        if (!features.empty())
        {
            for (int i = 0; i < indent; ++i) output << ' ';
        }
        output << "]\n";
    }

    void EnsureParentDirectory(const std::wstring& outputPath);
    void MinimizeCurrentProcessTopLevelWindows();
    void CaptureModelPreview(ProMdl model, const std::wstring& requestedFilePath, const std::wstring& previewOutputPath, CreoQuotePlugin::CreoQuoteMetrics& metrics);
    CreoQuotePlugin::CreoQuoteMetrics CollectModelMetrics(ProMdl model, const std::wstring& requestedFilePath, const std::wstring& previewOutputPath)
    {
        CreoQuotePlugin::CreoQuoteMetrics metrics;
        metrics.filePath = requestedFilePath;
        metrics.fileName = FileNameFromPath(requestedFilePath);

        FillModelIdentity(model, metrics);
        PopulateExpressionCount(model, metrics);
        PopulateConfigurationCount(model, metrics);

        ProMdlType modelType = PRO_MDL_UNUSED;
        if (ProMdlTypeGet(model, &modelType) != PRO_TK_NO_ERROR)
        {
            metrics.status = PRO_TK_GENERAL_ERROR;
            metrics.errorMessage = "Could not determine Creo model type.";
            return metrics;
        }

        switch (modelType)
        {
        case PRO_MDL_PART:
            PopulatePartCounts(model, metrics);
            break;
        case PRO_MDL_ASSEMBLY:
            PopulateAssemblyCounts(model, metrics);
            break;
        case PRO_MDL_DRAWING:
            PopulateDrawingCounts(model, metrics);
            break;
        default:
            metrics.status = PRO_TK_GENERAL_ERROR;
            metrics.errorMessage = "Unsupported Creo model type.";
            break;
        }

        if (!previewOutputPath.empty())
        {
            CaptureModelPreview(model, requestedFilePath, previewOutputPath, metrics);
        }

        return metrics;
    }



    BOOL CALLBACK MinimizeTopLevelWindowForCurrentProcess(HWND windowHandle, LPARAM currentProcessIdParam)
    {
        DWORD windowProcessId = 0;
        GetWindowThreadProcessId(windowHandle, &windowProcessId);
        DWORD currentProcessId = static_cast<DWORD>(currentProcessIdParam);
        if (windowProcessId != currentProcessId || !IsWindowVisible(windowHandle))
        {
            return TRUE;
        }

        ShowWindowAsync(windowHandle, SW_FORCEMINIMIZE);
        ShowWindow(windowHandle, SW_MINIMIZE);
        return TRUE;
    }

    void MinimizeCurrentProcessTopLevelWindows()
    {
        EnumWindows(MinimizeTopLevelWindowForCurrentProcess, static_cast<LPARAM>(GetCurrentProcessId()));
    }
    void CaptureModelPreview(ProMdl model, const std::wstring& requestedFilePath, const std::wstring& previewOutputPath, CreoQuotePlugin::CreoQuoteMetrics& metrics)
    {
        metrics.previewImagePath = previewOutputPath;
        metrics.previewImageFormat = "jpg";

        if (model == nullptr || previewOutputPath.empty())
        {
            metrics.previewImageError = "Preview output path is empty.";
            return;
        }

        MinimizeCurrentProcessTopLevelWindows();

        int defaultWindowId = -1;
        ProWindowCurrentGet(&defaultWindowId);

        ProMdlName modelName;
        modelName[0] = L'\0';
        ProError status = ProMdlNameGet(model, modelName);
        if (status != PRO_TK_NO_ERROR)
        {
            metrics.previewImageError = "Could not get Creo model name for preview. " + ToolkitErrorMessage(status);
            return;
        }

        ProMdlType modelType = PRO_MDL_UNUSED;
        status = ProMdlTypeGet(model, &modelType);
        if (status != PRO_TK_NO_ERROR)
        {
            metrics.previewImageError = "Could not get Creo model type for preview. " + ToolkitErrorMessage(status);
            return;
        }

        if (modelType == PRO_MDL_DRAWING)
        {
            metrics.previewImageError = "ProRasterFileWrite does not support drawing previews.";
            return;
        }

        int previewWindowId = -1;
        status = ProObjectwindowMdlnameCreate(modelName, static_cast<ProType>(modelType), &previewWindowId);
        if (status != PRO_TK_NO_ERROR)
        {
            metrics.previewImageError = "Could not create Creo preview window. " + ToolkitErrorMessage(status);
            return;
        }

        MinimizeCurrentProcessTopLevelWindows();

        status = ProWindowCurrentSet(previewWindowId);
        if (status == PRO_TK_NO_ERROR)
        {
            ProMdlDisplay(model);
            ProWindowRefresh(previewWindowId);
            ProWindowRefit(previewWindowId);
            MinimizeCurrentProcessTopLevelWindows();
            Sleep(75);

            ProPath outputPath;
            outputPath[0] = L'\0';
            wcsncpy_s(outputPath, previewOutputPath.c_str(), _TRUNCATE);
            EnsureParentDirectory(previewOutputPath);
            status = ProRasterFileWrite(previewWindowId, PRORASTERDEPTH_24, 5.2, 3.6, PRORASTERDPI_100, PRORASTERTYPE_JPEG, outputPath);
        }

        metrics.previewImageSucceeded = status == PRO_TK_NO_ERROR;
        if (!metrics.previewImageSucceeded)
        {
            metrics.previewImageError = "Could not export Creo preview image. " + ToolkitErrorMessage(status);
        }

        if (defaultWindowId != -1 && defaultWindowId != previewWindowId)
        {
            ProWindowCurrentSet(defaultWindowId);
            ProWindowDelete(previewWindowId);
            ProMdlEraseNotDisplayed();
        }

        MinimizeCurrentProcessTopLevelWindows();
    }

    void EnsureParentDirectory(const std::wstring& outputPath)
    {
        size_t index = outputPath.find_last_of(L"\\/");
        if (index == std::wstring::npos || index == 0)
        {
            return;
        }

        CreateDirectoryW(outputPath.substr(0, index).c_str(), nullptr);
    }
}

namespace CreoQuotePlugin
{
    CreoQuoteMetrics CollectCurrentModelMetrics()
    {
        ProMdl model = nullptr;
        ProError status = ProMdlCurrentGet(&model);
        if (status != PRO_TK_NO_ERROR || model == nullptr)
        {
            CreoQuoteMetrics metrics;
            metrics.status = status == PRO_TK_NO_ERROR ? PRO_TK_GENERAL_ERROR : status;
            metrics.errorMessage = "No active Creo model is available.";
            return metrics;
        }

        return CollectModelMetrics(model, std::wstring(), std::wstring());
    }

    CreoQuoteMetrics CollectFileMetrics(const std::wstring& filePath, const std::wstring& previewOutputPath)
    {
        CreoQuoteMetrics metrics;
        metrics.filePath = filePath;
        metrics.fileName = FileNameFromPath(filePath);

        ProPath proPath;
        proPath[0] = L'\0';
        wcsncpy_s(proPath, filePath.c_str(), _TRUNCATE);

        ProMdl model = nullptr;
        ProError status = ProMdlFiletypeLoad(proPath, PRO_MDLFILE_UNUSED, PRO_B_FALSE, &model);
        if (status != PRO_TK_NO_ERROR || model == nullptr)
        {
            metrics.status = status == PRO_TK_NO_ERROR ? PRO_TK_GENERAL_ERROR : status;
            metrics.errorMessage = std::string("Failed to load Creo model. ") + ToolkitErrorMessage(metrics.status);
            return metrics;
        }

        return CollectModelMetrics(model, filePath, previewOutputPath);
    }

    std::string MetricsToJson(const CreoQuoteMetrics& metrics)
    {
        const bool succeeded = metrics.status == PRO_TK_NO_ERROR && metrics.errorMessage.empty();
        std::ostringstream output;
        output << "{\n";
        output << "  \"source\": \"CreoPlugin\",\n";
        output << "  \"Succeeded\": " << (succeeded ? "true" : "false") << ",\n";
        output << "  \"Status\": " << static_cast<int>(metrics.status) << ",\n";
        output << "  \"ErrorMessage\": " << JsonString(metrics.errorMessage) << ",\n";
        output << "  \"FilePath\": " << JsonString(metrics.filePath) << ",\n";
        output << "  \"FileName\": " << JsonString(metrics.fileName) << ",\n";
        output << "  \"ModelName\": " << JsonString(metrics.modelName) << ",\n";
        output << "  \"ModelExtension\": " << JsonString(metrics.modelExtension) << ",\n";
        output << "  \"DocumentKind\": " << JsonString(metrics.documentKind) << ",\n";
        output << "  \"FeatureCount\": " << metrics.featureCount << ",\n";
        output << "  \"ConfigurationCount\": " << metrics.configurationCount << ",\n";
        output << "  \"ExpressionCount\": " << metrics.expressionCount << ",\n";
        output << "  \"ComponentCount\": " << metrics.componentCount << ",\n";
        output << "  \"MateCount\": " << metrics.mateCount << ",\n";
        output << "  \"AssemblyFeatureCount\": " << metrics.assemblyFeatureCount << ",\n";
        output << "  \"DrawingSheetCount\": " << metrics.drawingSheetCount << ",\n";
        output << "  \"ViewCount\": " << metrics.viewCount << ",\n";
        output << "  \"NoteCount\": " << metrics.noteCount << ",\n";
        output << "  \"DimensionCount\": " << metrics.dimensionCount << ",\n";
        output << "  \"TableCount\": " << metrics.tableCount << ",\n";
        output << "  \"PreviewImageSucceeded\": " << (metrics.previewImageSucceeded ? "true" : "false") << ",\n";
        output << "  \"PreviewImagePath\": " << JsonString(metrics.previewImagePath) << ",\n";
        output << "  \"PreviewImageFormat\": " << JsonString(metrics.previewImageFormat) << ",\n";
        output << "  \"PreviewImageError\": " << JsonString(metrics.previewImageError) << ",\n";
        output << "  \"Diagnostics\": {\n";
        AppendStringArray(output, "ParameterNames", metrics.parameterNames, 4, true);
        AppendStringArray(output, "ParameterDetails", metrics.parameterDiagnosticMessages, 4, true);
        AppendStringArray(output, "FilteredParameterMessages", metrics.filteredParameterMessages, 4, true);
        AppendStringArray(output, "FamilyInstanceNames", metrics.familyInstanceNames, 4, true);
        output << "    \"ConfigurationSource\": " << JsonString(metrics.configurationSource) << ",\n";
        AppendStringArray(output, "ConfigurationProbeMessages", metrics.configurationProbeMessages, 4, true);
        AppendFeatureDiagnostics(output, metrics.featureDiagnostics, 4);
        output << "  }\n";
        output << "}\n";
        return output.str();
    }

    std::wstring GetDefaultMetricsPath()
    {
        wchar_t explicitPath[32768];
        DWORD explicitLength = GetEnvironmentVariableW(MetricsEnvironmentVariable, explicitPath, static_cast<DWORD>(_countof(explicitPath)));
        if (explicitLength > 0 && explicitLength < _countof(explicitPath))
        {
            return explicitPath;
        }

        wchar_t tempPath[MAX_PATH];
        DWORD tempLength = GetTempPathW(static_cast<DWORD>(_countof(tempPath)), tempPath);
        std::wstring basePath = tempLength > 0 ? std::wstring(tempPath) : std::wstring(L".");
        if (!basePath.empty() && basePath[basePath.size() - 1] != L'\\' && basePath[basePath.size() - 1] != L'/')
        {
            basePath += L"\\";
        }

        std::wstring folderPath = basePath + DefaultMetricsFolder;
        CreateDirectoryW(folderPath.c_str(), nullptr);
        return folderPath + L"\\" + DefaultMetricsFileName;
    }

    bool WriteMetricsJson(const CreoQuoteMetrics& metrics, const std::wstring& outputPath)
    {
        EnsureParentDirectory(outputPath);
        std::string json = MetricsToJson(metrics);
        FILE* file = nullptr;
        if (_wfopen_s(&file, outputPath.c_str(), L"wb") != 0 || file == nullptr)
        {
            return false;
        }

        size_t written = fwrite(json.data(), 1, json.size(), file);
        fclose(file);
        return written == json.size();
    }
}

