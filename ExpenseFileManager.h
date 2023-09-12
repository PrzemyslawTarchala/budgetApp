#ifndef EXPENSEFILEMANAGER_H
#define EXPENSEFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "Transaction.h"
#include "Markup.h"
#include "FileManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ExpenseFileManager : public FileManager{
    string EXPENSES_FILE_NAME;
    string ACCES_PATH_TO_EXPENSE_FILE;

public:
    ExpenseFileManager(string expensesFileName) : EXPENSES_FILE_NAME(expensesFileName){
        ACCES_PATH_TO_EXPENSE_FILE = createPathToFile(EXPENSES_FILE_NAME);
    };

    vector <Transaction> loadExpenseFromFile(int idLoggedInUser);

    void saveNewExpenseToFile(Transaction newExpense);
    void openFileAndSaveNewExpense(Transaction newExpense);
    void creatExpenseFileAndAddFirstExpense(Transaction newExpense);
};

#endif
