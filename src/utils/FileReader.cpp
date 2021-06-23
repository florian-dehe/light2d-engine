#include "FileReader.h"

#include <fstream>
#include <iostream>

using namespace light2d::utils;

std::string FileReader::readFile(std::string filepath) {
    std::ifstream file(filepath, std::ios::in);
    
    if (!file.is_open()) {
        throw std::runtime_error("ERROR :: File Reading :: Can't read file : " + filepath);
    }
    std::string buffer;
    std::string line;
    
    while (!file.eof()) {
        getline(file, line);
        buffer.append(line + "\n");
    }
    
    file.close();
    
    return buffer;
}
