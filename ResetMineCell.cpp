//
// Created by Cristi on 1/16/2024.
//


#include "ResetMineCell.h"
#include "MinesweeperGame.h"
std::random_device ResetMineCell::rd;
std::mt19937 ResetMineCell::gen(ResetMineCell::rd());
std::ostream &operator<<(std::ostream &os, [[maybe_unused]] const ResetMineCell &minecell) {
    minecell.print();
    return os;
}

ResetMineCell:: ResetMineCell(): Cell(false, true, 0, true), isPressed(false), isMine(true),nr_mine(0){}

bool ResetMineCell::Press() const {
    return isPressed;
}

void ResetMineCell::pressCell(MinesweeperGame &obj, int r, int c) {
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

bool ResetMineCell::Mine() const {
   return genrandmine();
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
    nr_mine = genrandnr();
}
int ResetMineCell::nrMine() const {

    return nr_mine;
}
int ResetMineCell::genrandmine() {

    std::uniform_int_distribution<int> rand(0, 1 );
    return rand(gen);
}

int ResetMineCell::genrandnr() {

    std::uniform_int_distribution<int> rand(4, 8 );
    return rand(gen);
}

std::string ResetMineCell::returnGamesit() {
    if(genrandmine()){
        return "GAME OVER";
    }
    else return "";
}

int ResetMineCell::returnScore() const {
    if(genrandmine()) {
        std::uniform_int_distribution<int> rand(-9999, -10);
        return rand(gen);
    }
    else{
        std::uniform_int_distribution<int> rand(101, 9999 );
        return rand(gen);
    }
}

void ResetMineCell::print() const {
    if (isPressed)
        std::cout << nr_mine << " ";

    else std::cout << "? ";
}
