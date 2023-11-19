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
#include "Player.h"


class MinesweeperGame {
private:
    int row;
    int col;
    int Mines;
    std::vector<std::vector<Cell>> table;
    Player player;
    bool gameOver;

    void revealZeroAdjacentCells(int r, int c);

    void isMine(int r, int c);

    friend std::ostream &operator<<(std::ostream &os, const MinesweeperGame &game);


public:
    MinesweeperGame(int row_, int col_, int Mines_, const std::string& nume, int scor);

    ~MinesweeperGame() = default;

    void placeMines();

    void pressCell(int r, int c);

    int countNearbyMines();

    [[nodiscard]] bool getSit() const;

    //void print_mines();

    void startCell(int r, int c, int ran);

    //void setName2(const std::string& newName);

    [[nodiscard]] std::string getName2() const;

    //void setScore2(const int scor);

    //int getScore2();

    void afisarePlayer();
};

#endif //OOP_MINESWEEPERGAME_H
