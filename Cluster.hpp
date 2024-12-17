#ifndef CLUSTER_H
#define CLUSTER_H

#include <vector>
#include "Square.hpp"

enum class ClusterType { ROW, COLUMN, BOX };
static constexpr const char* clusterTypeStrings[3] = { "Row", "Column", "Box" };

class Cluster {
private:
    const char* type;
    Square* squares[9];

public:
    Cluster(ClusterType clusterType, Square* sqArray[]);
    void print() const;
    void shoop(char val);
};

inline std::ostream& operator<<(std::ostream& out, const Cluster& c) {
    c.print();
    return out;
}

#endif //CLUSTER_H
