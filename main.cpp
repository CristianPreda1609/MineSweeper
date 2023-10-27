#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "headers/MinesweeperGame.h"
#include "headers/Player.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif


int main() {
    #ifdef __linux__
    XInitThreads();
    #endif
    startGame();


    return 0;
}
