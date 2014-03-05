template <typename T, int N>
const int NDGrid<T, N>::kDefaultSize;

template <typename T, int N>
NDGrid<T, N>::NDGrid(int inSize) : mSize(inSize)
{
    mElems = new NDGrid<T, N - 1>[mSize];
    //resize (N - 1) grid, for when new a array
    //it always construct with default constructor
    //NDGrid<T, N - 1>(), inSize = kDefaultSize
    for (int i = 0; i < mSize; i++) {
        mElems[i].reSize(inSize);
    }
}

template <typename T, int N>
NDGrid<T, N>::NDGrid() : mSize(kDefaultSize)
{
    mElems = new NDGrid<T, N - 1>[mSize];
}

template <typename T, int N>
NDGrid<T, N>::NDGrid(const NDGrid<T, N>& src)
{
    copyFrom(src);
}

template <typename T, int N>
NDGrid<T, N>::~NDGrid()
{
    delete [] mElems;
}

template <typename T, int N>
void NDGrid<T, N>::copyFrom(const NDGrid<T, N>& src)
{
    mSize = src.mSize;
    mElems = new NDGrid<T, N - 1>[mSize];
    for (int i = 0; i < mSize; i++) {
        mElems[i] = src.mElems[i];
    }
}

template <typename T, int N>
NDGrid<T, N>& NDGrid<T, N>::operator=(const NDGrid<T, N>& rhs)
{
    if (this == &rhs) {
        return *this;
    }

    delete [] mElems;
    copyFrom(rhs);
    return *this;
}

template <typename T, int N>
void NDGrid<T, N>::reSize(int newSize)
{
    //Allocate the new array with the new size
    NDGrid<T, N - 1>* newElems = new NDGrid<T, N - 1>[newSize];
    //copy all elements
    for (int i = 0; i < newSize && i < mSize; i++) {
        newElems[i] = mElems[i];
        //resize the nested Grid elements recursively
        newElems[i].reSize(newSize);
    }

    mSize = newSize;
    delete [] mElems;
    mElems = newElems;
}

template <typename T, int N>
NDGrid<T, N - 1>& NDGrid<T, N>::operator[](int x)
{
    return (mElems[x]);
}

template <typename T, int N>
const NDGrid<T, N - 1>& NDGrid<T, N>::operator[](int x) const
{
    return (mElems[x]);
}

template <typename T>
const int NDGrid<T, 1>::kDefaultSize;

template <typename T>
NDGrid<T, 1>::NDGrid(int inSize) : mSize(inSize)
{
    mElems = new T[mSize];
}

template <typename T>
NDGrid<T, 1>::NDGrid(const NDGrid<T, 1>& src)
{
    copyFrom(src);
}

template <typename T>
NDGrid<T, 1>::~NDGrid()
{
    delete [] mElems;
}

template <typename T>
void NDGrid<T, 1>::copyFrom(const NDGrid<T, 1>& src)
{
    mSize = src.mSize;
    mElems = new T[mSize];
    for (int i = 0; i < mSize; i++) {
        mElems[i] = src.mElems[i];
    }
}

template <typename T>
void NDGrid<T, 1>::reSize(int newSize)
{
    T* newElems = new T[newSize];

    for (int i = 0; i < newSize && i < mSize; i++) {
        newElems[i] = mElems[i];
    }

    mSize = newSize;
    delete [] mElems;
    mElems = newElems;
}

template <typename T>
NDGrid<T, 1>& NDGrid<T, 1>::operator=(const NDGrid<T, 1>& rhs)
{
    if (this == &rhs) {
        return (*this);
    }

    delete [] mElems;

    copyFrom(rhs);
    return (*this);
}

template <typename T>
T& NDGrid<T, 1>::operator[](int x)
{
    return (mElems[x]);
}

template <typename T>
const T& NDGrid<T, 1>::operator[](int x) const
{
    return (mElems[x]);
}
