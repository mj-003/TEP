//
// Created by Malwina Juchiewicz on 17/12/2023.
//

#ifndef LAB04_2_UI_HPP
#define LAB04_2_UI_HPP

#include "../tree/CTree.hpp"
#include "../operations-on-string/StringHelp.hpp"
#include <iostream>

template <typename T>
class UI {
private:

    CTree<T>* tree;

    void handleEnter(const std::string& formula);
    void handlePrint();
    void handleVars();
    void handleComp(const std::string& values);
    void handleJoin(const std::string& formula);
    static void handleHelp();

    std::string chooseTreeType();

public:

    UI() : tree(nullptr) {}
    ~UI() { delete tree; }

    void run();
    void handleTreeType();


};

const std::string HELP = "help";
const std::string ENTER = "enter";
const std::string VARS = "vars";
const std::string PRINT = "print";
const std::string COMP = "comp";
const std::string JOIN = "join";
const std::string EXIT = "exit";


#include "UI.tpp"

#endif //LAB04_2_UI_HPP
