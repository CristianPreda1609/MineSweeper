//
// Created by Cristi on 1/15/2024.
//

#ifndef OOP_SECONDEXCEPTION_H
#define OOP_SECONDEXCEPTION_H

#include "ExceptionBase.h"

class SecondException: public ExceptionBase {
public:
     [[nodiscard]] const char* first() const noexcept override {
        return "Nu respecta cerinta";
    }
};


#endif //OOP_SECONDEXCEPTION_H
