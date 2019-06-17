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

    //-------------------------------------------------
    string a = "+";
    string b = "(";
    string c = "12";
    string d = "10.1";
    string e = "3.1415926";
    string f = "aaa";
    string g = "g34te4";

    la.isOperator(a);
    la.isRoundBracket(b);

    if (la.isInteger(c)){
        cout << c << " to liczba int.\r\n";
    } else {
        cout << c << " to nie liczba int.\r\n";
    }

    if (la.isDouble(d)) {
        cout << d << " to liczba zmiennoprzec.\r\n";
    } else {
        cout << d << " to nie liczba zmiennoprzec.\r\n";
    }

    if (la.isDouble(e)) {
        cout << e << " to liczba zmiennoprzec.\r\n";
    } else {
        cout << e << " to nie liczba zmiennoprzec.\r\n";
    }

    if (la.isDouble(f)) {
        cout << f << " to liczba zmiennoprzec.\r\n";
    } else {
        cout << f << " to nie liczba zmiennoprzec.\r\n";
    }

    cout << "id: " << la.isId(g);

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