#include <iostream>
#include <stdexcept>
#include "State.h"
#include "tools.hpp"

using namespace std;

void Test() {
    cout << "This is s1, using default null constructor." << endl;
    State s2 = State();
    cout << "s2 possibilities:" << s2 << endl << endl;

    cout << "This is s3, value = 1." << endl;
    State s3 = State('1');
    cout << "s3 possibilities:" << s3 << endl << endl;

    cout << "This is s4, value = ‘-’." << endl;
    State s4 = State('-');
    cout << "s4 possibilities:" << s4 << endl;
    s4.mark('2');
    cout << "Mark value = 2 " << endl;
    cout << "s4 possibilities:" << s4 << endl << endl;
};


int main() {
    banner();

    try {
        cout << "This is s1, value = 0." << endl;
        State s1 = State('0');
    }
    catch (invalid_argument& e) {
        cout << "Error:" << e.what() << endl << endl;
        Test();
    }

    bye();
    return 0;
}
