// ==========================================================================================
// Header file for model of Sudoku Board    Author: Kim & Jingming
// File: board.hpp
// ==========================================================================================
#pragma once
#include "Square.hpp"
#include "Cluster.hpp"
// ==========================================================================================
class Board {
private:
    int n;
    short int rs = n*n;
    ifstream& fin;
    Square* bd;
    vector<Cluster*> cs;   //new addition

    void getPuzzle();
    void makeClusters();
    void createRow(short j);
    void createColumn(short k);
    void createBox(short j, short k);

public:
    Board(char type, ifstream& puzfile);
    ~Board();

    Square& sub( int r, int c ) const;
    // updated to print board n clusters or only clusters
    void print(ostream& os, bool clusOnly = false) const;
};
//----------------------------------------------------------------------------------
inline ostream& operator<<(ostream& os, Board& bd) {
    bd.print(os);
    return os;
}
