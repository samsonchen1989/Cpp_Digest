#include "SpreadsheetImpl.h"

//forward declaration
class SpreadsheetImpl;
class SpreadsheetApplication;

class Spreadsheet
{
    public:
        Spreadsheet(SpreadsheetApplication& theApp,int inWidth, int inHeight);
        Spreadsheet(SpreadsheetApplication& theApp);
        //if new in constructor, must rewrite copy constructor
        //and operator '=''
        //if set to private, code will not be able to use these
        //two constructors, implementation is not required.
        Spreadsheet(const Spreadsheet& src);
        Spreadsheet& operator=(const Spreadsheet& rhs);

        ~Spreadsheet();

        void setCellAt(int x, int y, const SpreadsheetCell& cell);
        SpreadsheetCell getCellAt(int x, int y);
        int getId();

    protected:
        SpreadsheetImpl* mImpl;
};