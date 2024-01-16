//
// Created by Cristi on 11/19/2023.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <iostream>
#include <string>
#include "User.h"

class Player : public User {
private:
    std::string name;
    int score;
    friend std::ostream &operator<<(std::ostream &os, const Player &player);

public:
    Player( const std::string &playerName, int playerScore);
    ~Player() override = default;
    static void swap(Player& first, Player& second) noexcept {
        using std::swap;
        swap(static_cast<User&>(first), static_cast<User&>(second));
        swap(first.name, second.name);
        swap(first.score, second.score);
    }


    friend std::ostream &operator<<(std::ostream &os, const Player &player) {
        os << "Nume: " << player.name << ", Scor: " << player.score;
        return os;
    }

    Player& operator=(Player other) noexcept {
        swap(*this, other);
        return *this;
    }

    //void setName(const std::string& newName);

    //virtual std::string getName() const override;

   // void setScore(const int scor);

   // int getScore();



};
#endif //OOP_PLAYER_H
