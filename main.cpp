//
// Created by Michal S. on 2019-05-07.
//
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <sstream>
#include "FileLoader.h"
#include "LexicalAnalyzer.h"

using namespace std;

int main() {

    string path = "";
    cout << "Podaj sciezke do pliku: ";
    path = "C:\\Users\\EB79OJ\\Projects\\CLionProjects\\compiler\\input.txt";
    //cin >> path;
    cout << "\r\n" << "Laduje plik: " << path  << " ..." << endl;

    //auto content;

    FileLoader loader;
    LexicalAnalyzer la;

    //string a = "+";

    vector<string> content = loader.loadToVector(path);

    string a = "fiat";
    string b = "125";
    string c = "1591.25";
    string d = "\r\n";

    la.printRoleOfToken(a);
    la.printRoleOfToken(b);
    la.printRoleOfToken(c);
    la.printRoleOfToken(d);
//    cout << "Type a char: ";
//    char inputData;
//    cin >> inputData;
//
//    string input;
//    input.push_back(inputData);
//    // "<", ">", "<=", ">=", "*", "+", "-", "/", "=", "-=", "*=", "+=", "/=", "++", "--", "=="
//    switch (inputData){
//        case '<':
//        case '>':
//        case '<=':
//        case '>=':
//        case '+':
//        case '-':
//        case '*':
//        case '/':
//        case '=':
//        case '+=':
//        case '-=':
//        case '*=':
//        case '/=':
//        case '==': cout << la.isOperator(input) << endl;
//
//        //default: cout << "not a operator";
//    }
//
//    //-------------------------------------------------
//    string a = "+";
//    string b = "(";
//    string c = "12";
//    string d = "10.1";
//    string e = "3.1415926";
//    string f = "aaa";
//    string g = "g34te4";
//    string h = "rge4t34\n";
//    string i = "//comment";
//    string j = "/*comment*/";
//
//    cout << "operator: " << la.isOperator(a) << endl;
//    cout << "nawias: " << la.isRoundBracket(b) << endl;
//
//    if (la.isInteger(c)){
//        cout << c << " to liczba int.\r\n";
//    } else {
//        cout << c << " to nie liczba int.\r\n";
//    }
//
//    if (la.isDouble(d)) {
//        cout << d << " to liczba zmiennoprzec.\r\n";
//    } else {
//        cout << d << " to nie liczba zmiennoprzec.\r\n";
//    }
//
//    if (la.isDouble(e)) {
//        cout << e << " to liczba zmiennoprzec.\r\n";
//    } else {
//        cout << e << " to nie liczba zmiennoprzec.\r\n";
//    }
//
//    if (la.isDouble(f)) {
//        cout << f << " to liczba zmiennoprzec.\r\n";
//    } else {
//        cout << f << " to nie liczba zmiennoprzec.\r\n";
//    }
//
//    if (la.isId(g)) {
//        cout << g << " to jest id.\r\n";
//    } else {
//        cout << g << " to nie jest id.\r\n";
//    }
//
//    cout << la.isEndOfLine(c) << endl;
//    cout << la.isEndOfLine(g) << endl;
//    cout << la.isEndOfLine(h) << endl;
//
//    cout << la.isComment(h) << endl;
//    cout << la.isComment(i) << endl;
//    cout << la.isComment(j) << endl;

//-------------------------------------------------------------
//    int element;
//
//    for (string const& item : content){
//        //la.is_operator(item);
//        cout << "element " << element << ": " << item << endl;
//        la.is_operator(item);
//        element++;
//    }

//    cout << "cap.: " << content.capacity();
//    cout << endl;
//    for (string const& op: content){
//        cout << op << endl;
//        la.is_operator(op);
//    }

//    string content = loader.loadAsString(path);
//    cout << "STRING: " << endl;
//    cout << content << endl;

    //ostringstream ss;

//    cout << "\r\n LIST:" << endl;
//
//    list<string> contentList = loader.loadToList(path);
//
//    for (auto const& item: contentList){
//        string s = item;
//        //cout << "string: " << s << endl;
//        la.is_operator(item);
//    }


//    cout << "\r\n SET (sorted elements):" << endl;
//
//    set<string> contentSet = loader.loadToSet(path);
//
//    for (auto const& item: contentSet){
//        cout << item << endl;
//    }
//
//    cout << "\r\n VECTOR:" << endl;
//
//    vector<string> content = loader.loadToVector(path);
//
//    for (auto const& item: content){
//        bool check = la.is_operator(item);
//        cout << item << "is: " << check << endl;
//        cout << item << endl;
//        la.is_operator(item);
//    }

//    cout << endl;
//    cout << "File lines number: " << content.size() << endl;

//    string toString(content.begin(), content.end() - 1);
//    cout << la.is_operator(toString) << endl;
//    la.analyze("input.txt");

    return 0;
}