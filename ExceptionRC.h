//
// Created by Cristi on 1/17/2024.
//

#ifndef OOP_EXCEPTIONRC_H
#define OOP_EXCEPTIONRC_H
#include "ExceptionBase.h"

class ExceptionRC : public ExceptionBase {
public:
    [[nodiscard]] const char* first() const noexcept override;
};


#endif //OOP_EXCEPTIONRC_H
