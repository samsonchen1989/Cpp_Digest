#ifndef SUB_SIMPLE_H
#define SUB_SIMPLE_H

#include "Simple.h"

class SubSimple : public Simple
{
public:
    SubSimple();
    virtual ~SubSimple();

    virtual void publicMethod();

    virtual void anotherMethod();
};

#endif