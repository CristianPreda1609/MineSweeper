#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "MinesweeperGame.h"
#include <rlutil.h>

#ifdef __linux__
#include <X11/Xlib.h>
#endif

void startGame() {

    std::cout
            << "Alege Nivelul:\r\n 1.Incepator (Matrice 9x9 cu 10 mine) \r\n 2.Intermediar (Matrice 16x16 cu 40 de mine)\r\n 3.Expert (Matrice 16x30 cu 99 de mine)\r\n";
    int cho, r, c;
    std::cin >> cho;
    MinesweeperGame game(0, 0, 0);

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
    while (true) {
        rlutil::cls();
        std::cout << game;
        std::cout << "\r\n";
        std::cout
                << "Introduceti coordonatele patratului pe care vreti sa il apasati(Rand si apoi coloana) sau -1 -1 pentru a iesi:";
        std::cin >> r >> c;
        if (r == -1 && c == -1) {
            std::cout << "\n Ati iesit \n";
            break;
        }
        if (!(r < 0 || c < 0)) {
            game.pressCell(r, c);
            if (game.getSit()) {
                std::cout << "\n Game Over \n";
                break;
            }
            std::cout << game;
        }
    }


}


int main() {
    #ifdef __linux__
    XInitThreads();
    #endif
    startGame();


    return 0;
}
