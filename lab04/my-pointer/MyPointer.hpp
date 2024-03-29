//
// Created by Malwina Juchiewicz on 07/01/2024.
//

#ifndef LAB03_V02_MYPOINTER_HPP
#define LAB03_V02_MYPOINTER_HPP

#include "RefCounter.h"

template <typename T>

class MyPointer {
public:

    MyPointer(T* pointer);
    MyPointer();
    MyPointer(const MyPointer& other);
    ~MyPointer();

    MyPointer &operator=(const MyPointer &pcOther);

    T &operator*();
    T *operator->();

    int getRefCount() const;

private:

    T* smartPointer;
    RefCounter* refCounter;

};



#endif //LAB03_V02_MYPOINTER_HPP
