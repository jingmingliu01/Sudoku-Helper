#include <iostream>
#include <stdexcept>
#include "Game.h"
#include "Square.h"
#include "Board.h"
#include "tools.hpp"

using namespace std;



int main(int argc, char* argv[]) {
    banner();

    if (argc != 2) {
        fatal("Wrong number of arguments");
    }
    ifstream f(argv[1]);
    if (!f.is_open()) { fatal("Can't open file!"); }
    Game g1(6,f);
    g1.run();

    bye();
    return 0;
}
