//
// Created by Cristi on 10/23/2023.
//

#ifndef OOP_CELL_H
#define OOP_CELL_H
#include <ostream>

class Cell{
private:
    int nr_mine{};
    bool isFlagged, isPressed, isMine, isUncovered;
public:
    Cell(bool isFlagged, bool isPressed, bool isMine, bool isUncovered, int nr_mine)
            : nr_mine(nr_mine), isFlagged(isFlagged), isPressed(isPressed), isMine(isMine), isUncovered(isUncovered) {
    }
    Cell(const Cell& other): nr_mine{other.nr_mine}, isFlagged{other.isFlagged}, isPressed{other.isPressed}, isMine{other.isMine}, isUncovered{other.isUncovered}{}
    Cell& operator=(const Cell& other){
        isFlagged = other.isFlagged;
        isPressed = other.isPressed;
        isMine = other.isMine;
        isUncovered = other.isUncovered;
        nr_mine = other.nr_mine;
        return *this;
    }
    ~Cell() = default;
    friend std::ostream& operator<<(std::ostream& os, const Cell& cell) {
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
    void Flag(){
        isFlagged = true;
    }
    void notFlag(){
        isFlagged = false;
    }
    void setMine(){
        isMine = true;
    }
    void setNrMines( int& _nr){
        nr_mine = _nr;
    }
    [[nodiscard]] bool Press() const{
        return isPressed;
    }
    void uncoverCell(){
        isUncovered = true;
    }
    void pressCell(){
        uncoverCell();
        isPressed = true;

    }
    bool Mine(){
        return isMine;
    }
    [[nodiscard]] int nrMine() const{
        return nr_mine;
    }


};

#endif //OOP_CELL_H
