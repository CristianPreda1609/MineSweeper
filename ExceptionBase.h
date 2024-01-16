//
// Created by Cristi on 1/15/2024.
//

#ifndef OOP_EXCEPTIONBASE_H
#define OOP_EXCEPTIONBASE_H

#include <iostream>
#include <exception>
#include <stdexcept>


class ExceptionBase : public std::exception {
public:
    [[nodiscard]] virtual const char* first() const noexcept ;
};

#endif //OOP_EXCEPTIONBASE_H
