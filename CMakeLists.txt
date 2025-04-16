cmake_minimum_required(VERSION 3.25)

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

file(GLOB_RECURSE GAME_FILES CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/core/enums/*.h
    ${PROJECT_SOURCE_DIR}/core/tools/*.h
    ${PROJECT_SOURCE_DIR}/core/tools/*.cpp

    ${PROJECT_SOURCE_DIR}/infra/adapters/contracts/*.h
    ${PROJECT_SOURCE_DIR}/infra/adapters/.h
    ${PROJECT_SOURCE_DIR}/infra/adapters/*.cpp
    ${PROJECT_SOURCE_DIR}/infra/managers/*.h
    ${PROJECT_SOURCE_DIR}/infra/managers/*.cpp
)

add_executable(Game2D main.cpp ${GAME_FILES})

target_link_libraries(Game2D raylib)

target_include_directories(Game2D PRIVATE
  ${PROJECT_SOURCE_DIR}/core/enums
  ${PROJECT_SOURCE_DIR}/core/tools
  ${PROJECT_SOURCE_DIR}/infra/adapters
  ${PROJECT_SOURCE_DIR}/infra/adapters/contracts
  ${PROJECT_SOURCE_DIR}/infra/managers
)

include(GNUInstallDirs)
install(TARGETS Game2D
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
