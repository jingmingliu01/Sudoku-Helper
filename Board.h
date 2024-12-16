#ifndef BOARD_H
#define BOARD_H

#include "Cluster.h"
#include "tools.hpp"
#include "Square.h"
#include <vector>

class Board {
private:
    ifstream& f;
    int n; // Size of the puzzle
    Square* bd; // Dynamically allocated array of Squares
    short remain_squares; // Track the number of remaining squares with a ‘-’ instead of digit
    vector<unique_ptr<Cluster>> clusters; // Stores pointers to all clusters (27 total for 9x9 Sudoku)

    void getPuzzle(); // Private helper function
    void makeClusters(); // Creates all clusters (rows, columns, boxes)
    void createRow(short row) ; // Create a row cluster
    void createColumn(short col) ; // Create a column cluster
    void createBox(short box) ; // Create a box cluster

public:
    Board(int gameSize, ifstream& f); // Constructor with size
    Board(char type, ifstream& puzfile); // Constructor with type
    ~Board();
    Square& sub(const int r, const int c) const { return bd[n * (r - 1) + (c - 1)]; }; // Subscript function
    void print() const; // Print function
};

// Inline method for the output operator
inline ostream& operator<<(ostream& out, const Board& b) {
    b.print();
    return out;
}

#endif // BOARD_H