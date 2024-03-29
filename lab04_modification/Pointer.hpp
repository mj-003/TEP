//
// Created by Malwina Juchiewicz on 19/12/2023.
//

#ifndef LAB04_MODIFICATION_POINTER_HPP
#define LAB04_MODIFICATION_POINTER_HPP

template <typename T>
class Pointer;


template <typename T>
class Pointer<T*> {
public:
    Pointer(T* ptr) : data(ptr)
    {}

    T& operator*() {
        return *data;
    }

private:
    T* data;
};

#endif //LAB04_MODIFICATION_POINTER_HPP
