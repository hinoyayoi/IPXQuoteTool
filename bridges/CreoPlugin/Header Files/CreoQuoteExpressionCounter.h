#pragma once

#include <ProMdl.h>

namespace CreoQuotePlugin
{
    struct CreoQuoteMetrics;

    void PopulateExpressionCount(ProMdl model, CreoQuoteMetrics& metrics);
}