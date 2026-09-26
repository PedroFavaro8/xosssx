$ErrorActionPreference = 'Continue'

$root = Split-Path -Parent $PSScriptRoot
$checks = @(
    @{ Name = 'Git'; Command = 'git' },
    @{ Name = 'CMake'; Command = 'cmake' },
    @{ Name = 'MSVC'; Command = 'cl' },
    @{ Name = 'Ninja'; Command = 'ninja' },
    @{ Name = 'MIDL'; Command = 'midl' },
    @{ Name = 'cppwinrt'; Command = 'cppwinrt' },
    @{ Name = '.NET SDK'; Command = 'dotnet' }
)

Write-Output "WinDurango doctor — $root"
$missing = 0
foreach ($check in $checks) {
    $command = Get-Command $check.Command -ErrorAction SilentlyContinue
    if ($command) {
        if ($check.Command -eq 'dotnet') {
            $sdks = & $command.Source --list-sdks 2>$null
            if (-not $sdks) {
                Write-Output ("MISS {0}: dotnet exists but no SDK is installed" -f $check.Name)
                $missing++
                continue
            }
        }
        Write-Output ("PASS {0}: {1}" -f $check.Name, $command.Source)
    }
    else {
        Write-Output ("MISS {0}: {1}" -f $check.Name, $check.Command)
        $missing++
    }
}

if (Test-Path -LiteralPath (Join-Path $root 'projects/WinDurango.WinRT/Generated Files')) {
    Write-Output 'PASS generated WinRT directory exists'
}
else {
    Write-Output 'MISS generated WinRT directory; configure CMake before building'
    $missing++
}

$workflow = Join-Path $root '.github/workflows/build-WD.yml'
if (Test-Path -LiteralPath $workflow) {
    Write-Output 'PASS GitHub Actions workflow exists'
}
else {
    Write-Output 'MISS GitHub Actions workflow'
    $missing++
}

if (Test-Path -LiteralPath (Join-Path $root 'tests/validate_project.ps1')) {
    & (Join-Path $root 'tests/validate_project.ps1')
    if ($LASTEXITCODE -ne 0) { $missing++ }
}

if ($missing -gt 0) {
    Write-Output "Doctor finished with $missing missing prerequisite(s)."
    exit 1
}

Write-Output 'Doctor finished: environment ready for a build.'
