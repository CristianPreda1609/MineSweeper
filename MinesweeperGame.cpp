//
// Created by Cristi on 11/3/2023.
//

#include "MinesweeperGame.h"

MinesweeperGame::MinesweeperGame(const int row_, const int col_, int Mines_, const std::string& nume, int scor )
        : row{row_}, col{col_}, Mines{Mines_}, table(row_ + 2, std::vector<Cell>(col_ + 2, Cell(false, false, false, false, 0, true))) ,
          player(nume,scor), gameOver(false) {
    for (int c = 1; c < col + 2; c++) {
        table[0][c] = Cell(false, false, false, false, c - 1, true);
    }


    for (int r = 1; r < row + 2; r++) {
        table[r][0] = Cell(false, false, false, false, r - 1, true);
    }

}


void MinesweeperGame::placeMines() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> rowDist(1, row + 1);
    std::uniform_int_distribution<int> colDist(1, col + 1);

    for (int i = 0; i < Mines; ++i) {
        int randomRow = rowDist(gen);
        int randomCol = colDist(gen);

        if (!table[randomRow][randomCol].Mine() && table[randomRow][randomCol].canBeModified()) {
            table[randomRow][randomCol].setMine();
        } else {

            --i;
        }
    }
}

void MinesweeperGame::revealZeroAdjacentCells(int r, int c) {
    if (r < 1 || r > row || c < 1 || c > col || table[r][c].Press()) {
        return;
    }

    if (table[r][c].Mine() == 0 ) {
        table[r][c].pressCell();

        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                revealZeroAdjacentCells(r + dr, c + dc);
            }
        }
    }
}

void MinesweeperGame::pressCell(int r, int c) {
    if (table[r + 1][c + 1].Press()) {
        return;
    }

    table[r + 1][c + 1].pressCell();
    isMine(r + 1, c + 1);

    if (table[r][c].nrMine() == 0) {
        revealZeroAdjacentCells(r, c);
    }
}

void MinesweeperGame::isMine(int r, int c) {
    if (table[r][c].Mine())
        gameOver = true;
}

bool MinesweeperGame::getSit() const {
    return gameOver;
}

std::ostream &operator<<(std::ostream &os, const MinesweeperGame &game) {
    for (int r = 0; r < game.row + 2; r++) {
        for (int c = 0; c < game.col + 2; c++) {
            if (r != 0 && c != 0) {
                if (game.table[r][c].Press()) {
                    os << game.table[r][c].nrMine() << " ";
                } else
                    os << "? ";
            } else
                os << game.table[r][c].nrMine() << " ";
        }
        os << std::endl;
    }
    return os;
}

/*void MinesweeperGame::print_mines() {
    for (int r = 0; r < row + 2; r++) {
        for (int c = 0; c < col + 2; c++) {

            std::cout << table[r][c].Mine();
        }
        std::cout << std::endl;
    }
}*/

int MinesweeperGame::countNearbyMines() {
    int r, c;
    int nearbyMines = 0;

    for (r = 1; r < row + 2; ++r) {
        for (c = 1; c < col + 2; ++c) {
            nearbyMines = 0;

            const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

            for (int dir = 0; dir < 8; ++dir) {

                int newRow = r + dr[dir];
                int newCol = c + dc[dir];

                if (newRow >= 1 && newRow < row && newCol >= 1 && newCol < col) {
                    if (table[newRow][newCol].Mine()) {
                        nearbyMines++;
                    }
                }

            }
            table[r][c].setNrMines(nearbyMines);
        }
    }

    return nearbyMines;
}

void MinesweeperGame::startCell(int r, int c, int ran){
    if (ran <= 0 || r < 1 || r > row || c < 1 || c > col || !table[r][c].canBeModified()) {
        return;
    }

    table[r][c].pressCell();
    table[r][c].modify(false);
    ran--;

    int offsets[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    for (int i = 0; i < 8; ++i) {
        int randRow = r + offsets[i][0];
        int randCol = c + offsets[i][1];

        startCell(randRow, randCol, ran);
    }


}

/*void MinesweeperGame::setName2(const std::string &newName) {
    player.setName(newName);
}*/

std::string MinesweeperGame::getName2() const {
    return player.getName();
}

void MinesweeperGame::afisarePlayer() {
    std::cout<<player;
}

/*int MinesweeperGame::getScore2() {
    return player.getScore();
}*/

/*void MinesweeperGame::setScore2(const int scor) {
    player.setScore(scor);
}*/


