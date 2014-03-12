#include <ostream>
#include <string>
#include <queue>
#include <stdexcept>

// sample error class with just a priority and a string error description
class Error
{
public:
    Error(int priority, std::string errMsg) :
        mPriority(priority), mError(errMsg) {}
    int getPriority() const { return mPriority; }
    std::string getErrorString() const { return mError; }

    friend bool operator<(const Error& lhs, const Error& rhs);
    friend std::ostream& operator<<(std::ostream& str, const Error& err);

protected:
    int mPriority;
    std::string mError;

};

// simple errorCorrelator class returns highest priority error first
class ErrorCorrelator
{
public:
    ErrorCorrelator() {}

    // add an error to be correlated
    void addError(const Error& error);

    // retrieve the next error to be processed
    Error getError() throw (std::out_of_range);

protected:
    std::priority_queue<Error> mErrors;
private:
    // prevent assignment and pass-by-value
    ErrorCorrelator(const ErrorCorrelator& src);
    ErrorCorrelator& operator=(const ErrorCorrelator& rhs);
};