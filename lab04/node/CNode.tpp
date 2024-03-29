//
// Created by Malwina Juchiewicz on 11/12/2023.
//

#ifndef LAB03_V02_CNODE_TPP
#define LAB03_V02_CNODE_TPP
#include <iostream>


template <typename T>
CNode<T>::CNode() :
        howManyChildren(0), value(0), children() {}


template <typename T>
CNode<T>::~CNode()
{
    for (CNode<T> *child : children) {
        delete child;
    }
}


template <typename T>
CNode<T>::CNode(const CNode<T>& other)
{

    data = other.data;
    howManyChildren = other.howManyChildren;
    value = other.value;

    // std::cout << "copy CNode: " << this->data << std::endl;

    children.clear();
    for (CNode<T>* child : other.children) {
        children.push_back(new CNode(*child));
    }
}


template <typename T>
CNode<T>::CNode(const std::string& data)
{
    children.clear();
    this->data = data;
    if (isValue(data)) {
        this->setValue(data);
    }

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


template <typename T>
CNode<T>::CNode(CNode<T>&& other) noexcept
{
    // std::cout << "MOVE CONSTRUCTOR (CNode)" << std::endl;
    data = other.data;
    howManyChildren = other.howManyChildren;
    value = other.value;
    children = std::move(other.children);

    other.data = "";
    other.howManyChildren = 0;
    other.value = T();
    other.children.clear();
}



// -------- evaluating node --------

template <typename T>
T CNode<T>::evaluate() const
{
    if (isOneArg(data))
    {
        T x = getChild(0)->evaluate();
        return operation(data, x, 0);
    }

    else if (isTwoArg(data))
    {
        T x = getChild(0)->evaluate();
        T y = getChild(1)->evaluate();
        return operation(data, x, y);
    }

    else {
        return value;
    }
}


// -------- operations on children ---------

template <typename T>
CNode<T> *CNode<T>::getChild(int index) const
{
    if (index < children.size())
        return (children)[index];
    else return nullptr;
}


template <typename T>
int CNode<T>::childrenNeeded() const
{
    return howManyChildren - children.size();
}


// -------- helpers --------

template <typename T>
bool CNode<T>::isLeaf() const
{
    return howManyChildren == 0;
}


template <typename T>
bool CNode<T>::isOneArg(const std::string& op)
{
    for (const std::string& str : ONE_ARG_OPER) {
        if (str == op) return true;
    }
    return false;
}


template <typename T>
bool CNode<T>::isTwoArg(const std::string& op)
{
    for (const std::string& str : TWO_ARG_OPER) {
        if (str == op) return true;
    }
    return false;
}


template <typename T>
bool CNode<T>::isValue(const std::string& token)
{
    int dotFound = 0;
    for (char c : token) {
        if (!isdigit(c)) {
            if (c == '.' && !dotFound) {
                dotFound += 1;
            } else {
                return false;
            }
        }
    }
    return dotFound <= 1;
}



template <typename T>
T CNode<T>::operation(const std::string& op, T x, T y)
{
    if (op == ADD) { return x + y; }
    if (op == SUB) { return x - y; }
    if (op == MUL) { return x * y; }
    if (op == DIV) { return x / y; }
    if (op == SIN) {return sin(x);}
    if (op == COS) {return cos(x);}
    return 0;
}


template<typename T>
void CNode<T>::setValue(std::string val)
{
    value = std::stoi(val);
}


template<typename T>
bool CNode<T>::isVariable(const std::string& data)
{
    return !isValue(data) && !isOneArg(data) && !isTwoArg(data);
}



#endif //LAB03_V02_CNODE_TPP
