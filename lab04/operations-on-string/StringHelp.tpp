//
// Created by Malwina Juchiewicz on 13/12/2023.
//

#ifndef LAB03_V02_STRINGHELP_TPP
#define LAB03_V02_STRINGHELP_TPP


template <typename T>
bool validateValues(const std::string& values, CTree<T>* tree) {
    std::istringstream iss(values);
    std::vector<T> parsedValues;
    T value;

    while (iss >> value) {
        if (iss.fail()) {
            return false;
        }
        else parsedValues.push_back(value);
    }

    return parsedValues.size() == tree->getVariablesCount();
}



#endif //LAB03_V02_STRINGHELP_TPP
