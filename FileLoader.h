//
// Created by EB79OJ on 2019-06-10.
//

#ifndef COMPILER_FILELOADER_H
#define COMPILER_FILELOADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <set>

class FileLoader {

private:
    std::string filePath;

public:
    //void loadFile(std::string &path);
    std::string loadAsString(std::string& path);
    std::list<std::string> loadToList(std::string& path);
    std::set<std::string> loadToSet(std::string& path);
    std::vector<std::string> loadToVector(std::string &path);
};

#endif //COMPILER_FILELOADER_H
