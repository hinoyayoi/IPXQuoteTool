#include "CreoQuoteEnvironment.h"
#include "CreoQuotePipeMessage.h"

#include <Windows.h>

#include <cwctype>
#include <iomanip>
#include <locale>
#include <sstream>

namespace CreoQuotePlugin
{
namespace
{
    const unsigned long long FnvOffsetBasis = 14695981039346656037ULL;
    const unsigned long long FnvPrime = 1099511628211ULL;

    std::wstring TrimTrailingSlash(const std::wstring& path)
    {
        if (path.empty())
        {
            return path;
        }

        std::wstring normalized = path;
        while (!normalized.empty() && (normalized.back() == L'\\' || normalized.back() == L'/'))
        {
            normalized.pop_back();
        }

        return normalized;
    }

    std::wstring GetParentDirectory(const std::wstring& path)
    {
        std::wstring normalized = TrimTrailingSlash(path);
        std::size_t slash = normalized.find_last_of(L"\\/");
        if (slash == std::wstring::npos)
        {
            return std::wstring();
        }

        return normalized.substr(0, slash);
    }

    std::wstring GetFileName(const std::wstring& path)
    {
        std::wstring normalized = TrimTrailingSlash(path);
        std::size_t slash = normalized.find_last_of(L"\\/");
        if (slash == std::wstring::npos)
        {
            return normalized;
        }

        return normalized.substr(slash + 1);
    }

    bool EqualsIgnoreCase(const std::wstring& left, const std::wstring& right)
    {
        if (left.size() != right.size())
        {
            return false;
        }

        for (std::size_t index = 0; index < left.size(); ++index)
        {
            if (std::towlower(left[index]) != std::towlower(right[index]))
            {
                return false;
            }
        }

        return true;
    }

    std::wstring GetDirectoryName(const std::wstring& path)
    {
        return GetParentDirectory(path);
    }

    std::wstring ResolveCreoInstallRootFromProcessPath(const std::wstring& processPath)
    {
        std::wstring binDirectory = GetDirectoryName(processPath);
        if (binDirectory.empty())
        {
            return std::wstring();
        }

        std::wstring parametricDirectory = GetParentDirectory(binDirectory);
        std::wstring creoRootDirectory = GetParentDirectory(parametricDirectory);
        if (EqualsIgnoreCase(GetFileName(binDirectory), L"bin") &&
            EqualsIgnoreCase(GetFileName(parametricDirectory), L"Parametric") &&
            !creoRootDirectory.empty())
        {
            return TrimTrailingSlash(creoRootDirectory);
        }

        std::wstring current = binDirectory;
        for (int depth = 0; depth < 8 && !current.empty(); ++depth)
        {
            std::wstring commonText = current + L"\\Common Files\\text";
            std::wstring parametricBin = current + L"\\Parametric\\bin";
            DWORD commonAttributes = GetFileAttributesW(commonText.c_str());
            DWORD binAttributes = GetFileAttributesW(parametricBin.c_str());
            if ((commonAttributes != INVALID_FILE_ATTRIBUTES && (commonAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0) &&
                (binAttributes != INVALID_FILE_ATTRIBUTES && (binAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0))
            {
                return TrimTrailingSlash(current);
            }

            current = GetParentDirectory(current);
        }

        return TrimTrailingSlash(binDirectory);
    }

    std::wstring ToUpperInvariant(const std::wstring& text)
    {
        std::wstring upper;
        upper.reserve(text.size());
        for (wchar_t ch : text)
        {
            upper.push_back(static_cast<wchar_t>(std::towupper(ch)));
        }

        return upper;
    }

    std::wstring NormalizeForHash(const std::wstring& path)
    {
        wchar_t fullPath[MAX_PATH] = { 0 };
        DWORD length = GetFullPathNameW(path.c_str(), MAX_PATH, fullPath, nullptr);
        std::wstring normalized = length > 0 && length < MAX_PATH ? std::wstring(fullPath, length) : path;
        for (wchar_t& ch : normalized)
        {
            if (ch == L'/')
            {
                ch = L'\\';
            }
        }

        return TrimTrailingSlash(normalized);
    }

    std::wstring HashEnvironmentPath(const std::wstring& creoRootDirectory)
    {
        std::wstring normalized = NormalizeForHash(creoRootDirectory);
        if (normalized.empty())
        {
            normalized = L"unknown";
        }

        unsigned long long hash = FnvOffsetBasis;
        std::wstring upper = ToUpperInvariant(normalized);
        for (wchar_t ch : upper)
        {
            hash ^= static_cast<unsigned long long>(ch);
            hash *= FnvPrime;
        }

        std::wstringstream stream;
        stream << L"Creo_" << std::uppercase << std::hex << std::setw(16) << std::setfill(L'0') << hash;
        return stream.str();
    }

    std::wstring SanitizePipeSegment(const std::wstring& value)
    {
        if (value.empty())
        {
            return L"Unknown";
        }

        std::wstring sanitized;
        sanitized.reserve(value.size());
        for (wchar_t ch : value)
        {
            if ((ch >= L'A' && ch <= L'Z') ||
                (ch >= L'a' && ch <= L'z') ||
                (ch >= L'0' && ch <= L'9') ||
                ch == L'_' ||
                ch == L'-')
            {
                sanitized.push_back(ch);
            }
            else
            {
                sanitized.push_back(L'_');
            }
        }

        return sanitized.empty() ? L"Unknown" : sanitized;
    }

    std::string WideToUtf8Text(const std::wstring& value)
    {
        if (value.empty())
        {
            return std::string();
        }

        int byteCount = WideCharToMultiByte(CP_UTF8, 0, value.c_str(), static_cast<int>(value.size()), nullptr, 0, nullptr, nullptr);
        if (byteCount <= 0)
        {
            return std::string();
        }

        std::string converted(static_cast<std::size_t>(byteCount), '\0');
        WideCharToMultiByte(CP_UTF8, 0, value.c_str(), static_cast<int>(value.size()), &converted[0], byteCount, nullptr, nullptr);
        return converted;
    }
}

std::wstring GetCreoProcessPath()
{
    wchar_t buffer[MAX_PATH] = { 0 };
    DWORD length = GetModuleFileNameW(nullptr, buffer, MAX_PATH);
    if (length == 0 || length >= MAX_PATH)
    {
        return std::wstring();
    }

    return std::wstring(buffer, length);
}

std::string GetCreoProcessPathUtf8()
{
    return WideToUtf8Text(GetCreoProcessPath());
}

std::wstring GetCreoEnvironmentId()
{
    static std::wstring environmentId = HashEnvironmentPath(ResolveCreoInstallRootFromProcessPath(GetCreoProcessPath()));
    return environmentId;
}

std::string GetCreoEnvironmentIdUtf8()
{
    return WideToUtf8Text(GetCreoEnvironmentId());
}

std::wstring GetCreoPipeName()
{
    static std::wstring pipeName = L"\\\\.\\pipe\\IPXQuoteCreoPlugin_" + SanitizePipeSegment(GetCreoEnvironmentId());
    return pipeName;
}
}

