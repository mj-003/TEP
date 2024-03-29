//
// Created by Malwina Juchiewicz on 29/10/2023.
//

#ifndef TEP_LAB2V3_ARITHMETICOPERATIONS_H
#define TEP_LAB2V3_ARITHMETICOPERATIONS_H
#include "CNumber.h"


class ArithmeticOperations {
public:
    static CNumber add(const CNumber &pcNewVal1, const CNumber &pcNewVal2) ;
    static CNumber subtract(const CNumber &pcNewVal1, const CNumber &pcNewVal2) ;
    static CNumber multiply(const CNumber &pcNewVal1, const CNumber &pcNewVal2);
    static CNumber divide(const CNumber &pcNewVal1, const CNumber& pcNewVal2);

private:
    static void deleteZeros(CNumber &pcNewVal);
    static void shiftLeft(CNumber &pcNewVal);
};


#endif //TEP_LAB2V3_ARITHMETICOPERATIONS_H
