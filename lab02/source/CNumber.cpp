//
// Created by Malwina Juchiewicz on 29/10/2023.
//

#include "../headers/CNumber.h"
#include <iostream>
#include "../headers/ArithmeticOperations.h"

CNumber::CNumber() : i_length(NUMBER_DEFAULT_LENGTH), is_negative(false) {
    pi_number = new int[i_length];
}

CNumber::CNumber(int* values, int size, bool is_negative) :
    i_length(size), pi_number(values), is_negative(is_negative) {
}


CNumber::CNumber(const CNumber &pcOther) {
    i_length = pcOther.i_length;
    is_negative = pcOther.is_negative;
    pi_number = new int[i_length];
    for (int i = 0; i < i_length; i++) {
        pi_number[i] = pcOther.pi_number[i];
    }
}

CNumber::CNumber(int value) {
    is_negative = (value < 0);
    std::string valueString = std::to_string(value);
    int length = valueString.length();

    i_length = (is_negative) ? (length - 1) : length;
    pi_number = new int[i_length];

    int startIndex = (is_negative) ? 1 : 0;

    for (int i = 0; i < i_length; i++) {
        pi_number[i_length - 1 - i] = valueString[startIndex + i] - '0';
    }
}


CNumber::~CNumber() {
    delete[] pi_number;
}

CNumber& CNumber::operator=(CNumber other) {
    if (this != &other) {
        delete[] pi_number;
        i_length = other.i_length;
        is_negative = other.is_negative;
        pi_number = new int[i_length];
        for (int i = 0; i < i_length; i++) {
            pi_number[i] = other.pi_number[i];
        }
    }
    return *this;
}

CNumber& CNumber::operator=(const int value) {
    is_negative = (value < 0);
    std::string valueString = std::to_string(value);
    int length = valueString.length();

    i_length = is_negative ? (length - 1) : length;
    delete[] pi_number;
    pi_number = new int[i_length];
    int startIndex = is_negative ? 1 : 0;
    for (int i = 0; i < i_length; i++) {
        pi_number[i_length - 1 - i] = valueString[startIndex + i] - '0';
    }
    return *this;
}


CNumber CNumber::operator+(const CNumber &pcNewVal) const {
    CNumber result;
    if (is_negative == pcNewVal.is_negative) {
        result = ArithmeticOperations::add(*this, pcNewVal);
        result.is_negative = is_negative;
    }
    else {
        if (this->isAbsGreater(pcNewVal))
            result = ArithmeticOperations::subtract(*this, pcNewVal);
        else
            result = ArithmeticOperations::subtract(pcNewVal, *this);
        result.is_negative = this->isAbsGreater(pcNewVal) ? is_negative : pcNewVal.is_negative;
    }
    if (result.pi_number[0] == 0)
        result.is_negative = false;
    return result;
}


CNumber CNumber::operator-(const CNumber& pcNewVal) const {
    CNumber result;
    if (is_negative == pcNewVal.is_negative) {
        if (this->isAbsGreater(pcNewVal)) {
            result = ArithmeticOperations::subtract(*this, pcNewVal);
            result.is_negative = is_negative;
        }
        else {
            result = ArithmeticOperations::subtract(pcNewVal, *this);
            result.is_negative = !is_negative;
        }
    }
    else {
        result = ArithmeticOperations::add(*this, pcNewVal);
        result.is_negative = this->is_negative;
    }
    if (result.pi_number[0] == 0)
        result.is_negative = false;
    return result;
}

CNumber CNumber::operator*(const CNumber &pcNewVal) const {
    CNumber result;
    result = ArithmeticOperations::multiply(*this, pcNewVal);
    is_negative == pcNewVal.is_negative ? result.is_negative = false : result.is_negative = true;
    if (result.pi_number[0] == 0)
        result.is_negative = false;
    return result;
}


CNumber CNumber::operator/(const CNumber &pcNewVal) const {
    CNumber result;
    result = ArithmeticOperations::divide(*this, pcNewVal);
    is_negative == pcNewVal.is_negative ? result.is_negative = false : result.is_negative = true;
    if (result.pi_number[0] == 0)
        result.is_negative = false;
    return result;
}

CNumber CNumber::operator+(int iNewVal) const {
    CNumber other(iNewVal);
    CNumber result = *this + other;
    return result;
}


CNumber CNumber::operator*(int iNewVal) const {
    CNumber other(iNewVal);
    CNumber result = (*this) * other;
    return result;
}

CNumber CNumber::operator-(int iNewVal) const {
    CNumber other(iNewVal);
    CNumber result = *this - other;
    return result;
}

CNumber CNumber::operator/(int iNewVal) const {
    CNumber other(iNewVal);
    CNumber result = *this / other;
    return result;
}

bool CNumber::operator==(const CNumber &pcNewVal) const {
    if (this->i_length != pcNewVal.i_length || this->is_negative != pcNewVal.is_negative) {
        return false;
    }
    for(int i = 0; i < i_length; i++) {
        if (pi_number[i] != pcNewVal.pi_number[i]) {
            return false;
        }
    }
    return true;
}

bool CNumber::operator>=(const CNumber &pcNewVal) const {
    if (this->is_negative && !pcNewVal.is_negative) {
        return false;
    }
    else if (!this->is_negative && pcNewVal.is_negative) {
        return true;
    }
    else if (this->is_negative && pcNewVal.is_negative) {
        return !this->isAbsGreater(pcNewVal);
    }
    else {
        return this->isAbsGreater(pcNewVal);
    }
}

bool CNumber::isAbsGreater(const CNumber &pcNewVal) const {
    if (this->i_length > pcNewVal.i_length) {
        return true;
    }
    else if (this->i_length < pcNewVal.i_length) {
        return false;
    }
    else {
        for (int i = this->i_length - 1; i >= 0; i--) {
            if (this->pi_number[i] > pcNewVal.pi_number[i]) {
                return true;
            }
            else if (this->pi_number[i] < pcNewVal.pi_number[i]) {
                return false;
            }
        }
    }
    return true;
}


std::string CNumber::sToString() const {
    std::string stringResult;
    if (is_negative) {
        stringResult += "-";
    }
    for (int i = i_length - 1; i >= 0; i--) {
        stringResult += std::to_string(pi_number[i]);
    }
    return stringResult;
}

int CNumber::getI_length() const {
    return i_length;
}

int *CNumber::getPi_number() const {
    return pi_number;
}

bool CNumber::isIs_negative() const {
    return is_negative;
}

void CNumber::setI_length(int new_i_length) {
    CNumber::i_length = new_i_length;
}

void CNumber::setPi_number(int *new_pi_number) {
    CNumber::pi_number = new_pi_number;
}

int& operator<=(int &prevVal, const CNumber &pcNewVal) {
    int temp = stoi(pcNewVal.sToString());
    prevVal = temp;
    return prevVal;
}

CNumber& CNumber::operator<=(const CNumber &pcNewVal)  {
    i_length = pcNewVal.i_length;
    is_negative = pcNewVal.is_negative;
    int* new_pi_number = new int[i_length];
    for (int i = 0; i < i_length; i++) {
        new_pi_number[i] = pcNewVal.pi_number[i];
    }
    delete[] pi_number;
    pi_number = new_pi_number;
    return *this;
}





















