cmake_minimum_required(VERSION 3.30)

# R2Shims: pack opcional de compatibilidade para Windows 7 / Server 2008 R2.
#
# Motivo: as DLLs de compatibilidade importam api-sets que nao existem no
# kernel 6.1 (winrt-*, memory-l1-1-6/7, file-l1-2-2, heap-l2-1-0,
# localization-l1-2-0, com-l1-1-1, threadpool-l1-2-0) e o d3d12_x importa
# d3d12.dll. Sem esses arquivos o loader falha e nada carrega.
#
# Estes shims implementam o emulavel de verdade (HSTRING, RoInitialize-,
# VirtualAlloc2/MapViewOfFile3/CreateFileMapping2 via APIs antigas,
# TrySubmitThreadpoolCallback via QueueUserWorkItem, forwards para APIs
# que existem no R2) e retornam E_NOTIMPL com graca onde o SO nao tem o
# recurso (ativacao WinRT, D3D12). Nenhum dialogo, nenhum hang.
#
# Nao vao para o bindir: saem em <build>/r2shim/ e so sao copiados para
# junto do host manualmente numa maquina R2. No Windows 10+ os api-sets
# sao resolvidos pelo schema do SO e estes arquivos sao ignorados, mas o
# stub d3d12.dll JAMAIS deve ir para o bindir (sombrearia o D3D12 real).

if(NOT WIN32)
    return()
endif()

set(WD_R2SHIM_DIR "${CMAKE_BINARY_DIR}/r2shim")

function(wd_r2shim name)
    add_library(${name} SHARED ${ARGN})
    set_target_properties(${name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${WD_R2SHIM_DIR}"
        ARCHIVE_OUTPUT_DIRECTORY "${WD_R2SHIM_DIR}"
        LIBRARY_OUTPUT_DIRECTORY "${WD_R2SHIM_DIR}")
    if(MSVC)
        # CRT estatico: R2 offline, sem VS Redist.
        set_target_properties(${name} PROPERTIES
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    endif()
endfunction()

wd_r2shim(api-ms-win-core-winrt-l1-1-0 winrt_activation.c winrt_activation.def)
wd_r2shim(api-ms-win-core-winrt-string-l1-1-0 winrt_string.c winrt_string.def)
wd_r2shim(api-ms-win-core-winrt-error-l1-1-0 winrt_error.c winrt_error.def)
wd_r2shim(api-ms-win-core-winrt-error-l1-1-1 winrt_error.c winrt_error11.def)
wd_r2shim(api-ms-win-core-memory-l1-1-5 winrt_memory.c winrt_memory5.def)
wd_r2shim(api-ms-win-core-memory-l1-1-6 winrt_memory.c winrt_memory6.def)
wd_r2shim(api-ms-win-core-memory-l1-1-7 winrt_memory.c winrt_memory7.def)
wd_r2shim(api-ms-win-core-file-l1-2-2 winrt_misc.c winrt_file.def)
wd_r2shim(api-ms-win-core-heap-l2-1-0 winrt_empty.c winrt_heap.def)
wd_r2shim(api-ms-win-core-localization-l1-2-0 winrt_empty.c winrt_locale.def)
wd_r2shim(api-ms-win-core-com-l1-1-1 winrt_misc.c winrt_com.def)
wd_r2shim(api-ms-win-core-threadpool-l1-2-0 winrt_threadpool.c winrt_threadpool.def)
wd_r2shim(d3d12 winrt_d3d12.c winrt_d3d12.def)
