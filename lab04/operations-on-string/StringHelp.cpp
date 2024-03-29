//
// Created by Malwina Juchiewicz on 19/12/2023.
//

#include "StringHelp.hpp"

std::pair<std::string, std::string> splitFirstWord(const std::string& input) {
    std::istringstream iss(input);
    std::string firstWord, rest;

    iss >> firstWord;
    std::getline(iss >> std::ws, rest);

    return std::make_pair(firstWord, rest);
}


bool isInQuotes(const std::string& word) {
    size_t length = word.length();
    if (length < 2) return false;
    if (word[0] == '"' && word[length - 1] == '"') return true;
    return false;
}


template <>
bool validateValues(const std::string& values, CTree<std::string>* tree) {
    std::istringstream iss(values);
    std::vector<std::string> tokens;
    std::string token;

    while (iss >> token) {
        if (!isInQuotes(token)) return false;
        else tokens.push_back(token);
    }

    return tokens.size() == tree->getVariablesCount();
}