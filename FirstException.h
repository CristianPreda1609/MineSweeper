//
// Created by Cristi on 1/15/2024.
//

#ifndef OOP_FIRSTEXCEPTION_H
#define OOP_FIRSTEXCEPTION_H

#include "ExceptionBase.h"


class FirstException : public ExceptionBase {
public:
    [[nodiscard]] const char* first() const noexcept override;
};


#endif //OOP_FIRSTEXCEPTION_H
