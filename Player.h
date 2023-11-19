//
// Created by Cristi on 11/19/2023.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <iostream>
#include <cstring>

class Player {
private:
    int score;
    char name[31];

public:
    Player(const char* playerName, int playerScore);

    ~Player() = default;

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    /*void setName(const char* newName);
    void setScore(const int points ){
        score += points;
    };*/
    //char* getNume();
};

#endif //OOP_PLAYER_H
