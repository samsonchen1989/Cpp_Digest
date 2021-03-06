#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <stdlib.h>     /* exit, EXIT_FAILURE */

using namespace std;

void readIntegerFile(const string& fileName, vector<int>& dest)
{
    ifstream istr;
    int temp;

    istr.open(fileName.c_str());
    if (istr.fail()) {
        //fail to open the file
        throw exception();
    }

    //read the integers one by one and add them to the vector
    while (istr >> temp) {
        dest.push_back(temp);
    }

    if (istr.eof()) {
        //we reached the end of file
        istr.close();
    } else {
        istr.close();
        throw exception();
    }
}

int main(int argc, char** argv)
{
    vector<int> myInts;
    const string fileName = "IntegerFile.txt";

    try {
        readIntegerFile(fileName, myInts);
    } catch (const exception& e) {
        cerr << "Unable to open file" << fileName << endl;
        exit(1);
    }


    for (size_t i = 0; i < myInts.size(); i++) {
        cout << myInts[i] << endl;
    }
    cout << endl;

    return 0;
}