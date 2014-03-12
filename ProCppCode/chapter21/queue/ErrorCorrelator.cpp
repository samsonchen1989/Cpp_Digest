#include "ErrorCorrelator.h"

using namespace std;

// No Error::operator, operator<(Error&, Error&) is
// a friend function but not belong to class Error instance
bool operator<(const Error& lhs, const Error& rhs)
{
    return (lhs.mPriority < rhs.mPriority);
}

ostream& operator<<(ostream& str, const Error& err)
{
    str << err.mError << " (priority " << err.mPriority << ")";
    return (str);
}

void ErrorCorrelator::addError(const Error& error)
{
    mErrors.push(error);
}

Error ErrorCorrelator::getError() throw (out_of_range)
{
    //if there are no more errors, throw an exception
    if (mErrors.empty()) {
        throw (out_of_range("No elements!"));
    }

    Error top = mErrors.top();
    mErrors.pop();
    return (top);
}