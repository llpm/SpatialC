#include "search_path.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdio>

using namespace std;

static bool fileExists(string fn) {
    struct stat s;
    int rc = stat(fn.c_str(), &s);
    if (rc == ENOENT)
        return false;
    return !S_ISDIR(s.st_mode);
}

FILE* SearchPath::open(string relPath, const char* mode) {
    for (string path: _paths) {
        string fn = path + "/" + relPath;
        if (fileExists(fn)) {
            return fopen(fn.c_str(), mode);
        }
    }
    return nullptr;
}
