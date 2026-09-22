#include "CreoQuoteIpc.h"

#include "CreoQuoteEnvironment.h"
#include "CreoQuoteMetrics.h"
#include "CreoQuotePluginLog.h"
#include "CreoQuotePipeMessage.h"

#include <atomic>
#include <deque>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <windows.h>

#include <ProUIDialog.h>

namespace
{
    const char* TimerDialogName = "main_dlg_cur";
    const int TimerIntervalMs = 500;
    const int RequestTimeoutMs = 120000;

    struct PipeRequest
    {
        PipeRequest(const std::wstring& requestedFilePath, const std::wstring& requestedPreviewOutputPath, const std::string& requestedId, bool protocolRequest)
            : filePath(requestedFilePath), previewOutputPath(requestedPreviewOutputPath), requestId(requestedId), useProtocol(protocolRequest), completedEvent(CreateEventW(nullptr, TRUE, FALSE, nullptr))
        {
        }

        ~PipeRequest()
        {
            if (completedEvent != nullptr)
            {
                CloseHandle(completedEvent);
            }
        }

        std::wstring filePath;
        std::wstring previewOutputPath;
        std::string requestId;
        bool useProtocol = false;
        std::string responseJson;
        HANDLE completedEvent = nullptr;
    };

    std::atomic<bool> g_running(false);
    std::thread g_serverThread;
    CRITICAL_SECTION g_queueLock;
    std::atomic<bool> g_queueLockReady(false);
    std::deque<std::shared_ptr<PipeRequest>> g_pendingRequests;
    ProUITimerID g_timerId = nullptr;

    bool StartsWithJsonObject(const std::string& value)
    {
        for (char ch : value)
        {
            if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n')
            {
                continue;
            }

            return ch == '{';
        }

        return false;
    }

    std::string JsonEscape(const std::string& value)
    {
        std::string escaped;
        escaped.reserve(value.size() + 16);
        for (char ch : value)
        {
            switch (ch)
            {
            case '\\':
                escaped += "\\\\";
                break;
            case '"':
                escaped += "\\\"";
                break;
            case '\b':
                escaped += "\\b";
                break;
            case '\f':
                escaped += "\\f";
                break;
            case '\n':
                escaped += "\\n";
                break;
            case '\r':
                escaped += "\\r";
                break;
            case '\t':
                escaped += "\\t";
                break;
            default:
                escaped += ch;
                break;
            }
        }

        return escaped;
    }

    std::string ExtractJsonString(const std::string& json, const std::string& propertyName)
    {
        std::string key = "\"" + propertyName + "\"";
        size_t keyIndex = json.find(key);
        if (keyIndex == std::string::npos)
        {
            return std::string();
        }

        size_t colonIndex = json.find(':', keyIndex + key.size());
        if (colonIndex == std::string::npos)
        {
            return std::string();
        }

        size_t quoteIndex = json.find('"', colonIndex + 1);
        if (quoteIndex == std::string::npos)
        {
            return std::string();
        }

        std::string result;
        bool escaping = false;
        for (size_t i = quoteIndex + 1; i < json.size(); ++i)
        {
            char ch = json[i];
            if (escaping)
            {
                switch (ch)
                {
                case '"':
                    result += '"';
                    break;
                case '\\':
                    result += '\\';
                    break;
                case '/':
                    result += '/';
                    break;
                case 'b':
                    result += '\b';
                    break;
                case 'f':
                    result += '\f';
                    break;
                case 'n':
                    result += '\n';
                    break;
                case 'r':
                    result += '\r';
                    break;
                case 't':
                    result += '\t';
                    break;
                default:
                    result += ch;
                    break;
                }

                escaping = false;
                continue;
            }

            if (ch == '\\')
            {
                escaping = true;
                continue;
            }

            if (ch == '"')
            {
                break;
            }

            result += ch;
        }

        return result;
    }

    std::string MakeProtocolResponse(
        const std::string& requestId,
        const std::string& command,
        const std::string& status,
        const std::string& errorCode,
        const std::string& message,
        const std::string& metricsJson)
    {
        std::string response = "{";
        response += "\"version\":1";
        response += ",\"requestId\":\"" + JsonEscape(requestId) + "\"";
        response += ",\"command\":\"" + JsonEscape(command) + "\"";
        response += ",\"status\":\"" + JsonEscape(status) + "\"";
        response += ",\"errorCode\":\"" + JsonEscape(errorCode) + "\"";
        response += ",\"message\":\"" + JsonEscape(message) + "\"";
        response += ",\"environmentId\":\"" + JsonEscape(CreoQuotePlugin::GetCreoEnvironmentIdUtf8()) + "\"";
        response += ",\"processPath\":\"" + JsonEscape(CreoQuotePlugin::GetCreoProcessPathUtf8()) + "\"";
        if (!metricsJson.empty())
        {
            response += ",\"metrics\":";
            response += metricsJson;
        }
        response += "}";
        return response;
    }

    std::wstring Utf8ToWide(const std::string& value)
    {
        if (value.empty())
        {
            return std::wstring();
        }

        int count = MultiByteToWideChar(CP_UTF8, 0, value.c_str(), static_cast<int>(value.size()), nullptr, 0);
        if (count <= 0)
        {
            return std::wstring();
        }

        std::wstring result(static_cast<size_t>(count), L'\0');
        MultiByteToWideChar(CP_UTF8, 0, value.c_str(), static_cast<int>(value.size()), &result[0], count);
        return result;
    }

    std::string MakeFailedJson(const std::wstring& filePath, const std::string& errorMessage)
    {
        CreoQuotePlugin::CreoQuoteMetrics metrics;
        metrics.status = PRO_TK_GENERAL_ERROR;
        metrics.filePath = filePath;
        metrics.errorMessage = errorMessage;
        return CreoQuotePlugin::MetricsToJson(metrics);
    }

    std::string TrimRequestText(const std::string& value)
    {
        size_t begin = 0;
        while (begin < value.size() && (value[begin] == '\0' || value[begin] == '\r' || value[begin] == '\n' || value[begin] == ' ' || value[begin] == '\t'))
        {
            ++begin;
        }

        size_t end = value.size();
        while (end > begin && (value[end - 1] == '\0' || value[end - 1] == '\r' || value[end - 1] == '\n' || value[end - 1] == ' ' || value[end - 1] == '\t'))
        {
            --end;
        }

        return value.substr(begin, end - begin);
    }

    void EnqueueRequest(const std::shared_ptr<PipeRequest>& request)
    {
        EnterCriticalSection(&g_queueLock);
        g_pendingRequests.push_back(request);
        LeaveCriticalSection(&g_queueLock);
    }

    void ProcessPendingRequestsOnCreoThread()
    {
        while (true)
        {
            std::shared_ptr<PipeRequest> request;
            EnterCriticalSection(&g_queueLock);
            if (!g_pendingRequests.empty())
            {
                request = g_pendingRequests.front();
                g_pendingRequests.pop_front();
            }
            LeaveCriticalSection(&g_queueLock);

            if (!request)
            {
                break;
            }

            try
            {
                std::string metricsJson = CreoQuotePlugin::MetricsToJson(CreoQuotePlugin::CollectFileMetrics(request->filePath, request->previewOutputPath));
                request->responseJson = request->useProtocol
                    ? MakeProtocolResponse(request->requestId, "ReadMetrics", "Succeeded", "", "", metricsJson)
                    : metricsJson;
                CreoQuotePlugin::WritePluginLog("Metrics collected. requestId=" + request->requestId, request->filePath);
            }
            catch (...)
            {
                std::string failedJson = MakeFailedJson(request->filePath, "Unhandled exception while reading Creo model metrics.");
                request->responseJson = request->useProtocol
                    ? MakeProtocolResponse(request->requestId, "ReadMetrics", "Failed", "UnhandledException", "Unhandled exception while reading Creo model metrics.", failedJson)
                    : failedJson;
                CreoQuotePlugin::WritePluginLog("Metrics collection failed: unhandled exception. requestId=" + request->requestId, request->filePath);
            }

            if (request->completedEvent != nullptr)
            {
                SetEvent(request->completedEvent);
            }
        }
    }

    void RestartTimer()
    {
        if (g_running.load() && g_timerId != nullptr)
        {
            ProUIDialogTimerStart(const_cast<char*>(TimerDialogName), g_timerId, TimerIntervalMs, PRO_B_FALSE);
        }
    }

    void IpcTimerAction(char*, ProUITimerID, ProAppData)
    {
        ProcessPendingRequestsOnCreoThread();
        RestartTimer();
    }

    std::string ReadPipeRequest(HANDLE pipe, bool& wasFramed)
    {
        std::string requestText;
        std::string errorMessage;
        if (!CreoQuotePlugin::ReadPipeMessage(pipe, requestText, wasFramed, errorMessage))
        {
            CreoQuotePlugin::WritePluginLog("IPC request read failed: " + errorMessage);
            return std::string();
        }

        return TrimRequestText(requestText);
    }

    void WritePipeResponse(HANDLE pipe, const std::string& response, bool useFramedResponse)
    {
        std::string errorMessage;
        bool writeSucceeded = useFramedResponse
            ? CreoQuotePlugin::WritePipeMessage(pipe, response, errorMessage)
            : CreoQuotePlugin::WriteRawPipeMessage(pipe, response, errorMessage);
        if (!writeSucceeded)
        {
            CreoQuotePlugin::WritePluginLog("IPC response write failed: " + errorMessage);
        }
    }

    void HandlePipeClient(HANDLE pipe)
    {
        bool wasFramedRequest = false;
        std::string requestText = ReadPipeRequest(pipe, wasFramedRequest);
        const bool useProtocol = StartsWithJsonObject(requestText);
        std::string requestId;
        std::string command = "ReadMetrics";
        std::string filePathText = requestText;
        std::string previewOutputPathText;

        if (useProtocol)
        {
            requestId = ExtractJsonString(requestText, "requestId");
            command = ExtractJsonString(requestText, "command");
            filePathText = ExtractJsonString(requestText, "filePath");
            previewOutputPathText = ExtractJsonString(requestText, "previewOutputPath");
            if (command.empty())
            {
                command = "ReadMetrics";
            }
        }

        if (command == "Ping")
        {
            CreoQuotePlugin::WritePluginLog("Ping received. requestId=" + requestId);
            WritePipeResponse(pipe, MakeProtocolResponse(requestId, "Ping", "Succeeded", "", "Ready", std::string()), wasFramedRequest);
            CreoQuotePlugin::WritePluginLog("Ping response sent. requestId=" + requestId);
            return;
        }

        if (command != "ReadMetrics")
        {
            CreoQuotePlugin::WritePluginLog("Unsupported command received. requestId=" + requestId + " command=" + command);
            WritePipeResponse(pipe, MakeProtocolResponse(requestId, command, "Failed", "UnsupportedCommand", "Unsupported Creo IPC command.", std::string()), wasFramedRequest);
            return;
        }

        std::wstring filePath = Utf8ToWide(filePathText);
        std::wstring previewOutputPath = Utf8ToWide(previewOutputPathText);
        CreoQuotePlugin::WritePluginLog("ReadMetrics received. requestId=" + requestId, filePath);
        if (filePath.empty())
        {
            std::string failedJson = MakeFailedJson(std::wstring(), "Creo IPC request did not contain a file path.");
            CreoQuotePlugin::WritePluginLog("ReadMetrics failed: empty file path. requestId=" + requestId);
            WritePipeResponse(pipe, useProtocol
                ? MakeProtocolResponse(requestId, "ReadMetrics", "Failed", "EmptyFilePath", "Creo IPC request did not contain a file path.", failedJson)
                : failedJson, wasFramedRequest);
            return;
        }

        std::shared_ptr<PipeRequest> request = std::make_shared<PipeRequest>(filePath, previewOutputPath, requestId, useProtocol);
        if (request->completedEvent == nullptr)
        {
            std::string failedJson = MakeFailedJson(filePath, "Could not create Creo IPC completion event.");
            CreoQuotePlugin::WritePluginLog("ReadMetrics failed: completion event create failed. requestId=" + requestId, filePath);
            WritePipeResponse(pipe, useProtocol
                ? MakeProtocolResponse(requestId, "ReadMetrics", "Failed", "CompletionEventCreateFailed", "Could not create Creo IPC completion event.", failedJson)
                : failedJson, wasFramedRequest);
            return;
        }

        EnqueueRequest(request);
        DWORD waitResult = WaitForSingleObject(request->completedEvent, RequestTimeoutMs);
        if (waitResult != WAIT_OBJECT_0)
        {
            std::string failedJson = MakeFailedJson(filePath, "Timed out waiting for Creo plugin to process the request.");
            CreoQuotePlugin::WritePluginLog("ReadMetrics failed: request timeout. requestId=" + requestId, filePath);
            WritePipeResponse(pipe, useProtocol
                ? MakeProtocolResponse(requestId, "ReadMetrics", "Failed", "RequestTimeout", "Timed out waiting for Creo plugin to process the request.", failedJson)
                : failedJson, wasFramedRequest);
            return;
        }

        WritePipeResponse(pipe, request->responseJson, wasFramedRequest);
        CreoQuotePlugin::WritePluginLog("ReadMetrics response sent. requestId=" + requestId, filePath);
    }

    void PipeServerLoop()
    {
        while (g_running.load())
        {
            std::wstring pipeName = CreoQuotePlugin::GetCreoPipeName();
            HANDLE pipe = CreateNamedPipeW(
                pipeName.c_str(),
                PIPE_ACCESS_DUPLEX,
                PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
                1,
                65536,
                65536,
                0,
                nullptr);

            if (pipe == INVALID_HANDLE_VALUE)
            {
                Sleep(500);
                continue;
            }

            BOOL connected = ConnectNamedPipe(pipe, nullptr) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
            if (connected && g_running.load())
            {
                HandlePipeClient(pipe);
            }

            DisconnectNamedPipe(pipe);
            CloseHandle(pipe);
        }
    }

    void UnblockPipeServer()
    {
        std::wstring pipeName = CreoQuotePlugin::GetCreoPipeName();
        HANDLE pipe = CreateFileW(pipeName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
        if (pipe != INVALID_HANDLE_VALUE)
        {
            CloseHandle(pipe);
        }
    }
}

namespace CreoQuotePlugin
{
    bool StartIpcServer()
    {
        if (g_running.exchange(true))
        {
            CreoQuotePlugin::WritePluginLog("IPC server already running.");
            return true;
        }

        if (!g_queueLockReady.exchange(true))
        {
            InitializeCriticalSection(&g_queueLock);
        }

        ProName timerName = L"IPXQuoteIpcTimer";
        ProError err = ProUITimerCreate(IpcTimerAction, nullptr, timerName, &g_timerId);
        if (err != PRO_TK_NO_ERROR && err != PRO_TK_E_IN_USE)
        {
            g_running.store(false);
            CreoQuotePlugin::WritePluginLog("IPC server failed to create Creo UI timer.");
            return false;
        }

        RestartTimer();
        g_serverThread = std::thread(PipeServerLoop);
        CreoQuotePlugin::WritePluginLog("IPC server started. environmentId=" + CreoQuotePlugin::GetCreoEnvironmentIdUtf8());
        return true;
    }

    void StopIpcServer()
    {
        if (!g_running.exchange(false))
        {
            return;
        }

        CreoQuotePlugin::WritePluginLog("IPC server stopping.");

        if (g_timerId != nullptr)
        {
            ProUIDialogTimerStop(g_timerId);
            ProUITimerDestroy(g_timerId);
            g_timerId = nullptr;
        }

        UnblockPipeServer();
        if (g_serverThread.joinable())
        {
            g_serverThread.join();
        }
        CreoQuotePlugin::WritePluginLog("IPC server stopped.");
    }
}
