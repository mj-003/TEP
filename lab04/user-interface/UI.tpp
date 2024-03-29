//
// Created by Malwina Juchiewicz on 17/12/2023.
//

#ifndef LAB04_2_UI_TPP
#define LAB04_2_UI_TPP

#include "UI.hpp"

template <typename T>
void UI<T>::run() {
    std::string treeType = chooseTreeType();

    if (treeType == INT_TYPE) {
        UI<int> ui;
        ui.handleTreeType();
    }

    else if (treeType == DOUBLE_TYPE) {
        UI<double> ui;
        ui.handleTreeType();
    }

    else if (treeType == FLOAT_TYPE) {
        UI<float> ui;
        ui.handleTreeType();
    }

    else if (treeType == STRING_TYPE) {
        UI<std::string> ui;
        ui.handleTreeType();
    }

    else {
        std::cout << INVALID_CHOICE << std::endl;
    }
}

template <typename T>
std::string UI<T>::chooseTreeType() {
    std::string userInput;
    std::cout << std::endl << CHOOSE_TYPE_MSG;
    std::getline(std::cin, userInput);
    std::cout << std::endl;
    return userInput;
}

template <typename T>
void UI<T>::handleTreeType() {
    std::string userInput, currentCommand, formula;

    while (true) {
        std::cout << ENTER_SIGN;

        std::getline(std::cin, userInput);
        if (userInput.empty()) break;

        std::tie(currentCommand, formula) = splitFirstWord(userInput);

        if (currentCommand == EXIT) break;
        else if (currentCommand == HELP) handleHelp();
        else if (currentCommand == ENTER) handleEnter(formula);
        else if (tree != nullptr)
        {
            if (currentCommand == VARS) handleVars();
            else if (currentCommand == PRINT) handlePrint();
            else if (currentCommand == COMP) handleComp(formula);
            else if (currentCommand == JOIN) handleJoin(formula);
            else std::cout << INVALID_MSG << std::endl;
        }
        else {
            std::cout << ERROR_TREE << std::endl;
        }
    }
}

template <typename T>
void UI<T>::handleEnter(const std::string& formula) {
    delete tree;
    tree = new CTree<T>(formula);
    if (tree->getIsError()) {
        std::cout << "Fixed formula: " << tree->getFormula();
    }
    std::cout << std::endl;
}

template <typename T>
void UI<T>::handlePrint() {
    tree->printTree();
    std::cout << std::endl;
}

template <typename T>
void UI<T>::handleVars() {
    tree->selectUniqueVariables();
    std::cout << std::endl;
}

template <typename T>
void UI<T>::handleComp(const std::string& values) {
    if (validateValues(values, tree)) {
        tree->assignValuesToVariables(values);
        try {
            T result = tree->calculate(tree->getRoot());
            std::cout << RESULT << result << std::endl;
        } catch (const std::runtime_error& e) {
            std::cerr << ERROR << e.what() << std::endl;
        }
    } else {
        std::cout << ERROR_VALUES << std::endl;
    }
    std::cout << std::endl;
}

template <typename T>
void UI<T>::handleJoin(const std::string& formula) {
    CTree<T> tree2;
    tree2.createTree(formula);
    *tree = *tree + tree2;
    //tree->setFormula(tree->getRoot());
    std::cout << std::endl;
}

template <typename T>
void UI<T>::handleHelp() {
    std::cout << HELP_MSG << std::endl;
}



#endif //LAB04_2_UI_TPP
