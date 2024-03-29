//
// Created by Malwina Juchiewicz on 11/12/2023.
//

#ifndef LAB03_V02_CTree_TPP
#define LAB03_V02_CTree_TPP


template <typename T>
CTree<T>::CTree() : root(nullptr), isError(false)
{
    formula.clear();
    variableValues.clear();
}


template <typename T>
CTree<T>::~CTree()
{
    delete root;
}


template <typename T>
CTree<T>::CTree(const std::string& expression)
{
    isError = false;
    formula.clear();
    variableValues.clear();
    root = new CNode<T>();
    createTree(expression);
}


template <typename T>
CTree<T>::CTree(const CTree<T> &otherTree)
{
    // std::cout << "COPY CONSTRUCTOR " << std::endl;

    isError = otherTree.isError;
    formula = otherTree.formula;
    variableValues = otherTree.variableValues;
    root = new CNode(*otherTree.root);
}


template <typename T>
CTree<T>::CTree(CTree<T> &&other) noexcept
{
    // std::cout << "MOVE CONSTRUCTOR " <<  std::endl;

    root = other.root;
    isError = other.isError;
    formula = std::move(other.formula);
    variableValues = std::move(other.variableValues);

    other.root = nullptr;
    other.isError = false;
    other.formula.clear();
    other.variableValues.clear();
}


// -------- creating tree ---------

template <typename T>
void CTree<T>::createTree(const std::string& expression)
{
    std::vector<std::string> tokens = getVector(expression);
    root = createSubtree(tokens);
    isError = (!tokens.empty() || isError);
}


template <typename T>
CNode<T>* CTree<T>::createSubtree(std::vector<std::string>& tokens)
{
    if (tokens.empty()) {
        handleError(tokens);
    }

    std::string currentToken = tokens.front();
    tokens.erase(tokens.begin());
    formula.push_back(currentToken);

    auto* newNode = new CNode<T>(currentToken);

    for (int i = 0; i < newNode->howManyChildren; i++)
    {
        if (tokens.size() >= newNode->childrenNeeded())
            newNode->children.push_back(createSubtree(tokens));
        else
        {
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
void CTree<T>::handleError(std::vector<std::string>& tokens)
{
    isError = true;
    tokens.insert(tokens.end(), DEFAULT_VALUE_ADD);
}



// -------- calculating tree ---------

template <typename T>
T CTree<T>::calculate(CNode<T> *node)
{
    if (node != nullptr) {
        return node->evaluate();
    }
    else return 0;
}


// --------- operations on variables ---------

template <typename T>
void CTree<T>::assignValuesToVariables(const std::string& expression)
{
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
void CTree<T>::setUniqueVariables(CNode<T>* node)
{
    if (node != nullptr) {
        if (node->isLeaf()) {
            for (const auto& pair : variableValues)
            {
                if (pair.first == node->data) {
                    node->setValue(pair.second);
                    break;
                }
            }
        }
        for (int i = 0; i < node->howManyChildren; ++i)
        {
            setUniqueVariables(node->getChild(i));
        }
    }
}


template <typename T>
void CTree<T>::selectUniqueVariables()
{
    if (variableValues.empty()) std::cout << NO_VARS_MSG << std::endl;
    else
    {
        std::cout << VARS_MSG << " [ ";
        for (const auto &var : variableValues) {
            std::cout << var.first << " ";
        }
        std::cout << "]" << std::endl;
    }
}


// -------- operators --------

template <typename T>
CTree<T>& CTree<T>::operator=(const CTree<T>& otherTree)
{
    std::cout << "COPY =" << std::endl;

    if (this != &otherTree)
    {
        delete root;
        root = new CNode<T>(*otherTree.root);
        isError = otherTree.isError;
        variableValues = otherTree.variableValues;
        formula = otherTree.formula;
    }
    return *this;
}

template <typename T>
CTree<T> CTree<T>::operator+(const CTree<T>& other) const
{
    std::cout << "COPY +" << std::endl;

    if (root == nullptr) {
        return CTree<T>(other);
    }

    if (other.root == nullptr) {
        return CTree<T>(*this);
    }

    CTree<T> result = CTree<T>(*this);
    CNode<T>* resultParent = result.findLeafParent(result.root);
    CNode<T>* otherTreeRoot = new CNode(*other.root);

    if (resultParent != nullptr)
    {
        if (resultParent->children.size() > 0) {
            delete resultParent->children.at(0);
        }
        resultParent->children.at(0) = otherTreeRoot;
    }

    result.setAttributes(result.root);
    return result;
}


template <typename T>
CTree<T>& CTree<T>::operator=(CTree<T>&& other) noexcept
{
    std::cout << "MOVE =" << std::endl;

    if (this != &other)
    {
        delete root;
        root = other.root;
        isError = other.isError;
        variableValues = std::move(other.variableValues);
        formula = std::move(other.formula);

        other.root = nullptr;
        other.isError = false;
        other.formula.clear();
        other.variableValues.clear();
    }
    return *this;
}


template <typename T>
CTree<T> CTree<T>::operator+(CTree<T>&& other) const
{
    std::cout << "MOVE +" << std::endl;

    if (other.root == nullptr) {
        return CTree<T>(*this);
    }

    if (root == nullptr) {
        return other;
    }

    CTree<T> result(*this);
    CNode<T>* resultParent = result.findLeafParent(result.root);

    if (resultParent != nullptr && !resultParent->children.empty()) {
        resultParent->children.at(0) = other.root;

        other.root = nullptr;
        other.isError = false;
        other.formula.clear();
        other.variableValues.clear();
    }

    result.setAttributes(result.root);

    return result;
}


// -------- printing --------

template <typename T>
void CTree<T>::printTree() const
{
    std::cout<< FORMULA;
    printTokens(formula);
    std::cout<< TREE_STRUCTURE << std::endl;
    if (root != nullptr) {
        printSubtree(root, 0);
    }
}


template <typename T>
void CTree<T>::printSubtree(const CNode<T> *node, int depth) const
{
    if (node != nullptr)
    {
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
void CTree<T>::printTokens(const std::vector<std::string>& vector)
{
    for (auto & i : vector) {
        std::cout << i << " ";
    }
    std::cout<< std::endl;
}


// -------- getters --------

template <typename T>
CNode<T> *CTree<T>::getRoot() const
{
    return root;
}


template <typename T>
std::vector<std::string> CTree<T>::getVector(const std::string& expression)
{
    std::istringstream iss(expression);
    std::vector<std::string> tokens;
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}


template <typename T>
int CTree<T>::getVariablesCount() const
{
    return variableValues.size();
}


template <typename T>
bool CTree<T>::getIsError() const
{
    return isError;
}


template <typename T>
std::string CTree<T>::getFormula() const
{
    std::string result;
    for (const std::string& token : formula) {
        result += token + " ";
    }
    return result;
}


template <typename T>
bool CTree<T>::findVariable(const std::string& variable) const
{
    for (const auto& pair : variableValues) {
        if (pair.first == variable) {
            return true;
        }
    }
    return false;
}


template <typename T>
CNode<T>* CTree<T>::findLeafParent(CNode<T>* root_) const
{
    if (root_ == nullptr || root_->isLeaf()) return nullptr;

    for (int i = 0; i < root_->howManyChildren; ++i)
    {
        if (root_->getChild(i) != nullptr && root_->getChild(i)->isLeaf()) {
            return root_;
        }

        CNode<T>* leafParent = findLeafParent(root_->getChild(i));
        if (leafParent != nullptr) return leafParent;
    }

    return nullptr;
}


template <typename T>
void CTree<T>::setAttributes(CNode<T> *node)
{
    formula.clear();
    variableValues.clear();

    if (node != nullptr) {
        updateFormulaAndVariables(node);
    }
}


template <typename T>
void CTree<T>::updateFormulaAndVariables(CNode<T> *node)
{
    if (node != nullptr) {
        formula.push_back(node->data);

        for (int i = 0; i < node->howManyChildren; ++i) {
            updateFormulaAndVariables(node->getChild(i));
        }

        if (CNode<T>::isVariable(node->data) && !findVariable(node->data)) {
            variableValues.emplace_back(node->data, DEFAULT_VALUE);
        }
    }
}


#endif //LAB03_V02_CTree<T>_TPP
