cmake_minimum_required(VERSION 3.30)
project(WinDurangoPackageFixture LANGUAGES CXX)

add_executable(WinDurangoPackageApp PackageApp.cpp)
target_compile_features(WinDurangoPackageApp PRIVATE cxx_std_20)
set_target_properties(WinDurangoPackageApp PROPERTIES
    OUTPUT_NAME app
    RUNTIME_OUTPUT_DIRECTORY "$<TARGET_FILE_DIR:WinDurangoHost>/apps/Test.wdapp")

add_executable(WinDurangoPackageService PackageService.cpp)
target_compile_features(WinDurangoPackageService PRIVATE cxx_std_20)
set_target_properties(WinDurangoPackageService PROPERTIES
    OUTPUT_NAME service
    RUNTIME_OUTPUT_DIRECTORY "$<TARGET_FILE_DIR:WinDurangoHost>/apps/Test.wdapp/services")

add_dependencies(WinDurangoPackageApp WinDurangoApiFixture)
add_dependencies(WinDurangoPackageApp WinDurangoPackageService)
add_custom_command(TARGET WinDurangoPackageApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
            "$<TARGET_FILE_DIR:WinDurangoPackageApp>/apis"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_FILE:WinDurangoApiFixture>"
            "$<TARGET_FILE_DIR:WinDurangoPackageApp>/apis/")
