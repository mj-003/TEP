//
// Created by Malwina Juchiewicz on 05/12/2023.
//

#include "StringHelp.h"

std::pair<std::string, std::string> splitFirstWord(const std::string& input) {
    std::istringstream iss(input);
    std::string firstWord, rest;

    iss >> firstWord;
    std::getline(iss >> std::ws, rest);

    return std::make_pair(firstWord, rest);
}

bool validateValues(const std::string& values, CTree* tree) {
    std::istringstream iss(values);
    std::vector<double> parsedValues;
    double value;

    while (iss >> value) {
        if (iss.fail()) {
            return false;
        }
        else parsedValues.push_back(value);
    }
    return parsedValues.size() == tree->getVariablesCount();
}

