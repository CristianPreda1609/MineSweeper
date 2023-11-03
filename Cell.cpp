//
// Created by Cristi on 11/3/2023.
//

#include "Cell.h"

Cell::Cell(bool isFlagged, bool isPressed, bool isMine, bool isUncovered, int nr_mine)
        : nr_mine(nr_mine), isFlagged(isFlagged), isPressed(isPressed), isMine(isMine), isUncovered(isUncovered) {
}

Cell::Cell(const Cell &other) : nr_mine{other.nr_mine}, isFlagged{other.isFlagged}, isPressed{other.isPressed},
                                isMine{other.isMine}, isUncovered{other.isUncovered} {}

Cell &Cell::operator=(const Cell &other) {
    isFlagged = other.isFlagged;
    isPressed = other.isPressed;
    isMine = other.isMine;
    isUncovered = other.isUncovered;
    nr_mine = other.nr_mine;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    if (cell.isFlagged) {
        os << "F";
    } else if (cell.isPressed) {
        if (cell.isMine) {
            os << "*";
        } else {
            os << cell.nr_mine;
        }
    } else {
        os << ".";
    }
    return os;
}

void Cell::Flag() {
    isFlagged = true;
}

void Cell::notFlag() {
    isFlagged = false;
}

void Cell::setMine() {
    isMine = true;
}

void Cell::setNrMines(const int &NrMines) {
    nr_mine = NrMines;
}

bool Cell::Press() const {
    return isPressed;
}

void Cell::uncoverCell() {
    isUncovered = true;
}

void Cell::pressCell() {
    uncoverCell();
    isPressed = true;

}

bool Cell::Mine() {
    return isMine;
}

int Cell::nrMine() const {
    return nr_mine;
}
