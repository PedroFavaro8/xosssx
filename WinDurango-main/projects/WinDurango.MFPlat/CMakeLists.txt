cmake_minimum_required(VERSION 3.30)
project(WinDurango.MFPlat VERSION 1.0.0)

set(VERSION_SUFFIX "-dev.1") # used for non-stable versions, otherwise blank
set(CMAKE_CXX_STANDARD 20)

set(FILES
    Exports.def
    "src/WinDurango.MFPlat.cpp"
    "include/WinDurango.MFPlat/WinDurango.MFPlat.h"
)

add_library(WinDurango.MFPlat SHARED ${FILES})

target_include_directories(WinDurango.MFPlat PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/WinDurango.MFPlat/
)

set_target_properties(WinDurango.MFPlat PROPERTIES
    OUTPUT_NAME "mfplat"
)
