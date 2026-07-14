param(
    [string]$Configuration = "Release",
    [string]$Runtime = "win-x64",
    [switch]$SelfContained
)

$ErrorActionPreference = "Stop"

$scriptRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$projectRoot = Split-Path -Parent $scriptRoot
$projectFile = Join-Path $projectRoot "IPXQuoteTool.csproj"
$publishRoot = Join-Path $projectRoot "artifacts\publish"
$portableDir = Join-Path $publishRoot "IPXQuoteTool_Portable"
$zipPath = Join-Path $publishRoot "IPXQuoteTool_Portable.zip"
$coefficientFileName = "对象系数.xlsx"
$requiredDesktopRuntimeMajor = "10"
$runtimePackageId = "Microsoft.DotNet.DesktopRuntime.10"
$runtimeDownloadUrl = "https://dotnet.microsoft.com/en-us/download/dotnet/10.0"

if (!(Test-Path -LiteralPath $projectFile)) {
    throw "Project file was not found: $projectFile"
}

if (Test-Path -LiteralPath $portableDir) {
    Remove-Item -LiteralPath $portableDir -Recurse -Force
}

if (Test-Path -LiteralPath $zipPath) {
    Remove-Item -LiteralPath $zipPath -Force
}

New-Item -ItemType Directory -Path $portableDir -Force | Out-Null

$selfContainedValue = $SelfContained.IsPresent
$publishArgs = @(
    "publish",
    $projectFile,
    "-c", $Configuration,
    "-r", $Runtime,
    "--self-contained", $selfContainedValue.ToString().ToLowerInvariant(),
    "-p:EnableComHosting=false",
    "-o", $portableDir
)

if ($selfContainedValue) {
    $publishArgs += @(
        "-p:PublishSingleFile=false",
        "-p:PublishTrimmed=false"
    )
}

dotnet @publishArgs

$coefficientFile = Join-Path $portableDir $coefficientFileName
if (!(Test-Path -LiteralPath $coefficientFile)) {
    throw "Missing required file in portable folder: $coefficientFileName"
}

$launcherPath = Join-Path $portableDir "启动报价工具.cmd"
$launcher = @"
@echo off
setlocal
chcp 65001 >nul
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0Start-IPXQuoteTool.ps1"
exit /b %errorlevel%
"@
Set-Content -LiteralPath $launcherPath -Value $launcher -Encoding ASCII

$psLauncherPath = Join-Path $portableDir "Start-IPXQuoteTool.ps1"
$psLauncher = @"
`$ErrorActionPreference = "Stop"
`$Host.UI.RawUI.WindowTitle = "IPX报价工具启动器"
[Console]::OutputEncoding = [System.Text.UTF8Encoding]::new()

`$requiredMajor = "$requiredDesktopRuntimeMajor"
`$packageId = "$runtimePackageId"
`$downloadUrl = "$runtimeDownloadUrl"
`$appPath = Join-Path `$PSScriptRoot "IPXQuoteTool.exe"

function Test-DesktopRuntimeInstalled {
    try {
        `$runtimes = & dotnet --list-runtimes 2>`$null
        return (`$runtimes | Where-Object { `$_ -match "^Microsoft\.WindowsDesktop\.App\s+`$requiredMajor\." }).Count -gt 0
    }
    catch {
        return `$false
    }
}

function Start-App {
    if (!(Test-Path -LiteralPath `$appPath)) {
        Write-Host "未找到 IPXQuoteTool.exe，请确认文件夹完整。" -ForegroundColor Red
        Read-Host "按回车键退出"
        exit 1
    }

    Start-Process -FilePath `$appPath
    exit 0
}

if (Test-DesktopRuntimeInstalled) {
    Start-App
}

Write-Host "未检测到 .NET `$requiredMajor Desktop Runtime x64。" -ForegroundColor Yellow
Write-Host "将尝试通过 winget 自动安装：`$packageId"
Write-Host "安装过程中如果弹出权限或协议确认，请选择同意。"
Write-Host ""

`$wingetCommand = Get-Command winget -ErrorAction SilentlyContinue
if (`$null -eq `$wingetCommand) {
    Write-Host "当前系统未找到 winget，无法自动安装 .NET。" -ForegroundColor Red
    Write-Host "将打开官方下载页面，请安装 .NET `$requiredMajor Desktop Runtime x64 后重新运行。"
    Start-Process `$downloadUrl
    Read-Host "按回车键退出"
    exit 1
}

try {
    winget install --id `$packageId --source winget --accept-package-agreements --accept-source-agreements
}
catch {
    Write-Host "winget 安装过程出现异常：`$(`$_.Exception.Message)" -ForegroundColor Red
}

if (Test-DesktopRuntimeInstalled) {
    Write-Host ""
    Write-Host ".NET Desktop Runtime 已安装，正在启动报价工具..." -ForegroundColor Green
    Start-App
}

Write-Host ""
Write-Host "未能确认 .NET Desktop Runtime 安装成功。" -ForegroundColor Red
Write-Host "将打开官方下载页面，请安装 .NET `$requiredMajor Desktop Runtime x64 后重新运行。"
Start-Process `$downloadUrl
Read-Host "按回车键退出"
exit 1
"@
Set-Content -LiteralPath $psLauncherPath -Value $psLauncher -Encoding UTF8

$readmePath = Join-Path $portableDir "免安装使用说明.txt"
$packageType = if ($selfContainedValue) { "自包含版，已随包携带 .NET 运行时，文件较大。" } else { "小包版，客户电脑需安装 .NET $requiredDesktopRuntimeMajor Desktop Runtime x64；启动器会优先尝试自动安装。" }
$readme = @"
IPX报价工具 - 免安装版

包类型：
$packageType

使用方式：
1. 解压整个文件夹，不要只单独复制 IPXQuoteTool.exe。
2. 双击“启动报价工具.cmd”运行。
3. 如果未安装 .NET $requiredDesktopRuntimeMajor Desktop Runtime，启动器会尝试通过 winget 自动安装。
4. 安装过程中如果弹出权限或协议确认，请选择同意。
5. 对象系数.xlsx 必须和 IPXQuoteTool.exe 放在同一目录。
6. 销售可用 Excel 修改对象系数.xlsx 第三列的系数，保存后重新运行报价即可生效。
7. 客户电脑仍需具备对应的 SolidWorks/Document Manager 环境，否则无法读取 SolidWorks 文件。

.NET 下载页面：
$runtimeDownloadUrl

发布方式：
把整个 IPXQuoteTool_Portable 文件夹，或 IPXQuoteTool_Portable.zip 发给客户。
"@
Set-Content -LiteralPath $readmePath -Value $readme -Encoding UTF8

if (Test-Path -LiteralPath $zipPath) {
    Remove-Item -LiteralPath $zipPath -Force
}

Add-Type -AssemblyName System.IO.Compression.FileSystem
[System.IO.Compression.ZipFile]::CreateFromDirectory($portableDir, $zipPath, [System.IO.Compression.CompressionLevel]::Optimal, $true)

Write-Host ""
Write-Host "Portable folder: $portableDir"
Write-Host "Portable zip:    $zipPath"
if ($selfContainedValue) {
    Write-Host "Package type:    self-contained"
} else {
    Write-Host "Package type:    framework-dependent (.NET Desktop Runtime $requiredDesktopRuntimeMajor required)"
}

