cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_RELEASE "-O2")

include_directories(./src)

add_library(
    _sudoku
    ./src/game/sudoku.cpp
)

#build command line game
project(sudoku-tui)

add_executable(${PROJECT_NAME} ./src/tui/main.cpp)
target_link_libraries(${PROJECT_NAME} _sudoku)

#build tests
project(tests)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework)

add_executable(${PROJECT_NAME} ./test/tests.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} _sudoku ${Boost_LIBRARIES})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${PROJECT_NAME})
