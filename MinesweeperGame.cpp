//
// Created by Cristi on 11/3/2023.
//

#include "MinesweeperGame.h"

MinesweeperGame::MinesweeperGame(const int row_, const int col_, int Mines_, const std::string& nume, int scor )
        : row{row_}, col{col_}, Mines{Mines_}, table(row_ , std::vector<Cell>(col_ , Cell(false, false, false, false, 0, true))) ,
          player(nume,scor), gameOver(false) {
    for (int c = 0; c < col ; c++) {
        table[0][c] = Cell(false, false, false, false, c , true);
    }


    for (int r = 0; r < row ; r++) {
        table[r][0] = Cell(false, false, false, false, r , true);
    }

}


void MinesweeperGame::placeMines() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> rowDist(1, row - 1 );
    std::uniform_int_distribution<int> colDist(1, col - 1);

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

    if (r < 1 || r >= row || c < 1 || c >= col || table[r][c].Press() || table[r][c].Mine()) {

        return;
    }

    table[r][c].pressCell();
    if(table[r][c].nrMine() == 0) {
        revealZeroAdjacentCells(r+1, c + 1);
        revealZeroAdjacentCells(r, c + 1);
        revealZeroAdjacentCells(r, c - 1);
        revealZeroAdjacentCells(r + 1, c);
        revealZeroAdjacentCells(r - 1, c);
        revealZeroAdjacentCells(r - 1, c-1);
        revealZeroAdjacentCells(r + 1, c-1);
        revealZeroAdjacentCells(r -1 , c+1);
    }
}



void MinesweeperGame::pressCell(int r, int c) {
    if(table[r][c].Press())
        return;

    isMine(r,c);

        revealZeroAdjacentCells(r,c);
}

void MinesweeperGame::isMine(int r, int c) {
    if (table[r][c].Mine())
        gameOver = true;
}

bool MinesweeperGame::getSit() const {
    return gameOver;
}

std::ostream &operator<<(std::ostream &os, const MinesweeperGame &game) {
    for (int r = 0; r < game.row; r++) {
        for (int c = 0; c < game.col; c++) {
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
    for (int r = 1; r < row; r++) {
        for (int c = 1; c < col; c++) {

            std::cout <<" "<< table[r][c].Mine()<<" ";
        }
        std::cout << std::endl;
    }
}*/

int MinesweeperGame::countNearbyMines() {
    int r, c;
    int nearbyMines = 0;

    for (r = 1; r < row; ++r) {
        for (c = 1; c < col; ++c) {
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

void MinesweeperGame::startCell(int r, int c, int ran) {
    if (ran <= 0 || r < 1 || r > row || c < 1 || c > col || !table[r][c].canBeModified()) {
        return;
    }

    table[r][c].modify(false);

    int offsets[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int i = 0; i < 8; ++i) {
        int randRow = r + offsets[i][0];
        int randCol = c + offsets[i][1];

        // Check if within the range of 6 cells and not modified yet
        if (ran > 1) {
            startCell(randRow, randCol, ran - 1);
        }
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

