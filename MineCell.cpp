//
// Created by Cristi on 12/22/2023.
//

#include "MineCell.h"

std::ostream &operator<<(std::ostream &os, const MineCell &minecell) {
            os << "*";

    return os;
}

MineCell::MineCell(bool isPressed, bool isMine) : Cell( false, true, 0, true), isPressed(false), isMine(true) {}

bool MineCell::Press() const {
    return isPressed;
}

void MineCell::pressCell() {
    isPressed = true;
}

bool MineCell::Mine() const {
    return true;
}

MineCell::MineCell(const MineCell &other) : isPressed(other.isPressed), Cell(other){}

MineCell &MineCell::operator=(const MineCell &other) {
    if (this != &other) {
        static_cast<Cell &>(*this) = static_cast<const Cell &>(other);
        isPressed = other.isPressed;
        isMine = other.isMine;
    }
    return *this;
}

