//
// Created by Cristi on 11/19/2023.
//

#include "Player.h"


Player::Player( const std::string &playerName, int  r, int c) : User(
        playerName,r,c), name{playerName}, score{0},r(r),c(c) {}
void Player::swap(Player &first, Player &second) noexcept {
    using std::swap;
    swap(static_cast<User&>(first), static_cast<User&>(second));
    swap(first.name, second.name);
    swap(first.score, second.score);
}
std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << player.name << " " << player.score << "\n";
    return os;
}

Player &Player::operator=(Player other) noexcept {
    swap(*this, other);
    return *this;
}
/*int Player::getScore() {
    return score;
}*/

void Player::calculateScore( int coef) {
    if(coef == 1 ){
        score += coef*r*c;
    }else
    if(coef>100){
        score += coef*coef*r;
    }
    else if(coef <= -10 && coef >=-100){
        score /= coef;
        score = abs(score);
    }
    else{
        score -=coef;
    }
}

/*void Player::setName(const std::string &newName) {
    name = newName;
}*/

/*std::string Player::getName() const {
    return name;
}*/

/*

void Player::setScore(const int scor) {
    score = scor;
}*/
