// ==========================================================================================
// Implementing the model of the Sudoku Board       Author: Kim & Jingming
// File: board.cpp
// ==========================================================================================
#include "Board.hpp"
#include "tools.hpp"
#include "Errors.hpp"
//-------------------------------------------------------------------------------------------
Board::Board(const char type, ifstream& puzfile) : fin(puzfile) {
    cerr << "----------CONSTRUCTING A BOARD----------\n"
         << "Reading Game Type (t, d or s) from Puzzle File.\n";

    if (type == 't' || type == 'd') n = 9;
    else if (type == 's') n = 6;
    else throw GameLogicError("Invalid Game Type in Puzzle File (Must be t or d or s)");

    fin.ignore(); // Consume the trailing newline after 't'

    bd = new Square[n*n];

    getPuzzle();
    makeClusters();

    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= n; ++c) {
            Square& sq = sub(r, c);
            if (sq.getValue() != '-') {
                sq.shoop(sq.getValue());
            }
        }
    }

    cerr << "----------" << n << " by " << n << " BOARD CONSTRUCTED----------\n";
}
//-------------------------------------------------------------------------------------------
Board::~Board() {
    for (const Cluster* c : cs) delete c;
    delete[] bd;
    cerr << "\n\nFreeing Board and its Memory.\n";
}
//-------------------------------------------------------------------------------------------
Square& Board::
sub(const int r, const int c) const {
    return bd[n * (r - 1) + (c - 1)];
}
//-------------------------------------------------------------------------------------------
void Board::
getPuzzle() {
    int j;      //row value
    int k;      //column value
    char ch;

    // Nested Loop for row j and column k
    for (j = 1; j <= n; ++j) {
        string buf;

        // Read a line and clean it
        if (!getline(fin, buf)) {
            throw StreamError("Error reading row " + to_string(j)
                + ": unexpected end of file.");
        }

        // Remove carriage return if present
        if (!buf.empty() && buf.back() == '\r') {
            buf.pop_back();
        }

        if (buf.size() != n) {
            throw StreamError("Row " + to_string(j) + " has wrong size "
                       + to_string(buf.size()));
        }

        for (k = 1; k <= n; ++k) {
            ch = buf[k - 1];

            if ((ch >= '1' && ch <= char('0' + n)) || ch == '-') {
                sub(j, k) = Square(ch, j, k);

                if (ch != '-') --rs;
            }
            else throw StreamError("Invalid character in puzzle file: " + string(1,ch));
        }

        if (k == n && fin.peek() != '\n') {
            throw StreamError("Puzzle file format error: missing newline.");
        }
    }
    if (fin >> ch && !fin.eof()) throw StreamError("Additional char found at EOF");
}
//-------------------------------------------------------------------------------------------
void Board::
print(ostream &os, const bool clusOnly) const{    //print all or cluster only
    if (!clusOnly) {
        os << "Board Squares:\n";
        for (int r = 1; r <= n; ++r) {
            for (int c = 1; c <= n; ++c) {
                sub(r, c).print(os);
            }
        }
        os << "\n";
    }

    for (const Cluster* c : cs) {
        os << *c;
    }
}
//-------------------------------------------------------------------------------------------
void Board::
makeClusters() {
    for (short j = 1; j <= n; ++j) {
        createRow(j);
        createColumn(j);
    }
    for (short j = 1; j <= n; j += 3) {
        for (short k = 1; k <= n; k += 3) {
            createBox(j, k);
        }
    }
}
//-------------------------------------------------------------------------------------------
void Board::
createRow(short j) {
    Square* sqrs[9];
    for (short k = 0; k < n; ++k) {
        sqrs[k] = &sub(j, k + 1);
    }
    cs.push_back(new Cluster(ClusterT::ROW, sqrs));
}
//-------------------------------------------------------------------------------------------
void Board::
createColumn(short k) {
    Square* sqrs[9];
    for (short m = 0; m < n; ++m) {
        sqrs[m] = &sub(m + 1, k);
    }
    cs.push_back(new Cluster(ClusterT::COLUMN, sqrs));
}
//-------------------------------------------------------------------------------------------
void Board::
createBox(const short j, const short k) {
    Square* sqrs[9];
    short idx = 0;
    for (short r = 0; r < 3; ++r) {
        for (short c = 0; c < 3; ++c) {
            sqrs[idx++] = &sub(j + r, k + c);
        }
    }
    cs.push_back(new Cluster(ClusterT::BOX, sqrs));
}
