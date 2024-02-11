//
// Created by Cristi on 2/11/2024.
//

#ifndef OOP_TEMPLATE_PAIRS_H
#define OOP_TEMPLATE_PAIRS_H


template<typename T1, typename T2>
class Template_Pairs {
private:
    T1 first;
    T2 second;

public:
    Template_Pairs(const T1 f, const T2 s) : first(f), second(s) {}

    T1 getFirst() const {
        return first;
    }

    T2 getSecond() const {
        return second;
    }

    /*void setFirst(T1 first) {
        Template_Pairs::first = first;
    }

    void setSecond(T2 second) {
        Template_Pairs::second = second;
    }*/
};


#endif //OOP_TEMPLATE_PAIRS_H
