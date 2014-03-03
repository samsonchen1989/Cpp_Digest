#include "Spreadsheet.h"

Spreadsheet::Spreadsheet(SpreadsheetApplication& theApp,
        int inWidth, int inHeight)
{
    mImpl = new SpreadsheetImpl(theApp, inWidth, inHeight);
}

Spreadsheet::Spreadsheet(SpreadsheetApplication& theApp)
{
    mImpl = new SpreadsheetImpl(theApp);
}

//copy every data in copy constructor
Spreadsheet::Spreadsheet(const Spreadsheet& src)
{
    mImpl = new SpreadsheetImpl(*(src.mImpl));
}

Spreadsheet::~Spreadsheet()
{
    delete mImpl;
    mImpl = NULL;
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
    *mImpl = *(rhs.mImpl);

    return *this;
}

void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell)
{
    return (mImpl->setCellAt(x, y, cell));
}

SpreadsheetCell Spreadsheet::getCellAt(int x, int y)
{
    return (mImpl->getCellAt(x, y));
}