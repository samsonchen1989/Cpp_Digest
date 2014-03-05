#include <iostream>
#include <sstream>

#include "SpreadsheetCell.h"

using namespace std;

SpreadsheetCell::SpreadsheetCell() : mValue(0), mString("") {}

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src)
{
    set(src.mValue);
    set(src.mString);
}

SpreadsheetCell::SpreadsheetCell(double initialValue)
{
    set(initialValue);
}

SpreadsheetCell::SpreadsheetCell(string initialString)
{
    set(initialString);
}

void SpreadsheetCell::set(double inValue)
{
    mValue = inValue;
    mString = doubleToString(inValue);
}

//inline, like #define in C
double SpreadsheetCell::getValue() const
{
    return mValue;
}

void SpreadsheetCell::set(string inString)
{
    mString = inString;
    mValue = stringToDouble(inString);
}

string SpreadsheetCell::getString() const
{
    return (mString);
}

string SpreadsheetCell::doubleToString(double inValue)
{
    ostringstream ostr;

    ostr << inValue;
    return (ostr.str());
}

double SpreadsheetCell::stringToDouble(string inString)
{
    double temp;

    istringstream istr(inString);

    istr >> temp;
    if (istr.fail() || !istr.eof()) {
        return 0;
    }

    return temp;
}

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
    if (this == &rhs) {
        return (*this);
    }

    mValue = rhs.mValue;
    mString = rhs.mString;

    return (*this);
}

//see detail in:
//http://goo.gl/5kSoFv
SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& cell)
{
    set(mValue + cell.mValue);
    return (*this);
}

//Pay attention to left value, we don't want to change
//left value, so we just input left by value, not the '&'
//reference.
SpreadsheetCell operator+(SpreadsheetCell left,
    const SpreadsheetCell& right)
{
    return (left += right);
}

SpreadsheetCell& SpreadsheetCell::operator-=(const SpreadsheetCell& cell)
{
    set(mValue - cell.mValue);
    return (*this);
}

SpreadsheetCell operator-(SpreadsheetCell lefths,
    const SpreadsheetCell& righths)
{
    return (lefths -= righths);
}

SpreadsheetCell& SpreadsheetCell::operator*=(const SpreadsheetCell& cell)
{
    set(mValue * cell.mValue);
    return (*this);
}

SpreadsheetCell operator*(SpreadsheetCell lefths,
    const SpreadsheetCell& righths)
{
    return (lefths*=righths);
}

SpreadsheetCell& SpreadsheetCell::operator/=(const SpreadsheetCell& cell)
{
    if (cell.mValue == 0) {
        set(0);
    } else {
        set(mValue / cell.mValue);
    }

    return (*this);
}

SpreadsheetCell operator/(SpreadsheetCell lefths,
    const SpreadsheetCell& righths)
{
    return (lefths /= righths);
}

bool operator==(const SpreadsheetCell& leftCell,
    const SpreadsheetCell& rightCell)
{
    return (leftCell.mValue == rightCell.mValue);
}

bool operator<(const SpreadsheetCell& leftCell,
    const SpreadsheetCell& rightCell)
{
    return (leftCell.mValue < rightCell.mValue);
}

bool operator!=(const SpreadsheetCell& leftCell,
    const SpreadsheetCell& rightCell)
{
    return !(leftCell == rightCell);
}

bool operator>=(const SpreadsheetCell& leftCell,
    const SpreadsheetCell& rightCell)
{
    return !(leftCell < rightCell);
}

bool operator>(const SpreadsheetCell& leftCell,
    const SpreadsheetCell& rightCell)
{
    return ((leftCell >= rightCell) && (leftCell != rightCell));
}

bool operator<=(const SpreadsheetCell& leftCell,
    const SpreadsheetCell& rightCell)
{
    return !(leftCell > rightCell);
}
