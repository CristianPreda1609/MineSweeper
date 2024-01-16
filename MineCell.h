//
// Created by Cristi on 12/22/2023.
//

#ifndef OOP_MINECELL_H
#define OOP_MINECELL_H
#include "Cell.h"
#include "MinesweeperGame.h"

class MineCell : public Cell{
private:
    bool isPressed, isMine{};
    friend std::ostream &operator<<(std::ostream &os, const MineCell &minecell);
public:
    MineCell();

    ~MineCell() override = default;

    [[maybe_unused]] MineCell(const MineCell& other);

    [[nodiscard]] bool Press() const override;

    void pressCell()  override;

    [[nodiscard]] bool Mine() const override;
    MineCell& operator=(const MineCell& other);
    friend void swap(MineCell &first, MineCell &second) noexcept;

};


#endif //OOP_MINECELL_H
