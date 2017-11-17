cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_RELEASE "-O2")

include_directories(./src)

add_library(
    _sudoku
    ./src/game/sudoku.cpp
)

project(sudoku-tui)

add_executable(${PROJECT_NAME} ./src/tui/main.cpp)
target_link_libraries(${PROJECT_NAME} _sudoku)
