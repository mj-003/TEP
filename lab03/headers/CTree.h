//
// Created by Malwina Juchiewicz on 16/11/2023.
//

#ifndef LAB03_V02_CTREE_H
#define LAB03_V02_CTREE_H

#include "CNode.h"
#include "../Const.h"
#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>

class CTree {
private:
    CNode* root;
    bool isError;
    std::vector<std::string> formula;
    std::vector<std::pair<std::string, std::string>> variableValues;

    CNode *createSubtree(std::vector<std::string>& vector);

    static std::vector<std::string> getVector(const std::string &expression) ;

    void setUniqueVariables(CNode *node);

    static void printTokens(const std::vector<std::string>& vector1);
    void printSubtree(const CNode *node, int depth) const;
    bool findVariable(const std::string& variable) const;

public:
    CTree();
    explicit CTree(const std::string& expression);
    ~CTree();
    CTree(const CTree& other);

    void createTree(const std::string& expression);
    void printTree() const;
    void selectUniqueVariables();
    static double calculate(CNode *pNode);
    void assignValuesToVariables(const std::string &expression);


    CTree& operator=(const CTree& otherTree);
    CTree operator+(const CTree& tree) const;

    CNode* getRoot() const;
    int getVariablesCount() const;
    bool getIsError() const;
    std::string getFormula() const;

};

#endif //LAB03_V02_CTREE_H
