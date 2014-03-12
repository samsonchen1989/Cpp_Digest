#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class RoundRobin
{
public:
    RoundRobin(int numExpected = 0);
    ~RoundRobin();

    //Append elem to the end of list, may be
    //called between calls to getNext()
    void add(const T& elem);

    //remove the first element in the list
    //that is equal to elem, maybe called 
    //between calls to getNext()
    void remove(const T& elem);

    //return the next elememt in the list,
    //start from 0 and continuously cycling,
    //taking in account elements that are added
    //or removed
    T& getNext() throw(std::out_of_range);

protected:
    vector<T> mElems;
    typename std::vector<T>::iterator mCurElem;

private:
    //prevent assignment and pass by reference
    RoundRobin(const RoundRobin& src);
    RoundRobin& operator=(const RoundRobin& rhs);
};

#include "RoundRobin.tpp"

#endif