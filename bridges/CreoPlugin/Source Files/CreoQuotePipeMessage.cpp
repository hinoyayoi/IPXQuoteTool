#include "CreoQuotePipeMessage.h"

#include <cstdint>
#include <string>
#include <vector>

namespace
{
    const uint32_t HeaderLengthBytes = 4;
    const uint32_t MaxMessageBytes = 4 * 1024 * 1024;

    std::string FormatWin32Error(const char* operation, DWORD errorCode)
    {
        return std::string(operation) + " failed. Win32 error=" + std::to_string(errorCode) + ".";
    }

    bool ReadExact(HANDLE pipe, void* buffer, DWORD byteCount, std::string& errorMessage)
    {
        char* cursor = static_cast<char*>(buffer);
        DWORD totalRead = 0;
        while (totalRead < byteCount)
        {
            DWORD bytesRead = 0;
            if (!ReadFile(pipe, cursor + totalRead, byteCount - totalRead, &bytesRead, nullptr))
            {
                errorMessage = FormatWin32Error("ReadFile", GetLastError());
                return false;
            }

            if (bytesRead == 0)
            {
                errorMessage = "Pipe closed before the complete message was received.";
                return false;
            }

            totalRead += bytesRead;
        }

        return true;
    }

    bool WriteExact(HANDLE pipe, const void* buffer, DWORD byteCount, std::string& errorMessage)
    {
        const char* cursor = static_cast<const char*>(buffer);
        DWORD totalWritten = 0;
        while (totalWritten < byteCount)
        {
            DWORD bytesWritten = 0;
            if (!WriteFile(pipe, cursor + totalWritten, byteCount - totalWritten, &bytesWritten, nullptr))
            {
                errorMessage = FormatWin32Error("WriteFile", GetLastError());
                return false;
            }

            if (bytesWritten == 0)
            {
                errorMessage = "Pipe write completed with zero bytes written.";
                return false;
            }

            totalWritten += bytesWritten;
        }

        return true;
    }

    uint32_t DecodeLittleEndianLength(const unsigned char* header)
    {
        return static_cast<uint32_t>(header[0]) |
            (static_cast<uint32_t>(header[1]) << 8) |
            (static_cast<uint32_t>(header[2]) << 16) |
            (static_cast<uint32_t>(header[3]) << 24);
    }

    void EncodeLittleEndianLength(uint32_t length, unsigned char* header)
    {
        header[0] = static_cast<unsigned char>(length & 0xFF);
        header[1] = static_cast<unsigned char>((length >> 8) & 0xFF);
        header[2] = static_cast<unsigned char>((length >> 16) & 0xFF);
        header[3] = static_cast<unsigned char>((length >> 24) & 0xFF);
    }

    bool ReadAvailableBytes(HANDLE pipe, std::string& message, std::string& errorMessage)
    {
        for (int attempt = 0; attempt < 5; ++attempt)
        {
            DWORD bytesAvailable = 0;
            if (!PeekNamedPipe(pipe, nullptr, 0, nullptr, &bytesAvailable, nullptr))
            {
                errorMessage = FormatWin32Error("PeekNamedPipe", GetLastError());
                return false;
            }

            if (bytesAvailable == 0)
            {
                Sleep(10);
                continue;
            }

            std::vector<char> buffer(bytesAvailable);
            if (!ReadExact(pipe, buffer.data(), bytesAvailable, errorMessage))
            {
                return false;
            }

            message.append(buffer.begin(), buffer.end());
        }

        return true;
    }
}

namespace CreoQuotePlugin
{
    bool ReadPipeMessage(HANDLE pipe, std::string& message, bool& wasFramed, std::string& errorMessage)
    {
        wasFramed = false;

        unsigned char header[HeaderLengthBytes] = {};
        if (!ReadExact(pipe, header, HeaderLengthBytes, errorMessage))
        {
            return false;
        }

        uint32_t payloadLength = DecodeLittleEndianLength(header);
        if (payloadLength == 0 || payloadLength > MaxMessageBytes)
        {
            message.assign(reinterpret_cast<const char*>(header), reinterpret_cast<const char*>(header) + HeaderLengthBytes);
            return ReadAvailableBytes(pipe, message, errorMessage);
        }

        std::vector<char> payload(payloadLength);
        if (!ReadExact(pipe, payload.data(), payloadLength, errorMessage))
        {
            return false;
        }

        message.assign(payload.begin(), payload.end());
        wasFramed = true;
        return true;
    }

    bool WritePipeMessage(HANDLE pipe, const std::string& message, std::string& errorMessage)
    {
        if (message.empty() || message.size() > MaxMessageBytes)
        {
            errorMessage = "Invalid Creo IPC response length: " + std::to_string(message.size()) + " bytes.";
            return false;
        }

        unsigned char header[HeaderLengthBytes] = {};
        EncodeLittleEndianLength(static_cast<uint32_t>(message.size()), header);
        if (!WriteExact(pipe, header, HeaderLengthBytes, errorMessage))
        {
            return false;
        }

        if (!WriteExact(pipe, message.data(), static_cast<DWORD>(message.size()), errorMessage))
        {
            return false;
        }

        FlushFileBuffers(pipe);
        return true;
    }

    bool WriteRawPipeMessage(HANDLE pipe, const std::string& message, std::string& errorMessage)
    {
        if (message.empty() || message.size() > MaxMessageBytes)
        {
            errorMessage = "Invalid Creo IPC raw response length: " + std::to_string(message.size()) + " bytes.";
            return false;
        }

        if (!WriteExact(pipe, message.data(), static_cast<DWORD>(message.size()), errorMessage))
        {
            return false;
        }

        FlushFileBuffers(pipe);
        return true;
    }
}
