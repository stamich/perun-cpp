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

    ostringstream ss;

    cout << "\r\n LIST:" << endl;

    list<string> contentList = loader.loadToList(path);

    for (auto const& item: contentList){
        string s = item;
        cout << "string: " << s << endl;
        la.is_operator(s);
    }

    cout << "\r\n SET (sorted elements):" << endl;

    set<string> contentSet = loader.loadToSet(path);

    for (auto const& item: contentSet){
        cout << item << endl;
    }

    cout << "\r\n VECTOR:" << endl;

    vector<string> content = loader.loadToVector(path);

    for (auto const& item: content){
        cout << item << endl;
    }

    cout << endl;
    cout << "File lines number: " << content.size() << endl;

//    string toString(content.begin(), content.end() - 1);
//    cout << la.is_operator(toString) << endl;
//    la.analyze("input.txt");
    return 0;
}