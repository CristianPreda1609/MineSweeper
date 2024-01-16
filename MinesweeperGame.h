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
#include "FlagCell.h"
#include "MineCell.h"
#include <type_traits>
#include "ResetMineCell.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif



class MinesweeperGame {
private:
    int row;
    int col;
    int Mines;
    std::vector<std::vector<Cell*>> table;
    Player player;
    bool gameOver;
    bool gameWon;

    void revealZeroAdjacentCells(int r, int c);

    void isMine(int r, int c);

    friend std::ostream &operator<<(std::ostream &os, const MinesweeperGame &game);

    [[nodiscard]] bool getSit() const;

    [[nodiscard]] bool isgameWon() const;

    void isCell0 ();


public:
    MinesweeperGame(int row_, int col_, int Mines_, const std::string& nume, int scor);

    ~MinesweeperGame() = default;

    void placeMines();

    bool pressCell(int r, int c);

    int countNearbyMines();

    void flagg(int r, int c){
        int nr_mine;
        bool ismine;
        nr_mine = table[r][c]->nrMine();
        ismine = table[r][c]->Mine();
        delete table[r][c];
        table[r][c] = new FlagCell(ismine,nr_mine);
    }

    void unflag(int r, int c){
        int nr_mine;
        bool ismine;
        nr_mine = table[r][c]->nrMine();
        ismine = table[r][c]->Mine();
        delete table[r][c];
        table[r][c] = new Cell(false, ismine, nr_mine, true);
    }
    void startCell(int r, int c, int ran);

    //void setName2(const std::string& newName);

    //[[nodiscard]] std::string getName2() const;

    //void setScore2(const int scor);

    //int getScore2();

    //void afisarePlayer();

};

#endif //OOP_MINESWEEPERGAME_H