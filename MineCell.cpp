//
// Created by Cristi on 12/22/2023.
//

#include "MineCell.h"

std::ostream &operator<<(std::ostream &os, [[maybe_unused]] MineCell &minecell) {
            os << "*";

    return os;
}

MineCell::MineCell() : Cell(false, true, 0, true), isPressed(false), isMine(true) {}

bool MineCell::Press() const {
    return isPressed;
}

void MineCell::pressCell() {
    isPressed = true;
}

bool MineCell::Mine() const {
    return true;
}

[[maybe_unused]] MineCell::MineCell(const MineCell &other) : Cell(other), isPressed(other.isPressed){}

MineCell &MineCell::operator=(const MineCell &other) {
    if (this != &other) {
        static_cast<Cell &>(*this) = static_cast<const Cell &>(other);
        isPressed = other.isPressed;
        isMine = other.isMine;
    }
    return *this;
}

