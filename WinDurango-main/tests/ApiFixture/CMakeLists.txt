cmake_minimum_required(VERSION 3.30)
project(WinDurangoApiFixture LANGUAGES CXX)

add_library(WinDurangoApiFixture SHARED ApiFixture.cpp)
target_compile_features(WinDurangoApiFixture PRIVATE cxx_std_20)
target_compile_definitions(WinDurangoApiFixture PRIVATE WINDURANGO_API_BUILD)
target_include_directories(WinDurangoApiFixture PRIVATE
    "${CMAKE_SOURCE_DIR}/projects/WinDurango.Host/include")

set_target_properties(WinDurangoApiFixture PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "$<TARGET_FILE_DIR:WinDurangoHost>/apis"
    LIBRARY_OUTPUT_DIRECTORY "$<TARGET_FILE_DIR:WinDurangoHost>/apis"
    ARCHIVE_OUTPUT_DIRECTORY "$<TARGET_FILE_DIR:WinDurangoHost>/apis")
