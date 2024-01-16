//
// Created by Cristi on 12/22/2023.
//

#ifndef OOP_USER_H
#define OOP_USER_H
#include <iostream>
#include <string>
#include <fstream>



class User {
private:
     std::string name;
    int score;

   friend std::ostream &operator<<(std::ostream &os, User &user);

public:

    User(std::string  playerName, int playerScore);
    virtual ~User() = default;
    static void swap(User& first, User& second) noexcept {
        using std::swap;
        swap(first.name, second.name);
        swap(first.score, second.score);
    }

    friend std::ostream &operator<<(std::ostream& os,  User& user) {
        os << "Name: " << user.name << ", Score: " << user.score;
        return os;
    }
    User& operator=(User other) noexcept {
        swap(*this, other);
        return *this;
    }
    /*virtual std::string getName() const;
    int getScore();
    void setName(const std::string& newName);
    void setScore(const int scor);*/
};

#endif //OOP_USER_H
