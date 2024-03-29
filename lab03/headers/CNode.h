//
// Created by Malwina Juchiewicz on 16/11/2023.
//

#ifndef LAB03_V02_CNODE_H
#define LAB03_V02_CNODE_H

#include "../Const.h"
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

class CNode {
private:
    std::string data;
    std::vector<CNode*>* children;
    int howManyChildren;
    double value;


    CNode();
    ~CNode();
    CNode(const CNode& other);
    CNode(const std::string& val);


    double evaluate() const;
    static double operation(const std::string& op, double x, double y);


    CNode* getChild(int index) const;
    int childrenNeeded() const;


    bool isLeaf() const;
    static bool isOneArg(const std::string& basicString) ;
    static bool isTwoArg(const std::string& basicString) ;
    static bool isNumber(const std::string& basicString);


    friend class CTree;
};



#endif //LAB03_V02_CNODE_H
