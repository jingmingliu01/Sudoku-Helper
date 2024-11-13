//
// Created by Jimmy on 2024-11-11.
//

#ifndef STATE_H
#define STATE_H
#include <iostream>
#include <stdexcept>

using namespace std;

class State {
private:
    short possibilities;
    char value;
    bool fixed;

public:
    State() = default;
    //Initialize
    State(const char v);;
    ~State() = default;
    //Mark
    void mark(char ch);

    ostream& print(ostream& os) const;
};

inline ostream& operator<<(ostream& os, const State& state) { return state.print(os); }

#endif //STATE_H
