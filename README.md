# Sudoku Helper

Sudoku Helper is a C++ program that helps solve Sudoku puzzles interactively. It was built as a learning exercise in object‑oriented design. The project models the puzzle using `Square`, `Board`, and `Cluster` classes and provides a small command line interface for marking squares, undoing or redoing moves, and printing the state of the board.

## Features

- Reads traditional or diagonal Sudoku puzzle files (see `puz1.txt` or `puzd-1.txt`).
- Represents each square with possible values and tracks fixed numbers.
- Organizes rows, columns and 3×3 boxes via `Cluster` objects for fast rule checking.
- Simple in‑terminal menu for marking squares and printing the updated board and clusters.
- Written in modern C++20 with minimal external dependencies.

## Building

The project can be built using a recent C++ compiler or via CMake (requires CMake 3.29 or newer).

```bash
# build with g++ (requires C++20 support)
g++ -std=c++20 main.cpp Square.cpp tools.cpp Game.cpp Board.cpp Cluster.cpp State.cpp Errors.cpp -o sudoku

# or use CMake
cmake -S . -B build
cmake --build build
```

## Usage

Run the resulting `sudoku` executable. The program loads the puzzle from `puz1.txt` by default. After the initial board is printed, follow the menu prompts to mark a square or quit the program.

```
$ ./sudoku
Sudoku Main Menu
         M: Mark
         U: Undo
         R: Redo
         Q: Quit
Enter code of desired item:
```

Marking a square requires entering the row, column, and value separated by spaces (e.g., `1 2 3`). The board and affected clusters are displayed after each move.

## Puzzle Format

The first line of a puzzle file contains the game type (`t` for traditional or `d` for diagonal). The next nine lines list the puzzle grid using digits for fixed values and `-` for empty squares. Example:

```
t
4-6--7--3
-9-5-6-7-
------58-
---9--34-
3-------8
-78--4---
-17------
-8--2-9-6
9--7--8-4
```

## Contributing

This project is a small educational exercise and is not under active development. Feel free to experiment or extend it for your own learning.

