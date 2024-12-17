#include "Board.hpp"

// Constructor with type
Board::Board(const char type, ifstream& puzfile) : f(puzfile) {
    cerr << "Constructing Board" << endl;

    // Determine board size based on type
    switch (type) {
        case 't':
        case 'd':
            n = 9;
            break;
        case 's':
            n = 6;
            break;
        default:
            fatal("Invalid type code");
    }

    // Allocate memory for the board
    bd = new Square[n * n];
    remain_squares = n * n;

    // Load the puzzle
    getPuzzle();

    // Create clusters (rows, columns, boxes)
    makeClusters();

    cerr << "Board construction done" << endl;
}

// Constructor with size
Board::Board(int gameSize, ifstream& f) : f(f), n(gameSize), remain_squares(gameSize * gameSize) {
    bd = new Square[n * n]; // Dynamically allocate the board
    getPuzzle();            // Load the puzzle from the file
    makeClusters();         // Create clusters after the board is initialized
}

// Destructor
Board::~Board() {
    delete[] bd; // Delete the dynamically allocated array
    cerr << "Deleting Board" << endl;
}

// Create all clusters: rows, columns, and boxes
void Board::makeClusters() {
    Square* sqArray[9];

    // Create row clusters
    for (int i = 0; i < n; ++i) {
        createRow(i);
    }

    // Create column clusters
    for (int j = 0; j < n; ++j) {
        createColumn(j);
    }

    // Create box clusters
    int boxSize = static_cast<int>(sqrt(n));
    for (int boxRow = 0; boxRow < boxSize; ++boxRow) {
        for (int boxCol = 0; boxCol < boxSize; ++boxCol) {
            createBox(boxRow * 3 + boxCol);
        }
    }
}

// Create a row cluster
void Board::createRow(short row) {
    Square* sqArray[9];
    for (int col = 0; col < n; ++col) {
        sqArray[col] = &sub(row + 1, col + 1);
    }
    clusters.push_back(std::move(std::make_unique<Cluster>(ClusterType::ROW, sqArray)));
}

// Create a column cluster
void Board::createColumn(short col) {
    Square* sqArray[9];
    for (int row = 0; row < n; ++row) {
        sqArray[row] = &sub(row + 1, col + 1);
    }
    clusters.push_back(std::move(std::make_unique<Cluster>(ClusterType::COLUMN, sqArray)));
}

// Create a box cluster
void Board::createBox(short box) {
    Square* sqArray[9];
    int boxRowStart = (box / 3) * 3;
    int boxColStart = (box % 3) * 3;

    int idx = 0;
    for (int i = 0; i < 3; ++i) { // Rows in the box
        for (int j = 0; j < 3; ++j) { // Columns in the box
            sqArray[idx++] = &sub(boxRowStart + i + 1, boxColStart + j + 1);
        }
    }
    clusters.push_back(std::move(std::make_unique<Cluster>(ClusterType::BOX, sqArray)));
}

// Load the puzzle from the file
void Board::getPuzzle() {
    int emptyCount = 0;
    for (int j = 1; j <= n; ++j) {
        string line;
        getline(f, line);
        if ((int)line.length() != n) {
            fatal("Invalid line length");
        }
        for (int k = 1; k <= n; ++k) {
            char ch = line[k - 1];
            if (isdigit(ch) || ch == '-') {
                sub(j, k) = Square(ch, j, k);
                if (ch == '-') {
                    emptyCount++;
                }
            } else {
                fatal("Invalid character in puzzle");
            }
        }
    }
    // remain_squares is the number of empty squares
    remain_squares = emptyCount;
    if (f.get() != EOF) {
        fatal("Extra data after puzzle");
    }
}

// Print the board
void Board::print() const {
    for (int i = 0; i < n * n; ++i) {
        bd[i].print(cout);
        cout << endl;
        if ((i + 1) % n == 0) {
            cout << endl;
        }
    }
}