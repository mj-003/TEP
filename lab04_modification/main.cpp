#include <iostream>
#include "Pointer.hpp"

int main() {
    bool* intPtr = new bool(true);
    Pointer<bool*> p(intPtr);

    std::cout << *p << std::endl;

    return 0;
}
