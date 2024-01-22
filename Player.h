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
    int score, r,c ;
    friend std::ostream &operator<<(std::ostream &os, const Player &player);

public:
    explicit Player( const std::string &playerName, int  r,int c);
    ~Player() override = default;
    static void swap(Player& first, Player& second) noexcept;


    friend std::ostream &operator<<(std::ostream &os, const Player &player);

    Player& operator=(Player other) noexcept;

    void calculateScore(int coef) override;
    int getScore() override;
    //void setName(const std::string& newName);

    //virtual std::string getName() const override;

   // void setScore(const int scor);





};




#endif //OOP_PLAYER_H
