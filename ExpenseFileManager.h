#ifndef EXPENSEFILEMANAGER_H
#define EXPENSEFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Transaction.h"
#include "Markup.h"
#include "FileManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ExpenseFileManager : public FileManager{
    string ACCES_PATH_TO_EXPENSE_FILE;

public:
    ExpenseFileManager();

    void saveNewExpenseToFile(Transaction newExpense);
    void openFileAndSaveNewExpense(Transaction newExpense);
    void creatExpenseFileAndAddFirstExpense(Transaction newExpense);
};

#endif
