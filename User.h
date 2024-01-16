//
// Created by Cristi on 12/22/2023.
//

#ifndef OOP_USER_H
#define OOP_USER_H
#include <iostream>
#include <string>
#include <fstream>
#include "libsodium/include/sodium.h"



class User {
private:
     std::string name;
    int score;

   friend std::ostream &operator<<(std::ostream &os, User &user);

public:

    User(const std::string& playerName, int playerScore);
    virtual ~User() = default;

    virtual std::string getName() const;
    int getScore();
    void setName(const std::string& newName);
    void setScore(const int scor);
};

#endif //OOP_USER_H
