//
// Created by Cristi on 12/22/2023.
//

#ifndef OOP_FLAGCELL_H
#define OOP_FLAGCELL_H

#include "Cell.h"
#include <rlutil.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

class FlagCell : public Cell{
private:
    bool isMine, isFlagged = true, beModified;
    int nr_mine;
    friend std::ostream &operator<<(std::ostream &os, const FlagCell &flagcell);
public:
    FlagCell(bool isMine, int nr_mine, bool beModified);
    ~FlagCell() = default;
    friend void swap(FlagCell& first, FlagCell& other);
    FlagCell& operator=(const FlagCell& other);

};


#endif //OOP_FLAGCELL_H
