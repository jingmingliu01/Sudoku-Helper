#include "Game.h"

Game::Game(short gameSize, ifstream& f): gameSize(gameSize), f(f) {
    //set gameType by reading first letter from file
    f >> gameType;
    string ValidGameType = "tdsTDS"; // string of all the game type, in both upper and lower case.
    if (ValidGameType.find(gameType) == string::npos) {
        fatal("Invalid game type");
    }
    else {
        cerr << "Game Type: " << gameType << endl;
    }
    //create Board
    board = new Board(gameSize, f);
}

void Game::run() {
    string ValidMenuChoice = "MURSYQ";
    menu_c("------Sudoku Helper Menu------", 6, menu, ValidMenuChoice);
}
