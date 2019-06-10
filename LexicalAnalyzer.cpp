//
// Created by EB79OJ on 2019-06-07.
//

#include "LexicalAnalyzer.h"

using namespace std;

//LexicalAnalyzer::LexicalAnalyzer(string s) {
//    input = s;
//    LexicalAnalyzer lexicalAnalyzer(s);
//}

bool LexicalAnalyzer::is_operator(const string &s) {
    const vector<string> operators{"<", ">", "<=", ">=", "*", "+", "-", "/", "=", "-=", "*=", "+=", "/=", "++", "--", "=="};
    for(const auto& op : operators){
        if (op == s){
            return true;
        }
    }
    return false;
}

bool LexicalAnalyzer::is_round_bracket(const string &s) {
    const vector<string> brackets{"(", ")"};
    for (const auto& br: brackets){
        if (br == s){
            return true;
        }
    }
    return false;
}

bool LexicalAnalyzer::is_integer(const string &s) {
    return all_of(s.begin(), s.end(), ::isdigit);
}

bool LexicalAnalyzer::is_double(const string &s) {
    return all_of(s.begin(), s.end(), ::isdigit);
}

bool LexicalAnalyzer::is_id(const string &s) {
    if (isdigit(s[0])){
        return false;
    }
    int counter = 0;

    if (s[0] == '_'){
        counter++;
    }

    for (; counter < s.size(); counter++){
        if (!(isalnum(s[counter]))){
            return false;
        }
        return true;
    }
}

bool LexicalAnalyzer::is_not_legal(const string &s){
    return s == " " || s == "\n";
}

bool LexicalAnalyzer::is_comment(const string &s) {
    return s == "/*" || s == "//";
}

void LexicalAnalyzer::print_role_of_token(const string &token) {
    if (is_operator(token)){
        cout << "(is operator, " << token << ")";
    }
    else if(is_round_bracket(token)){
        cout << "(separator, " << token << ")";
    }

    else if(is_integer(token)){
        cout << "(keyword, " << token << ")";
    }
    else if(is_double(token)){
        cout << "(statement, " << token << ")";
    }
    else if(is_id(token)){
        cout << "(literal, " << token << ")";
    }
    else if(is_comment(token)){
        cout << "(identifier, " << token << ")";
    }
    else{
        throw runtime_error(token);
    }
}

void LexicalAnalyzer::analyze(const string &nameOfFile) {
    char ch;
    string buffer;
    fstream file(nameOfFile, fstream::in);

    if (!file.is_open()) {
        cout << "Error while opening the file!\n";
        cout << "Application stoppped!\n";
        exit(0);
    }
    cout << "File opened. Processing...\n";

    bool miltiCm = false, singleCm = false;
    while (file >> noskipws >> ch) {
        if (singleCm || miltiCm) {
            if (singleCm && ch == '\n')
                singleCm = false;

            if (miltiCm && ch == '*') {
                file >> ch;
                if (ch == EOF)
                    break;

                if (ch == '/')
                    miltiCm = false;
            }
            continue;
        }

        if (ch == '/') {
            std::string comm(1, ch);
            file >> ch;
            if (ch == EOF) {
                print_role_of_token(comm);
                break;
            }

            if (ch == '*') {
                miltiCm = true;
                comm += ch;
            } else if (ch == '/') {
                singleCm = true;
                comm += ch;
            }
            if (miltiCm || singleCm) {
                print_role_of_token(comm);
                continue;
            }
        }

//        if (isNotLegal(string(1, ch))) {
//            if (!buffer.empty()) {
//                printRoleOfToken(buffer);
//                buffer = "";
//            }
//            continue;
//        }

        if (is_operator(string(1, ch))) {
            if (!buffer.empty() && !is_operator(buffer)) {
                print_role_of_token(buffer);
                buffer = "";
            }
        }

//        if (isSeparator(string(1, ch))) {
//            if (!buffer.empty()) {
//                printRoleOfToken(buffer);
//                buffer = "";
//            }
//            if (isSeparator(string(1, ch))) {
//                printRoleOfToken(string(1, ch));
//                continue;
//            }
//        }
//        buffer += ch;
    }
    file.close();
}

LexicalAnalyzer::~LexicalAnalyzer() {

}