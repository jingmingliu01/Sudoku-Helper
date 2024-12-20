// ==========================================================================================
// Implementing Simplest Data Structure - Square        Author: Kim & Jingming
// File: state.cpp
// ==========================================================================================
#include "tools.hpp"
#include "State.hpp"
//----------------------------------------------------------------------------------------
State::State() : posList(0x3fe), value('-'), fixed(false) {}
//-------------------------------------------------------------------------------------------
State::State(const char ch) {
    if (ch >= '1' && ch <= '9') {
        value = ch;
        posList = 0;
        fixed = true;
    }
    else if (ch == '-') {
        value = ch;
        posList = 0x3fe;
        fixed = false;
    }
}
//-------------------------------------------------------------------------------------------
void State::
mark(const char ch) {
    if (fixed) { cout << "Error: Cannot mark a square with a fixed value." << endl; }
    else {
        value = ch;
        posList = 0;
    }
}
//-------------------------------------------------------------------------------------------
void State::
print(ostream& os) const {
    // os << value;
    os << "Value: " << value << " Fixed: " << (fixed ? "Yes" : "No") << ", Possible: ";
    for (int k = 1; k <= 9; ++k) {
        if ((posList >> k) & 1) {
            os << k;
        } else {
            os << '-';
        }
    }
    os << "\n";
}
//-------------------------------------------------------------------------------------------
void
State::turnOff(const int n) {
    posList &= ~(1 << n);
}
