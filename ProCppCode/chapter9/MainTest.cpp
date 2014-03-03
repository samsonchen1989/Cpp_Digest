#include <iostream>
#include "Spreadsheet.h"

using namespace std;

int main(int argc, char** argv)
{
    SpreadsheetCell stackCell1(1024), stackCell2;
    stackCell2 = stackCell1 + 1024;

    cout<<"stackCell1 == stackCell2:" <<
        (stackCell1 == stackCell2 ? "true":"false") << endl;
    cout<<"stackCell1 >  stackCell2:" <<
        (stackCell1 > stackCell2 ? "true":"false") << endl;
    cout<<"stackCell1 <= stackCell2:" <<
        (stackCell1 <= stackCell2 ? "true":"false") << endl;
    cout<<"stackCell1 >= stackCell2:" <<
        (stackCell1 >= stackCell2 ? "true":"false") << endl;

    cout << "stackCell2, value:" << stackCell2.getValue() << endl;
    stackCell2 = 1024 + stackCell2;
    cout << "stackCell2, value:" << stackCell2.getValue() << endl;
    stackCell2 += 1024;
    cout << "stackCell2, value:" << stackCell2.getValue() << endl;
    cout << "address:" << &stackCell2 << endl;

    //SpreadsheetCell *heapCell = new SpreadsheetCell("99");
    SpreadsheetCell *heapCell = new SpreadsheetCell("99");
    //heapCell->setValue(8);
    *heapCell = stackCell1;

    cout << "stackCell, mString:" << stackCell1.getString() << endl;
    cout << "heapCell, mString:" << heapCell->getString() << endl;

/*
    SpreadsheetApplication app;
    Spreadsheet stackSheet(app, 5, 5);
    stackSheet.setCellAt(1, 1, *heapCell);
    cout << "Cell[1, 1]:" << stackSheet.getCellAt(1, 1).getValue() << endl;
*/

    delete heapCell;

    return 0;
}
