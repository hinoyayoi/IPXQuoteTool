#pragma once

#include <string>

namespace CreoQuotePlugin
{
    std::wstring GetPluginLogPath();
    void WritePluginLog(const std::string& message);
    void WritePluginLog(const std::string& message, const std::wstring& detail);
}