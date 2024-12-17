#include "Cluster.hpp"
#include <iostream>
using namespace std;

Cluster::Cluster(ClusterType clusterType, Square* sqArray[]) {
    type = clusterTypeStrings[static_cast<int>(clusterType)]; //convert enum to string
    for (int i = 0; i < 9; i++) {
        squares[i] = sqArray[i];
        squares[i]->addCluster(this); //add this cluster to the square's list of clusters
    }
}

void Cluster::print() const {
    cout << type << " Cluster:" << endl;
    for (int i = 0; i < 9; i++) {
        squares[i]->print(cout);
        cout << endl;
    }
    cout << endl;
}

void Cluster::shoop(char val) {
    int num = val - '0';
    for (Square* sq : squares) {
        sq->turnOff(num);
    }
}
