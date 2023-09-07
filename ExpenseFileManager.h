#ifndef EXPENSEFILEMANAGER_H
#define EXPENSEFILEMANAGER_H

#include <iostream>
#include "FileManager.h"

using namespace std;

class ExpenseFileManager : public FileManager{
    string ACCES_PATH_TO_EXPENSE_FILE;
public:
    ExpenseFileManager();
};

#endif
