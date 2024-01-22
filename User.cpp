//
// Created by Cristi on 12/22/2023.
//

#include "User.h"

#include <utility>

std::ostream &operator<<(std::ostream &os, const User &user) {
    os<< "Nume : " << user.name << "Scor : "<< user.score<<"\n";
    return os;
}
/*std::string User::getName() const {
    return name;
}


void User::setScore(const int scor) {
    score = scor;
}
void User::setName(const std::string &newName) {
    name = newName;
}
*/
/*int User::getScore() {
    return score;
}*/
User::User(std::string playerName, int  r, int c) : name{std::move(playerName)}, score{0}, r(r), c(c){}

void User::calculateScore(int coef) {
    score += coef*r*c;
}
