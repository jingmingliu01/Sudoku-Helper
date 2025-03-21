// ==========================================================================================
// Implementing Simplest Data Structure - Square        Author: Kim & Jingming
// File: square.cpp
// ==========================================================================================
#include "Square.hpp"
#include "Cluster.hpp"
//-------------------------------------------------------------------------------------------
void Square::
print(ostream &os) const {
    os << "[" << row << "," << col << "] ";
    st.print(os);
}
//-------------------------------------------------------------------------------------------
void Square::
mark(const char ch) {
    st.mark(ch);
}
//-------------------------------------------------------------------------------------------
void Square::
shoop(const char val) const {
    for (const Cluster* c : cs) {
        c->shoop(val);
    }
}
//-------------------------------------------------------------------------------------------
void Square::
turnOff(const int n) {
    st.turnOff(n);
}
