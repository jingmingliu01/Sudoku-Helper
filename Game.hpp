// ==========================================================================================
// Header file for the Game Controller of Sudoku Helper     Author: Kim & Jingming
// File: game.hpp
// ==========================================================================================
#pragma once
#include "tools.hpp"
//-------------------------------------------------------------------------------------------
class Board;
//-------------------------------------------------------------------------------------------
class Game {
private:
    const string gMenu[4] = {"M: Mark","U: Undo","R: Redo","Q: Quit"};
    Board* brd;
    char gmType;
    short int gmSize;
    ifstream& fin;

public:
    explicit Game(ifstream& fin);
    ~Game() = default;

    void run() const;
};
