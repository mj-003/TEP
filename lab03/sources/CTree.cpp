//
// Created by Malwina Juchiewicz on 16/11/2023.
//

#include "../headers/CTree.h"

CTree::CTree() : root(nullptr), isError(false) {
    formula.clear();
    variableValues.clear();
}

CTree::~CTree() {
    delete root;
}

CTree::CTree(const std::string& expression) {
    isError = false;
    formula.clear();
    variableValues.clear();
    root = new CNode();
    createTree(expression);
}

CTree::CTree(const CTree &otherTree) {
    isError = otherTree.isError;
    formula = otherTree.formula;
    variableValues = otherTree.variableValues;
    root = new CNode(*otherTree.root);
}


// -------- creating tree ---------

void CTree::createTree(const std::string& expression) {
    std::vector<std::string> tokens = getVector(expression);
    root = createSubtree(tokens);
    isError = (!tokens.empty() || isError);
}

CNode* CTree::createSubtree(std::vector<std::string>& tokens) {
    if (tokens.empty()) {
        return nullptr;
    }

    std::string currentToken = tokens.front();
    tokens.erase(tokens.begin());
    formula.push_back(currentToken);

    CNode* newNode = new CNode(currentToken);

    for (int i = 0; i < newNode->howManyChildren; i++) {

        if (tokens.size() >= newNode->childrenNeeded())
            newNode->children->push_back(createSubtree(tokens));

        else {
            isError = true;
            tokens.insert(tokens.end(), DEFAULT_VALUE_ADD);
            newNode->children->push_back(createSubtree(tokens));
        }
    }

    if (newNode->isLeaf() && !CNode::isNumber(newNode->data) && !findVariable(newNode->data)) {
            variableValues.emplace_back(newNode->data, DEFAULT_VALUE);
    }

    return newNode;
}


// -------- calculating tree ---------

double CTree::calculate(CNode *node) {
    if (node != nullptr) {
        return node->evaluate();
    }
    else return 0;
}


// --------- operations on variables ---------

void CTree::assignValuesToVariables(const std::string& expression) {
    std::vector<std::string> tokens = getVector(expression);

    auto it = variableValues.begin();
    for (const std::string& var : tokens) {
        if (it != variableValues.end()) {
            it->second = var;
            ++it;
        } else {
            break;
        }
    }

    setUniqueVariables(root);
}

void CTree::setUniqueVariables(CNode* node) {
    if (node != nullptr) {
        if (node->isLeaf()) {
            for (const auto& pair : variableValues) {
                if (pair.first == node->data) {
                    node->value = std::stod(pair.second);
                    break;
                }
            }
        }
        for (int i = 0; i < node->howManyChildren; ++i) {
            setUniqueVariables(node->getChild(i));
        }
    }
}


void CTree::selectUniqueVariables() {
    for (const auto &var : variableValues) {
        std::cout << var.first << " = " << var.second << std::endl;
    }
}


// -------- operators --------

CTree& CTree::operator=(const CTree& otherTree) {
    if (this != &otherTree) {
        delete root;
        root = new CNode(*otherTree.root);
        isError = otherTree.isError;
        variableValues = otherTree.variableValues;
        formula = otherTree.formula;
    }
    return *this;
}


CTree CTree::operator+(const CTree& tree) const {
    std::string newFormula;

    for (size_t i = 0; i < formula.size() - 1; ++i) {
        newFormula += formula[i] + " ";
    }
    for (const std::string& token : tree.formula) {
        newFormula += token + " ";
    }

    return CTree(newFormula);

}


// -------- printing --------

void CTree::printTree() const {
    std::cout<< "Formula: ";
    printTokens(formula);
    std::cout<< "Tree structure:" << std::endl;
    if (root != nullptr) {
        printSubtree(root, 0);
    }
}

void CTree::printSubtree(const CNode *node, int depth) const {
    if (node != nullptr) {
        for (int i = 0; i < depth; ++i) {
            std::cout << "|  ";
        }
        std::cout << "|--" << node->data << std::endl;
        for (int i = 0; i < node->howManyChildren; ++i) {
            printSubtree(node->getChild(i), depth + 1);
        }
    }
}

void CTree::printTokens(const std::vector<std::string>& vector) {
    for (auto & i : vector) {
        std::cout << i << " ";
    }
    std::cout<< std::endl;
}


// -------- getters --------

CNode *CTree::getRoot() const {
    return root;
}

std::vector<std::string> CTree::getVector(const std::string& expression) {
    std::istringstream iss(expression);
    std::vector<std::string> tokens;
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

int CTree::getVariablesCount() const {
    return variableValues.size();
}

bool CTree::getIsError() const {
    return isError;
}

std::string CTree::getFormula() const {
    std::string result;
    for (const std::string& token : formula) {
        result += token + " ";
    }
    return result;
}

bool CTree::findVariable(const std::string& variable) const {
    for (const auto& pair : variableValues) {
        if (pair.first == variable) {
            return true;
        }
    }
    return false;
}
























