#include "Board.h"

Board::Board(char type, ifstream& puzfile) : f(puzfile) {
    cerr << "Constructing Board" << endl;

    switch (type) {
        case 't':
        case 'd':
            n = 9;
            break;
        case 's':
            n = 6;
            break;
        default:
            fatal("Invalid type code");
    }

    bd = new Square[n * n];
    remain_squares = n * n;

    getPuzzle();

    cerr << "Board construction done" << endl;
}

void Board::getPuzzle() {
    for (int j = 1; j <= n; ++j) {
        string line;
        getline(f, line);
        if (line.length() != n) {
            fatal("Invalid line length");
        }
        for (int k = 1; k <= n; ++k) {
            char ch = line[k - 1];
            if (isdigit(ch) || ch == '-') {
                sub(j, k) = Square(ch, j, k); // 调用 Board::sub 函数
                if (ch == '-') {
                    remain_squares++;
                }
            } else {
                fatal("Invalid character in puzzle");
            }
        }
        if (f.peek() != '\n' && f.peek() != EOF) {
            fatal("Expected newline after line");
        }
    }
    if (f.get() != EOF) {
        fatal("Extra data after puzzle");
    }
}

void Board::print() const {
    for (int i = 0; i < n * n; ++i) {
        bd[i].print(cout);
        cout << endl;
        if ((i + 1) % n == 0) {
            cout << endl;
        }
    }
}