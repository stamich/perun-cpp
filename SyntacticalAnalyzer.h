//
// Created by EB79OJ on 2019-06-18.
//

#ifndef COMPILER_SYNTACTICALANALYZER_H
#define COMPILER_SYNTACTICALANALYZER_H

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

class SyntacticalAnalyzer {

    // wyrazenie - w
    bool isExpression(std::vector<std::string> tokens);

    // skladnik - s
    bool isComponent(std::vector<std::string> tokens);

    // czynnik - c
    bool isFactor(std::vector<std::string> tokens);

    bool isTermrminalChar(std::string& s);
    char* nonTerminalType(std::string& s);
    char* terminalType(std::string& s);
};


#endif //COMPILER_SYNTACTICALANALYZER_H
