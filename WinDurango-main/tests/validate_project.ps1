$ErrorActionPreference = 'Stop'

$root = Split-Path -Parent $PSScriptRoot

function Require-Text([string]$Path, [string]$Pattern) {
    $content = Get-Content -Raw -LiteralPath (Join-Path $root $Path)
    if ($content -notmatch $Pattern) {
        throw "Missing '$Pattern' in $Path"
    }
}

Require-Text 'CMakeLists.txt' 'add_subdirectory\(projects/WinDurango\.Host\)'
Require-Text 'CMakeLists.txt' 'WinDurangoHostSelfTest'
Require-Text 'CMakeLists.txt' 'WinDurangoStaticProjectChecks'
Require-Text 'CMakeLists.txt' 'cmake_minimum_required\(VERSION 3\.30\)'
Require-Text 'WinDurango.sln' 'Visual Studio Version 17'
Require-Text 'tools/WinDurango.CMake.vcxproj' 'ConfigurationType>Makefile'
Require-Text 'tools/WinDurango.CMake.vcxproj' 'build-vs2022.ps1'
Require-Text 'tools/build-vs2022.ps1' 'Visual Studio 17 2022'
Require-Text 'tools/build-vs2022.ps1' 'VCPKG_ROOT'
Require-Text 'README.md' 'Visual Studio 2022 with the Desktop C\+\+ workload'
Require-Text 'README.md' 'Developer PowerShell for VS 2022'
Require-Text 'CMakePresets.json' '"minor": 30'
Require-Text 'docs/PLATFORM_PROFILE.md' '8 GB de RAM'
Require-Text 'docs/COMPATIBILITY_SCOPE.md' 'Execução de jogos comerciais'
Require-Text 'docs/API_INVENTORY.md' 'Windows.Xbox.Input.idl'
Require-Text 'docs/API_INVENTORY.md' 'não prova que ele seja uma API pública'
Require-Text 'tools/doctor.ps1' 'no SDK is installed'
Require-Text 'tools/doctor.ps1' "Name = 'Git'"
Require-Text 'tools/doctor.ps1' 'GitHub Actions workflow exists'
Require-Text 'projects/WinDurango.Host/main.cpp' '--self-test'
Require-Text 'projects/WinDurango.Host/main.cpp' '--capabilities'
Require-Text 'projects/WinDurango.Host/main.cpp' '--window'
Require-Text 'projects/WinDurango.Host/Window.cpp' 'compatibility shell'
Require-Text 'projects/WinDurango.Host/CMakeLists.txt' 'Window.cpp'
Require-Text 'projects/WinDurango.Host/CMakeLists.txt' 'ProcessSupervisor.cpp'
Require-Text 'projects/WinDurango.Host/main.cpp' '--launch-dashboard'
Require-Text 'projects/WinDurango.Host/main.cpp' '--launch-package'
Require-Text 'projects/WinDurango.Host/ProcessSupervisor.cpp' 'LaunchPackage'
Require-Text 'projects/WinDurango.Host/ProcessSupervisor.cpp' 'background_root'
Require-Text 'projects/WinDurango.Host/ProcessSupervisor.cpp' 'servicesRoot'
Require-Text 'projects/WinDurango.Host/ProcessSupervisor.cpp' '\.wdapp'
Require-Text 'apis/README.md' 'app.exe'
Require-Text 'apis/README.md' 'WINDURANGO_API_ROOT'
Require-Text 'projects/WinDurango.Host/ProcessSupervisor.cpp' 'LoadApis\(resolvedPackage / "apis"\)'
Require-Text 'projects/WinDurango.Host/main.cpp' '--inspect-media'
Require-Text 'projects/WinDurango.Host/main.cpp' '--load-apis'
Require-Text 'projects/WinDurango.Host/main.cpp' '--load-api'
Require-Text 'projects/WinDurango.Host/CMakeLists.txt' 'ApiLoader.cpp'
Require-Text 'projects/WinDurango.Host/ApiLoader.cpp' 'WinDurangoApiGetInfo'
Require-Text 'projects/WinDurango.Host/ApiLoader.cpp' 'WinDurangoApiInitialize'
Require-Text 'projects/WinDurango.Host/ApiLoader.cpp' 'LoadApiFile'
Require-Text 'apis/README.md' 'ABI atual é a versão `1`'
Require-Text 'README.md' '--load-api C:\\caminho\\MinhaApi\.dll'
Require-Text 'README.md' 'not supported or promised'
Require-Text 'README.md' 'Historical upstream status'
Require-Text 'CMakeLists.txt' 'WinDurangoHostApiLoadTest'
Require-Text 'CMakeLists.txt' 'WinDurangoHostExternalApiLoadTest'
Require-Text 'tests/ApiFixture/CMakeLists.txt' 'ApiFixture.cpp'
Require-Text 'tests/ApiFixture/CMakeLists.txt' '\$<TARGET_FILE_DIR:WinDurangoHost>/apis'
Require-Text 'tests/ApiFixture/ApiFixture.cpp' 'WinDurangoApiGetInfo'
Require-Text 'tests/PackageFixture/CMakeLists.txt' 'WinDurangoPackageApp'
Require-Text 'tests/PackageFixture/CMakeLists.txt' 'WinDurangoPackageService'
Require-Text 'tests/PackageFixture/CMakeLists.txt' 'apps.Test.wdapp'
Require-Text 'tests/PackageFixture/CMakeLists.txt' 'WinDurangoApiFixture'
Require-Text 'tests/PackageFixture/CMakeLists.txt' 'copy_if_different'
Require-Text 'tests/PackageFixture/PackageApp.cpp' 'package fixture app started'
Require-Text 'tests/PackageFixture/PackageApp.cpp' 'package api root propagated'
Require-Text 'tests/PackageFixture/PackageApp.cpp' 'package service started'
Require-Text 'tests/PackageFixture/PackageService.cpp' 'sleep_for'
Require-Text 'tests/PackageFixture/PackageService.cpp' 'service.started'
Require-Text 'tests/PackageFixture/PackageApp.cpp' '#ifdef _WIN32'
Require-Text 'CMakeLists.txt' 'WinDurangoHostPackageTest'
Require-Text 'projects/WinDurango.Host/ProcessSupervisor.cpp' 'WINDURANGO_API_ROOT'
Require-Text 'projects/WinDurango.Host/ProcessSupervisor.cpp' 'WINDURANGO_PACKAGE_RUN_TOKEN'
Require-Text 'projects/WinDurango.Host/include/WinDurango.Host/ProcessSupervisor.h' 'api_root'
Require-Text 'projects/WinDurango.Host/include/WinDurango.Host/ProcessSupervisor.h' 'run_token'
Require-Text 'projects/WinDurango.Host/main.cpp' 'execution_policy=unrestricted'
Require-Text 'projects/WinDurango.Host/main.cpp' 'action=accepted'
Require-Text 'projects/WinDurango.Host/ProcessSupervisor.cpp' 'services'
Require-Text 'projects/WinDurango.Host/ProcessSupervisor.cpp' 'CreateProcessW'
Require-Text 'projects/WinDurango.Host/ProcessSupervisor.cpp' 'TerminateProcess'
Require-Text 'projects/WinDurango.Host/ProcessSupervisor.cpp' 'ChildProcess\(const ChildProcess&\) = delete'
Require-Text 'projects/WinDurango.Host/ProcessSupervisor.cpp' 'is_regular_file'
Require-Text 'projects/WinDurango.Host/main.cpp' 'LoadLibraryExW'
Require-Text 'projects/WinDurango.Host/main.cpp' 'weakly_canonical'
Require-Text 'projects/WinDurango.Host/main.cpp' 'FreeLibrary'
Require-Text 'projects/WinDurango.Host/main.cpp' 'winrt_x\.dll'
Require-Text 'projects/WinDurango.Host/main.cpp' 'case-insensitive'
Require-Text 'projects/WinDurango.Host/main.cpp' 'MinimumPhysicalMemoryBytes'
Require-Text 'projects/WinDurango.Host/include/WinDurango.Host/PlatformProfile.h' '8ull \* 1024ull \* 1024ull \* 1024ull'
Require-Text 'projects/WinDurango.Common/src/Config.cpp' 'if \(!pDirectory\)'
Require-Text 'projects/WinDurango.Common/src/WinDurango.cpp' 'Root directory is null'
Require-Text 'projects/WinDurango.Common/src/Logging.cpp' 'isInitialized\)'
Require-Text 'projects/WinDurango.Common/include/WinDurango.Common/Logging.h' 'recursive_mutex'
Require-Text 'projects/WinDurango.Common/src/Logging.cpp' 'lock_guard'
Require-Text 'projects/WinDurango.Common/include/WinDurango.Common/Interfaces/Storage/Directory.h' 'virtual ~Directory\(\) = default'
Require-Text 'projects/WinDurango.Common/include/WinDurango.Common/Interfaces/Storage/File.h' 'virtual ~File\(\) = default'
Require-Text 'projects/WinDurango.Implementation.WinRT/src/interfaces/Storage/File.cpp' 'return true;'
Require-Text 'projects/WinDurango.Implementation.WinRT/src/interfaces/Storage/Directory.cpp' 'dir = nullptr;'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'return id;'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'GetUserById\(static_cast<uint32_t>\(Id\(\) % 4\)\)'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'ToNavigationReading'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'xinput1_3.dll'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'xinput9_1_0.dll'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'FreeLibrary\(candidate\)'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'std::clamp'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'make<NavigationReading>'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'return ToNavigationReading\(GetRawCurrentReading\(\)\)'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'reading\.Timestamp = GetTickCount64\(\)'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'if \(p_wd\)'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'p_wd && p_wd->config'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'removedEvents.push_back'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'XInput backend unavailable'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'kb_ltr\)\s*\& 0x8000\)\s*\{\s*reading\.LeftTrigger'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp' 'kb_rtr\)\s*\& 0x8000\)\s*\{\s*reading\.RightTrigger'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Controller.cpp' 'return e_ControllerAdded\.add\(handler\)'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Controller.cpp' 'return id;'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/System/Windows.Xbox.System.User.cpp' 'Controller::Controllers()'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.NavigationController.cpp' 'NavigationController"'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.NavigationController.cpp' 'Gamepad gamepad\(id, true\)'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.NavigationController.cpp' 'return gamepad.GetNavigationReading\(\)'
Require-Text 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.NavigationController.cpp' 'return gamepad.GetRawNavigationReading\(\)'

$config = Get-Content -Raw -LiteralPath (Join-Path $root 'projects/WinDurango.Common/src/Config.cpp')
if (([regex]::Matches($config, 'pFile->write\(jsonTemplate\)')).Count -ne 1) {
    throw 'Configuration template must be written only when the file is created.'
}

$gamepad = Get-Content -Raw -LiteralPath (Join-Path $root 'projects/WinDurango.WinRT/src/Windows/Xbox/Input/Windows.Xbox.Input.Gamepad.cpp')
if ($gamepad -notmatch 'kb_ltr\)\s*\& 0x8000\)\s*\{\s*reading\.LeftTrigger' -or
    $gamepad -notmatch 'kb_rtr\)\s*\& 0x8000\)\s*\{\s*reading\.RightTrigger') {
    throw 'Keyboard trigger mappings are inconsistent.'
}

$sourceFiles = Get-ChildItem -LiteralPath (Join-Path $root 'projects') -File -Recurse -Include *.c,*.cc,*.cpp,*.h,*.hpp
$forbidden = $sourceFiles | Select-String -Pattern '\$SystemUpdate|systemupdate|\.xvd'
if ($forbidden) {
    throw 'Compatibility source must not depend on system image artifacts.'
}

$cmakeFiles = Get-ChildItem -LiteralPath $root -File -Recurse -Filter CMakeLists.txt
$incompatible = $cmakeFiles | Select-String -Pattern 'cmake_minimum_required\(VERSION 4\.'
if ($incompatible) {
    throw 'A subproject requires a newer CMake version than the root project.'
}

$hostSource = Get-Content -Raw -LiteralPath (Join-Path $root 'projects/WinDurango.Host/main.cpp')
$manifest = [regex]::Match($hostSource, '(?s)kCompatibilityModules\s*=\s*\{(?<body>.*?)\};').Groups['body'].Value
$manifestNames = [regex]::Matches($manifest, '"([^"]+\.dll)"') | ForEach-Object { $_.Groups[1].Value.ToLowerInvariant() }
foreach ($cmake in $cmakeFiles) {
    $content = Get-Content -Raw -LiteralPath $cmake.FullName
    foreach ($output in [regex]::Matches($content, 'OUTPUT_NAME\s+"([^"]+)"')) {
        $dllName = ($output.Groups[1].Value + '.dll').ToLowerInvariant()
        if ($manifestNames -notcontains $dllName) {
            throw "CMake output is absent from host manifest: $dllName"
        }
    }
}

Get-Content -Raw -LiteralPath (Join-Path $root 'CMakePresets.json') | ConvertFrom-Json | Out-Null
Get-Content -Raw -LiteralPath (Join-Path $root 'vcpkg.json') | ConvertFrom-Json | Out-Null

$releaseDir = Join-Path (Split-Path $root -Parent) 'WinDurango-Release'
if (Test-Path -LiteralPath $releaseDir) {
    foreach ($match in [regex]::Matches($manifest, '"([^"]+\.dll)"')) {
        $artifact = Join-Path $releaseDir $match.Groups[1].Value
        if (-not (Test-Path -LiteralPath $artifact)) {
            throw "Release artifact missing from host manifest: $artifact"
        }
    }
}

Write-Output 'PASS: WinDurango static project checks'
exit 0
