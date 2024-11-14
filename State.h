//
// Created by Jimmy on 2024-11-11.
//

#ifndef STATE_H
#define STATE_H
#include <iostream>
#include <stdexcept>

using namespace std;

//Part that change frequently
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
    char getValue() { return value; };

    ostream& print(ostream& os) const;
};

inline ostream& operator<<(ostream& os, const State& state) { return state.print(os); }


//Part that don't change
class Square {
private:
    State state;
    short row;
    short col;
    vector<Square> neighbors;

public:
    Square() = default;

    Square(char c, short row, short col);;
    ~Square() { cerr << "Deleting Square" << '[' << row << ',' << col << ']' << endl; };

    void mark(char c);

    ostream& print(ostream& os) const;;
};

inline ostream& operator<<(ostream& os, const Square& square) { return square.print(os); }

#endif //STATE_H

class Square {
private:
    State state;
    short row;
    short col;
    vector<Square> neighbors;

public:
    Square() = default;

    Square(char c, short row, short col);;
    ~Square() { cerr << "Deleting Square" << '[' << row << ',' << col << ']' << endl; };

    void mark(char c);

    ostream& print(ostream& os) const;;
};

inline ostream& operator<<(ostream& os, const Square& square) { return square.print(os); }
