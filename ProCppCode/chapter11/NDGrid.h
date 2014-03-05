#ifndef NDGRID_H
#define NDGRID_H

template <typename T, int N>
class NDGrid
{
public:
    NDGrid();
    NDGrid(int inSize);
    NDGrid(const NDGrid<T, N>& src);
    ~NDGrid();

    NDGrid<T, N>& operator=(const NDGrid<T, N>& rhs);
    NDGrid<T, N - 1>& operator[](int x);
    const NDGrid<T, N - 1>& operator[](int x) const;

    void reSize(int newSize);
    int getSize() const { return mSize; }

    static const int kDefaultSize = 10;

protected:
    void copyFrom(const NDGrid<T, N>& src);
    NDGrid<T, N - 1>* mElems;
    int mSize;
};

template <typename T>
class NDGrid<T, 1>
{
public:
    NDGrid(int inSize = kDefaultSize);
    NDGrid(const NDGrid<T, 1>& src);
    ~NDGrid();
    NDGrid<T, 1>& operator=(const NDGrid<T, 1>& rhs);
    void reSize(int newSize);
    T& operator[](int x);
    const T& operator[](int x) const;

    int getSize() const { return mSize; }
    static const int kDefaultSize = 10;

protected:
    void copyFrom(const NDGrid<T, 1>& src);
    T* mElems;
    int mSize;
};

#include "NDGrid.tpp"

#endif
