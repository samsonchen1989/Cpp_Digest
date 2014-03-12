template <typename T>
RoundRobin<T>::RoundRobin(int numExpected)
{
    //reserve that much space
    mElems.reserve(numExpected);
    mCurElem = mElems.begin();
}

template <typename T>
RoundRobin<T>::~RoundRobin()
{

}

template <typename T>
void RoundRobin<T>::add(const T& elem)
{
    int pos = mCurElem - mElems.begin();
    mElems.push_back(elem);

    if (mElems.size() == 1) {
        mCurElem = mElems.begin();
    } else {
        mCurElem = mElems.begin() + pos;
    }
}

template <typename T>
void RoundRobin<T>::remove(const T& elem)
{
    typename std::vector<T>::iterator it;
    for (it = mElems.begin(); it != mElems.end(); ++it) {
        if (*it == elem) {
            int newPos;
            if (mCurElem <= it) {
                newPos = mCurElem - mElems.begin();
            } else {
                newPos = mCurElem - mElems.begin() - 1;
            }

            mElems.erase(it);
            mCurElem = mElems.begin() + newPos;

            if (mCurElem ==  mElems.end()) {
                mCurElem = mElems.begin();
            }

            return;
        }
    }    
}

template <typename T>
T& RoundRobin<T>::getNext() throw (std::out_of_range)
{
    //first, make sure there are any elements
    if (mElems.empty()) {
        throw std::out_of_range("No elements in the list.");
    }

    // retrieve a reference to return
    T& retVal = *mCurElem;
    cout << "getNext():" << (mCurElem - mElems.begin()) << endl; 
    // Increment the iterator modulo the number of elements
    ++mCurElem;
    if (mCurElem == mElems.end()) {
        mCurElem = mElems.begin();
    }

    return retVal;
}