#ifndef BOARD_H
#define BOARD_H

#include "tools.hpp"
#include "Square.h"

class Board {
private:
    ifstream& f;
    int n; // size of the puzzle
    Square* bd; // dynamically allocated array of Squares
    short remain_squares; // track the number of remaining squares with a ‘-’ instead of digit
    void getPuzzle(); // private helper function
public:
    Board(int gameSize, ifstream& f) : f(f), n(gameSize), remain_squares(gameSize * gameSize) {
        bd = new Square[n * n];
    }
    Board(char type, ifstream& puzfile);
    ~Board() {
        delete[] bd;
        cerr << "Deleting Board" << endl;
    }
    Square& sub(int r, int c){return bd[n * (r - 1) + (c - 1)];}; // subscript function
    void print() const; // print function
};

// Inline method for the output operator
inline ostream& operator<<(ostream& out, Board& b) {
    b.print();
    return out;
}

#endif // BOARD_H