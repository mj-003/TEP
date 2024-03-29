//
// Created by Malwina Juchiewicz on 09/01/2024.
//

#ifndef LAB05_MODIFICATION_REFCOUNTER_HPP
#define LAB05_MODIFICATION_REFCOUNTER_HPP


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


#endif //LAB05_MODIFICATION_REFCOUNTER_HPP
