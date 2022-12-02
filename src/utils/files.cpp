#include "files.h"

#include <fstream>
#include <iostream>

std::vector<std::string> read_file(const std::string& path) {
    std::ifstream fs;
    fs.open (path);

    std::string line;
    std::vector<std::string> file;
    if(fs.is_open()) {
        while(getline(fs, line)) {
            if(line.empty()) {
                file.emplace_back("");
            } else {
                file.push_back(line);
            }
        }
        fs.close();
    }else {
        std::cout << "Unable to read file at: " << path << std::endl;
    }

    return file;
}

std::string read_file_oneline(const std::string& path) {
    std::ifstream fs;
    fs.open (path);

    std::string line;
    std::string file;
    if(fs.is_open()) {
        while(getline(fs, line)) {
            file.append(line);
        }
        fs.close();
    }else {
        std::cout << "Unable to read file at: " << path << std::endl;
    }

    return file;
}