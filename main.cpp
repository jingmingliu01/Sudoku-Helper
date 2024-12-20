//=======================================================================
// Project: Sudoku Helper P5 - Cluster       File: main.cpp
// Authors:  Jingming Liu & Kim Kanor
// ======================================================================
#include "Game.hpp"
#include "Square.hpp"
#include "Errors.hpp"

int main()
{
    banner();
    try {
        ifstream puzFile ("puz1.txt");
        Game gm (puzFile);
        gm.run();
    }catch (const StreamError& e) {
        e.print(cerr);
        return 1;
    }catch (const GameLogicError& e) {
        e.print(cerr);
        return 1;
    }catch (...) {
        cerr << "Unknown error occurred." << endl;
        return 1;
    }



    bye();
    return 0;
}
