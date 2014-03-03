#include "SpreadsheetCell.h"

//forward declaration
class SpreadsheetApplication;

class SpreadsheetImpl
{
    public:
        SpreadsheetImpl(SpreadsheetApplication& theApp,
            int inWidth = kMaxWidth, int inHeight = kMaxHeight);
        //if new in constructor, must rewrite copy constructor
        //and operator '=''
        //if set to private, code will not be able to use these
        //two constructors, implementation is not required.
        SpreadsheetImpl(const SpreadsheetImpl& src);
        SpreadsheetImpl& operator=(const SpreadsheetImpl& rhs);

        ~SpreadsheetImpl();

        void setCellAt(int x, int y, const SpreadsheetCell& cell);
        SpreadsheetCell getCellAt(int x, int y);

        static const int kMaxHeight = 100;
        static const int kMaxWidth = 100;

    protected:
        bool inRange(int val, int upper);
        void copyFrom(const SpreadsheetImpl& src);

        int mWidth, mHeight;
        int mId;
        SpreadsheetCell** mCells;
        SpreadsheetApplication& mTheApp;

        static int sCounter;
};