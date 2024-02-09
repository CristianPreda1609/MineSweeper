//
// Created by Cristi on 10/23/2023.
//

#ifndef OOP_CELL_H
#define OOP_CELL_H
#include <iostream>
#include <algorithm>

class MinesweeperGame;
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

    virtual void setNrMines(const int &NrMines);

    [[nodiscard]] virtual bool Press() const;

    virtual void pressCell(MinesweeperGame &obj, int r, int c);

    [[nodiscard]] virtual bool Mine() const;

    [[nodiscard]]  virtual int nrMine() const;

    void modify(bool a);

    virtual std::string returnGamesit();

    [[nodiscard]] bool canBeModified() const;

    [[nodiscard]] virtual int returnScore() const;



};

#endif //OOP_CELL_H
