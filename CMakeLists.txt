cmake_minimum_required(VERSION 3.29)
project(sudoku)

set(CMAKE_CXX_STANDARD 20)

add_executable(sudoku main.cpp
        Square.cpp
        Square.hpp
        tools.hpp
        tools.cpp
        Game.hpp
        Game.cpp
        Board.cpp
        Board.hpp
        Cluster.cpp
        Cluster.hpp
        State.cpp
        State.hpp)
