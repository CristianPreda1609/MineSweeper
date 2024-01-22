//
// Created by Cristi on 12/22/2023.
//

#ifndef OOP_USER_H
#define OOP_USER_H
#include <iostream>
#include <string>
#include <fstream>
#include <utility>



class User {
private:
     std::string name;
    int score, r,c;

   friend std::ostream &operator<<(std::ostream &os, const User &user);

public:

    explicit User(std::string  playerName,int  r,int c);
    virtual ~User() = default;
    static void swap(User& first, User& second) noexcept {
        using std::swap;
        swap(first.name, second.name);
        swap(first.score, second.score);
    }

    User& operator=(User other) noexcept {
        swap(*this, other);
        return *this;
    }
    virtual void calculateScore( int coef);
    //virtual int getScore();
    /* virtual std::string getName() const;

     void setName(const std::string& newName);
     void setScore(const int scor);*/
};

#endif //OOP_USER_H
