// ==========================================================================================
// Implementing the logical structure and cluster       Author: Kim & Jingming
// File: cluster.cpp
// ==========================================================================================
#include "Cluster.hpp"
static constexpr const char* clusterT[] = { "Row", "Column", "Box" };
//-------------------------------------------------------------------------------------------
Cluster::Cluster(ClusterT type, Square* sqrArr[9])
        : cl(clusterT[static_cast<int>(type)]) {
    for (int i = 0; i < 9; ++i) {
        sqrs.push_back(sqrArr[i]);
        sqrArr[i]->addCluster(this);
    }
}
//-------------------------------------------------------------------------------------------
void Cluster::
print(ostream& os) const {
    os << cl << " Cluster:\n";
    for (const Square* sqr : sqrs) {
        sqr->print(os);
    }
    os << "\n";
}
//-------------------------------------------------------------------------------------------
void Cluster::
shoop(char val) const {
    int ch = val - '0';
    for (Square* sqr : sqrs) {
        sqr->turnOff(ch);
    }
}
