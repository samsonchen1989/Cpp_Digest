#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    ifstream inFile("readfile.cpp");
    if (inFile.fail()) {
        cerr << "Unable to open file for reading." << endl;
        exit(1);
    }

    string nextToken;
    while (inFile >> nextToken) {
        cout << "Token:" << nextToken << endl;
    }

    inFile.close();

    return 0;
}