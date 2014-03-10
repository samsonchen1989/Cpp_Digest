#ifndef SIMPLE_H
#define SIMPLE_H

class Simple
{
public:
    Simple();
    virtual ~Simple();

    virtual void publicMethod();

    int mPublishInteger;

protected:
    int mProtectedInteger;

private:
    int mPrivateInteger;

    //private const
    static const int mConstant = 2;

    //private static data member
    static int sStaticInt;

    //disallow assignment and pass-by-value
    Simple(const Simple& src);
    Simple& operator=(const Simple& rhs);
};

#endif