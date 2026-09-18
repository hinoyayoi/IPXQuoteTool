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
$runtimeInstallerFileName = "windowsdesktop-runtime-10.0.10-win-x64.exe"
$runtimeInstallerSourceCandidates = @(
    (Join-Path $scriptRoot "runtime\$runtimeInstallerFileName"),
    (Join-Path $scriptRoot "runntime\$runtimeInstallerFileName")
)

if (!(Test-Path -LiteralPath $projectFile)) {
    throw "Project file was not found: $projectFile"
}

$normalizedConfiguration = if ($Configuration.Equals("Debug", [System.StringComparison]::OrdinalIgnoreCase)) { "Debug" } elseif ($Configuration.Equals("Release", [System.StringComparison]::OrdinalIgnoreCase)) { "Release" } else { throw "Unsupported Configuration: $Configuration. Use Debug or Release." }

$creoPluginDllName = "IPXQuoteCreoPlugin.dll"
$creoPluginSourceCandidates = @(
    (Join-Path $projectRoot "artifacts\bin\CreoPlugin\x64\$normalizedConfiguration\$creoPluginDllName"),
    (Join-Path $projectRoot "artifacts\bin\CreoPlugin\x64\Release\$creoPluginDllName"),
    (Join-Path $projectRoot "artifacts\bin\CreoPlugin\x64\Debug\$creoPluginDllName"),
    (Join-Path $projectRoot "bridges\CreoPlugin\x64\$normalizedConfiguration\$creoPluginDllName"),
    (Join-Path $projectRoot "bridges\CreoPlugin\x64\Release\$creoPluginDllName"),
    (Join-Path $projectRoot "bridges\CreoPlugin\x64\Debug\$creoPluginDllName")
)
$creoPluginTextSource = Join-Path $projectRoot "bridges\CreoPlugin\text"

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
    "-c", $normalizedConfiguration,
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

$runtimeInstallerSource = $runtimeInstallerSourceCandidates | Where-Object { Test-Path -LiteralPath $_ } | Select-Object -First 1
if (!$selfContainedValue -and ![string]::IsNullOrWhiteSpace($runtimeInstallerSource)) {
    $portableRuntimeDir = Join-Path $portableDir "runtime"
    New-Item -ItemType Directory -Path $portableRuntimeDir -Force | Out-Null
    Copy-Item -LiteralPath $runtimeInstallerSource -Destination (Join-Path $portableRuntimeDir $runtimeInstallerFileName) -Force
}

$creoPluginSource = $creoPluginSourceCandidates | Where-Object { Test-Path -LiteralPath $_ } | Select-Object -First 1
if ([string]::IsNullOrWhiteSpace($creoPluginSource)) {
    throw "Missing Creo plugin DLL. Please build bridges\CreoPlugin first. Expected: $($creoPluginSourceCandidates -join '; ')"
}

if (!(Test-Path -LiteralPath $creoPluginTextSource)) {
    throw "Missing Creo plugin text directory: $creoPluginTextSource"
}

$portableCreoPluginDir = Join-Path $portableDir "creo-plugin"
$portableCreoTextDir = Join-Path $portableCreoPluginDir "text"
New-Item -ItemType Directory -Path $portableCreoPluginDir -Force | Out-Null
Copy-Item -LiteralPath $creoPluginSource -Destination (Join-Path $portableCreoPluginDir $creoPluginDllName) -Force
Copy-Item -LiteralPath $creoPluginTextSource -Destination $portableCreoTextDir -Recurse -Force

$protkTemplate = @"
name IPXQuoteCreoPlugin
startup dll
exec_file {{PLUGIN_DLL}}
text_dir {{TEXT_DIR}}
revision 4
end
"@
Set-Content -LiteralPath (Join-Path $portableCreoPluginDir "protk.dat.template") -Value $protkTemplate -Encoding ASCII

$launcherPath = Join-Path $portableDir "启动费用估算.cmd"
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
`$Host.UI.RawUI.WindowTitle = "IPX费用估算启动器"
[Console]::OutputEncoding = [System.Text.UTF8Encoding]::new()

`$requiredMajor = "$requiredDesktopRuntimeMajor"
`$packageId = "$runtimePackageId"
`$downloadUrl = "$runtimeDownloadUrl"
`$appPath = Join-Path `$PSScriptRoot "IPXQuoteTool.exe"
`$localInstallerPath = Join-Path `$PSScriptRoot "runtime\$runtimeInstallerFileName"

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
Write-Host ""

if (Test-Path -LiteralPath `$localInstallerPath) {
    Write-Host "已找到随包携带的 .NET Desktop Runtime 安装程序。"
    `$confirm = Read-Host "是否现在安装 .NET `$requiredMajor Desktop Runtime？请输入 Y 确认"
    if (`$confirm -notin @("Y", "y")) {
        Write-Host "已取消安装，无法启动费用估算。" -ForegroundColor Yellow
        Read-Host "按回车键退出"
        exit 1
    }

    try {
        Write-Host "正在启动 .NET Desktop Runtime 安装程序，请按安装向导提示完成。"
        `$process = Start-Process -FilePath `$localInstallerPath -ArgumentList "/install", "/passive", "/norestart" -Verb RunAs -Wait -PassThru
        Write-Host "安装程序已退出，退出码：`$(`$process.ExitCode)"
    }
    catch {
        Write-Host "启动本地 .NET 安装程序失败：`$(`$_.Exception.Message)" -ForegroundColor Red
    }

    if (Test-DesktopRuntimeInstalled) {
        Write-Host ""
        Write-Host ".NET Desktop Runtime 已安装，正在启动费用估算..." -ForegroundColor Green
        Start-App
    }

    Write-Host ""
    Write-Host "未能确认 .NET Desktop Runtime 安装成功。" -ForegroundColor Red
    Write-Host "请手动运行 runtime 文件夹中的 `$([System.IO.Path]::GetFileName(`$localInstallerPath))，完成安装后重新启动。"
    Read-Host "按回车键退出"
    exit 1
}

Write-Host "未找到随包携带的 .NET 安装程序，将尝试通过 winget 自动安装：`$packageId"
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
    Write-Host ".NET Desktop Runtime 已安装，正在启动费用估算..." -ForegroundColor Green
    Start-App
}

Write-Host ""
Write-Host "未能确认 .NET Desktop Runtime 安装成功。" -ForegroundColor Red
Write-Host "将打开官方下载页面，请安装 .NET `$requiredMajor Desktop Runtime x64 后重新运行。"
Start-Process `$downloadUrl
Read-Host "按回车键退出"
exit 1
"@
[System.IO.File]::WriteAllText($psLauncherPath, $psLauncher, [System.Text.UTF8Encoding]::new($true))

$readmePath = Join-Path $portableDir "免安装使用说明.txt"
$hasLocalRuntimeInstaller = (!$selfContainedValue -and ![string]::IsNullOrWhiteSpace($runtimeInstallerSource))
$packageType = if ($selfContainedValue) { "自包含版，已随包携带 .NET 运行时，文件较大。" } elseif ($hasLocalRuntimeInstaller) { "小包版，随包携带 .NET $requiredDesktopRuntimeMajor Desktop Runtime x64 安装程序；启动器会在缺少运行时时提示安装。" } else { "小包版，客户电脑需安装 .NET $requiredDesktopRuntimeMajor Desktop Runtime x64；启动器会优先尝试自动安装。" }
$runtimeInstallStep = if ($hasLocalRuntimeInstaller) { "3. 如果未安装 .NET $requiredDesktopRuntimeMajor Desktop Runtime，启动器会优先使用 runtime 文件夹内的安装程序。" } else { "3. 如果未安装 .NET $requiredDesktopRuntimeMajor Desktop Runtime，启动器会尝试通过 winget 自动安装。" }
$pricingMode = if ($normalizedConfiguration -eq "Debug") { "Debug 版本：对象系数.xlsx 中的对象系数、单价、复杂度系数均会读取，便于开发测试。" } else { "Release 版本：对象系数.xlsx 第三列对象系数会读取；单价和复杂度系数固定使用程序内置值，修改表格中的单价/复杂度不会影响报价。" }

$buildInfoPath = Join-Path $portableDir "build-info.txt"
$buildInfo = @"
IPXQuoteTool build info

Configuration: $normalizedConfiguration
Runtime: $Runtime
SelfContained: $selfContainedValue
PricingMode: $pricingMode
BuiltAt: $(Get-Date -Format "yyyy-MM-dd HH:mm:ss")
"@
Set-Content -LiteralPath $buildInfoPath -Value $buildInfo -Encoding UTF8

$readme = @"
IPX费用估算 - 免安装版

包类型：
$packageType

构建配置：
$normalizedConfiguration

计价配置：
$pricingMode

使用方式：
1. 解压整个文件夹，不要只单独复制 IPXQuoteTool.exe。
2. 双击“启动费用估算.cmd”运行。
${runtimeInstallStep}
4. 安装过程中如果弹出权限或协议确认，请选择同意。
5. 对象系数.xlsx 必须和 IPXQuoteTool.exe 放在同一目录。
6. 销售可用 Excel 修改对象系数.xlsx 第三列的对象系数，保存后重新运行报价即可生效。
7. Release 版本不允许通过对象系数.xlsx 调整单价和复杂度系数；Debug 版本才会读取这些调试配置。
8. 客户电脑仍需具备对应的 SolidWorks/Document Manager 环境，否则无法读取 SolidWorks 文件。
9. 使用 Creo 报价时，请在软件路径中选择 Creo 安装目录，例如 ...\\PTC\\Creo 4.0；程序会自动定位版本目录和 Parametric\\bin。首次运行会请求管理员权限写入 protk.dat，以便 Creo 加载随包携带的 IPXQuoteCreoPlugin.dll。

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

