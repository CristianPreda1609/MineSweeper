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
#include <fstream>
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
    bool gameWon;

    void revealZeroAdjacentCells(int r, int c);


    friend std::ostream &operator<<(std::ostream &os, const MinesweeperGame &game);

    [[nodiscard]] bool isgameWon() const;

    void isCell0 ();

public:
    void writePlayer() const {
        std::ofstream outputFile("ScoreTable.txt");

        if (outputFile.is_open()) {
            outputFile << player << std::endl;
            outputFile.close();
        } else {
            std::cerr << "Unable to open file: " << "ScoreTable.txt" << std::endl;
        }
    }

MinesweeperGame(int row_, int col_, int Mines_, const std::string& nume);

    ~MinesweeperGame() = default;

    void placeMines();

    bool pressCell(int r, int c);

    int countNearbyMines();

    void flagg(int r, int c);

    void unflag(int r, int c);

    void startCell(int r, int c, int ran);



    //void setName2(const std::string& newName);

    //[[nodiscard]] std::string getName2() const;

    //void setScore2(const int scor);

    //int getScore2();

    void afisarePlayer();

};

#endif //OOP_MINESWEEPERGAME_H