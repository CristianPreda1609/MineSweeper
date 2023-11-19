//
// Created by Cristi on 10/23/2023.
//

#ifndef OOP_MINESWEEPERGAME_H
#define OOP_MINESWEEPERGAME_H

#include <iostream>
#include <vector>
#include "Cell.h"
#include <random>
#include "rlutil.h"


class MinesweeperGame {
private:
    int row;
    int col;
    int Mines;
    std::vector<std::vector<Cell>> table;
    bool gameOver;

    void revealZeroAdjacentCells(int r, int c);

    void isMine(int r, int c);

    friend std::ostream &operator<<(std::ostream &os, const MinesweeperGame &game);


public:
    MinesweeperGame(int row_, int col_, int Mines_);

    ~MinesweeperGame() = default;

    void placeMines();

    void pressCell(int r, int c);

    int countNearbyMines();

    [[nodiscard]] bool getSit() const;

    //void print_mines();

    void startCell(int r, int c, int ran);
};

#endif //OOP_MINESWEEPERGAME_H
