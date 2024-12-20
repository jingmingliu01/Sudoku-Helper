// ==========================================================================================
// Header file for logical structure and cluster    Author: Kim & Jingming
// File: cluster.hpp
// ==========================================================================================
#pragma once
#include "Square.hpp"
#include <vector>

enum class ClusterT {ROW, COLUMN, BOX};
//------------------------------------------------------------------------------------------
class Cluster {
private:
    vector<Square*> sqrs;
    const char* cl;

public:
    Cluster(ClusterT type, Square* sqrArr[9]);
    ~Cluster() = default;

    void print(ostream& os) const;
    void shoop( char val) const;
};
//----------------------------------------------------------------------------------
inline ostream& operator<<(ostream& os, const Cluster& c) {
    c.print(os);
    return os;
}
