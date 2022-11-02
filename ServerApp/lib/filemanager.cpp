#include "filemanager.h"

using namespace std;

FileManager::FileManager()
{
     file = new fstream();
}

fstream *FileManager::openFile(const string &path, bool isRead)
{
    if (path.size() == 0) {
        cout << "Path is not valid" << endl;
        return file;
    }
    m_path.assign(path);
    cout << "Opening file: " << m_path << endl;
    if (isRead) {
        file->open(m_path, fstream::out | fstream::in | fstream::app);
    } else {
        file->open(m_path, fstream::out | fstream::in | fstream::trunc);
    }
    isOpening = true;
    return file;
}

bool FileManager::closeFile()
{
    cout << "Closing file" << endl;
    if (isOpening) {
        file->close();
        isOpening = false;
    }
}

string FileManager::readFile(const std::string &path)
{
    string s = "";
    openFile(path);
    cout << "Start reading file" << endl;
    string txtData;
    while (getline(*file, txtData)) {
        cout << " -> " << txtData << endl;
        // s.append(txtData, 0 , txtData.rfind(CEOL)+1);
    }
    // cout << " s -> " << s << endl;
    closeFile();
    return s;
}

bool FileManager::writeFile(const std::string &path, char *data, bool overWrite)
{
    openFile(path, !overWrite);
    cout << "Start writing file" << endl;
    *file << data;
    closeFile();
    return true;
}
