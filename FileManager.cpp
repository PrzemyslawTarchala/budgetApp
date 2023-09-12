#include "FileManager.h"

string FileManager::createPathToFile(string fileName){

    string filePath = __FILE__;
    string dirPath = filePath.substr(0, filePath.rfind("\\"));
    string newPath;

    for (size_t i = 0; i < dirPath.length(); ++i){
        if(dirPath[i] == '\\'){
            newPath += "\\\\";
        }
        else{
            newPath += dirPath[i];
        }
    }
    newPath = newPath + "\\\\" + fileName;
    return newPath;
}
