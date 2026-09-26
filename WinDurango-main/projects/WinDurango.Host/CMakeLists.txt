cmake_minimum_required(VERSION 3.30)
project(WinDurango.Host LANGUAGES CXX)

if (NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
endif()

add_executable(WinDurangoHost main.cpp Window.cpp ProcessSupervisor.cpp ApiLoader.cpp
    include/WinDurango.Host/PlatformProfile.h
    include/WinDurango.Host/ProcessSupervisor.h
    include/WinDurango.Host/ApiContract.h
    include/WinDurango.Host/ApiLoader.h)
target_compile_features(WinDurangoHost PRIVATE cxx_std_20)
target_include_directories(WinDurangoHost PRIVATE include)

if (WIN32)
    target_compile_definitions(WinDurangoHost PRIVATE UNICODE _UNICODE NOMINMAX WIN32_LEAN_AND_MEAN)
endif()

set_target_properties(WinDurangoHost PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)

file(MAKE_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/apis")
