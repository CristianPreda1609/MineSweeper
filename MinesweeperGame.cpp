//
// Created by Cristi on 11/3/2023.
//

#include "MinesweeperGame.h"

MinesweeperGame::MinesweeperGame(const int row_, const int col_, int Mines_, const std::string& nume, int scor )
        : row{row_}, col{col_}, Mines{Mines_}, table(row_),
          player( nume, scor), gameOver(false), gameWon(false) {
    if (Mines > row * col) {
        throw std::invalid_argument("Numarul minelor depaseste marimea tablei");
    }
    for (int r = 0; r < row; r++) {
        table.push_back({});
        for (int c = 0; c < col; c++) {
            table[r].push_back(new Cell(false, false, 0, true));
        }
    }

    for (int c = 1; c < col; c++) {
        table[0][c] =  new Cell(false, false, c, true);
    }
    for (int r = 1; r < row; r++) {
        table[r][0] = new Cell(false, false, r, true);
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
            delete table[randomRow][randomCol] ;
            table[randomRow][randomCol] = new MineCell(false,true);
        } else {
            --i;
        }
    }
}

void MinesweeperGame::revealZeroAdjacentCells(int r, int c) {

    if (r < 1 || r >= row || c < 1 || c >= col || table[r][c]->Press() || table[r][c]->Mine()) {

        return;
    }

    table[r][c]->pressCell();
    if(table[r][c]->nrMine() == 0) {
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



bool MinesweeperGame::pressCell(int r, int c) {
    if(table[r][c]->Press())
        return false;
    isCell0();
    bool a = false;
    isMine(r,c);
    if (getSit()) {
        std::cout << "GAME OVER";
        a = getSit();
    } else if (isgameWon()) {
        std::cout << "GAME WON";
        a = isgameWon();
    } else
        revealZeroAdjacentCells(r, c);
    return a;
}

void MinesweeperGame::isMine(int r, int c) {
    if (table[r][c]->Mine())
        gameOver = true;
}

bool MinesweeperGame::getSit() const {
    return gameOver;
}

std::ostream &operator<<(std::ostream &os, const MinesweeperGame &game) {
    for (int r = 0; r < game.row; r++) {
        for (int c = 0; c < game.col; c++) {
            if (r != 0 && c != 0) {
                if(FlagCell* flagCellPtr = dynamic_cast<FlagCell*>(game.table[r][c]))
                {
                    #ifdef _WIN32
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    #else
                    cout << "\033[1;31mText rosu\033[0m" << endl;
                    #endif

                      os << "? " ;

                    #ifdef _WIN32
                      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    #endif
                }else{
                if (game.table[r][c]->Press()) {
                    os << game.table[r][c]->nrMine() << " ";
                } else
                    os << "? ";
            }} else
                os << game.table[r][c]->nrMine() << " ";

        }
        os << std::endl;
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

/*void MinesweeperGame::setName2(const std::string &newName) {
    player.setName(newName);
}*/

/*std::string MinesweeperGame::getName2() const {
    return player.getName();
}*/

/*void MinesweeperGame::afisarePlayer() {
    std::cout<<player;
}*/



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
    if(count == 0)
        gameWon = true;
}



/*int MinesweeperGame::getScore2() {
    return player.getScore();
}*/

/*void MinesweeperGame::setScore2(const int scor) {
    player.setScore(scor);
}*/

