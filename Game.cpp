// ==========================================================================================
// Implementing the Game Controller of Sudoku Helper
// File: game.cpp
// ==========================================================================================
#include "tools.hpp"
#include "Game.hpp"
#include "Board.hpp"
#include "Errors.hpp"
//-------------------------------------------------------------------------------------------
Game::Game(ifstream& fin) : fin(fin) {
    char tc;    //type code
    const string codes = "tTdDsS";     //string of legal menu codes

    if (!fin.is_open()) {
        throw StreamError("Puzzle file could not be opened.");
    }
    fin >> tc;
    if (codes.find(tc) == string::npos) {
        throw GameLogicError("Invalid game type");
    }
    cout << "Game type read: " << tc << endl;
    brd = new Board(tc, fin);
}
//-------------------------------------------------------------------------------------------
// Game::~Game() {
//     cerr << "\nGame Closed.\n\n";
// }
//-------------------------------------------------------------------------------------------
void Game::
run() const {
    cout << "\nINITIAL BOARD STATE\n";
    brd->print(cout);

    const string mCodes = "mMuUrRqQ";  // upper & lower case menu codes
    char ch = menu_c("Sudoku Main Menu", 4, gMenu, mCodes);

    switch (ch) {
        case 'm' : case 'M':
            int r, c;
            char val;
            cout << "\nTo MARK a SQUARE, enter the ROW, COLUMN, and VALUE(one space between each,"
                 << " ex. 1 2 3):\n";
            cin >> r >> c >> val;

            brd->sub(r, c).mark(val);
            brd->sub(r, c).shoop(val);

            cout << "\nUpdated Clusters after marking [" << r << ","
                 << c << "] with " << val << ":\n";
            brd->print(cout, true);
            break;

        case 'q' : case 'Q':
            cout << "\n\nQuitting Game.\n\n";
            break;
    }
}
