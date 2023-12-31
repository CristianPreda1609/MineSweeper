#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "MinesweeperGame.h"
#include <rlutil.h>
#include <string>

#ifdef __linux__
#include <X11/Xlib.h>
#endif


void startGame() {
    std::string nume;
    do {
        std::cout
                << "Alege Numele(maxim 30 caractere):";

        std::cin >> nume;
    }while(nume.size()>31);
    rlutil::cls();
    MinesweeperGame game(0, 0, 0, nume, 0);
    std::cout<<"Numele si scorul tau sunt: " ;
    game.afisarePlayer() ;
    std::cout<<"\n";
    std::cout
            << "Salut "<< nume <<"\nAlege Nivelul:\n 1.Incepator (Matrice 9x9 cu 10 mine) \n 2.Intermediar (Matrice 16x16 cu 40 de mine)\n 3.Expert (Matrice 16x30 cu 99 de mine)\r\n";
    int cho, r, c;
    std::cin >> cho;


    switch (cho) {
        case 1: {
            game = MinesweeperGame(10, 10, 10, game.getName2(), 0);
            break;
        }
        case 2: {
            game = MinesweeperGame(17, 17, 40, game.getName2(), 0);
            break;
        }
        case 3: {
            game = MinesweeperGame(17, 31, 99, game.getName2(), 0);
            break;
        }
    }
    std::cout<<game;
    std::cout << "\r\n ";
    std::cout
            << "Introduceti coordonatele patratului pe care vreti sa il apasati(Rand si apoi coloana) sau -1 -1 pentru a iesi:";

    std::cin >> r >> c;
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
        game.pressCell(r,c);

    }
    while (true) {
        rlutil::cls();

        std::cout << game;
        std::cout<<"\r";
        std::cout<<"\r";
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
    /*// Create the main window
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