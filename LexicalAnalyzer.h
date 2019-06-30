//
// Created by Michal S. on 2019-05-07.
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
    bool isSquareBracket(const std::string& s);
    bool isCurlyBracket(const std::string& s);
    bool isAngleBracket(const std::string& s);
    bool isDigit(const std::string& s);
    bool isInteger(const std::string& s);
    bool isDouble(const std::string& s);
    bool isId(const std::string& s);
    bool isComment(const std::string& s);
    bool isEndOfLine(const std::string &s);
    bool isSpace(const std::string& s);

    int charCount(const std::string& s);

    void printRoleOfToken(const std::string& token);
    void printRoleOfToken2(const char& token);

    void analyze(const std::string& nameOfFile);

    ~LexicalAnalyzer();
};


#endif //COMPILER_LEXICALANALYZER_H
