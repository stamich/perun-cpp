//
// Created by Michal S. on 2019-05-07.
//
#include "FileLoader.h"

using namespace std;

string FileLoader::loadAsString(std::string &path) {
    filePath = path;
    ifstream file;
    string fileLine;

    string content;

    try {
        file.open(filePath);

        content.assign(fileLine);

        while (getline(file, fileLine)){

            content.assign(fileLine);
        }
    } catch (exception e){
        e.what();
        file.close();
    }
    file.close();
    return content;
}

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