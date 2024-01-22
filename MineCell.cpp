//
// Created by Cristi on 12/22/2023.
//

#include "MineCell.h"

std::ostream &operator<<(std::ostream &os, [[maybe_unused]] const MineCell &minecell) {
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

void swap(MineCell &first, MineCell &second) noexcept {
    using std::swap;
    swap(first.isPressed, second.isPressed);
    swap(first.isMine, second.isMine);
    swap(static_cast<Cell&>(first), static_cast<Cell&>(second));
}

std::string MineCell::returnGamesit() {
    return "GAME OVER";
}

int MineCell::returnScore() const {
    return -20;
}
