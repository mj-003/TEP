//
// Created by Malwina Juchiewicz on 09/01/2024.
//

#include "RefCounter.hpp"

RefCounter::RefCounter()
        : refCount(0)
{}

int RefCounter::add() {
    return ++refCount;
}

int RefCounter::dec() {
    return --refCount;
}

int RefCounter::get() const {
    return refCount;
}
