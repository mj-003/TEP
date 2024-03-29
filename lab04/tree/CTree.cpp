//
// Created by Malwina Juchiewicz on 19/12/2023.
//

#include "CTree.hpp"

template <>
void CTree<std::string>::handleError(std::vector<std::string>& tokens) {
    isError = true;
    tokens.insert(tokens.end(), DEFAULT_STRING_ADD);
}

