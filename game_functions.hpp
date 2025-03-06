#ifndef GAME_FUNCTIONS
#define GAME_FUNCTIONS

#include <vector>
#include <string>
using namespace std;


vector<int> readLine(string line);
int checkSurroundings(vector<vector<int>> space, int row, int column);
vector<vector<int>> nextGeneration(vector<vector<int>> space);
void printArea(vector<vector<int>> area);

#endif