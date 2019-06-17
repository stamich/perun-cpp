//
// Created by EB79OJ on 2019-06-07.
//

#include "LexicalAnalyzer.h"

using namespace std;

bool LexicalAnalyzer::isOperator(const string& s) {

    const vector<string> operators{"+", "-", "*", "/", "=", "+="};

    for (const auto& op: operators){

        if (s == op){
            cout << "value: " << s << " matches to: " << op << " operator." << endl;
            return true;
        }
    }
    cout << "value: " << s << " not matches to any operator \r\n";
}

bool LexicalAnalyzer::isRoundBracket(const string& s) {

    const vector<string> brackets{"(", ")"};

    for (const auto& br: brackets){
        if (s == br){
            cout << "value: " << s << " is round bracket\r\n";
            return true;
        }
    }
    cout << "value: " << s << " is not round bracket\r\n";
    return false;
}

bool LexicalAnalyzer::isDigit(const string &s) {
    auto result = double();
    auto i = istringstream(s);
    i >> result;
    i >> ws;
    return (!i.fail() && i.eof());
}

bool LexicalAnalyzer::isInteger(const string& s) {
    return all_of(s.begin(), s.end(), ::isdigit);
}

bool LexicalAnalyzer::isDouble(const string& s) {

    size_t dot = s.find(".");
    if (dot != string::npos){
        return true;
    }
    return false;
//    char* c = strdup(s.c_str());
//
//    if (strtok(c, ".")){
//        free(c);
//        return true;
//    }
//    return false;
}

bool LexicalAnalyzer::isId(const std::string &s) {

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

bool LexicalAnalyzer::isNotLegal(const string &s){

    if (s == "\n" || s == "\r\n"){
        return true;
    }
    return false;

    //return s == " " || s == "\n";
}

bool LexicalAnalyzer::isComment(const string &s) {
    return s == "/*" || s == "//";
}

void LexicalAnalyzer::printRoleOfToken(const string &token) {
    if (isOperator(token)){
        cout << "(is operator, " << token << ")";
    }
    else if(isRoundBracket(token)){
        cout << "(separator, " << token << ")";
    }

    else if(isInteger(token)){
        cout << "(keyword, " << token << ")";
    }
    else if(isDouble(token)){
        cout << "(statement, " << token << ")";
    }
    else if(isId(token)){
        cout << "(literal, " << token << ")";
    }
    else if(isComment(token)){
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
                printRoleOfToken(comm);
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
                printRoleOfToken(comm);
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

        if (isOperator(string(1, ch))) {
            if (!buffer.empty() && !isOperator(buffer)) {
                printRoleOfToken(buffer);
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