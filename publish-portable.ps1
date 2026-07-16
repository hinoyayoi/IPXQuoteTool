param(
    [string]$Configuration = "Release",
    [string]$Runtime = "win-x64",
    [switch]$SelfContained
)

$ErrorActionPreference = "Stop"

$scriptPath = Join-Path $PSScriptRoot "packaging\publish-portable.ps1"
if (!(Test-Path -LiteralPath $scriptPath)) {
    throw "Portable publish script was not found: $scriptPath"
}

$arguments = @{
    Configuration = $Configuration
    Runtime = $Runtime
}

if ($SelfContained.IsPresent) {
    $arguments.SelfContained = $true
}

& $scriptPath @arguments
exit $LASTEXITCODE
