//
// Created by Cristi on 2/11/2024.
//

#ifndef OOP_TEMPLATE_FUNCTIONS_H
#define OOP_TEMPLATE_FUNCTIONS_H


template<typename T>
void swapValues(T &a, T &b);

template<typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

#include "Template_Functions.cpp"


#endif //OOP_TEMPLATE_FUNCTIONS_H
