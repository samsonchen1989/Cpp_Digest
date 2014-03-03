#ifndef SPREADSHEETCELL_H
#define SPREADSHEETCELL_H

#include <string>

class SpreadsheetCell
{
public:
    SpreadsheetCell();
    //always use virtual in destructor, in case
    // 
    virtual ~SpreadsheetCell();

    //pure virtual method, tell compiler SpreadsheetCell
    //is abstract, instance of SpreadsheetCell cannot be created.
    virtual void set(const std::string& inString) = 0;
    virtual std::string getString() const = 0;
};

#endif