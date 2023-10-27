//
// Created by Cristi on 10/24/2023.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <ostream>
#include <string>

class Player{
private:
    std::string name;
    int score;
    int wins;

public:
   explicit Player(const std::string& name_new)
            : name(name_new), score(0), wins(0) {}

    friend std::ostream& operator<<(std::ostream& os, const Player& player) {
        os << "Player: " << player.name << "\n";
        os << "Score: " << player.score << "\n";
        os << "Won Games: " << player.wins << "\n";
        return os;
    }
 void setScore(int nr){
        score = nr;
    };
 void checkWin() {
     wins++;
 };
};
#endif //OOP_PLAYER_H
