//
// Created by Malwina Juchiewicz on 17/11/2023.
//

#ifndef LAB03_V02_CONST_H
#define LAB03_V02_CONST_H

#include <set>
#include <string>

const std::set<std::string> TWO_ARG_OPER = {"+", "-", "*", "/"};
const std::set<std::string> ONE_ARG_OPER = {"sin", "cos"};


const std::string DEFAULT_VALUE_ADD = "1";
const std::string DEFAULT_VALUE = "0";
const std::string DEFAULT_STRING_ADD = "\"a\"";


const int CHILDREN_TWO_ARG = 2;
const int CHILDREN_ONE_ARG = 1;
const int CHILDREN_LEAF = 0;


const std::string MUL = "*";
const std::string DIV = "/";
const std::string ADD = "+";
const std::string SUB = "-";
const std::string COS = "cos";
const std::string SIN = "sin";


std::string const INT_TYPE = "int";
std::string const DOUBLE_TYPE = "double";
std::string const STRING_TYPE = "string";
std::string const FLOAT_TYPE = "float";

std::string const ENTER_SIGN = "> ";
std::string const ERROR_VALUES = "Error: invalid values.";
std::string const ERROR_TREE = "Error: tree is not initialized.";
std::string const INVALID_MSG = "Invalid commend.";
std::string const INVALID_CHOICE = "Invalid choice.";
std::string const NO_VARS_MSG = "No variables.";
std::string const VARS_MSG = "Variables: ";

std::string const ERROR = "Error: ";
std::string const RESULT = "Result: ";
std::string const FORMULA = "Formula: ";
std::string const TREE_STRUCTURE = "Tree structure: ";

std::string const CHOOSE_TYPE_MSG = "Enter 'int', 'double', 'float' or 'string' to choose the tree type: ";
std::string const HELP_MSG = "\nCommands: \n"
                             "\tenter <formula> - creates new tree with given formula\n"
                             "\tvars - prints all unique variables from current tree\n"
                             "\tprint - prints current tree\n"
                             "\tcomp <values> - calculates current tree with given values\n"
                             "\tjoin <formula> - joins current tree with new one\n"
                             "\texit - exits program\n";



#endif //LAB03_V02_CONST_H
