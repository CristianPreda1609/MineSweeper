//
// Created by Cristi on 12/22/2023.
//

#ifndef OOP_FLAGCELL_H
#define OOP_FLAGCELL_H

#include "Cell.h"
#include <rlutil.h>

class FlagCell : public Cell{
private:
    bool isMine, isFlagged = true;
    int nr_mine;
    friend std::ostream &operator<<(std::ostream &os, const FlagCell &flagcell);
public:
    FlagCell(bool isMine, int nr_mine);
    ~FlagCell() override = default;
    friend void swap(FlagCell& first, FlagCell& other);
    FlagCell& operator=(const FlagCell& other);

    void print() const override {
        rlutil::setColor(rlutil::RED);

        std::cout << "? ";

        rlutil::resetColor();
        rlutil::setColor(rlutil::WHITE);

    }

};


#endif //OOP_FLAGCELL_H
