//
// Created by Cristi on 2/9/2024.
//

#ifndef OOP_EXCEPTIONTABLE_H
#define OOP_EXCEPTIONTABLE_H

#include "ExceptionBase.h"


class ExceptionTable : public ExceptionBase {
public:
    [[nodiscard]] const char *first() const noexcept override {
        return "Table invalid";
    };
};

#endif //OOP_EXCEPTIONTABLE_H
