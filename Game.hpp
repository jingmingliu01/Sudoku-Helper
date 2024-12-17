#ifndef GAME_H
#define GAME_H

#include <string>
#include "tools.hpp"
#include "Board.hpp"

using namespace std;

class Game {
private:
    const string menu[6] = {
        "M:Mark. Input row, column, and value, then call Board::mark().",
        "U:Undo",
        "R:Redo",
        "S:Save Game",
        "Y:Restore Game",
        "Q:Quit and discard game. End and print a message."
    };
    Board* board;
    char gameType; //legal type code when the game is finished:  ‘t’ for traditional, ‘d’ for diagonal, and ‘s’ for sixy
    short gameSize; //legal value: 6 or 9
    ifstream& f;

public:
    Game(short gameSize, ifstream& f);
    ~Game() = default;

    void run();
};

#endif //GAME_H
