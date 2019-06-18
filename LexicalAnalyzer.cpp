//
// Created by Michal S. on 2019-05-07.
//

#include "LexicalAnalyzer.h"

using namespace std;

// Method resturns boolean values in case of operators
bool LexicalAnalyzer::isOperator(const string& s) {

    const vector<string> operators{"<", ">", "<=", ">=", "*", "+", "-", "/", "=", "-=", "*=", "+=", "/=", "++", "--", "=="};

    for (const auto& op: operators){

        if (s == op){
            //cout << "value: " << s << " matches to: " << op << " operator." << endl;
            return true;
        }
    }
    //cout << "value: " << s << " not matches to any operator \r\n";
    return false;
}

// Method resturns boolean values in case of round brackets ( )
bool LexicalAnalyzer::isRoundBracket(const string& s) {

    const vector<string> brackets{"(", ")"};

    for (const auto& br: brackets){
        if (s == br){
            //cout << "value: " << s << " is round bracket\r\n";
            return true;
        }
    }
    //cout << "value: " << s << " is not round bracket\r\n";
    return false;
}

// Method resturns boolean values in case of square brackets [ ]
bool LexicalAnalyzer::isSquareBracket(const std::string &s) {

    const vector<string> brackets{"[", "]"};
    for (const auto& br: brackets){
        if (s == br){
            return true;
        }
    }
    return false;
}

// Method resturns boolean values in case of curly brackets { }
bool LexicalAnalyzer::isCurlyBracket(const std::string &s) {

    const vector<string> brackets{"{", "}"};
    for (const auto& br: brackets){
        if (s == br){
            return true;
        }
    }
    return false;
}

// Method returns boolean values in case of angle brackets < >
bool LexicalAnalyzer::isAngleBracket(const std::string &s) {

    const vector<string> brackets{"<", ">"};
    for (const auto& br: brackets){
        if (s == br){
            return true;
        }
    }
    return false;
}

// Method returns boolean values in case of digit (integer and double/float)
bool LexicalAnalyzer::isDigit(const string &s) {
    auto result = double();
    auto i = istringstream(s);
    i >> result;
    i >> ws;
    return (!i.fail() && i.eof());
}

// Method returns boolean values for integers
bool LexicalAnalyzer::isInteger(const string& s) {
    return all_of(s.begin(), s.end(), ::isdigit);
}

// Method returns boolean values for double precision or floating point numbers
bool LexicalAnalyzer::isDouble(const string& s) {

    size_t dot = s.find(".");
    if (dot != string::npos){
        return true;
    }
    return false;
}

// Method returns boolean values for id string
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

// Method returns values in both cases - for Windows eol (\r\n - carriage return and line feed) and for Linux systems (\n - just line feed)
bool LexicalAnalyzer::isEndOfLine(const string &s){

    if (((s.find("\n") || (s.find("\r\n"))) != string::npos)){
        return true;
    }
    return false;
}

// Method returns boolean values in case of comment
bool LexicalAnalyzer::isComment(const string &s) {

    while ((s.find("/*") != string::npos) || (s.find("//") != string::npos)){
        return true;
    }
    return false;
}

// Method counts all characters in file
int LexicalAnalyzer::charCount(const std::string &s) {
    int counter = 0;
    for (size_t i = 0; i <= s.size(); i++){
        counter++;
    }
    return counter;
}

void LexicalAnalyzer::printRoleOfToken(const string& token) {

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

void LexicalAnalyzer::analyze(const string& nameOfFile) {
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