#pragma once

#include <string>

namespace CreoQuotePlugin
{
    std::wstring GetCreoEnvironmentId();
    std::string GetCreoEnvironmentIdUtf8();
    std::wstring GetCreoPipeName();
    std::wstring GetCreoProcessPath();
    std::string GetCreoProcessPathUtf8();
}
