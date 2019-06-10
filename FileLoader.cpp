//
// Created by EB79OJ on 2019-06-10.
//

#include "FileLoader.h"

using namespace std;

void FileLoader::loadFile(std::string &path) {

    filePath = path;
    ifstream file;
    vector<string> fileContent;

    if (filePath.length() == 0){
        cout << "filepath is empty! " << endl;
    }

    try {

        file.open(filePath);

        string fileLine;

        while (getline(file, fileLine)){

            cout << "Content: ";
            cout << fileLine << endl;

//            if (fileLine.size() > 0){
//                fileContent.push_back(fileLine);
//            }
        }
    } catch (exception e) {
        e.what();
        file.close();
    }

    file.close();
}