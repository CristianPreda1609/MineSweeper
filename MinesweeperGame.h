//
// Created by Cristi on 10/23/2023.
//

#ifndef OOP_MINESWEEPERGAME_H
#define OOP_MINESWEEPERGAME_H

#include <iostream>
#include <vector>
#include "Cell.h"
#include <random>
#include <rlutil.h>


class MinesweeperGame {
private:
    int row;
    int col;
    int Mines;
    std::vector<std::vector<Cell>> table;
    bool gameOver;


public:
    MinesweeperGame(const int row_, const int col_, int Mines_);

    void placeMines();

    void revealZeroAdjacentCells(int r, int c);

    void pressCell(int r, int c);

    void isMine(int r, int c);

    bool getSit() const;


    friend std::ostream &operator<<(std::ostream &os, const MinesweeperGame &game);

    void print_mines();

    int countNearbyMines();

};

#endif //OOP_MINESWEEPERGAME_H
