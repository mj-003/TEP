//
// Created by Malwina Juchiewicz on 07/01/2024.
//

#include "RefCounter.h"

#include "RefCounter.h"

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