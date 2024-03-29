#include "tree/CTree.hpp"
#include "user-interface/UI.hpp"
#include <iostream>

int main() {
    UI<std::string> ui;
    ui.run();


    CTree<int> result;

//    CTree<int> tree("+ 1 2");
//    CTree<int> tree2("* 3 4");
//    CTree<int> tree3("+ 5 6");
//
//    result = tree + tree2 + tree3;
//    std::cout << result.calculate(result.getRoot());
//    std::cout << tree.calculate(tree.getRoot());
//    std::cout << tree2.calculate(tree2.getRoot());
//    std::cout << tree3.calculate(tree3.getRoot());

    result = CTree<int>("+ 1 2") + CTree<int>("* 3 4") + CTree<int>("+ 5 6");
    std::cout << std::endl;
    result.printTree();


    return 0;
}
