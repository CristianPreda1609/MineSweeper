//
// Created by Cristi on 1/16/2024.
//

#include "ResetMineCell.h"
std::ostream &operator<<(std::ostream &os, [[maybe_unused]] const ResetMineCell &minecell) {
    os << "*";

    return os;
}

ResetMineCell:: ResetMineCell(): Cell(false, true, 0, true), isPressed(false), isMine(true),nr_mine(0){}

bool ResetMineCell::Press() const {
    return isPressed;
}
void ResetMineCell::pressCell() {
    isPressed = true;

}

bool ResetMineCell::Mine() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> rand(0, 1 );
    int randd = rand(gen);
   return randd;
}
ResetMineCell &ResetMineCell::operator=(const ResetMineCell &other) {
    if (this != &other) {
        static_cast<Cell &>(*this) = static_cast<const Cell &>(other);
        isPressed = other.isPressed;
        isMine = other.isMine;
    }
    return *this;
}

void swap(ResetMineCell &first, ResetMineCell &second) noexcept {
    using std::swap;
    swap(first.isPressed, second.isPressed);
    swap(first.isMine, second.isMine);
    swap(static_cast<Cell&>(first), static_cast<Cell&>(second));
}
void ResetMineCell::setNrMines(const int &NrMines) {
    nr_mine = NrMines;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> rand(4, 8 );
    nr_mine = rand(gen);
}
int ResetMineCell::nrMine() const {

    return nr_mine;
}