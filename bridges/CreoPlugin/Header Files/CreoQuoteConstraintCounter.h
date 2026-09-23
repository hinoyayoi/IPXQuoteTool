#pragma once

#include <ProFeature.h>
#include <ProToolkit.h>

namespace CreoQuotePlugin
{
    enum class CreoQuoteConstraintSource
    {
        None,
        ElementTree
    };

    struct CreoQuoteConstraintCount
    {
        int count = 0;
        CreoQuoteConstraintSource source = CreoQuoteConstraintSource::None;
        ProError elementTreeStatus = PRO_TK_GENERAL_ERROR;
    };

    CreoQuoteConstraintCount CountQuoteComponentConstraints(ProFeature* feature);
    const char* ConstraintSourceName(CreoQuoteConstraintSource source);
}
