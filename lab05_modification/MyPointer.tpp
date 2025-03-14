//
// Created by Malwina Juchiewicz on 09/01/2024.
//

#ifndef LAB05_MODIFICATION_MYPOINTER_TPP
#define LAB05_MODIFICATION_MYPOINTER_TPP
#include "MyPointer.hpp"

template <typename T>
MyPointer<T>::MyPointer(T* pointer)
{
    smartPointer = pointer;
    refCounter = new RefCounter();
    refCounter->add();
}

template <typename T>
MyPointer<T>::MyPointer()
{
    smartPointer = nullptr;
    refCounter = new RefCounter();
    refCounter->add();
}


template <typename T>
MyPointer<T>::MyPointer(const MyPointer &other)
{
    smartPointer = other.smartPointer;
    refCounter = other.refCounter;
    refCounter->add();
}


template <typename T>
MyPointer<T>::~MyPointer()
{
    if (refCounter->dec() == 0) {
        delete smartPointer;
        delete refCounter;
    }
}


template <typename T>
MyPointer<T> &MyPointer<T>::operator=(const MyPointer &pcOther)
{
    if (this != &pcOther)
    {
        if (refCounter->dec() == 0) {
            delete smartPointer;
            delete refCounter;
        }

        smartPointer = pcOther.smartPointer;
        refCounter = pcOther.refCounter;
        refCounter->add();
    }
    return *this;
}


template <typename T>
T &MyPointer<T>::operator*() {
    return *smartPointer;
}


template <typename T>
T *MyPointer<T>::operator->() {
    return smartPointer;
}


template <typename T>
int MyPointer<T>::getRefCount() const {
    return refCounter->get();
}

template <typename T>
T* MyPointer<T>::get() const {
    return smartPointer;
}




#endif //LAB05_MODIFICATION_MYPOINTER_TPP
