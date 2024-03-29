//
// Created by Malwina Juchiewicz on 29/10/2023.
//

#ifndef TEP_LAB2V3_CNUMBER_H
#define TEP_LAB2V3_CNUMBER_H
#include "iostream"
#include "Constant.h"


class CNumber {
private:
    int *pi_number;
    int i_length;
    bool is_negative;

public:
    CNumber();
    CNumber(int* values, int size, bool is_negative);
    CNumber(const CNumber &pcOther);
    ~CNumber();
    CNumber(int value);

    CNumber& operator=(CNumber other);
    CNumber& operator=(int value);
    CNumber operator+(const CNumber &pcNewVal) const;
    CNumber operator*(const CNumber &pcNewVal) const;
    CNumber operator-(const CNumber &pcNewVal) const;
    CNumber operator/(const CNumber &pcNewVal) const;
    CNumber operator+(int iNewVal) const;
    CNumber operator*(int iNewVal) const;
    CNumber operator-(int iNewVal) const;
    CNumber operator/(int iNewVal) const;
    friend int& operator<=(int &prevVal, const CNumber &pcNewVal);
    CNumber& operator<=(const CNumber &pcNewVal) ;

    bool operator==(const CNumber &pcNewVal) const;
    bool operator>=(const CNumber &pcNewVal) const;

    bool isAbsGreater(const CNumber &pcNewVal) const;
    std::string sToString() const;
    int* getPi_number() const;
    int getI_length() const;
    bool isIs_negative() const;
    void setI_length(int i_length);
    void setPi_number(int *pi_number);
};


#endif //TEP_LAB2V3_CNUMBER_H
