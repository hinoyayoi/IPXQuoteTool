#include "CreoQuoteAssemblyComponents.h"

#include "CreoQuoteConstraintCounter.h"

#include <ProArray.h>
#include <ProAsmcomp.h>
#include <ProElemId.h>
#include <ProElement.h>
#include <ProElempath.h>
#include <ProFeature.h>
#include <ProMdl.h>
#include <ProPattern.h>
#include <ProSolid.h>
#include <ProUdf.h>

#include <set>

namespace
{
    struct CollectionState
    {
        CreoQuotePlugin::CreoQuoteAssemblyCounts counts;
        std::set<int> componentFeatureIds;
        std::set<int> assemblyFeatureIds;
        std::set<int> expandedGroupFeatureIds;
        std::set<int> inspectedPatternFeatureIds;
    };

    bool IsVisibleModelTreeFeature(ProFeature* feature)
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

        return true;
    }

    bool IsSuppressedOrInvalidFeatureStatus(ProFeatStatus status)
    {
        return status == PRO_FEAT_INVALID ||
               status == PRO_FEAT_FAMTAB_SUPPRESSED ||
               status == PRO_FEAT_SIMP_REP_SUPPRESSED ||
               status == PRO_FEAT_PROG_SUPPRESSED ||
               status == PRO_FEAT_SUPPRESSED;
    }

    bool IsVisibleUnsuppressedModelTreeFeature(ProFeature* feature)
    {
        if (!IsVisibleModelTreeFeature(feature))
        {
            return false;
        }

        ProFeatStatus status = PRO_FEAT_INVALID;
        if (ProFeatureStatusGet(feature, &status) != PRO_TK_NO_ERROR)
        {
            return false;
        }

        return !IsSuppressedOrInvalidFeatureStatus(status);
    }

    bool IsActiveVisibleModelTreeFeature(ProFeature* feature)
    {
        if (!IsVisibleModelTreeFeature(feature))
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

    bool IsPatternMemberOrLeaderFeature(ProFeature* feature)
    {
        ProPatternStatus patternStatus = GetPatternStatus(feature);
        ProGrppatternStatus groupPatternStatus = GetGroupPatternStatus(feature);
        return patternStatus == PRO_PATTERN_LEADER ||
               patternStatus == PRO_PATTERN_MEMBER ||
               groupPatternStatus == PRO_GRP_PATTERN_LEADER ||
               groupPatternStatus == PRO_GRP_PATTERN_MEMBER;
    }

    bool IsPatternMemberFeature(ProFeature* feature)
    {
        ProPatternStatus patternStatus = GetPatternStatus(feature);
        ProGrppatternStatus groupPatternStatus = GetGroupPatternStatus(feature);
        return patternStatus == PRO_PATTERN_MEMBER ||
               groupPatternStatus == PRO_GRP_PATTERN_MEMBER;
    }

    bool IsGroupMemberFeature(ProFeature* feature)
    {
        if (feature == nullptr)
        {
            return false;
        }

        ProGroupStatus groupStatus = PRO_GROUP_NONE;
        return ProFeatureGroupStatusGet(feature, &groupStatus) == PRO_TK_NO_ERROR &&
               groupStatus == PRO_GROUP_MEMBER;
    }

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
        case PRO_FEAT_REFERENCE:
        case PRO_FEAT_ANNOTATION:
            return true;
        default:
            return false;
        }
    }

    bool IsIgnoredAssemblyContainer(ProFeattype featureType)
    {
        return featureType == PRO_FEAT_GROUP_HEAD ||
               featureType == PRO_FEAT_TERMINATOR;
    }

    bool TryGetComponentModelType(ProFeature* feature, ProMdlType& modelType)
    {
        modelType = PRO_MDL_UNUSED;
        if (feature == nullptr)
        {
            return false;
        }

        ProAsmcomp component = *reinterpret_cast<ProAsmcomp*>(feature);
        ProMdl componentModel = nullptr;
        if (ProAsmcompMdlGet(&component, &componentModel) != PRO_TK_NO_ERROR || componentModel == nullptr)
        {
            return false;
        }

        return ProMdlTypeGet(componentModel, &modelType) == PRO_TK_NO_ERROR;
    }

    bool IsQuoteComponentModelType(ProMdlType modelType)
    {
        return modelType == PRO_MDL_PART || modelType == PRO_MDL_ASSEMBLY;
    }

    bool TryGetBooleanStatus(ProError status, ProBoolean value)
    {
        return status == PRO_TK_NO_ERROR && value == PRO_B_TRUE;
    }

    ProError GetDirectElementById(ProElement elementTree, ProElemId elementId, ProElement* element)
    {
        if (elementTree == nullptr || element == nullptr)
        {
            return PRO_TK_BAD_INPUTS;
        }

        *element = nullptr;

        ProElempath elementPath = nullptr;
        ProError status = ProElempathAlloc(&elementPath);
        if (status != PRO_TK_NO_ERROR)
        {
            return status;
        }

        ProElempathItem pathItem = {};
        pathItem.type = PRO_ELEM_PATH_ITEM_TYPE_ID;
        pathItem.path_item.elem_id = elementId;

        status = ProElempathDataSet(elementPath, &pathItem, 1);
        if (status == PRO_TK_NO_ERROR)
        {
            status = ProElemtreeElementGet(elementTree, elementPath, element);
        }

        ProElempathFree(&elementPath);
        return status;
    }

    bool TryGetComponentMiscAttributes(ProFeature* feature, int& attributes)
    {
        attributes = 0;
        if (feature == nullptr)
        {
            return false;
        }

        ProElement elementTree = nullptr;
        ProError status = ProFeatureElemtreeExtract(feature, nullptr, PRO_FEAT_EXTRACT_NO_OPTS, &elementTree);
        if (status != PRO_TK_NO_ERROR || elementTree == nullptr)
        {
            return false;
        }

        ProElement miscAttributesElement = nullptr;
        bool found = false;
        status = GetDirectElementById(elementTree, PRO_E_COMPONENT_MISC_ATTR, &miscAttributesElement);
        if (status == PRO_TK_NO_ERROR && miscAttributesElement != nullptr)
        {
            found = ProElementIntegerGet(miscAttributesElement, nullptr, &attributes) == PRO_TK_NO_ERROR;
        }

        ProElementFree(&elementTree);
        return found;
    }

    void FillComponentState(ProFeature* feature, CreoQuotePlugin::CreoQuoteAssemblyComponent& item)
    {
        ProAsmcomp component = *reinterpret_cast<ProAsmcomp*>(feature);

        ProBoolean placed = PRO_B_FALSE;
        item.placed = TryGetBooleanStatus(ProAsmcompIsPlaced(&component, &placed), placed);

        ProBoolean packaged = PRO_B_FALSE;
        item.packaged = TryGetBooleanStatus(ProAsmcompIsPackaged(&component, &packaged), packaged);

        ProBoolean unplaced = PRO_B_FALSE;
        item.unplaced = TryGetBooleanStatus(ProAsmcompIsUnplaced(&component, &unplaced), unplaced);

        ProBoolean frozen = PRO_B_FALSE;
        item.frozen = TryGetBooleanStatus(ProAsmcompIsFrozen(&component, &frozen), frozen);

        ProBoolean bulkItem = PRO_B_FALSE;
        item.bulkItem = TryGetBooleanStatus(ProAsmcompIsBulkitem(&component, &bulkItem), bulkItem);

        ProBoolean substitute = PRO_B_FALSE;
        item.substitute = TryGetBooleanStatus(ProAsmcompIsSubstitute(&component, &substitute), substitute);

        ProBoolean underconstrained = PRO_B_FALSE;
        item.underconstrained = TryGetBooleanStatus(ProAsmcompIsUnderconstrained(&component, &underconstrained), underconstrained);

        ProBoolean readOnly = PRO_B_FALSE;
        item.readOnly = TryGetBooleanStatus(ProFeatureIsReadonly(feature, &readOnly), readOnly);

        ProBoolean incomplete = PRO_B_FALSE;
        item.incomplete = TryGetBooleanStatus(ProFeatureIsIncomplete(feature, &incomplete), incomplete);

        unsigned int statusFlags = 0;
        if (ProFeatureStatusflagsGet(feature, &statusFlags) == PRO_TK_NO_ERROR)
        {
            item.statusFlagsAvailable = true;
            item.statusFlags = statusFlags;
        }

        ProAsmcompType componentType = PRO_ASM_COMP_TYPE_NONE;
        if (ProAsmcompTypeGet(&component, reinterpret_cast<ProAssembly>(feature->owner), &componentType) == PRO_TK_NO_ERROR)
        {
            item.componentType = componentType;
        }

        int componentMiscAttributes = 0;
        if (TryGetComponentMiscAttributes(feature, componentMiscAttributes))
        {
            item.componentMiscAttributesAvailable = true;
            item.componentMiscAttributes = componentMiscAttributes;
        }
    }

    std::string GetPlacementDefinitionFilterReason(const CreoQuotePlugin::CreoQuoteAssemblyComponent& item)
    {
        if (!item.placed)
        {
            return "NotPlaced";
        }

        if (item.unplaced)
        {
            return "Unplaced";
        }

        if (item.packaged)
        {
            return "Packaged";
        }

        if (!IsQuoteComponentModelType(item.modelType))
        {
            return "ComponentModelUnavailable";
        }

        if (item.frozen)
        {
            return "Frozen";
        }

        if (item.readOnly)
        {
            return "ReadOnlyFeature";
        }

        if (item.incomplete)
        {
            return "IncompleteFeature";
        }

        if (item.bulkItem)
        {
            return "BulkItem";
        }

        if (item.substitute)
        {
            return "Substitute";
        }

        int componentTypeValue = static_cast<int>(item.componentType);
        if (item.componentType == PRO_ASM_COMP_TYPE_NO_DEF_ASSUM ||
            (item.componentMiscAttributesAvailable &&
             (item.componentMiscAttributes & PRO_ASM_COMP_ATTR_NO_DEFAULT_ASSUMP) != 0) ||
            (componentTypeValue & PRO_ASM_COMP_ATTR_NO_DEFAULT_ASSUMP) != 0)
        {
            return "NoDefaultAssumption";
        }

        return std::string();
    }

    bool AddQuoteComponent(CollectionState& state, ProFeature feature, const char* category)
    {
        if (!IsVisibleUnsuppressedModelTreeFeature(&feature))
        {
            return false;
        }

        ProFeattype featureType = 0;
        if (!TryGetFeatureType(&feature, featureType) || featureType != PRO_FEAT_COMPONENT)
        {
            return false;
        }

        ProMdlType modelType = PRO_MDL_UNUSED;
        if (TryGetComponentModelType(&feature, modelType) && !IsQuoteComponentModelType(modelType))
        {
            return false;
        }

        if (!state.componentFeatureIds.insert(feature.id).second)
        {
            return false;
        }

        CreoQuotePlugin::CreoQuoteAssemblyComponent item;
        item.feature = feature;
        item.featureType = featureType;
        item.category = category == nullptr ? "SecondLevelComponent" : category;
        item.patternStatus = static_cast<int>(GetPatternStatus(&feature));
        item.groupPatternStatus = static_cast<int>(GetGroupPatternStatus(&feature));
        item.groupMember = IsGroupMemberFeature(&feature);
        item.modelType = modelType;
        FillComponentState(&feature, item);
        item.placementDefinitionFilterReason = GetPlacementDefinitionFilterReason(item);

        if (item.placementDefinitionFilterReason.empty())
        {
            CreoQuotePlugin::CreoQuoteConstraintCount constraintCount = CreoQuotePlugin::CountQuoteComponentConstraints(&feature);
            item.constraintCount = constraintCount.count;
            item.constraintSource = CreoQuotePlugin::ConstraintSourceName(constraintCount.source);
        }
        else
        {
            item.constraintCount = 0;
            item.constraintSource = "NoEditDefinition:" + item.placementDefinitionFilterReason;
        }

        state.counts.constraintCount += item.constraintCount;
        state.counts.components.push_back(item);
        return true;
    }

    bool AddAssemblyFeature(CollectionState& state, ProFeature feature, const char* category)
    {
        if (!IsActiveVisibleModelTreeFeature(&feature))
        {
            return false;
        }

        ProFeattype featureType = 0;
        if (!TryGetFeatureType(&feature, featureType))
        {
            return false;
        }

        if (featureType == PRO_FEAT_COMPONENT || IsReferenceFeature(featureType) || IsIgnoredAssemblyContainer(featureType))
        {
            return false;
        }

        if (IsPatternMemberFeature(&feature) && featureType != PRO_FEAT_PATTERN_HEAD)
        {
            return false;
        }

        if (!state.assemblyFeatureIds.insert(feature.id).second)
        {
            return false;
        }

        CreoQuotePlugin::CreoQuoteAssemblyFeature item;
        item.feature = feature;
        item.featureType = featureType;
        item.category = category == nullptr ? "SecondLevelAssemblyFeature" : category;
        item.patternStatus = static_cast<int>(GetPatternStatus(&feature));
        item.groupPatternStatus = static_cast<int>(GetGroupPatternStatus(&feature));
        item.groupMember = IsGroupMemberFeature(&feature);
        state.counts.assemblyFeatures.push_back(item);
        return true;
    }

    bool TryGetPattern(ProFeature* feature, ProPatternClass patternClass, ProPattern& pattern)
    {
        return feature != nullptr && ProFeaturePatternGet(feature, patternClass, &pattern) == PRO_TK_NO_ERROR;
    }

    bool TryAddFirstComponentFromPattern(CollectionState& state, ProPattern& pattern, const char* category)
    {
        ProFeature* members = nullptr;
        if (ProPatternMembersGet(&pattern, &members) != PRO_TK_NO_ERROR || members == nullptr)
        {
            return false;
        }

        bool added = false;
        int memberCount = 0;
        if (ProArraySizeGet(members, &memberCount) == PRO_TK_NO_ERROR)
        {
            for (int i = 0; i < memberCount; ++i)
            {
                ProFeattype memberType = 0;
                if (!TryGetFeatureType(&members[i], memberType))
                {
                    continue;
                }

                if (memberType == PRO_FEAT_COMPONENT)
                {
                    added = AddQuoteComponent(state, members[i], category);
                    break;
                }

                if (memberType == PRO_FEAT_GROUP_HEAD)
                {
                    // Patterned groups represent one second-level operation; the group itself is not a component.
                    continue;
                }
            }
        }

        ProArrayFree(reinterpret_cast<ProArray*>(&members));
        return added;
    }

    bool TryAddFirstComponentFromPatternFeature(CollectionState& state, ProFeature feature, const char* category)
    {
        bool added = false;
        ProPattern pattern = {};
        if (TryGetPattern(&feature, PRO_FEAT_PATTERN, pattern))
        {
            added = TryAddFirstComponentFromPattern(state, pattern, category) || added;
        }

        ProPattern groupPattern = {};
        if (TryGetPattern(&feature, PRO_GROUP_PATTERN, groupPattern))
        {
            added = TryAddFirstComponentFromPattern(state, groupPattern, category) || added;
        }

        return added;
    }

    bool IsFirstComponentInOwnPattern(ProFeature* feature)
    {
        if (feature == nullptr)
        {
            return false;
        }

        ProPattern patterns[2] = {};
        ProPatternClass classes[2] = { PRO_FEAT_PATTERN, PRO_GROUP_PATTERN };
        bool inspected = false;
        for (int patternIndex = 0; patternIndex < 2; ++patternIndex)
        {
            if (!TryGetPattern(feature, classes[patternIndex], patterns[patternIndex]))
            {
                continue;
            }

            inspected = true;
            ProFeature* members = nullptr;
            if (ProPatternMembersGet(&patterns[patternIndex], &members) != PRO_TK_NO_ERROR || members == nullptr)
            {
                continue;
            }

            bool result = false;
            int memberCount = 0;
            if (ProArraySizeGet(members, &memberCount) == PRO_TK_NO_ERROR)
            {
                for (int i = 0; i < memberCount; ++i)
                {
                    ProFeattype memberType = 0;
                    if (!TryGetFeatureType(&members[i], memberType) || memberType != PRO_FEAT_COMPONENT)
                    {
                        continue;
                    }

                    result = members[i].id == feature->id && members[i].owner == feature->owner;
                    break;
                }
            }

            ProArrayFree(reinterpret_cast<ProArray*>(&members));
            if (result)
            {
                return true;
            }
        }

        if (!inspected)
        {
            ProPatternStatus patternStatus = GetPatternStatus(feature);
            ProGrppatternStatus groupPatternStatus = GetGroupPatternStatus(feature);
            return patternStatus == PRO_PATTERN_LEADER || groupPatternStatus == PRO_GRP_PATTERN_LEADER;
        }

        return false;
    }

    void CollectGroupComponents(CollectionState& state, ProFeature feature, const char* category);
    void CollectFeatureOrContainer(CollectionState& state, ProFeature feature, const char* category);

    void CollectPatternFeature(CollectionState& state, ProFeature feature)
    {
        AddAssemblyFeature(state, feature, "SecondLevelAssemblyFeature");
        if (!state.inspectedPatternFeatureIds.insert(feature.id).second)
        {
            return;
        }

        TryAddFirstComponentFromPatternFeature(state, feature, "PatternSourceComponent");
    }

    void CollectFeatureOrContainer(CollectionState& state, ProFeature feature, const char* category)
    {
        if (!IsVisibleUnsuppressedModelTreeFeature(&feature))
        {
            return;
        }

        ProFeattype featureType = 0;
        if (!TryGetFeatureType(&feature, featureType))
        {
            return;
        }

        if (featureType == PRO_FEAT_COMPONENT)
        {
            if (IsPatternMemberOrLeaderFeature(&feature))
            {
                if (IsFirstComponentInOwnPattern(&feature))
                {
                    AddQuoteComponent(state, feature, "PatternSourceComponent");
                }
                return;
            }

            AddQuoteComponent(state, feature, category);
        }
        else if (featureType == PRO_FEAT_GROUP_HEAD)
        {
            CollectGroupComponents(state, feature, "GroupedSecondLevelComponent");
        }
        else if (featureType == PRO_FEAT_PATTERN_HEAD)
        {
            CollectPatternFeature(state, feature);
        }
        else
        {
            AddAssemblyFeature(state, feature, "SecondLevelAssemblyFeature");
        }
    }

    void CollectGroupComponents(CollectionState& state, ProFeature feature, const char* category)
    {
        if (!state.expandedGroupFeatureIds.insert(feature.id).second)
        {
            return;
        }

        ProGroup group = {};
        if (ProFeatureGroupGet(&feature, &group) != PRO_TK_NO_ERROR)
        {
            return;
        }

        ProFeature* members = nullptr;
        if (ProGroupFeaturesCollect(&group, &members) != PRO_TK_NO_ERROR || members == nullptr)
        {
            return;
        }

        int memberCount = 0;
        if (ProArraySizeGet(members, &memberCount) == PRO_TK_NO_ERROR)
        {
            for (int i = 0; i < memberCount; ++i)
            {
                if (members[i].id == feature.id)
                {
                    continue;
                }
                CollectFeatureOrContainer(state, members[i], category);
            }
        }

        ProArrayFree(reinterpret_cast<ProArray*>(&members));
    }

    ProError VisitTopAssemblyFeature(ProFeature* feature, ProError, ProAppData data)
    {
        CollectionState* state = reinterpret_cast<CollectionState*>(data);
        if (state == nullptr || feature == nullptr)
        {
            return PRO_TK_NO_ERROR;
        }

        if (IsGroupMemberFeature(feature))
        {
            ProFeattype featureType = 0;
            if (TryGetFeatureType(feature, featureType) && featureType == PRO_FEAT_COMPONENT)
            {
                CollectFeatureOrContainer(*state, *feature, "GroupedSecondLevelComponent");
            }
            return PRO_TK_NO_ERROR;
        }

        CollectFeatureOrContainer(*state, *feature, "SecondLevelComponent");
        return PRO_TK_NO_ERROR;
    }
}

namespace CreoQuotePlugin
{
    CreoQuoteAssemblyCounts CollectQuoteAssemblyCounts(ProSolid solid)
    {
        CollectionState state;
        ProError status = ProSolidFeatVisit(solid, VisitTopAssemblyFeature, nullptr, &state);
        if (status != PRO_TK_NO_ERROR && status != PRO_TK_E_NOT_FOUND)
        {
            return state.counts;
        }

        state.counts.componentCount = static_cast<int>(state.counts.components.size());
        state.counts.assemblyFeatureCount = static_cast<int>(state.counts.assemblyFeatures.size());
        return state.counts;
    }
}






