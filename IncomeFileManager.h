#ifndef INCOMEFILEMANAGER_H
#define INCOMEFILEMANAGER_H

#include <iostream>
#include "FileManager.h"

using namespace std;

class IncomeFileManager : public FileManager{
    string ACCES_PATH_TO_INCOME_FILE;

public:
    IncomeFileManager();
};

#endif
