#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <iostream>
#include <fstream>
#include <string.h>
#include "constantDefine.h"

class FileManager
{
public:
    FileManager();

private:
    std::string m_path;
    std::fstream *file = nullptr;
    bool isOpening = false;

public:
    std::fstream *openFile(const std::string &path, bool isRead = true);
    bool closeFile();
    std::string readFile(const std::string &path);
    bool writeFile(const std::string &path, char *data, bool overWrite = false);
};

#endif // FILEMANAGER_H
