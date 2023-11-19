//
// Created by Cristi on 11/19/2023.
//

#include "Player.h"

/*void Player::setName(const char *newName) {
    strncpy(name, newName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}*/

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "Nume: " << player.name << ", Scor: " << player.score;
    return os;
}

Player::Player(const char *playerName, int playerScore) : score(playerScore) {
    strncpy(name, playerName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

/*char *Player::getNume() {
    return name;
}*/
