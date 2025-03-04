#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


// Function a string, looks for 1 or 0, and adds it to a vector
vector<int> readLine(string line) {
    vector<int> row;
    for (char c : line) {
        switch (c) {
            case '1':
                row.push_back(1);
                break;
            case '0':
                row.push_back(0);
                break;
            case ' ':
                continue;
            default:
                cout << "Error, space found that is not 1 or 0. It will not be included" << endl;
        }
    }

    return row;
}




/* Checks the surrounding tiles around a specific tile given a row and column
and returns the number of active tiles*/
int checkSurroundings(vector<vector<int>> space, int row, int column)
{
    int surrounding = 0;
    int newRow = row;
    int newColumn = column;

    newRow++;
    newColumn++;
    while (newRow > row-2 && newRow >= 0) {
        while (newColumn > column-2 && newColumn >= 0) {
            if (newRow >= space.size())
                break;
            if (newColumn >= space[newRow].size()) {
                newColumn--;
                continue;
            }

            if (space[newRow][newColumn] == 1)
                surrounding++;

            newColumn--;
        }
        newRow--;
        newColumn = column+1;
    }

    if (space[row][column] == 1) surrounding--;

    return surrounding;
}




// Finds the next Generation (or 'step') given a space vector, and returns that vector
vector<vector<int>> nextGeneration(vector<vector<int>> space)
{
    vector<vector<int>> nextSpace = space;
    int surroundingActive = 0;
    for (int i = 0; i < nextSpace.size(); i++) {
        for (int j = 0; j < nextSpace[i].size(); j++) {
            surroundingActive = checkSurroundings(space, i, j);
            if (nextSpace[i][j] == 1) {
                if (surroundingActive < 2)
                nextSpace[i][j] = 0;
                if (surroundingActive > 3)
                nextSpace[i][j] = 0;
            }
            else if (nextSpace[i][j] == 0) {
                if (surroundingActive == 3)
                nextSpace[i][j] = 1;
            }
        }
    }

    return nextSpace;
}




int main() {

    ifstream inputFile("test.txt");

    vector<vector<int>> area;

    // Read each line of file, convert it to a vector, and add it to "area" vector
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            vector<int> row = readLine(line);
            area.push_back(row);
        }
        inputFile.close();
    }
    else {
        cerr << "Unable to open";
    }

    // Print out the first generation
    cout << "Current area: " << endl;
    for (int i = 0; i < area.size(); i++) {
        for (int i : area[i]) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Calculates the next generation
    area = nextGeneration(area);

    // Prints the next generation.
    cout << "New area: " << endl;
    for (int i = 0; i < area.size(); i++) {
        for (int i : area[i]) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Closes file.
    inputFile.close();

    return 0;
}