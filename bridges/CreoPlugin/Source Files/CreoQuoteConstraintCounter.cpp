#include "CreoQuoteConstraintCounter.h"

#include <ProElemId.h>
#include <ProElement.h>
#include <ProElempath.h>
#include <ProFeature.h>

namespace
{
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

    bool TryCountElementTreeConstraints(ProFeature* feature, int& count, ProError& status)
    {
        count = 0;
        status = PRO_TK_BAD_INPUTS;

        if (feature == nullptr)
        {
            return false;
        }

        ProElement elementTree = nullptr;
        status = ProFeatureElemtreeExtract(feature, nullptr, PRO_FEAT_EXTRACT_NO_OPTS, &elementTree);
        if (status != PRO_TK_NO_ERROR || elementTree == nullptr)
        {
            return false;
        }

        ProElement constraintsElement = nullptr;
        status = GetDirectElementById(elementTree, PRO_E_COMPONENT_CONSTRAINTS, &constraintsElement);
        if (status == PRO_TK_NO_ERROR && constraintsElement != nullptr)
        {
            int arrayCount = 0;
            ProError countStatus = ProElementArrayCount(constraintsElement, nullptr, &arrayCount);
            if (countStatus == PRO_TK_NO_ERROR)
            {
                count = arrayCount > 0 ? arrayCount : 0;
                status = countStatus;
                ProElementFree(&elementTree);
                return true;
            }

            status = countStatus;
        }

        ProElementFree(&elementTree);
        return false;
    }
}

namespace CreoQuotePlugin
{
    CreoQuoteConstraintCount CountQuoteComponentConstraints(ProFeature* feature)
    {
        CreoQuoteConstraintCount result;

        int elementTreeCount = 0;
        ProError elementTreeStatus = PRO_TK_GENERAL_ERROR;
        if (TryCountElementTreeConstraints(feature, elementTreeCount, elementTreeStatus))
        {
            result.count = elementTreeCount;
            result.source = CreoQuoteConstraintSource::ElementTree;
            result.elementTreeStatus = elementTreeStatus;
            return result;
        }

        result.count = 0;
        result.source = CreoQuoteConstraintSource::None;
        result.elementTreeStatus = elementTreeStatus;
        return result;
    }

    const char* ConstraintSourceName(CreoQuoteConstraintSource source)
    {
        switch (source)
        {
        case CreoQuoteConstraintSource::ElementTree:
            return "ElementTree";
        default:
            return "None";
        }
    }
}
