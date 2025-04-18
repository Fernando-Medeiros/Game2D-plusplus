cmake_minimum_required(VERSION 3.25)

project(GameSpec LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SPEC_FILES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/adapters/*.hpp
)

add_executable(GameSpec main.cpp ${SPEC_FILES})

target_link_libraries(GameSpec PUBLIC GameCore)

target_include_directories(GameSpec PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/adapters
)

include(GNUInstallDirs)
install(TARGETS GameSpec
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
