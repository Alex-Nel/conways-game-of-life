#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <fcntl.h>
#include <io.h>
#include "game_functions.hpp"

using namespace std;


/*
Main function handles reading the file for the area
and receiving each key press.
Mode is set to 0x00020000 to handle unicode characters,
as a result, wcout is used instead of cout.
*/
int main(int argc, char *argv[]) {

    _setmode(_fileno(stdout), 0x00020000);

    string filename = argv[1];

    if (filename.substr(filename.length() - 4, 4) != ".txt")
        filename += ".txt";

    ifstream inputFile(filename);

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
        cerr << "Unable to open" << endl;
        return 0;
    }


    int iterations = 0;
    char currentinput;

    wcout << "\033[2J";

    while (currentinput != 'c') {
        printArea(area);
        wcout << endl;
        // Future idea: Continuous loop
        // wcout << "l - start\t";
        wcout << "n - next step\t\t";
        wcout << "c - exit" << endl;
        
        while (currentinput != 'c' && currentinput != 'n' && currentinput != 'l')
            currentinput = getch();

        switch (currentinput) {
            case 'n':
                area = nextGeneration(area);
                break;
            case 'c':
                wcout << "\033[2J";
                return 0;
                
        }
        wcout << "\033[2J";
        currentinput = '\0';
    }

    // Closes file.
    inputFile.close();

    return 0;
}