#include "Square.h"
#include "Cluster.h"
#include "Errors.h"

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
    else { throw GameLogicError("Invalid state value!"); }
}

void State::mark(const char ch) {
    if (fixed == true) { throw GameLogicError("This state is fixed!"); }
    value = ch;
    possibilities = 0;
}

void State::turnOff(const int num) {
    if (num < 1 || num > 9) {
        throw GameLogicError("Marking invalid value in state");
    }

    short mask = ~(1 << num); // Create a mask to turn off the num bit
    possibilities &= mask;          // Apply the mask

    // Debugging information
    cerr << "Turned off " << num << " in State. New possibilities: ";
    print(cerr) << endl;
}

ostream& State::print(ostream& os) const {
    os << "Value: " << value << endl;
    os << "Possible: ";
    short poss = possibilities;
    poss >>= 1;
    for (int i = 1; i < 10; i++) {
        if (poss & 1) { os << i; }
        else { os << '-'; }
        poss >>= 1;
    }
    return os;
}

Square::Square(const char c, const short row, const short col): state(c), row(row), col(col) {
    cerr << "Square" << '[' << this->row << ',' << this->col << ']' << " created." << endl;
}

void Square::mark(const char c) {
    if (c >= '1' && c <= '9') {
        state.mark(c);
    }
}

ostream& Square::print(ostream& os) const {
    os << "Square" << '[' << this->row << ',' << this->col << ']' << endl;
    state.print(os);
    return os;
}

void Square::turnOff(const int num) {
    state.turnOff(num); // Delegate the task to State
}

void Square::shoop() const {
    cerr << "Shooping Square[" << row << "," << col << "] with value " << state.getValue() << endl;
    for (Cluster* cluster : clues) {
        cluster->shoop(state.getValue());
    }
}
