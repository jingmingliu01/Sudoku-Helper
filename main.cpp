//=======================================================================
// Project: Sudoku Helper P5 - Cluster       File: main.cpp
// Authors:  Jingming Liu & Kim Kanor
// ======================================================================
#include "game.hpp"
#include "square.hpp"

int main()
{
    banner();

    ifstream puzFile ("puz1.txt");

    Game gm (puzFile);
    gm.run();

    bye();
    return 0;
}
