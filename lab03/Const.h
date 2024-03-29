//
// Created by Malwina Juchiewicz on 17/11/2023.
//

#ifndef LAB03_V02_CONST_H
#define LAB03_V02_CONST_H

#include <set>
#include <string>

const std::set<std::string> TWO_ARG_OPER = {"+", "-", "*", "/"};
const std::set<std::string> ONE_ARG_OPER = {"sin", "cos"};


const std::string DEFAULT_VALUE_ADD = "1";
const std::string DEFAULT_VALUE = "0";


const int CHILDREN_TWO_ARG = 2;
const int CHILDREN_ONE_ARG = 1;
const int CHILDREN_LEAF = 0;


const std::string MUL = "*";
const std::string DIV = "/";
const std::string ADD = "+";
const std::string SUB = "-";
const std::string COS = "cos";
const std::string SIN = "sin";


#endif //LAB03_V02_CONST_H
