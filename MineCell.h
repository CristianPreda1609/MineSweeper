//
// Created by Cristi on 12/22/2023.
//

#ifndef OOP_MINECELL_H
#define OOP_MINECELL_H
#include "Cell.h"


class MineCell : public Cell{
private:
    bool isPressed, isMine{};
    friend std::ostream &operator<<(std::ostream &os, const MineCell &minecell);
public:
    MineCell();

    ~MineCell() override = default;

    [[maybe_unused]] MineCell(const MineCell& other);

    [[nodiscard]] bool Press() const override;

    void pressCell(MinesweeperGame &obj, int r, int c) override;

    [[nodiscard]] bool Mine() const override;
    MineCell& operator=(const MineCell& other);
    friend void swap(MineCell &first, MineCell &second) noexcept;
    std::string returnGamesit() override;
    [[nodiscard]] int returnScore() const override;

    void print() const override {
        if (isPressed)
            std::cout << "* ";
        else std::cout << "? ";
    }
};


#endif //OOP_MINECELL_H
