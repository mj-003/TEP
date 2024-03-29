//
// Created by Malwina Juchiewicz on 07/01/2024.
//

#ifndef LAB03_V02_REFCOUNTER_H
#define LAB03_V02_REFCOUNTER_H

class RefCounter
{
public:
    RefCounter();
    int add();
    int dec();
    int get() const;

private:
    int refCount;
};

#endif //LAB03_V02_REFCOUNTER_H
