cmake_minimum_required(VERSION 3.30)
project(WinDurangoMinimalHomebrew LANGUAGES CXX)

# Homebrew padrao do WinDurango: gera apps/Minimal.wdapp ao lado do host.
# Usa o minimo das APIs de compatibilidade (kernelx + d3d11_x), empacotadas
# junto ao app.exe para o carregamento em tempo de execucao.

add_executable(WinDurangoMinimalApp main.cpp)
target_compile_features(WinDurangoMinimalApp PRIVATE cxx_std_20)
set_target_properties(WinDurangoMinimalApp PROPERTIES
    OUTPUT_NAME app
    RUNTIME_OUTPUT_DIRECTORY "$<TARGET_FILE_DIR:WinDurangoHost>/apps/Minimal.wdapp")

add_dependencies(WinDurangoMinimalApp WinDurango.KernelX WinDurango.D3D11X)
add_custom_command(TARGET WinDurangoMinimalApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_FILE:WinDurango.KernelX>"
            "$<TARGET_FILE_DIR:WinDurangoMinimalApp>/"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_FILE:WinDurango.D3D11X>"
            "$<TARGET_FILE_DIR:WinDurangoMinimalApp>/")
