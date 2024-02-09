#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "MinesweeperGame.h"
#include <rlutil.h>
#include <string>
#include "ExceptionRC.h"
#include "ExceptionData.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif


void startGame() {
    std::string nume;
    do {
        std::cout
                << "Alege Numele(maxim 30 caractere):";

        std::cin >> nume;
    } while (nume.size() > 31);
    rlutil::cls();
    std::cout << "Numele si scorul tau sunt: " << nume << " 0 ";
    std::cout << "\n";
    std::cout
            << "Salut " << nume
            << "\nAlege Nivelul:\n 1.Incepator (Matrice 9x9 cu 10 mine) \n 2.Intermediar (Matrice 16x16 cu 40 de mine)\n 3.Expert (Matrice 16x30 cu 99 de mine)\r\n";
    int cho;
    std::cin >> cho;
    if (cho < 1 || cho > 3) {
        throw ExceptionData();
    }
    int row = 0;
    int col = 0;
    int mines = 0;
    switch (cho) {
        case 1: {
            row = 10;
            col = 10;
            mines = 10;
            break;
        }
        case 2: {
            row = 17;
            col = 17;
            mines = 40;
            break;
        }
        case 3: {
            row = 17;
            col = 31;
            mines = 99;
            break;
        }
        default : {
            std::cout << "Valoare incorecta!";
            break;
        }
    }
    try {
        MinesweeperGame game(row, col, mines, nume);

        std::cout << game;
        std::cout << "\r\n ";

        try {
            std::cout
                    << "Introduceti coordonatele patratului pe care vreti sa il apasati(Rand si apoi coloana) sau -1 -1 pentru a iesi:";
            int r, c;
            std::cin >> r >> c;
            if (r < -1 || r == 0 || r > row) {
                if (c < -1 || c == 0 || c > col)
                    throw ExceptionRC();
            }
            if (r == -1 && c == -1) {
                std::cout << "\n Ati iesit \n";
            }
            if (!(r < 0 || c < 0)) {

                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<int> rann(4, 10);
                int ran = rann(gen);
                game.startCell(r, c, ran);
                game.placeMines();
                game.countNearbyMines();
                game.pressCell(r, c);

            }
        } catch (ExceptionRC &e) {
            std::cerr << "Eroare :" << e.what() << std::endl;
        }
        while (true) {
            rlutil::cls();
            game.afisarePlayer();
            int numb;
            std::cout << game;
            std::cout << "\r";
            std::cout << "\r";
            std::cout << "\r\n";
            std::cout
                    << "Introduceti 1 daca dorit sa apasati o celula, 2 daca doriti sa puneti un steag pe celula sau 3 pentru a lua steagul de pe o celula: ";
            std::cin >> numb;
            try {
                int r, c;
                if (numb == 1) {
                    std::cout
                            << "Introduceti coordonatele patratului pe care vreti sa il apasati(Rand si apoi coloana) sau -1 -1 pentru a iesi:";
                    std::cin >> r >> c;
                    if (r < -1 || r == 0 || r > row) {
                        if (c < -1 || c == 0 || c > col)
                            throw ExceptionRC();
                    }

                    if (r == -1 && c == -1) {
                        std::cout << "\n Ati iesit \n";
                        break;
                    }
                    if (!(r < 0 || c < 0)) {
                        bool a;
                        a = game.pressCell(r, c);
                        if (a)
                            break;
                        std::cout << game;
                    }
                } else if (numb == 2) {
                    std::cout
                            << "Introduceti coordonatele patratului pe care vreti sa puneti un steag(Rand si apoi coloana) sau -1 -1 pentru a iesi:";
                    std::cin >> r >> c;
                    if (r == -1 && c == -1) {
                        std::cout << "\n Ati iesit \n";
                        break;
                    }
                    if (!(r < 0 || c < 0)) {

                        game.flagg(r, c);

                    }
                } else if (numb == 3) {
                    std::cout
                            << "Introduceti coordonatele patratului pe care vreti sa puneti un steag(Rand si apoi coloana) sau -1 -1 pentru a iesi:";
                    std::cin >> r >> c;
                    if (r == -1 && c == -1) {
                        std::cout << "\n Ati iesit \n";
                        break;
                    }
                    if (!(r < 0 || c < 0)) {

                        game.unflag(r, c);

                    }
                }
            } catch (ExceptionRC &e) {
                std::cerr << "Eroare :" << e.what() << std::endl;
            }
        }


    } catch (ExceptionTable &e) {
        std::cerr << "Eroare : " << e.what() << std::endl;
    }
}


int main() {
#ifdef __linux__
    XInitThreads();
#endif
    /*  Create the main window
    sf::Window window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }*/

    startGame();


    return 0;
}