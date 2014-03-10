#ifndef SIMPLE_TEMPLATE_H
#define SIMPLE_TEMPLATE_H

template <typename T>
class SimpleTemplate
{
public:
    SimpleTemplate(T& inObject);

    const T& get();
    void set(T& inObject);

protected:
    T& mObject;
};

#include "SimpleTemplate.tpp"

#endif