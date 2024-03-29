//
// Created by Malwina Juchiewicz on 13/12/2023.
//

#ifndef LAB03_V02_STRINGHELP_HPP
#define LAB03_V02_STRINGHELP_HPP

#include <iostream>
#include "../tree/CTree.hpp"


std::pair<std::string, std::string> splitFirstWord(const std::string& input);

template <typename T>
bool validateValues(const std::string& values, CTree<T>* tree);

template <>
bool validateValues(const std::string& values, CTree<std::string>* tree);


#include "StringHelp.tpp"



#endif //LAB03_V02_STRINGHELP_HPP
