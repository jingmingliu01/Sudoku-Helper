cmake_minimum_required(VERSION 3.29)
project(sudoku)

set(CMAKE_CXX_STANDARD 20)

add_executable(sudoku main.cpp
        State.cpp
        State.h
        tools.hpp
        tools.cpp
        Game.h
        Game.cpp)
