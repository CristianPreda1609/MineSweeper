//
// Created by Cristi on 10/23/2023.
//

#ifndef OOP_MINESWEEPERGAME_H
#define OOP_MINESWEEPERGAME_H
#include <iostream>
#include <vector>
#include "Cell.h"
#include <random>

void clearConsole() {
#ifdef _WIN32
    // Windows
    system("cls");
#elif defined __APPLE__ || defined __MACH__ || defined __linux__
    // macOS, Linux
    system("clear");
#endif
}

class MinesweeperGame {
private:
    int row;
    int col;
    int Mines;
    std::vector<std::vector<Cell>> table;
    bool gameOver;

public:
    MinesweeperGame(const int row_, const int col_,  int Mines_)
        : row{row_}, col{col_}, Mines{Mines_}, table(row_ + 2, std::vector<Cell>(col_ + 2, Cell(false, false, false, false, 0))), gameOver(false){
        for (int c = 1; c < col+2; c++) {
            table[0][c] = Cell(false,false, false, false, c-1);
        }


        for (int r = 1; r < row+2; r++) {
            table[r][0] = Cell(false, false, false, false, r-1);
        }

    }

    void placeMines() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> rowDist(1, row + 1);
        std::uniform_int_distribution<int> colDist(1, col + 1);

        for (int i = 0; i < Mines; ++i) {
            int randomRow = rowDist(gen);
            int randomCol = colDist(gen);

            if (!table[randomRow][randomCol].Mine()) {
                int nr = 100;
                table[randomRow][randomCol].setMine();
                table[randomRow][randomCol].setNrMines(nr);
            } else {

                --i;
            }
        }
    }

    void revealZeroAdjacentCells(int r, int c) {
        if (r < 1 || r > row + 1 || c < 1 || c > col + 1 || table[r][c].Press()) {
            return;
        }
        if(table[r][c].nrMine() < 100)
            table[r][c].pressCell();

        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                revealZeroAdjacentCells(r + dr, c + dc);
            }
        }
    }

    void pressCell(int r, int c){
        if(table[r+1][c+1].Press()){
            return;
        }

        table[r+1][c+1].pressCell();
        isMine(r+1,c+1);

        if (table[r][c].nrMine() == 0) {
            revealZeroAdjacentCells(r, c);
        }
    }

    void isMine(int r, int c){
        if(table[r][c].Mine())
            gameOver = true;
    }

    bool getSit() const{
        return gameOver;
    }

    void startGame();

    friend std::ostream& operator<<(std::ostream& os, const MinesweeperGame& game) {
        for (int r = 0; r < game.row+2; r++) {
            for (int c = 0; c < game.col+2; c++) {
                if(r != 0 && c != 0){
                    if(game.table[r][c].Press()){
                        os << game.table[r][c].nrMine() << " ";
                    }
                    else
                        os <<"? ";
                }
                else
                    os << game.table[r][c].nrMine() << " ";
            }
            os << std::endl;
        }
        return os;
    }

    void print_mines(){
        for (int r = 0; r < row+2; r++) {
            for (int c = 0; c < col+2; c++) {

                std::cout << table[r][c].Mine() << " ";
            }
            std::cout << std::endl;
        }
    }

    int countNearbyMines() {
        int r, c;
        int nearbyMines = 0;

        for(r = 1; r < row + 2; ++r) {
            for(c = 1; c < col + 2; ++c) {
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

};
void startGame(){

    std::cout<<"Alege Nivelul:\r\n 1.Incepator (Matrice 9x9 cu 10 mine) \r\n 2.Intermediar (Matrice 16x16 cu 40 de mine)\r\n 3.Expert (Matrice 16x30 cu 99 de mine)\r\n";
    int cho, r, c;
    std::cin>>cho;
    MinesweeperGame game(0,0,0);

    switch (cho) {
        case 1: {
            game = MinesweeperGame(9, 9, 10);
            break;
        }
        case 2: {
            game = MinesweeperGame(16, 16, 40);
            break;
        }
        case 3: {
            game = MinesweeperGame(16, 30, 99);
            break;
        }
    }
    game.placeMines();
    game.countNearbyMines();
    while(true) {
        clearConsole();
        std::cout << game;
        std::cout << "\r\n";
        std::cout
                << "Introduceti coordonatele patratului pe care vreti sa il apasati(Rand si apoi coloana) sau -1 -1 pentru a iesi:";
        std::cin >> r >> c;
        if (r == -1 && c == -1) {
            std::cout << "\n Ati iesit \n";
            break;
        }
        if(!(r < 0 || c <0)) {
            game.pressCell(r, c);
            if(game.getSit()){
                std::cout << "\n Game Over \n";
                break;
            }
            std::cout << game;
        }
    }


}
#endif //OOP_MINESWEEPERGAME_H
