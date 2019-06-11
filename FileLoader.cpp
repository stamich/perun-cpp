//
// Created by EB79OJ on 2019-06-10.
//

#include "FileLoader.h"

using namespace std;

vector<string> FileLoader::loadFile(std::string &path) {

    filePath = path;
    ifstream file;
    vector<string> fileContent;

    if (filePath.length() == 0){
        cout << "filepath is empty! " << endl;
    }

    try {

        file.open(filePath);

        string fileLine;
        long fileLength;
        fileLength = file.tellg();

        while (getline(file, fileLine)){

//            cout << "Content line " << fileLength << ": ";
//            cout << fileLine << endl;

            fileLength++;

            if (fileLine.size() > 0){
                fileContent.push_back(fileLine);
            }
        }
    } catch (exception e) {
        e.what();
        file.close();
    }

    file.close();

    return fileContent;
}