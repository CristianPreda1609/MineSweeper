//
// Created by Cristi on 11/3/2023.
//

#include "MinesweeperGame.h"
#include "ResetMineCell.h"
#include "MineCell.h"
#include "FlagCell.h"
#include "CellFactory.h"



MinesweeperGame::MinesweeperGame(const int row_, const int col_, int Mines_, const std::string& nume)
        : row{row_}, col{col_}, Mines{Mines_}, player(nume, row, col),
          gameWon(false), table(row_) {

    for (int r = 0; r < row; r++) {
        table.emplace_back();
        for (int c = 0; c < col; c++) {
            table[r].push_back(new Cell(false, false, 0, true));
            if (table[r][c] == nullptr)
                throw ExceptionTable();
        }
    }

    for (int c = 0; c < col; c++) {
        delete table[0][c];
        table[0][c] = new Cell(true, false, c, true);
        if (table[0][c] == nullptr)
            throw ExceptionTable();
    }
    for (int r = 0; r < row; r++) {
        delete table[r][0];
        table[r][0] = new Cell(true, false, r, true);
        if (table[r][0] == nullptr)
            throw ExceptionTable();
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

        if (!table[randomRow][randomCol]->Mine() && table[randomRow][randomCol]->canBeModified()) {

                delete table[randomRow][randomCol];
            table[randomRow][randomCol] = CellFactory::createCell(Mines);
        } else {
            --i;
        }
    }
}


bool MinesweeperGame::pressCell(int r, int c) {
    if (table[r][c]->Press())
        return false;
    isCell0();
    bool a = false;

    player.calculateScore(table[r][c]->returnScore());
    writePlayer();

    if (!table[r][c]->returnGamesit().empty()) {
        std::cout << table[r][c]->returnGamesit();
        a = true;
    } else if (isgameWon()) {
        std::cout << "GAME WON";
        a = isgameWon();
    } else {
        table[r][c]->pressCell(*this, r, c);
    }

    // revealZeroAdjacentCells(r, c);
    return a;

}


std::ostream &operator<<(std::ostream &os, const MinesweeperGame &game) {
    for (int r = 0; r < game.row; r++) {
        for (int c = 0; c < game.col; c++) {
            os << *(game.table[r][c]);
        }
        os << "\n";
    }
    return os;
}

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
                    if (table[newRow][newCol]->Mine()) {
                        nearbyMines++;
                    }
                }

            }
            table[r][c]->setNrMines(nearbyMines);
        }
    }

    return nearbyMines;
}

void MinesweeperGame::startCell(int r, int c, int ran) {
    if (ran <= 0 || r < 1 || r > row || c < 1 || c > col || !table[r][c]->canBeModified()) {
        return;
    }

    table[r][c]->modify(false);

    int offsets[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int i = 0; i < 8; ++i) {
        int randRow = r + offsets[i][0];
        int randCol = c + offsets[i][1];


        if (ran > 1) {
            startCell(randRow, randCol, ran - 1);
        }
    }
}


void MinesweeperGame::afisarePlayer() {
    std::cout<<player;
}



bool MinesweeperGame::isgameWon() const {
    return gameWon;
}

void MinesweeperGame::isCell0() {
    int count = 0;

    for (int r = 1; r < row; r++) {
        for (int c = 1; c < col; c++) {

            if(table[r][c]->Mine())
                count++;
        }
    }
    if(count == row*col-Mines )
        gameWon = true;
}

void MinesweeperGame::flagg(int r, int c) {
    int nr_mine;
    bool ismine;
    nr_mine = table[r][c]->nrMine();
    ismine = table[r][c]->Mine();
    delete table[r][c];
    table[r][c] = new FlagCell(ismine,nr_mine);
}

void MinesweeperGame::unflag(int r, int c) {
    int nr_mine;
    bool ismine;
    nr_mine = table[r][c]->nrMine();
    ismine = table[r][c]->Mine();
    delete table[r][c];
    table[r][c] = new Cell(false, ismine, nr_mine, true);
}

int MinesweeperGame::getRow() const {
    return row;
}

int MinesweeperGame::getCol() const {
    return col;
}


