#include "State.h"

State::State(const char v): value(v) {
    //as pre-set
    if (value >= '1' && value <= '9') {
        possibilities = 0;
        fixed = true;
    }
    //as empty
    else if (value == '-') {
        possibilities = 0x3fe; //0000 0011 1111 1110 in binary
        fixed = false;
    }
    else { throw invalid_argument("Invalid state value!"); }
}

void State::mark(char ch) {
    if (fixed == true) { cerr << "This state is fixed!" << endl; }
    else {
        value = ch;
        possibilities = 0;
    }
}

ostream& State::print(ostream& os) const {
    short poss = possibilities;
    poss >>= 1;
    for (int i = 1; i < 10; i++) {
        if (poss & 1) { os << i; }
        else { os << '-'; }
        poss >>= 1;
    }
    return os;
}
