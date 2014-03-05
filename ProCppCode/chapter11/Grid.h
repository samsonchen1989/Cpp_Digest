//start with __GRID_H__ is a bad practise, see
//explanation in http://goo.gl/ZfpKR6
#ifndef GRID_H
#define GRID_H

template <typename T>
class Grid
{
public:
    Grid(int inWidth = kDefaultWidth, int inHeight = kDefaultHeight);
    Grid(const Grid<T>& src);

    //use another Grid type, e.g.
    //construct int grid from double grid
    template <typename E>
    Grid(const Grid<E>& src);

    virtual ~Grid();
    Grid<T>& operator=(const Grid<T>& rhs);
    template <typename E>
    Grid<T>& operator=(const Grid<E>& rhs);

    void setElementAt(int x, int y, const T& inElem);
    T& getElementAt(int x, int y);
    const T& getElementAt(int x, int y) const;

    int getHeight() const { return mHeight; }
    int getWidth() const { return mWidth; }

    static const int kDefaultWidth = 10;
    static const int kDefaultHeight = 10;

protected:
    void copyFrom(const Grid<T>& src);
    template <typename E>
    void copyFrom(const Grid<E>& src);

    T** mCells;
    int mWidth;
    int mHeight;
};

//include template definition in header file
//so that the translation unit can use it
#include "Grid.tpp"

#endif 