//
// Created by EB79OJ on 2019-06-07.
//

#ifndef COMPILER_LEXICALANALYZER_H
#define COMPILER_LEXICALANALYZER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

class LexicalAnalyzer {

private:
    std::string input;

public:
//    LexicalAnalyzer(std::string s);
//    LexicalAnalyzer(const LexicalAnalyzer& la);

    bool is_operator(const std::string& s);
    bool is_round_bracket(const std::string& s);
    bool is_integer(const std::string& s);
    bool is_double(const std::string& s);
    bool is_id(const std::string& s);
    bool is_comment(const std::string& s);
    bool is_not_legal(const std::string &s);

    void print_role_of_token(const std::string& token);

    void analyze(const std::string &nameOfFile);

    ~LexicalAnalyzer();
};


#endif //COMPILER_LEXICALANALYZER_H
