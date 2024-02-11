//
// Created by Cristi on 2/10/2024.
//
#include "ResetMineCell.h"
#include "MineCell.h"
#include "Cell.h"
#include "MinesweeperGame.h"
#include "CellFactory.h"


Cell *CellFactory::createCell(int nr_mine) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> ran(1, nr_mine);


    int rand = ran(gen);

    if (rand < nr_mine)
        return (new ResetMineCell);
    else return (new MineCell);
}