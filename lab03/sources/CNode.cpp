//
// Created by Malwina Juchiewicz on 16/11/2023.
//

#include "../headers/CNode.h"

CNode::CNode() :
    howManyChildren(0), value(0), children(new std::vector<CNode*>()) {}


CNode::~CNode() {
    for (CNode *child : *children) {
        delete child;
    }
    delete children;
}

CNode::CNode(const CNode& other) {
    data = other.data;
    howManyChildren = other.howManyChildren;
    value = other.value;

    children = new std::vector<CNode*>();
    for (CNode* child : *(other.children)) {
        children->push_back(new CNode(*child));
    }
}

CNode::CNode(const std::string& data) {
    children = new std::vector<CNode*>();
    this->data = data;
    if (isNumber(data)) value = std::stod(data);

    if (isTwoArg(data)) {
        howManyChildren = CHILDREN_TWO_ARG;
    }

    else if (isOneArg(data)) {
        howManyChildren = CHILDREN_ONE_ARG;
    }

    else {
        howManyChildren = CHILDREN_LEAF;
    }
}


// -------- evaluating node --------

double CNode::evaluate() const {
    if (isOneArg(data))
    {
        double x = getChild(0)->evaluate();
        return operation(data, x, 0);
    }

    else if (isTwoArg(data))
    {
        double x = getChild(0)->evaluate();
        double y = getChild(1)->evaluate();
        return operation(data, x, y);
    }

    else {
        return value;
    }
}


// -------- operations on children ---------

CNode *CNode::getChild(int index) const {
    if (index < children->size())
        return (*children)[index];
    else return nullptr;
}

int CNode::childrenNeeded() const {
    return howManyChildren - children->size();
}


// -------- helpers --------

bool CNode::isLeaf() const {
    return howManyChildren == 0;
}

bool CNode::isOneArg(const std::string& op) {
    for (const std::string& str : ONE_ARG_OPER) {
        if (str == op) return true;
    }
    return false;
}

bool CNode::isTwoArg(const std::string& op) {
    for (const std::string& str : TWO_ARG_OPER) {
        if (str == op) return true;
    }
    return false;
}

bool CNode::isNumber(const std::string& basicString) {
    for (char i : basicString) {
        if (!isdigit(i)) return false;
    }
    return true;
}

double CNode::operation(const std::string& op, double x, double y) {
    if (op == ADD) { return x + y; }
    if (op == SUB) { return x - y; }
    if (op == MUL) { return x * y; }
    if (op == DIV) { return x / y; }
    if (op == SIN) {return sin(x);}
    if (op == COS) {return cos(x);}
    return 0;
}















