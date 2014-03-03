#ifndef STRINGSPREADSHEETCELL_H
#define STRINGSPREADSHEETCELL_H

#include "SpreadsheetCell.h"

class StringSpreadsheetCell : public SpreadsheetCell
{
public:
    StringSpreadsheetCell();

    virtual void set(const std::string& inString);
    virtual std::string getString() const;

protected:
    std::string mValue;
};

#endif