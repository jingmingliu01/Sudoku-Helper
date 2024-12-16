#include <iostream>
#include "Square.h"
#include "Cluster.h"
#include "Board.h"
#include "Game.h"

using namespace std;

// Test function for Square
void testSquare() {
    cout << "Testing Square..." << endl;

    // Create a square with all possibilities
    Square sq('-', 1, 1);
    cout << "Initial Square: ";
    sq.print(cout);
    cout << endl;

    // Test turnOff()
    sq.turnOff(3);
    sq.turnOff(5);
    cout << "After turning off 3 and 5: ";
    sq.print(cout);
    cout << endl;

    // Check edge cases
    sq.turnOff(10); // Invalid
    sq.turnOff(-1); // Invalid

    cout << "Square test completed." << endl << endl;
}

// Test function for Cluster
void testCluster() {
    cout << "Testing Cluster..." << endl;

    // Create 9 squares
    Square* squares[9];
    for (int i = 0; i < 9; i++) {
        squares[i] = new Square('-', 1, i + 1); // Row 1, Col 1-9
    }

    // Create a Row Cluster
    Cluster rowCluster(ClusterType::ROW, squares);
    cout << "Row Cluster Before Shoop:" << endl;
    rowCluster.print();

    // Test shoop()
    rowCluster.shoop('5'); // Eliminate the possibility of '5'
    cout << "Row Cluster After Shoop('5'):" << endl;
    rowCluster.print();

    // Clean up
    for (int i = 0; i < 9; i++) {
        delete squares[i];
    }

    cout << "Cluster test completed." << endl << endl;
}

// Test function for Board
void testBoard() {
    cout << "Testing Board..." << endl;

    // Create a test puzzle
    const char* testPuzzle =
        "4-6--7--3\n"
        "-9-5-6-7-\n"
        "------58-\n"
        "---9--34-\n"
        "3-------8\n"
        "-78--4---\n"
        "-17------\n"
        "-8--2-9-6\n"
        "9--7--8-4";

    // Write puzzle to a temporary file
    ofstream tempFile("tempPuzzle.txt");
    tempFile << testPuzzle;
    tempFile.close();

    // Open the file with ifstream
    ifstream puzzleFile("tempPuzzle.txt");
    Board board(9, puzzleFile);

    // Print all clusters
    board.print();

    cout << "Board test completed." << endl << endl;

    // Clean up temporary file
    remove("tempPuzzle.txt");
}

// Main function to execute tests
int main(int argc, char* argv[]) {
    banner();

    cout << "Running Tests..." << endl<<endl;

    // Test Square
    testSquare();

    // Test Cluster
    testCluster();

    // Test Board
    testBoard();

    cout << "All tests completed successfully." << endl;

    bye();
    return 0;
}