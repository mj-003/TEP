//
// Created by Malwina Juchiewicz on 11/12/2023.
//

#ifndef LAB03_V02_CTREE_HPP
#define LAB03_V02_CTREE_HPP

#include "../node/CNode.hpp"
#include "../node/CNode.tpp"

#include "../Const.h"
#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>
#include <vector>

template <typename T>
class CTree {
private:
    CNode<T>* root;
    bool isError;
    std::vector<std::string> formula;
    std::vector<std::pair<std::string, std::string>> variableValues;

    CNode<T> *createSubtree(std::vector<std::string>& tokens);

    static std::vector<std::string> getVector(const std::string &expression) ;

    void setUniqueVariables(CNode<T> *node);

    static void printTokens(const std::vector<std::string>& vector1);
    void printSubtree(const CNode<T> *node, int depth) const;
    bool findVariable(const std::string& variable) const;

    void handleError(std::vector<std::string>& tokens);

    static bool isValue(std::string token);
    static bool isOneArg(std::string token);
    static bool isTwoArg(std::string token);

public:
    CTree();
    CTree(const std::string& expression);
    ~CTree();
    CTree(const CTree& other);

    void createTree(const std::string& expression);

    void printTree() const;
    void selectUniqueVariables();
    static T calculate(CNode<T> *pNode);
    void assignValuesToVariables(const std::string &expression);


    CTree& operator=(const CTree& otherTree);
    CTree operator+(const CTree& tree) const;

    CNode<T>* getRoot() const;
    int getVariablesCount() const;
    bool getIsError() const;
    std::string getFormula() const;

};

template <>
void CTree<std::string>::handleError(std::vector<std::string> &tokens);



#include "CTree.tpp"

#endif //LAB03_V02_CTREE_HPP
