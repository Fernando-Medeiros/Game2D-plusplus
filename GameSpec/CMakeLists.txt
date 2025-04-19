cmake_minimum_required(VERSION 3.25)

project(GameSpec LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Verifica se o GoogleTest já está disponível no sistema
find_package(GTest QUIET)
if (NOT GTest_FOUND)
  include(FetchContent)

  set(GOOGLETEST_VERSION 1.16.0)
  FetchContent_Declare(
    googletest
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/google/googletest/archive/refs/tags/v${GOOGLETEST_VERSION}.zip
  )

  FetchContent_GetProperties(googletest)
  if (NOT googletest_POPULATED)
    message(STATUS "GoogleTest não encontrado. Baixando automaticamente...")
    # Evita que o CMake builde os testes internos do GoogleTest
    set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)
  endif()
endif()


file(GLOB_RECURSE SPEC_FILES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/adapters/*.cpp
)

add_executable(GameSpec ${SPEC_FILES})

target_link_libraries(GameSpec PRIVATE
    GameCore
    gtest
    gtest_main
)

target_include_directories(GameSpec PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/adapters
)

enable_testing()
include(GoogleTest)

include(GNUInstallDirs)
install(TARGETS GameSpec
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# [DLL] copia os arquivos compilados de gamecore para o output do gamespec.
# O gamecore.dll precisa estar junto do .exe quando compartilha a biblioteca com SHARED.
add_custom_command(TARGET GameSpec POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:GameCore>
    $<TARGET_FILE_DIR:GameSpec>
)