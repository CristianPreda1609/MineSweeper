//
// Created by Cristi on 11/19/2023.
//

#include "Player.h"

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "Nume: " << player.name << ", Scor: " << player.score;
    return os;
}

Player::Player(const std::string &playerName, int playerScore) : name(playerName), score(playerScore) {}

/*void Player::setName(const std::string &newName) {
    name = newName;
}*/

std::string Player::getName() const {
    return name;
}

/*int Player::getScore() {
    return score;
}

void Player::setScore(const int scor) {
    score = scor;
}*/
