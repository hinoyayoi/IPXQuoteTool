#include "CreoQuoteExpressionCounter.h"
#include "CreoQuoteMetrics.h"

#include <ProModelitem.h>
#include <ProParameter.h>
#include <ProToolkit.h>

#include <cwctype>
#include <set>
#include <string>

namespace
{
    struct ParameterVisitContext
    {
        CreoQuotePlugin::CreoQuoteMetrics* metrics = nullptr;
        std::set<std::wstring> countedParameterKeys;
    };

    std::wstring ParameterNameFromHandle(const ProParameter& parameter)
    {
        return parameter.id;
    }

    std::wstring NormalizeParameterKey(const std::wstring& name)
    {
        std::wstring result = name;
        for (size_t i = 0; i < result.size(); ++i)
        {
            result[i] = static_cast<wchar_t>(std::towupper(result[i]));
        }

        return result;
    }

    void AddFilteredParameter(ParameterVisitContext& context, const std::wstring& name, const std::wstring& reason)
    {
        if (context.metrics == nullptr)
        {
            return;
        }

        std::wstring message = name.empty() ? L"<empty>" : name;
        if (!reason.empty())
        {
            message += L"|";
            message += reason;
        }

        context.metrics->filteredParameterMessages.push_back(message);
    }

    void AppendDiagnosticField(std::wstring& message, const wchar_t* name, const std::wstring& value)
    {
        message += L"|";
        message += name;
        message += L"=";
        message += value;
    }

    void AppendDiagnosticField(std::wstring& message, const wchar_t* name, int value)
    {
        AppendDiagnosticField(message, name, std::to_wstring(value));
    }

    std::wstring BooleanDiagnosticValue(ProBoolean value)
    {
        return value == PRO_B_TRUE ? L"true" : L"false";
    }

    std::wstring ParameterDescription(ProParameter* parameter, ProError& status)
    {
        status = PRO_TK_BAD_INPUTS;
        if (parameter == nullptr)
        {
            return std::wstring();
        }

        wchar_t* description = nullptr;
        status = ProParameterDescriptionGet(parameter, &description);
        if (status != PRO_TK_NO_ERROR || description == nullptr)
        {
            return std::wstring();
        }

        std::wstring result(description);
        return result;
    }

    void AddParameterDiagnostic(ParameterVisitContext& context, ProParameter* parameter, const std::wstring& name, const std::wstring& decision, ProParamvalueType valueType, ProError valueStatus)
    {
        if (context.metrics == nullptr)
        {
            return;
        }

        std::wstring message = name.empty() ? L"<empty>" : name;
        AppendDiagnosticField(message, L"Decision", decision);
        AppendDiagnosticField(message, L"ValueType", static_cast<int>(valueType));
        AppendDiagnosticField(message, L"ValueStatus", static_cast<int>(valueStatus));

        ProLockstatus lockStatus = PRO_PARAMLOCKSTATUS_UNLOCKED;
        ProError lockReadStatus = parameter == nullptr ? PRO_TK_BAD_INPUTS : ProParameterLockstatusGet(parameter, &lockStatus);
        AppendDiagnosticField(message, L"LockStatus", static_cast<int>(lockStatus));
        AppendDiagnosticField(message, L"LockReadStatus", static_cast<int>(lockReadStatus));

        ProBoolean designated = PRO_B_FALSE;
        ProError designationStatus = parameter == nullptr ? PRO_TK_BAD_INPUTS : ProParameterDesignationVerify(parameter, &designated);
        AppendDiagnosticField(message, L"Designated", BooleanDiagnosticValue(designated));
        AppendDiagnosticField(message, L"DesignationStatus", static_cast<int>(designationStatus));

        ProParamtableSet tableSet = {};
        ProError tableStatus = parameter == nullptr ? PRO_TK_BAD_INPUTS : ProParameterTablesetGet(parameter, &tableSet);
        AppendDiagnosticField(message, L"TableStatus", static_cast<int>(tableStatus));

        ProError descriptionStatus = PRO_TK_BAD_INPUTS;
        std::wstring description = ParameterDescription(parameter, descriptionStatus);
        AppendDiagnosticField(message, L"DescriptionStatus", static_cast<int>(descriptionStatus));
        if (!description.empty())
        {
            AppendDiagnosticField(message, L"Description", description);
        }

        context.metrics->parameterDiagnosticMessages.push_back(message);
    }

    bool TryGetParameterValueType(ProParameter* parameter, ProParamvalueType& valueType, ProError& status)
    {
        ProParamvalue value = {};
        ProUnititem unit = {};
        status = ProParameterValueWithUnitsGet(parameter, &value, &unit);
        if (status != PRO_TK_NO_ERROR)
        {
            return false;
        }

        valueType = value.type;
        return true;
    }

    bool IsCountableParameterValueType(ProParamvalueType valueType)
    {
        switch (valueType)
        {
        case PRO_PARAM_DOUBLE:
        case PRO_PARAM_STRING:
        case PRO_PARAM_INTEGER:
        case PRO_PARAM_BOOLEAN:
        case PRO_PARAM_NOTE_ID:
            return true;
        default:
            return false;
        }
    }

    bool IsIgnoredPartParameterName(const std::wstring& key)
    {
        return key == L"PTC_MODIFIED";
    }

    bool IsPartModel(ProMdl model)
    {
        ProMdlType modelType = PRO_MDL_UNUSED;
        return ProMdlTypeGet(model, &modelType) == PRO_TK_NO_ERROR &&
               modelType == PRO_MDL_PART;
    }

    ProError CountRawModelParameterAction(ProParameter* parameter, ProError status, ProAppData data)
    {
        ParameterVisitContext* context = reinterpret_cast<ParameterVisitContext*>(data);
        if (context == nullptr || context->metrics == nullptr)
        {
            return PRO_TK_NO_ERROR;
        }

        if (parameter == nullptr || status != PRO_TK_NO_ERROR)
        {
            AddFilteredParameter(*context, L"", L"RawVisitStatus=" + std::to_wstring(static_cast<int>(status)));
            return PRO_TK_NO_ERROR;
        }

        ProParamvalueType valueType = PRO_PARAM_NOT_SET;
        ProError valueStatus = PRO_TK_GENERAL_ERROR;
        TryGetParameterValueType(parameter, valueType, valueStatus);

        ++context->metrics->expressionCount;

        const std::wstring name = ParameterNameFromHandle(*parameter);
        if (!name.empty())
        {
            context->metrics->parameterNames.push_back(name);
        }

        AddParameterDiagnostic(*context, parameter, name, L"RawCounted", valueType, valueStatus);
        return PRO_TK_NO_ERROR;
    }

    ProError CountQuoteParameterAction(ProParameter* parameter, ProError status, ProAppData data)
    {
        ParameterVisitContext* context = reinterpret_cast<ParameterVisitContext*>(data);
        if (context == nullptr || context->metrics == nullptr)
        {
            return PRO_TK_NO_ERROR;
        }

        if (parameter == nullptr || status != PRO_TK_NO_ERROR)
        {
            AddFilteredParameter(*context, L"", L"VisitStatus=" + std::to_wstring(static_cast<int>(status)));
            return PRO_TK_NO_ERROR;
        }

        const std::wstring name = ParameterNameFromHandle(*parameter);
        ProParamvalueType valueType = PRO_PARAM_NOT_SET;
        ProError valueStatus = PRO_TK_GENERAL_ERROR;
        const bool hasValue = TryGetParameterValueType(parameter, valueType, valueStatus);

        if (name.empty())
        {
            AddFilteredParameter(*context, name, L"EmptyName");
            AddParameterDiagnostic(*context, parameter, name, L"FilteredEmptyName", valueType, valueStatus);
            return PRO_TK_NO_ERROR;
        }

        const std::wstring key = NormalizeParameterKey(name);
        if (context->countedParameterKeys.find(key) != context->countedParameterKeys.end())
        {
            AddFilteredParameter(*context, name, L"DuplicateName");
            AddParameterDiagnostic(*context, parameter, name, L"FilteredDuplicateName", valueType, valueStatus);
            return PRO_TK_NO_ERROR;
        }

        if (IsIgnoredPartParameterName(key))
        {
            AddFilteredParameter(*context, name, L"IgnoredPartParameter");
            AddParameterDiagnostic(*context, parameter, name, L"FilteredIgnoredPartParameter", valueType, valueStatus);
            return PRO_TK_NO_ERROR;
        }

        if (!hasValue)
        {
            AddFilteredParameter(*context, name, L"ValueStatus=" + std::to_wstring(static_cast<int>(valueStatus)));
            AddParameterDiagnostic(*context, parameter, name, L"FilteredValueStatus", valueType, valueStatus);
            return PRO_TK_NO_ERROR;
        }

        if (!IsCountableParameterValueType(valueType))
        {
            AddFilteredParameter(*context, name, L"ValueType=" + std::to_wstring(static_cast<int>(valueType)));
            AddParameterDiagnostic(*context, parameter, name, L"FilteredValueType", valueType, valueStatus);
            return PRO_TK_NO_ERROR;
        }

        context->countedParameterKeys.insert(key);
        ++context->metrics->expressionCount;
        context->metrics->parameterNames.push_back(name);
        AddParameterDiagnostic(*context, parameter, name, L"Counted", valueType, valueStatus);
        return PRO_TK_NO_ERROR;
    }
}

namespace CreoQuotePlugin
{
    void PopulateExpressionCount(ProMdl model, CreoQuoteMetrics& metrics)
    {
        ProModelitem owner = {};
        if (ProMdlToModelitem(model, &owner) != PRO_TK_NO_ERROR)
        {
            return;
        }

        ParameterVisitContext context;
        context.metrics = &metrics;

        ProParameterAction action = IsPartModel(model) ? CountQuoteParameterAction : CountRawModelParameterAction;
        ProError visitStatus = ProParameterVisit(&owner, nullptr, action, &context);
        if (visitStatus != PRO_TK_NO_ERROR && visitStatus != PRO_TK_E_NOT_FOUND)
        {
            metrics.filteredParameterMessages.push_back(L"<visit>|Status=" + std::to_wstring(static_cast<int>(visitStatus)));
        }
    }
}
