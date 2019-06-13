//
// Created by EB79OJ on 2019-06-10.
//

#include "FileLoader.h"

using namespace std;

list<string> FileLoader::loadToList(std::string &path) {
    filePath = path;
    ifstream file;
    list<string> content;

    if (filePath.length() == 0){
        cout << "filepath is empty!" << endl;
    }

    try {
        file.open(filePath);

        string fileLine;

        while (getline(file, fileLine)){

            content.push_back(fileLine);
        }

    } catch (exception e){
        e.what();
        file.close();
    }

    file.close();
    return content;
}

std::set<std::string> FileLoader::loadToSet(std::string &path) {
    filePath = path;
    ifstream file;
    set<string> content;

    if (filePath.length() == 0){
        cout << "filepath is empty!" << endl;
    }

    try {
        file.open(filePath);

        string fileLine;

        while (getline(file, fileLine)){

            content.insert(fileLine);
        }

    } catch (exception e){
        e.what();
        file.close();
    }

    file.close();
    return content;
}

vector<string> FileLoader::loadToVector(std::string &path) {
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