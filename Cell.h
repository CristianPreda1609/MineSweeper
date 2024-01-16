//
// Created by Cristi on 10/23/2023.
//

#ifndef OOP_CELL_H
#define OOP_CELL_H

#include <iostream>
#include <algorithm>

class Cell {
private:
    int nr_mine;
    bool isPressed, isMine, beModified;
    friend std::ostream &operator<<(std::ostream &os, const Cell &cell);

public:

    Cell( bool isPressed, bool isMine, int nr_mine, bool beModified);

    Cell(const Cell &other);

    virtual ~Cell() = default;
    friend void swap(Cell& first, Cell& second) noexcept;

    Cell& operator=(const Cell& other);

    //void Flag();

    //void notFlag();

    //void setMine();

    void setNrMines(const int &NrMines);

    [[nodiscard]] virtual bool Press() const;

    virtual void pressCell();

    [[nodiscard]] virtual bool Mine() const;

    [[nodiscard]]  int nrMine() const;

    void modify(bool a);

    [[nodiscard]] bool canBeModified() const;



};

#endif //OOP_CELL_H
