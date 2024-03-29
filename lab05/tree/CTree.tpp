//
// Created by Malwina Juchiewicz on 11/12/2023.
//

#ifndef LAB03_V02_CTree_TPP
#define LAB03_V02_CTree_TPP


template <typename T>
CTree<T>::CTree() : root(nullptr), isError(false) {
    formula.clear();
    variableValues.clear();
}

template <typename T>
CTree<T>::~CTree() {
    delete root;
}

template <typename T>
CTree<T>::CTree(const std::string& expression) {
    isError = false;
    formula.clear();
    variableValues.clear();
    root = new CNode<T>();
    createTree(expression);
}

template <typename T>
CTree<T>::CTree(const CTree<T> &otherTree) {
    isError = otherTree.isError;
    formula = otherTree.formula;
    variableValues = otherTree.variableValues;
    root = new CNode(*otherTree.root);
}


// -------- creating tree ---------

template <typename T>
void CTree<T>::createTree(const std::string& expression) {
    std::vector<std::string> tokens = getVector(expression);
    root = createSubtree(tokens);
    isError = (!tokens.empty() || isError);
}

template <typename T>
CNode<T>* CTree<T>::createSubtree(std::vector<std::string>& tokens) {
    if (tokens.empty()) {
        handleError(tokens);
    }

    std::string currentToken = tokens.front();
    tokens.erase(tokens.begin());
    formula.push_back(currentToken);

    auto* newNode = new CNode<T>(currentToken);

    for (int i = 0; i < newNode->howManyChildren; i++) {
        if (tokens.size() >= newNode->childrenNeeded())
            newNode->children.push_back(createSubtree(tokens));
        else {
            handleError(tokens);
            newNode->children.push_back(createSubtree(tokens));
        }
    }

    if (newNode->isLeaf() && !CNode<T>::isValue(newNode->data) && !findVariable(newNode->data)) {
        variableValues.emplace_back(newNode->data, DEFAULT_VALUE);
    }

    return newNode;
}


template <typename T>
void CTree<T>::handleError(std::vector<std::string>& tokens) {
    isError = true;
    tokens.insert(tokens.end(), DEFAULT_VALUE_ADD);
}



// -------- calculating tree ---------

template <typename T>
T CTree<T>::calculate(CNode<T> *node) {
    if (node != nullptr) {
        return node->evaluate();
    }
    else return 0;
}


// --------- operations on variables ---------

template <typename T>
void CTree<T>::assignValuesToVariables(const std::string& expression) {
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

template <typename T>
void CTree<T>::setUniqueVariables(CNode<T>* node) {
    if (node != nullptr) {
        if (node->isLeaf()) {
            for (const auto& pair : variableValues) {
                if (pair.first == node->data) {
                    node->setValue(pair.second);
                    break;
                }
            }
        }
        for (int i = 0; i < node->howManyChildren; ++i) {
            setUniqueVariables(node->getChild(i));
        }
    }
}


template <typename T>
void CTree<T>::selectUniqueVariables() {
    if (variableValues.empty()) std::cout << NO_VARS_MSG << std::endl;
    else {
        std::cout << VARS_MSG << " [ ";
        for (const auto &var : variableValues) {
            std::cout << var.first << " ";
        }
        std::cout << "]" << std::endl;
    }
}


// -------- operators --------

template <typename T>
CTree<T>& CTree<T>::operator=(const CTree<T>& otherTree) {
    if (this != &otherTree) {
        delete root;
        root = new CNode<T>(*otherTree.root);
        isError = otherTree.isError;
        variableValues = otherTree.variableValues;
        formula = otherTree.formula;
    }
    return *this;
}


template <typename T>
CTree<T> CTree<T>::operator+(const CTree<T>& tree) const {
    std::string newFormula;

    for (size_t i = 0; i < formula.size() - 1; ++i) {
        newFormula += formula[i] + ' ';
    }
    for (const std::string& token : tree.formula) {
        newFormula += token + ' ';
    }
    std::cout<< newFormula << std::endl;

    return CTree<T>(newFormula);

}


// -------- printing --------

template <typename T>
void CTree<T>::printTree() const {
    std::cout<< FORMULA;
    printTokens(formula);
    std::cout<< TREE_STRUCTURE << std::endl;
    if (root != nullptr) {
        printSubtree(root, 0);
    }
}

template <typename T>
void CTree<T>::printSubtree(const CNode<T> *node, int depth) const {
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

template <typename T>
void CTree<T>::printTokens(const std::vector<std::string>& vector) {
    for (auto & i : vector) {
        std::cout << i << " ";
    }
    std::cout<< std::endl;
}


// -------- getters --------

template <typename T>
CNode<T> *CTree<T>::getRoot() const {
    return root;
}

template <typename T>
std::vector<std::string> CTree<T>::getVector(const std::string& expression) {
    std::istringstream iss(expression);
    std::vector<std::string> tokens;
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

template <typename T>
int CTree<T>::getVariablesCount() const {
    return variableValues.size();
}

template <typename T>
bool CTree<T>::getIsError() const {
    return isError;
}

template <typename T>
std::string CTree<T>::getFormula() const {
    std::string result;
    for (const std::string& token : formula) {
        result += token + " ";
    }
    return result;
}

template <typename T>
bool CTree<T>::findVariable(const std::string& variable) const {
    for (const auto& pair : variableValues) {
        if (pair.first == variable) {
            return true;
        }
    }
    return false;
}





#endif //LAB03_V02_CTree<T>_TPP
