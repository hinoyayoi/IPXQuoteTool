#include "CreoQuoteMetrics.h"
#include "CreoQuoteIpc.h"

#include <windows.h>

#include <ProMenuBar.h>
#include <ProToolkit.h>
#include <ProUICmd.h>

namespace
{
    const wchar_t* MessageFile = L"IPXQuoteCreoPlugin.txt";

    uiCmdAccessState AlwaysAccessible(uiCmdAccessMode)
    {
        return ACCESS_AVAILABLE;
    }

    int StartIpcServerCommand(uiCmdCmdId, uiCmdValue*, void*)
    {
        CreoQuotePlugin::StartIpcServer();
        MessageBoxW(
            nullptr,
            L"IPX Quote Creo Plugin IPC server has started.\n\nYou can now run batch processing from IPXQuoteTool.",
            L"IPX Quote Creo Plugin",
            MB_OK | MB_ICONINFORMATION);
        return 0;
    }

    int ExportCurrentModelMetrics(uiCmdCmdId, uiCmdValue*, void*)
    {
        const CreoQuotePlugin::CreoQuoteMetrics metrics = CreoQuotePlugin::CollectCurrentModelMetrics();
        const std::wstring outputPath = CreoQuotePlugin::GetDefaultMetricsPath();
        const bool written = CreoQuotePlugin::WriteMetricsJson(metrics, outputPath);

        std::wstring message = written
            ? L"Creo metrics JSON was written to:\n"
            : L"Failed to write Creo metrics JSON to:\n";
        message += outputPath;
        MessageBoxW(nullptr, message.c_str(), L"IPX Quote Creo Plugin", MB_OK | (written ? MB_ICONINFORMATION : MB_ICONERROR));
        return 0;
    }
}

extern "C" int user_initialize()
{
    uiCmdCmdId startIpcCommand = nullptr;
    ProError startErr = ProCmdActionAdd(
        const_cast<char*>("IPXQuoteStartIpcServer"),
        StartIpcServerCommand,
        uiProeImmediate,
        AlwaysAccessible,
        PRO_B_TRUE,
        PRO_B_TRUE,
        &startIpcCommand);

    uiCmdCmdId exportCommand = nullptr;
    ProError exportErr = ProCmdActionAdd(
        const_cast<char*>("IPXQuoteExportCurrentMetrics"),
        ExportCurrentModelMetrics,
        uiProeImmediate,
        AlwaysAccessible,
        PRO_B_TRUE,
        PRO_B_TRUE,
        &exportCommand);

    if ((startErr != PRO_TK_NO_ERROR && startErr != PRO_TK_E_FOUND) ||
        (exportErr != PRO_TK_NO_ERROR && exportErr != PRO_TK_E_FOUND))
    {
        return 0;
    }

    ProCmdDesignate(
        startIpcCommand,
        const_cast<char*>("IPXQuoteStartIpcServer.label"),
        const_cast<char*>("IPXQuoteStartIpcServer.help"),
        const_cast<char*>("Start IPC server for IPX Quote batch processing."),
        const_cast<wchar_t*>(MessageFile));

    ProCmdDesignate(
        exportCommand,
        const_cast<char*>("IPXQuoteExportCurrentMetrics.label"),
        const_cast<char*>("IPXQuoteExportCurrentMetrics.help"),
        const_cast<char*>("Export current Creo model metrics for IPX Quote."),
        const_cast<wchar_t*>(MessageFile));

    ProMenubarMenuAdd(
        const_cast<char*>("IPXQuote"),
        const_cast<char*>("IPXQuote.menu"),
        nullptr,
        PRO_B_TRUE,
        const_cast<wchar_t*>(MessageFile));

    ProMenubarmenuPushbuttonAdd(
        const_cast<char*>("IPXQuote"),
        const_cast<char*>("IPXQuoteStartIpcServer"),
        const_cast<char*>("IPXQuoteStartIpcServer.label"),
        const_cast<char*>("IPXQuoteStartIpcServer.help"),
        nullptr,
        PRO_B_TRUE,
        startIpcCommand,
        const_cast<wchar_t*>(MessageFile));

    ProMenubarmenuPushbuttonAdd(
        const_cast<char*>("IPXQuote"),
        const_cast<char*>("IPXQuoteExportCurrentMetrics"),
        const_cast<char*>("IPXQuoteExportCurrentMetrics.label"),
        const_cast<char*>("IPXQuoteExportCurrentMetrics.help"),
        nullptr,
        PRO_B_TRUE,
        exportCommand,
        const_cast<wchar_t*>(MessageFile));

    if (CreoQuotePlugin::StartIpcServer())
    {
        OutputDebugStringW(L"IPXQuoteCreoPlugin IPC server started automatically.\n");
    }
    else
    {
        OutputDebugStringW(L"IPXQuoteCreoPlugin failed to start IPC server automatically.\n");
    }

    return 0;
}

extern "C" void user_terminate()
{
    CreoQuotePlugin::StopIpcServer();
    OutputDebugStringW(L"IPXQuoteCreoPlugin user_terminate.\n");
}
