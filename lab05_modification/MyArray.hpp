#include <iostream>
#include "MyPointer.hpp"

template <typename T>

class MyArray {
private:
    MyPointer<T> data;
    size_t arraySize;

public:

    MyArray(size_t size) : arraySize(size), data(new T[size]) {}

    MyArray(MyArray<T> & array) = default;
    MyArray(MyArray<T> && array) = default;
    ~MyArray() = default;

    size_t size() const {
        return arraySize;
    }

    T& operator[](size_t index) {
        return data.get()[index];
    }


    MyArray& operator=(const MyArray& other) {
        if (this != &other) {
            arraySize = other.arraySize;
            data = other.data;
        }
        return *this;
    }

    MyArray& operator=(MyArray&& other) noexcept {
        if (this != &other) {
            arraySize = std::move(other.arraySize);
            data = std::move(other.data);
        }
        return *this;
    }

};








