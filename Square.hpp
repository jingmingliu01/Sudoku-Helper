// =================================================================================
// Name: Implementing Simplest Data Structure - Square      Author: Kim & Jingming
// File: state.hpp
// =================================================================================
#pragma once
#include "State.hpp"
class Cluster;
//----------------------------------------------------------------------------------
class Square {
private:
    State st;
    short int row;
    short int col;
    vector<Cluster*> cs;    //new addition; cs short for clusters

public:
    Square() = default;;
    Square(const char val, const short int row, const short int col)
        : st(val), row(row), col(col){};
    ~Square() = default;

    void print(ostream& os) const;    //Partial delegation to State's print function

    void mark (char ch);

    //new additions:
    void addCluster(Cluster* c) { cs.push_back(c);}

    void shoop(char val) const;

    void turnOff(int n);

    char getValue() const { return st.getValue(); } //new addition
};
//----------------------------------------------------------------------------------
inline ostream& operator<<(ostream& os, const Square& square) {
    square.print(os);
    return os;
}
