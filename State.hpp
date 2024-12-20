// =================================================================================
// Name: Implementing Simplest Data Structure - State       Author: Kim & Jingming
// File: state.hpp
// =================================================================================
#pragma once
#include "tools.hpp"
//----------------------------------------------------------------------------------
class State {
private:
    short posList;
    char value;
    bool fixed;

public:
    State();
    explicit State (char ch);
    ~State() = default;

    void mark (char ch);

    char getValue () const { return value; }
    bool isFixed() const { return fixed; }

    void turnOff(int n);

    void print(ostream& os) const;
};
//----------------------------------------------------------------------------------
inline ostream& operator<<(ostream& os, const State& state) {
    state.print(os);
    return os;
}
