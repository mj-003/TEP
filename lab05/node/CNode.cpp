//
// Created by Malwina Juchiewicz on 19/12/2023.
//

#include "CNode.hpp"

template <>
CNode<std::string>::CNode() :
        howManyChildren(0),  children() {}


template <>
bool CNode<std::string>::isValue(std::string token) {
    return token[0] == '"' && token[token.size() - 1] == '"';
}

template <>
bool CNode<int>::isValue(const std::string token) {
    for (char c : token) {
        if (!isdigit(c)) return false;
    }
    return true;
}

template<>
void CNode<double>::setValue(std::string val) {
    value = std::stod(val);
}

template<>
void CNode<std::string>::setValue(std::string val) {
    value = val;
}

template <>
std::string CNode<std::string>::operation(const std::string& op, std::string x, std::string y) {
    if (op == ADD) { return x + y; }
    if (op == SUB) { return x - y; }
    if (op == MUL) { return x * y; }
    if (op == DIV) { return x / y; }
    if (op == SIN) { return "";}
    if (op == COS) { return "";}
    return "";
}