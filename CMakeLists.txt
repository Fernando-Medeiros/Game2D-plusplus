cmake_minimum_required(VERSION 3.16)

project(Game2D LANGUAGES CXX)

# Generate compile_commands.json
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Instala as dependencias do raylib
set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
  endif()
endif()


# Adiciona os submódulos (módulos do projeto)
add_subdirectory(core)

# Adiciona os executaveis (arquivos .h e .cpp)
add_executable(Game2D main.cpp)

# Bibliotecas adicionais
target_link_libraries(Game2D raylib core)

# Globalização dos imports
target_include_directories(Game2D
  PRIVATE
    ${PROJECT_SOURCE_DIR}/design/scenes
    ${PROJECT_SOURCE_DIR}/infra/adapters
    ${PROJECT_SOURCE_DIR}/infra/managers
)

# Default
include(GNUInstallDirs)
install(TARGETS Game2D
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
