#include <iostream>
#include "MyArray.hpp"

int main() {
    MyArray<int> arr(5);

    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = i * i;
    }

    std::cout << "rozmiar: " <<arr.size() << std::endl;

    std::cout << "arr przed zmiana: "<< arr[2] << std::endl;
    arr[2] = 10;
    std::cout << "arr po zmianie: " << arr[2] << std::endl;

    MyArray<int> arr2 (arr);
    MyArray<int> arr3 (std::move(arr));

    std::cout << "arr2[2] (skopiowana arr): "<< arr2[2] << std::endl;
    std::cout << "arr3[2] (przeniesiona arr): "<< arr3[2] << std::endl;



    return 0;
}
