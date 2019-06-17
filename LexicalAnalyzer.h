//
// Created by EB79OJ on 2019-06-07.
//

#ifndef COMPILER_LEXICALANALYZER_H
#define COMPILER_LEXICALANALYZER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

class LexicalAnalyzer {

private:
    std::string input;

public:
//    LexicalAnalyzer(std::string s);
//    LexicalAnalyzer(const LexicalAnalyzer& la);

    bool isOperator(const std::string& s);
    bool isRoundBracket(const std::string& s);
    bool isDigit(const std::string& s);
    bool isInteger(const std::string& s);
    bool isDouble(const std::string& s);
    bool isId(const std::string& s);
    bool isComment(const std::string& s);
    bool isNotLegal(const std::string &s);

    void printRoleOfToken(const std::string& token);

    void analyze(const std::string &nameOfFile);

    ~LexicalAnalyzer();
};


#endif //COMPILER_LEXICALANALYZER_H
