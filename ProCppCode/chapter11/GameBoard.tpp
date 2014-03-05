template <typename T>
GameBoard<T>::GameBoard(int inWidth, int inHeight) :
    Grid<T>(inWidth, inHeight) {}

template <typename T>
GameBoard<T>::move(int xSrc, int ySrc, int xDes, int yDest)
{
    this->mCells[xDes][yDest] = this->mCells[xSrc][ySrc];
    this->mCells[xSrc][ySrc] = T();
}