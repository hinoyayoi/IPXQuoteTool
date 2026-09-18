#include "CreoQuotePluginLog.h"

#include <fstream>
#include <sstream>
#include <windows.h>

namespace
{
    const wchar_t* LogFolderName = L"IPXQuoteCreoPlugin";
    const wchar_t* LogFileName = L"plugin.log";

    std::wstring Utf8ToWideLog(const std::string& value)
    {
        if (value.empty())
        {
            return std::wstring();
        }

        int count = MultiByteToWideChar(CP_UTF8, 0, value.c_str(), static_cast<int>(value.size()), nullptr, 0);
        if (count <= 0)
        {
            return std::wstring(value.begin(), value.end());
        }

        std::wstring result(static_cast<size_t>(count), L'\0');
        MultiByteToWideChar(CP_UTF8, 0, value.c_str(), static_cast<int>(value.size()), &result[0], count);
        return result;
    }

    std::wstring GetLogDirectory()
    {
        wchar_t tempPath[MAX_PATH] = { 0 };
        DWORD length = GetTempPathW(MAX_PATH, tempPath);
        std::wstring directory = (length > 0 && length < MAX_PATH) ? std::wstring(tempPath) : std::wstring(L".\\");
        if (!directory.empty() && directory.back() != L'\\' && directory.back() != L'/')
        {
            directory += L"\\";
        }

        directory += LogFolderName;
        CreateDirectoryW(directory.c_str(), nullptr);
        return directory;
    }

    std::wstring GetTimestamp()
    {
        SYSTEMTIME now;
        GetLocalTime(&now);

        wchar_t buffer[64] = { 0 };
        swprintf_s(
            buffer,
            L"%04u-%02u-%02u %02u:%02u:%02u.%03u",
            now.wYear,
            now.wMonth,
            now.wDay,
            now.wHour,
            now.wMinute,
            now.wSecond,
            now.wMilliseconds);
        return buffer;
    }
}

namespace CreoQuotePlugin
{
    std::wstring GetPluginLogPath()
    {
        std::wstring path = GetLogDirectory();
        path += L"\\";
        path += LogFileName;
        return path;
    }

    void WritePluginLog(const std::string& message)
    {
        WritePluginLog(message, std::wstring());
    }

    void WritePluginLog(const std::string& message, const std::wstring& detail)
    {
        std::wofstream stream(GetPluginLogPath(), std::ios::app);
        if (!stream.is_open())
        {
            return;
        }

        stream << L"[" << GetTimestamp() << L"] " << Utf8ToWideLog(message);
        if (!detail.empty())
        {
            stream << L" " << detail;
        }
        stream << std::endl;
    }
}