cmake_minimum_required(VERSION 3.25)
project(MultiProject CXX)

set(CMAKE_CXX_STANDARD 23)

# Adiciona os dois projetos como subdiretórios
add_subdirectory(Game)
add_subdirectory(GameSpec)
