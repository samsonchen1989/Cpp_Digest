#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "Grid.h"

template <typename T>
class GameBoard : public Grid<T>
{
public:
    GameBoard(int inWidth = Grid<T>::kDefaultWidth,
        int inHeight = Grid<T>::kDefaultHeight);
    void move(int xSrc, int ySrc, int xDes, int yDest);
};

#endif