#include <iostream>
#include <string>
#include "FileLoader.h"
#include "LexicalAnalyzer.h"

using namespace std;

int main() {

    string path = "";
    cout << "Podaj sciezke do pliku: ";
    cin >> path;
    cout << "\r\n" << "Laduje plik: " << path  << " ..." << endl;

    FileLoader loader;
    loader.loadFile(path);

//    LexicalAnalyzer la;
//    la.analyze("input.txt");
    return 0;
}