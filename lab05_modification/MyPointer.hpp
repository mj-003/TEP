//
// Created by Malwina Juchiewicz on 09/01/2024.
//

#ifndef LAB05_MODIFICATION_MYPOINTER_HPP
#define LAB05_MODIFICATION_MYPOINTER_HPP



#include "RefCounter.hpp"

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
    T* get() const;


private:

    T* smartPointer;
    RefCounter* refCounter;

};


#include "MyPointer.tpp"


#endif //LAB05_MODIFICATION_MYPOINTER_HPP
