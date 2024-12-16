#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>

// Forward declaration of Cluster
class Cluster;

using namespace std;

// State class remains unchanged
class State {
private:
    short possibilities; // Bitmask for possibilities
    char value;
    bool fixed;
public:
    State() = default;
    explicit State(char v);
    ~State() = default;

    void mark(char ch);
    char getValue() const { return value; };
    void turnOff(int num); // New method to turn off possibilities
    ostream& print(ostream& os) const;
};

inline ostream& operator<<(ostream& os, const State& state) { return state.print(os); }


class Square {
private:
    State state;
    short row;
    short col;
    vector<Square> neighbors;
    vector<Cluster*> clues; // Added vector of Cluster*
public:
    // Constructor and Destructor
    Square() = default;
    Square(char c, short row, short col);
    ~Square() { cerr << "Deleting Square" << '[' << row << ',' << col << ']' << endl; };

    // Cluster related functions
    void addCluster(Cluster* c) { clues.push_back(c); } // Add a cluster
    void turnOff(int num); // Turn off a possibility
    void shoop() const; // Update all related clusters
    // Mark
    void mark(char c);
    // Print
    ostream& print(ostream& os) const;
};

inline ostream& operator<<(ostream& os, const Square& square) { return square.print(os); }

#endif //STATE_H