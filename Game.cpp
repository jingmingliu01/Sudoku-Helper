#include "Game.h"

#include "Errors.h"

Game::Game(short gameSize, ifstream& f): gameSize(gameSize), f(f) {
    //set gameType by reading first letter from file
    f >> gameType;
    f.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Skip to the end of the line
    string ValidGameType = "tdsTDS"; // string of all the game type, in both upper and lower case.
    if (ValidGameType.find(gameType) == string::npos) {
        throw GameLogicError("Invalid game type");
    }
    cerr << "Game Type: " << gameType << endl;
    //create Board
    board = new Board(gameSize, f);
}

void Game::run() const {
    const string ValidMenuChoice = "MURSYQ";
    menu_c("------Sudoku Helper Menu------", 6, menu, ValidMenuChoice);
}
