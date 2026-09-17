#pragma once

#include <string>
#include <windows.h>

namespace CreoQuotePlugin
{
    bool ReadPipeMessage(HANDLE pipe, std::string& message, bool& wasFramed, std::string& errorMessage);
    bool WritePipeMessage(HANDLE pipe, const std::string& message, std::string& errorMessage);
    bool WriteRawPipeMessage(HANDLE pipe, const std::string& message, std::string& errorMessage);
}
