#include <iostream>
#include <string>
#include <vector>
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
    vector<string> content = loader.loadFile(path);

    for (auto const& item: content){
        cout << item << endl;
    }

    cout << endl;
    cout << "File lines number: " << content.size() << endl;

    LexicalAnalyzer la;

    ostringstream ss;
//    string toString(content.begin(), content.end() - 1);
//    cout << la.is_operator(toString) << endl;
//    la.analyze("input.txt");
    return 0;
}