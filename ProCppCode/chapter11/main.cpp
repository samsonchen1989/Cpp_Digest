#include <iostream>

#include "Grid.h"
#include "NDGrid.h"
#include "SpreadsheetCell.h"

using namespace std;

template <typename T>
int Find(T& value, T* arr, int size)
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            //find it, return index
            return i;
        }
    }

    //fail to find it
    return -1;
}

int main(int argc, char** argv)
{
    //Declares a grid that stores ints
    Grid<int> myIntGrid;
    myIntGrid.setElementAt(0, 0, 10);

    Grid<double> myDoubleGrid;
    myDoubleGrid.setElementAt(0, 1, 20.0);

    int x = myIntGrid.getElementAt(0, 0);

    Grid<int> myIntGrid2(myDoubleGrid);
    Grid<int> myIntGrid3 = myDoubleGrid;

    cout << "IntGrid2[0, 1]:" << myIntGrid2.getElementAt(0, 1) << endl;
    cout << "IntGrid3[0, 1]:" << myIntGrid3.getElementAt(0, 1) << endl;

    Grid<SpreadsheetCell>* cellGrid;
    cellGrid = new Grid<SpreadsheetCell>();

    SpreadsheetCell cell1(1024);
    SpreadsheetCell cell2(2048);

    cellGrid->setElementAt(0, 0, cell1);
    cellGrid->setElementAt(1, 1, cell2);

    cout << "Element Cell 1:" << (cellGrid->getElementAt(0, 0).getString()) << endl;
    cout << "Element Cell 2:" << (cellGrid->getElementAt(1, 1).getString()) << endl;

    delete cellGrid;

    int intArr[4] = {1, 2, 3, 4};
    int res;
    int y = 4;
    //equal to Find<int>(4, intArr, sizeof(intArr))
    res = Find(y, intArr, 4);
    cout << "Find result:" << res << endl;

    SpreadsheetCell c1(10);
    SpreadsheetCell c2[2] = {SpreadsheetCell(4), SpreadsheetCell(10)};
    //equal to Find<SpreadsheetCell>(c1, c2, 2);
    res = Find(c1, c2, 2);
    cout << "Find result:" << res << endl;

    NDGrid<int, 3> my3DGrid;
    my3DGrid[2][1][2] = 5;
    my3DGrid[1][1][1] = 5;

    cout << my3DGrid[2][1][2] << endl;

    return 0;
}