#include <string>
using std::string;

class SpreadsheetCell
{
    public:
        SpreadsheetCell();
        SpreadsheetCell(double initialValue);
        //explicit tells compiler not to convert a string to 
        //SpreadsheetCell, explicit accepts only one param
        explicit SpreadsheetCell(string initialString);
        SpreadsheetCell(const SpreadsheetCell& src);
        SpreadsheetCell& operator=(const SpreadsheetCell& rhs);

        SpreadsheetCell& operator+=(const SpreadsheetCell& cell);
        friend SpreadsheetCell operator+(SpreadsheetCell lefths,
            const SpreadsheetCell& righths);

        SpreadsheetCell& operator-=(const SpreadsheetCell& cell);
        friend SpreadsheetCell operator-(SpreadsheetCell lefths,
            const SpreadsheetCell& righths);

        SpreadsheetCell& operator*=(const SpreadsheetCell& cell);
        friend SpreadsheetCell operator*(SpreadsheetCell lefths,
            const SpreadsheetCell& righths);

        SpreadsheetCell& operator/=(const SpreadsheetCell& cell);
        friend SpreadsheetCell operator/(SpreadsheetCell lefths,
            const SpreadsheetCell& righths);

        friend bool operator==(const SpreadsheetCell& leftCell,
            const SpreadsheetCell& rightCell);
        friend bool operator<(const SpreadsheetCell& leftCell,
            const SpreadsheetCell& rightCell);
        friend bool operator>(const SpreadsheetCell& leftCell,
            const SpreadsheetCell& rightCell);
        friend bool operator<=(const SpreadsheetCell& leftCell,
            const SpreadsheetCell& rightCell);
        friend bool operator>=(const SpreadsheetCell& leftCell,
            const SpreadsheetCell& rightCell);

        //void setValue(double inValue);
        //void setString(string inString);
        //overload
        void set(double inValue);
        void set(string inString);
        //const function will not modify any data
        string getString() const;
        double getValue() const;

        static string doubleToString(double inValue);
        static double stringToDouble(string inString);

    protected:

        double mValue;
        string mString;
};
