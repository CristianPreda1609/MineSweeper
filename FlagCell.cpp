//
// Created by Cristi on 12/22/2023.
//

#include "FlagCell.h"
std::ostream &operator<<(std::ostream &os, [[maybe_unused]] const FlagCell &flagcell) {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
#else
    cout << "\033[1;31mText rosu\033[0m" << endl;
#endif

    os << "?" ;

#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#endif


        return os;
}

FlagCell::FlagCell(bool isMine, int nr_mine, bool beModified) : Cell(false, isMine,0, false), isMine(isMine), beModified(beModified), nr_mine(nr_mine){}

void swap(FlagCell &first, FlagCell &other) {
    std::swap(first.isMine, other.isMine);
    std::swap(first.isFlagged, other.isFlagged);
    std::swap(first.nr_mine, other.nr_mine);
}

FlagCell &FlagCell::operator=(const FlagCell &other) {
    if (this != &other) {
        static_cast<Cell&>(*this) = static_cast<const Cell&>(other);
        isMine = other.isMine;
        isFlagged = other.isFlagged;
        nr_mine = other.nr_mine;
    }
    return *this;
}

