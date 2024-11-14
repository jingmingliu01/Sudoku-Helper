#include <iostream>
#include <stdexcept>
#include "Game.h"
#include "State.h"
#include "tools.hpp"

using namespace std;

// Unit test function for State
void testState() {
    //Test Case 1
    try {
        cout << "This is State1, value = 0." << endl;
        State s1 = State('0');
    }
    catch (invalid_argument& e) {
        cout << "Error:" << e.what() << endl << endl;
    }

    // Test Case 2
    cout << "This is State2, using default null constructor. It will be undefined behavior." << endl;
    State s2 = State();
    cout << s2 << endl << endl;

    // Test Case 3
    cout << "This is State3, value = 1." << endl;
    State s3 = State('1');
    cout << s3 << endl << endl;

    // Test Case 4
    cout << "Attempting to mark value on fixed State 3 (should fail):" << endl;
    s3.mark('4');
    cout << s3 << endl << endl;

    // Test Case 5
    cout << "This is State4, value = ‘-’." << endl;
    State s4 = State('-');
    cout << s4 << endl;
    // Test Case 5
    s4.mark('2');
    cout << "Marked value = 2" << endl;
    cout << s4 << endl << endl;
}

// Unit test function for Square
void testSquare() {
    // Test Case 1
    cout << "This is Square1, value=1, row=5, col=6." << endl;
    Square sq1 = Square('1', 5, 6);
    cout << sq1 << endl << endl;

    // Test Case 2
    cout << "This is Square2, value='-', row=3, col=4." << endl;
    Square sq2 = Square('-', 3, 4);
    cout << sq2 << endl << endl;

    // Test Case 3
    cout << "Make value = 5" << endl;
    sq2.mark('5');
    cout << sq2 << endl << endl;
}


int main(int argc, char* argv[]) {
    banner();

    if (argc != 2) {
        fatal("Wrong number of arguments");
    }
    ifstream f(argv[1]);
    if (!f.is_open()) { fatal("Can't open file!"); }
    Game g1(f);
    g1.run();

    bye();
    return 0;
}
