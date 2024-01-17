//
// Created by Cristi on 1/16/2024.
//

#ifndef OOP_RESETMINECELL_H
#define OOP_RESETMINECELL_H
#include "Cell.h"
#include <random>
#include <iostream>

class ResetMineCell: public Cell {
private:
    bool isPressed, isMine{};
    int nr_mine;
    static std::random_device rd;
    static std::mt19937 gen;
    friend std::ostream &operator<<(std::ostream &os, const ResetMineCell &minecell);
public:
    ResetMineCell();
    ~ResetMineCell() override = default;

    [[nodiscard]] bool Press() const override;
    void pressCell()  override;
    [[nodiscard]] bool Mine() const override;
    ResetMineCell& operator=(const ResetMineCell& other);
    friend void swap(ResetMineCell &first, ResetMineCell &second) noexcept;
    void setNrMines(const int &NrMines) override;
    [[nodiscard]]  int nrMine() const override;
    static int genrandmine();
    static int genrandnr();

};


#endif //OOP_RESETMINECELL_H
