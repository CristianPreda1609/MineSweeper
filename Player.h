//
// Created by Cristi on 11/19/2023.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int score;
    friend std::ostream &operator<<(std::ostream &os, const Player &player);

public:
    Player(const std::string& playerName, int playerScore);
    ~Player() = default;

    //void setName(const std::string& newName);

    std::string getName() const;

   // void setScore(const int scor);

   // int getScore();



};
#endif //OOP_PLAYER_H
