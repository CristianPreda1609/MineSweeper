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
    cell.print();
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
    if (r < 1 || r >= obj.getRow() || c < 1 || c >= obj.getCol() || obj.getCell(r, c)->Press() ||
        obj.getCell(r, c)->Mine()) {

        return;
    }
    isPressed = true;
    if (obj.getCell(r, c)->nrMine() == 0) {

        if (r + 1 < obj.getRow() && c + 1 < obj.getCol())
            obj.getCell(r + 1, c + 1)->pressCell(obj, r + 1, c + 1);
        if (c + 1 < obj.getCol())
            obj.getCell(r, c + 1)->pressCell(obj, r, c + 1);
        if (c - 1 > 0)
            obj.getCell(r, c - 1)->pressCell(obj, r, c - 1);
        if (r + 1 < obj.getCol())
            obj.getCell(r + 1, c)->pressCell(obj, r + 1, c);
        if (r - 1 > 0)
            obj.getCell(r - 1, c)->pressCell(obj, r - 1, c);
        if (r - 1 > 0 && c - 1 > 0)
            obj.getCell(r - 1, c - 1)->pressCell(obj, r - 1, c - 1);
        if (r + 1 < obj.getRow() && c - 1 > 0)
            obj.getCell(r + 1, c - 1)->pressCell(obj, r + 1, c - 1);
        if (r - 1 > 0 && c + 1 > obj.getCol())
            obj.getCell(r - 1, c + 1)->pressCell(obj, r - 1, c + 1);

    }

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
    swapValues(first.nr_mine, second.nr_mine);
    swapValues(first.isPressed, second.isPressed);
    swapValues(first.isMine, second.isMine);
    swapValues(first.beModified, second.beModified);
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

