cmake_minimum_required(VERSION 3.25)

project(GameCore LANGUAGES CXX)

# Generate compile_commands.json
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# --------------- raylib
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
# --------------- raylib

# --------------- magic_enum
set(MAGIC_ENUM_VERSION v0.9.7)

include(FetchContent)

FetchContent_Declare(
  magic_enum
  GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
  GIT_TAG        ${MAGIC_ENUM_VERSION}
  DOWNLOAD_EXTRACT_TIMESTAMP OFF
)

FetchContent_MakeAvailable(magic_enum)
# --------------- magic_enum

file(GLOB_RECURSE CPP_FILES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/core/tools/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/infra/adapters/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/infra/managers/*.cpp
)

file(GLOB_RECURSE HPP_FILES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/core/enums/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core/tools/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/infra/adapters/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/infra/managers/*.hpp
)

add_library(GameCore SHARED ${CPP_FILES} ${HPP_FILES})
target_link_libraries(GameCore PUBLIC raylib magic_enum)

add_executable(GameApp main.cpp)
add_dependencies(GameApp copy_resources)
target_link_libraries(GameApp PRIVATE GameCore)

target_include_directories(GameCore PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/core/enums
  ${CMAKE_CURRENT_SOURCE_DIR}/core/tools
  ${CMAKE_CURRENT_SOURCE_DIR}/infra/adapters
  ${CMAKE_CURRENT_SOURCE_DIR}/infra/adapters/shapes
  ${CMAKE_CURRENT_SOURCE_DIR}/infra/adapters/constants
  ${CMAKE_CURRENT_SOURCE_DIR}/infra/adapters/contracts
  ${CMAKE_CURRENT_SOURCE_DIR}/infra/adapters/drawables
  ${CMAKE_CURRENT_SOURCE_DIR}/infra/adapters/functions
  ${CMAKE_CURRENT_SOURCE_DIR}/infra/adapters/resources
  ${CMAKE_CURRENT_SOURCE_DIR}/infra/managers
  ${CMAKE_CURRENT_SOURCE_DIR}/infra/managers/dataStructs
  ${CMAKE_CURRENT_SOURCE_DIR}/infra/managers/dataSchemas
  ${CMAKE_CURRENT_SOURCE_DIR}/infra/managers/dataTransports
)

target_compile_definitions(GameCore PUBLIC
    MAGIC_ENUM_RANGE_MIN=-1000
    MAGIC_ENUM_RANGE_MAX=1000
)

include(GNUInstallDirs)
install(TARGETS GameCore
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
