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

class FileLoader {

private:
    std::string filePath;

public:
    //void loadFile(std::string &path);
    std::list<std::string> loadToList(std::string& path);
    std::vector<std::string> loadFile(std::string &path);
};

#endif //COMPILER_FILELOADER_H
