cmake_minimum_required(VERSION 3.25)
project(Game2D CXX)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(Game)
add_subdirectory(GameSpec)
add_subdirectory(GameInterop)

add_custom_target(copy_resources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources
    ${CMAKE_BINARY_DIR}/Game/resources
)
