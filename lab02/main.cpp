#include <iostream>
#include "headers/CNumber.h"
#include "headers/Constant.h"



int main() {
    // operator+ test
    std::cout << ADDITION_TEST_MSG << std::endl;
    CNumber cnum1, cnum2, cnum3, cnum4, res1, res2;

    cnum1 = 2457723;
    cnum2 = 98625011;
    res1 = cnum1 + cnum2;   // 101182734
    std::cout << res1.sToString() << std::endl;

    cnum3 = -234816;
    cnum4 = 82468;
    res2 = cnum3 + cnum4;   // -152348
    std::cout << res2.sToString() << std::endl;

    // operator- test
    std::cout << std::endl << SUBTRACTION_TEST_MSG << std::endl;
    CNumber cnum5, cnum6, cnum7, cnum8, res3, res4;

    cnum5 = 8269132;
    cnum6 = 98625011;
    res3 = cnum5 - cnum6;   // -90355879
    std::cout << res3.sToString() << std::endl;

    cnum7 = -234816;
    cnum8 = -82468931;    // 82603747
    res4 = cnum7 - cnum8;
    std::cout << res4.sToString() << std::endl;

    // operator* test
    std::cout << std::endl << MULTIPLICATION_TEST_MSG << std::endl;
    CNumber cnum9, cnum10, cnum11, cnum12, res5, res6;
    cnum9 = 869261;
    cnum10 = 491864;
    res5 = cnum9 * cnum10;  //427558192504
    std::cout << res5.sToString() << std::endl;

    cnum11 = 234816;
    cnum12 = -82468931;
    res6 = cnum11 * cnum12; // -19365024501696
    std::cout << res6.sToString() << std::endl;

    // operator/ test
    std::cout << std::endl << DIVISION_TEST_MSG << std::endl;
    CNumber cnum13, cnum14, cnum15, cnum16, res7, res8;
    cnum13 = 29846924;
    cnum14 = 283681;
    res7 = cnum13 / cnum14;  // 105
    std::cout << res7.sToString() << std::endl;

    cnum15 = -2414816;
    cnum16 = 85869201;
    res8 = cnum15 / cnum16; // 0
    std::cout << res8.sToString() << std::endl;

    // zlozenie
    std::cout << std::endl;
    CNumber result, cn;
    cn = 2;
    result = cn + 2 * 2;
    //result = cnum1 * 230 - 128 / 3 + 21940;
    //std::cout << result.sToString() << std::endl;

    CNumber n(-1234);
    CNumber m;
    int x;
    x <= (m <= n);
    std::cout<<m.sToString()<<std::endl;
    std::cout<<n.sToString()<<std::endl;
    std::cout<<x<<std::endl;






    return 0;
}




//class Number {
//private:
//    int value;
//
//public:
//    Number(int val) : value(val) {}
//
//    // Operator <= przypisuje wartość z prawego argumentu do lewego argumentu
//    Number& operator<=(const Number& other) {
//        this->value = other.value;
//        return *this; // Zwracamy referencję do obiektu, aby umożliwić łańcuchowe przypisania (np. a <= b <= c).
//    }
//
//    // Getter do odczytywania wartości
//    int getValue() const {
//        return value;
//    }
//};
//
//int main() {
//    Number m(1234);
//    Number x(5678);
//
//    // Przykład użycia operatora <=
//    m <= x;
//
//    // Sprawdzenie, czy wartości zostały przypisane poprawnie
//    std::cout << "Wartość m: " << m.getValue() << std::endl;
//    std::cout << "Wartość x: " << x.getValue() << std::endl;
//
//    return 0;
//}

