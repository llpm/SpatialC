#pragma once

#include <vector>
#include <string>

class SearchPath {
    std::vector<std::string> _paths;

public:
    SearchPath(std::vector<std::string> paths={}) :
        _paths(paths) {
    }

    void appendPath(std::string path) {
        _paths.push_back(path);
    }

    FILE* open(std::string relPath, const char* mode = "r");
};

