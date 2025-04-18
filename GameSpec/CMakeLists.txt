cmake_minimum_required(VERSION 3.25)

project(GameSpec LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(GameSpec main.cpp)

target_link_libraries(GameSpec PUBLIC Game)

include(GNUInstallDirs)
install(TARGETS GameSpec
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
