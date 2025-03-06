#include <iostream>
#include <vector>
#include <string>
#include "game_functions.hpp"

using namespace std;

// Function a string, looks for 1 or 0, and adds it to a vector
vector<int> readLine(string line)
{
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
        }
    }

    return row;
}




/*
Checks the surrounding tiles around a specific tile given a row and column
and returns the number of active tiles
*/
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




// Prints the area. 0's are printed as white square, and 1's are printed as black square
void printArea(vector<vector<int>> area) {
    for (int i = 0; i < area.size(); i++) {
        for (int i : area[i]) {
            // cout << i << " ";
            if (i == 1)
                wcout << L"\x25A0 ";
            if (i == 0)
                wcout << L"\x25A1 ";
        }
        wcout << endl;
    }
    wcout << endl;
}