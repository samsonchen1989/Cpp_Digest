#include <iostream>

#include "StringSpreadsheetCell.h"
#include "DoubleSpreadsheetCell.h"

using namespace std;

int main(int argc, char** argv)
{
    SpreadsheetCell* cellArray[3];

    cellArray[0] = new StringSpreadsheetCell();
    cellArray[1] = new StringSpreadsheetCell();
    cellArray[2] = new DoubleSpreadsheetCell();

    return 0;
}