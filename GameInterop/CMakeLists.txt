cmake_minimum_required(VERSION 3.25)

project(GameInterop LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(SOURCES
    viewport_adapter_api.cpp
)

set(HEADERS
    viewport_adapter_api.hpp
)

add_library(GameInterop SHARED ${SOURCES} ${HEADERS})

target_link_libraries(GameInterop PRIVATE GameCore)

include(GNUInstallDirs)
install(TARGETS GameInterop
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# [DLL] copia os arquivos compilados de gamecore para o output do GameInterop.
# O gamecore.dll precisa estar junto do .exe quando compartilha a biblioteca com SHARED.
add_custom_command(TARGET GameInterop POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:GameCore>
    $<TARGET_FILE_DIR:GameInterop>
)