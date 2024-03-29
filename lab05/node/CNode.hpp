#ifndef LAB03_V02_CNODE_HPP
#define LAB03_V02_CNODE_HPP

#include <string>
#include <vector>
#include "../Const.h"
#include <cmath>
#include "../operations-on-string/StringOperators.h"

template <typename T>
class CNode {
public:

    std::string data;
    std::vector<CNode<T>*> children;
    int howManyChildren;
    T value;

    CNode();
    ~CNode();
    CNode(const CNode& other);
    CNode(const std::string& val);

    T evaluate() const;
    static T operation(const std::string& op, T x, T y);

    CNode* getChild(int index) const;
    int childrenNeeded() const;

    bool isLeaf() const;
    static bool isOneArg(const std::string& op);
    static bool isTwoArg(const std::string& op);
    static bool isValue(std::string value);

    void setValue(std::string val);
};

template <>
CNode<std::string>::CNode();

template<>
bool CNode<std::string>::isValue(const std::string value);

template<>
bool CNode<int>::isValue(const std::string value);

template<>
void CNode<double>::setValue(std::string val);

template<>
void CNode<std::string>::setValue(std::string val);

template <>
std::string CNode<std::string>::operation(const std::string& op, std::string x, std::string y);


#include "CNode.tpp"


#endif //LAB03_V02_CNODE_HPP
