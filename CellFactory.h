//
// Created by Cristi on 2/10/2024.
//

#ifndef OOP_CELLFACTORY_H
#define OOP_CELLFACTORY_H

#include "Cell.h"
#include <random>

class MinesweeperGame;

class CellFactory {


public:
    explicit CellFactory() {};

    static Cell *createCell(int nr_mine);

};


#endif //OOP_CELLFACTORY_H
