//
// Created by Michal S. on 2019-05-07.
//

#ifndef COMPILER_FILELOADER_H
#define COMPILER_FILELOADER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <array>
#include <string>
#include <list>
#include <vector>
#include <set>

class FileLoader {

private:
    std::string filePath;

public:
    //void loadFile(std::string &path);
    char loadAsChar(std::string& path);
    std::string loadAsString(std::string& path);
    std::array<std::string, 20> loadAsArray(std::string& path);
    std::list<std::string> loadToList(std::string& path);
    std::set<std::string> loadToSet(std::string& path);
    std::vector<std::string> loadToVector(std::string &path);
};

#endif //COMPILER_FILELOADER_H
