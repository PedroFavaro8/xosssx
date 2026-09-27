cmake_minimum_required(VERSION 3.30)
project(WinDurango)

include(CTest)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
set(CMAKE_PDB_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

add_subdirectory(projects/WinDurango.Common)
add_subdirectory(projects/WinDurango.Implementation.WinRT)
#add_subdirectory(projects/WinDurango.Implementation.Native)
add_subdirectory(projects/WinDurango.WinRT)
add_subdirectory(projects/WinDurango.Kinect)
add_subdirectory(projects/WinDurango.etwplus)
add_subdirectory(projects/WinDurango.KernelX)
add_subdirectory(projects/WinDurango.D3D11X)
add_subdirectory(projects/WinDurango.D3D12X)
add_subdirectory(projects/WinDurango.MMDevAPI)
add_subdirectory(projects/WinDurango.MFPlat)
add_subdirectory(projects/WinDurango.Watchdog)
add_subdirectory(projects/WinDurango.PixEvt)
add_subdirectory(projects/WinDurango.ToolHelpX)
add_subdirectory(projects/WinDurango.Host)
add_subdirectory(tests/ApiFixture)
add_subdirectory(tests/PackageFixture)
add_subdirectory(samples/MinimalHomebrew)
add_subdirectory(compat/R2Shims)

add_custom_target(WinDurango ALL DEPENDS
    WinDurango.Common
    WinDurango.Implementation.WinRT
    #WinDurango.Implementation.Native
    WinDurango.WinRT
    WinDurango.Kinect
    WinDurango.etwplus
    WinDurango.KernelX
    WinDurango.D3D11X
    WinDurango.D3D12X
    WinDurango.MMDevAPI
    WinDurango.MFPlat
    WinDurango.Watchdog
    WinDurango.PixEvt
    WinDurango.ToolHelpX
    WinDurangoHost
    WinDurangoApiFixture
    WinDurangoPackageApp
    WinDurangoPackageService
    WinDurangoMinimalApp
)

if (BUILD_TESTING)
    add_test(NAME WinDurangoHostSelfTest COMMAND WinDurangoHost --self-test)
    set_tests_properties(WinDurangoHostSelfTest PROPERTIES TIMEOUT 120)
    add_test(NAME WinDurangoHostApiLoadTest
        COMMAND WinDurangoHost --load-apis)
    set_tests_properties(WinDurangoHostApiLoadTest PROPERTIES
        WORKING_DIRECTORY "$<TARGET_FILE_DIR:WinDurangoHost>"
        TIMEOUT 120)
    add_test(NAME WinDurangoHostExternalApiLoadTest
        COMMAND WinDurangoHost --load-api $<TARGET_FILE:WinDurangoApiFixture>)
    set_tests_properties(WinDurangoHostExternalApiLoadTest PROPERTIES
        WORKING_DIRECTORY "$<TARGET_FILE_DIR:WinDurangoHost>"
        TIMEOUT 120)
    if (WIN32)
        add_test(NAME WinDurangoHostPackageTest
            COMMAND WinDurangoHost --launch-package
                    "$<TARGET_FILE_DIR:WinDurangoHost>/apps/Test.wdapp")
        set_tests_properties(WinDurangoHostPackageTest PROPERTIES
            WORKING_DIRECTORY "$<TARGET_FILE_DIR:WinDurangoHost>"
            PASS_REGULAR_EXPRESSION "package service started"
            TIMEOUT 120)
        add_test(NAME WinDurangoMinimalHomebrewTest
            COMMAND WinDurangoHost --launch-package
                    "$<TARGET_FILE_DIR:WinDurangoHost>/apps/Minimal.wdapp")
        set_tests_properties(WinDurangoMinimalHomebrewTest PROPERTIES
            WORKING_DIRECTORY "$<TARGET_FILE_DIR:WinDurangoHost>"
            PASS_REGULAR_EXPRESSION "rodando coisas alem do normal"
            TIMEOUT 120)
    endif()

    if (WIN32)
        find_program(WINDURANGO_POWERSHELL NAMES pwsh powershell)
        if (WINDURANGO_POWERSHELL)
            add_test(
                NAME WinDurangoStaticProjectChecks
                COMMAND ${WINDURANGO_POWERSHELL} -NoProfile -ExecutionPolicy Bypass
                        -File "${CMAKE_SOURCE_DIR}/tests/validate_project.ps1"
            )
            set_tests_properties(WinDurangoStaticProjectChecks PROPERTIES TIMEOUT 300)
        endif()
    endif()
endif()
