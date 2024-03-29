//
// Created by Malwina Juchiewicz on 29/10/2023.
//

#include "../headers/ArithmeticOperations.h"
#include "../headers/Constant.h"


CNumber ArithmeticOperations::add(const CNumber &myNumber, const CNumber &otherNumber) {
    int result_length = std::max(myNumber.getI_length(), otherNumber.getI_length()) + 1;
    int* result_number = new int[result_length]{};
    int carry = 0;

    for (int i = 0; i < result_length; i++) {
        int a = (i < myNumber.getI_length()) ? myNumber.getPi_number()[i] : 0;
        int b = (i < otherNumber.getI_length()) ? otherNumber.getPi_number()[i] : 0;

        int temp = a + b + carry;
        result_number[i] = temp % 10;
        carry = temp / 10;
    }

    CNumber result(result_number, result_length, false);
    deleteZeros(result);
    return result;
}


CNumber ArithmeticOperations::subtract(const CNumber &myNumber, const CNumber &otherNumber) {
    int result_length = std::max(myNumber.getI_length(), otherNumber.getI_length()) + 1;
    int* result_number = new int[result_length]{};
    int carry = 0;

    for (int i = 0; i < result_length; i++) {
        int a = (i < myNumber.getI_length()) ? myNumber.getPi_number()[i] : 0;
        int b = (i < otherNumber.getI_length()) ? otherNumber.getPi_number()[i] : 0;

        int temp = a - b - carry;
        temp < 0 ? (temp += 10), carry = 1 : carry = 0;
        result_number[i] = temp;
    }
    CNumber result(result_number, result_length, false);
    deleteZeros(result);
    return result;
}


CNumber ArithmeticOperations::multiply(const CNumber &myNumber, const CNumber &otherNumber) {
    int result_length = myNumber.getI_length() + otherNumber.getI_length();
    int* result_number = new int[result_length]{};

    for (int i = 0; i < myNumber.getI_length(); i++) {
        int carry = 0;
        for (int j = 0; j < otherNumber.getI_length(); j++) {
            int product = myNumber.getPi_number()[i] * otherNumber.getPi_number()[j] + result_number[i + j] + carry;
            result_number[i + j] = product % 10;
            carry = product / 10;
        }
        result_number[i + otherNumber.getI_length()] += carry;
    }

    CNumber result(result_number, result_length, false);
    deleteZeros(result);
    return result;
}


CNumber ArithmeticOperations::divide(const CNumber& myNumber, const CNumber& otherNumber) {
    if (otherNumber.getPi_number()[0] == 0) {
        throw std::runtime_error("Division by zero");
    }
    if (myNumber.getPi_number()[0] == 0) {
        return CNumber(0);
    }

    int* resultNumber = new int[std::max(myNumber.getI_length(), otherNumber.getI_length())]{};
    CNumber rest(0);

    for (int i = myNumber.getI_length() - 1; i >= 0; i--) {
        shiftLeft(rest);
        rest =  rest + myNumber.getPi_number()[i];
        int count = 0;
        while (rest.isAbsGreater(otherNumber)) {
            otherNumber.isIs_negative() ? rest = rest + otherNumber : rest = rest - otherNumber;
            count++;
        }
        count > 0 ? resultNumber[i] = count : resultNumber[i] = 0;
    }
    CNumber result(resultNumber, myNumber.getI_length(), false);
    deleteZeros(result);
    return result;
}

void ArithmeticOperations::shiftLeft(CNumber& pcNewVal) {
    int newLength = pcNewVal.getI_length() + 1;
    int* newNumbers = new int[newLength];
    for (int i = newLength - 1; i > 0; i--) {
        newNumbers[i] = pcNewVal.getPi_number()[i - 1];
    }
    newNumbers[0] = 0;
    delete[] pcNewVal.getPi_number();
    pcNewVal.setPi_number(newNumbers);
    pcNewVal.setI_length(newLength);
}


void ArithmeticOperations::deleteZeros(CNumber &pcNewVal) {
    while (pcNewVal.getI_length() > 1 && pcNewVal.getPi_number()[pcNewVal.getI_length() - 1] == 0) {
        pcNewVal.setI_length(pcNewVal.getI_length() - 1);
    }
}






