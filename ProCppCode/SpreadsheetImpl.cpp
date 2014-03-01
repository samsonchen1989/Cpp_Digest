#include "SpreadsheetImpl.h"

//set static to 0 by default.
int SpreadsheetImpl::sCounter = 0;

SpreadsheetImpl::SpreadsheetImpl(SpreadsheetApplication& theApp,
        int inWidth, int inHeight) :
    mWidth(inWidth < kMaxWidth ? inWidth : kMaxWidth),
    mHeight(inHeight < kMaxHeight ? inHeight : kMaxHeight),
    mTheApp(theApp)
{
    mId = sCounter++;
    mCells = new SpreadsheetCell* [mWidth];

    for (int i = 0; i < mWidth; i++) {
        mCells[i] = new SpreadsheetCell[mHeight];
    }
}

//copy every data in copy constructor
SpreadsheetImpl::SpreadsheetImpl(const SpreadsheetImpl& src) :
    mTheApp(src.mTheApp)
{
    mId = sCounter++;
    copyFrom(src);
}

SpreadsheetImpl::~SpreadsheetImpl()
{
    for (int i = 0; i < mWidth; i++) {
        delete[] mCells[i];
    }

    delete[] mCells;
}

SpreadsheetImpl& SpreadsheetImpl::operator=(const SpreadsheetImpl& rhs)
{
    int i;

    if (this == &rhs) {
        return (*this);
    }

    for (i = 0; i < mWidth; i++) {
        delete[] mCells[i];
    }

    delete[] mCells;

    copyFrom(rhs);

    return (*this);
}

void SpreadsheetImpl::setCellAt(int x, int y, const SpreadsheetCell& cell)
{
    if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
        return;
    }

    mCells[x][y] = cell;
}

SpreadsheetCell SpreadsheetImpl::getCellAt(int x, int y)
{
    SpreadsheetCell empty;

    if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
        return empty;
    }

    return (mCells[x][y]);
}

bool SpreadsheetImpl::inRange(int val, int upper)
{
    return (val >= 0 && val < upper);
}

void SpreadsheetImpl::copyFrom(const SpreadsheetImpl& src)
{
    int i, j;

    mWidth = src.mWidth;
    mHeight = src.mHeight;

    mCells = new SpreadsheetCell* [mWidth];
    for (i = 0; i < mWidth; i++) {
        mCells[i] = new SpreadsheetCell[mHeight];
    }

    for (i = 0; i < mWidth; i++) {
        for (j = 0; j < mHeight; j++) {
            mCells[i][j] = src.mCells[i][j];
        }
    }
}