[CmdletBinding()]
param(
    [ValidateSet('Debug', 'Release')]
    [string]$Configuration = 'Release',
    [switch]$Rebuild,
    [switch]$Clean
)

$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$build = Join-Path $root '.cmake\VS2022'

if (-not (Get-Command cmake -ErrorAction SilentlyContinue)) {
    throw 'CMake não foi encontrado no PATH. Instale CMake 3.30+ e reabra o Visual Studio.'
}

if ($Clean) {
    if (Test-Path -LiteralPath $build) {
        & cmake --build $build --config $Configuration --target clean
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
    }
    exit 0
}

$configureArgs = @('-S', $root, '-B', $build, '-G', 'Visual Studio 17 2022', '-A', 'x64')
if ($env:VCPKG_ROOT) {
    $toolchain = Join-Path $env:VCPKG_ROOT 'scripts\buildsystems\vcpkg.cmake'
    if (Test-Path -LiteralPath $toolchain) {
        $configureArgs += "-DCMAKE_TOOLCHAIN_FILE=$toolchain"
    }
}

& cmake @configureArgs
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

if ($Rebuild) {
    & cmake --build $build --config $Configuration --target clean
    if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
}

& cmake --build $build --config $Configuration --target WinDurango -- /m
exit $LASTEXITCODE
