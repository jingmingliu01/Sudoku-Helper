#include "Game.h"

Game::Game(ifstream& f): f(f) {
    f >> gameType;
    string ValidGameType = "tdsTDS"; // string of all the game type, in both upper and lower case.
    if (ValidGameType.find(gameType) == string::npos) {
        fatal("Invalid game type");
    }
    else {
        cerr << "Game Type: " << gameType << endl;
    }
}

void Game::run() {
    string ValidMenuChoice = "MURSYQ";
    menu_c("------Sudoku Helper Menu------", 6, menu, ValidMenuChoice);
}
