//
// Created by Cristi on 10/23/2023.
//

#ifndef OOP_CELL_H
#define OOP_CELL_H

#include <ostream>

class Cell {
private:
    int nr_mine{};
    bool isFlagged, isPressed, isMine, isUncovered, beModified;
public:
    Cell(bool isFlagged, bool isPressed, bool isMine, bool isUncovered, int nr_mine, bool beModified);

    Cell(const Cell &other);

    Cell &operator=(const Cell &other);

    ~Cell() = default;

    friend std::ostream &operator<<(std::ostream &os, const Cell &cell);

    //void Flag();

    //void notFlag();

    void setMine();

    void setNrMines(const int &NrMines);
    void getisMine();

    [[nodiscard]] bool Press() const;

    void uncoverCell();

    void pressCell();

    bool Mine();

    [[nodiscard]] int nrMine() const;

    void modify(bool a);

    bool canBeModified();


};

#endif //OOP_CELL_H
