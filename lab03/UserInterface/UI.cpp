//
// Created by Malwina Juchiewicz on 05/12/2023.
//

#include "UI.h"

void run() {
    CTree* tree = nullptr;

    std::cout << START_COMMAND;

    std::string userInput;
    std::getline(std::cin, userInput);

    std::string currentCommand = splitFirstWord(userInput).first;
    std::string formula = splitFirstWord(userInput).second;


    while (currentCommand != EXIT) {
        if (currentCommand == HELP)
        {
            std::cout << "\nCommands: \n"
                         "\tenter <formula> - creates new tree with given formula\n"
                         "\tvars - prints all unique variables from current tree\n"
                         "\tprint - prints current tree\n"
                         "\tcomp <values> - calculates current tree with given values\n"
                         "\tjoin <formula> - joins current tree with new one\n"
                         "\texit - exits program\n";
        }

        else if (currentCommand == ENTER)
        {
            if (!formula.empty()) {
                delete tree;
                tree = new CTree(formula);
                if (tree->getIsError()) {
                    std::cout << "Fixed expression: ";
                    std::cout << tree->getFormula() << std::endl;
                }
            }
            else {
                std::cout << "Error: empty expression!" << std::endl;
            }
        }

        else if (currentCommand == VARS)
        {
            if (tree != nullptr) {
                tree->selectUniqueVariables();
            }
            else
                std::cout << "Error: tree is not initialized!" << std::endl;
        }

        else if (currentCommand == PRINT)
        {
            if (tree != nullptr) {
                tree->printTree();
            }
            else
                std::cout << "Error: tree is not initialized!" << std::endl;
        }

        else if (currentCommand == COMP)
        {
            if (tree != nullptr) {
                if (validateValues(formula, tree)) {
                    tree->assignValuesToVariables(formula);
                    std::cout << "Result: " << CTree::calculate(tree->getRoot()) << std::endl;
                }
                else
                    std::cout << "Error: invalid values!" << std::endl;
            }
            else
                std::cout << "Error: tree is not initialized!" << std::endl;
        }

        else if (currentCommand == JOIN)
        {
            if (tree != nullptr) {
                CTree tree2;
                tree2.createTree(formula);
                *tree = *tree + tree2;
            }
            else
                std::cout << "Error: tree is not initialized!" << std::endl;
        }
        else
            std::cout << "Invalid command!" << std::endl;

        std::cout << START_COMMAND;
        std::getline(std::cin, userInput);
        currentCommand = splitFirstWord(userInput).first;
        formula = splitFirstWord(userInput).second;

    }
}


