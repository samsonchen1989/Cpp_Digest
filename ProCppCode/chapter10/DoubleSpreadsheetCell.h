#ifndef DOUBLESPREADSHEETCELL_H
#define DOUBLESPREADSHEETCELL_H

#include "SpreadsheetCell.h"

class DoubleSpreadsheetCell : public SpreadsheetCell
{
public:
    DoubleSpreadsheetCell();
    virtual void set(const std::string& inString);
    virtual void set(double inDouble);

    virtual std::string getString() const;

protected:
    static std::string doubleToString(double inValue);
    static double stringToDouble(const std::string& inString);
    double mValue;
};

#endif