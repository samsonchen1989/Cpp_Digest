#include <iostream>
#include <sstream>

#include "DoubleSpreadsheetCell.h"

using namespace std;

DoubleSpreadsheetCell::DoubleSpreadsheetCell() : mValue(-1) {}

void DoubleSpreadsheetCell::set(const std::string& inString)
{
    mValue = stringToDouble(inString);
}

void DoubleSpreadsheetCell::set(double inDouble)
{
    mValue = inDouble;
}

std::string DoubleSpreadsheetCell::getString() const
{
    return doubleToString(mValue);
}

std::string DoubleSpreadsheetCell::doubleToString(double inValue)
{
    ostringstream ostr;

    ostr << inValue;
    return (ostr.str());   
}

double DoubleSpreadsheetCell::stringToDouble(const std::string& inString)
{
    double temp;

    istringstream istr(inString);

    istr >> temp;
    if (istr.fail() || !istr.eof()) {
        return 0;
    }

    return temp;
}