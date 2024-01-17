//
// Created by Cristi on 1/17/2024.
//

#ifndef OOP_EXCEPTIONDATA_H
#define OOP_EXCEPTIONDATA_H
#include "ExceptionBase.h"

class ExceptionData : public ExceptionBase {
public:
    [[nodiscard]] const char* first() const noexcept override;
};


#endif //OOP_EXCEPTIONDATA_H
