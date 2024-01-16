//
// Created by Cristi on 12/22/2023.
//

#include "User.h"

#include <utility>

std::ostream &operator<<(std::ostream &os, User &user) {
    os<< "Nume : " << user.name << "Scor : "<< user.score;
    return os;
}
/*std::string User::getName() const {
    return name;
}

int User::getScore() {
    return score;
}
void User::setScore(const int scor) {
    score = scor;
}
void User::setName(const std::string &newName) {
    name = newName;
}
*/
User::User(std::string playerName, int playerScore) : name{std::move(playerName)}, score{playerScore}{}
