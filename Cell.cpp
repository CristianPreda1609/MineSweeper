//
// Created by Cristi on 11/3/2023.
//

#include "Cell.h"
#include "MinesweeperGame.h"
Cell::Cell(bool isPressed, bool isMine, int nr_mine, bool beModified)
        : nr_mine(nr_mine), isPressed(isPressed), isMine(isMine), beModified(beModified) {
}

Cell::Cell(const Cell &other) = default;

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
     if (cell.isPressed) {
        if (!(cell.isMine)) {
            os << cell.nr_mine;

        } else {
            os << "*";
        }
    } else {
        os << "?";
    }
    return os;
}

/*void Cell::Flag() {
    isFlagged = true;
}

void Cell::notFlag() {
    isFlagged = false;
}*/

/*void Cell::setMine() {
    isMine = true;
}*/

void Cell::setNrMines(const int &NrMines) {
    nr_mine = NrMines;
}

bool Cell::Press() const {
    return isPressed;
}


void Cell::pressCell(MinesweeperGame &obj, int r, int c) {

    if (obj.table[r][c]->nrMine() == 0) {
        obj.revealZeroAdjacentCells(r + 1, c + 1);
        obj.revealZeroAdjacentCells(r, c + 1);
        obj.revealZeroAdjacentCells(r, c - 1);
        obj.revealZeroAdjacentCells(r + 1, c);
        obj.revealZeroAdjacentCells(r - 1, c);
        obj.revealZeroAdjacentCells(r - 1, c - 1);
        obj.revealZeroAdjacentCells(r + 1, c - 1);
        obj.revealZeroAdjacentCells(r - 1, c + 1);
    }
    isPressed = true;
}

bool Cell::Mine() const {
    return isMine;
}

  int Cell::nrMine() const {
    return nr_mine;
}

void Cell::modify(bool a) {
    beModified = a;
}
bool Cell::canBeModified() const
{
    return beModified;
}

void swap(Cell &first, Cell &second) noexcept {
    using std::swap;
    std::swap(first.nr_mine, second.nr_mine);
    std::swap(first.isPressed, second.isPressed);
    std::swap(first.isMine, second.isMine);
    std::swap(first.beModified, second.beModified);
}

std::string Cell::returnGamesit() {
    return "";
}

int Cell::returnScore() const {
    return 1;
}

Cell &Cell::operator=(const Cell &other) = default; /*{
    if (this != &other) {
        nr_mine = other.nr_mine;
        isPressed = other.isPressed;
        isMine = other.isMine;
        beModified = other.beModified;
    }
    return *this;
}*/

