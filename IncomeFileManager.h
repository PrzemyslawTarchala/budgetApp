#ifndef INCOMEFILEMANAGER_H
#define INCOMEFILEMANAGER_H

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

class IncomeFileManager : public FileManager{
    string INCOME_FILE_NAME;
    string ACCES_PATH_TO_INCOME_FILE;

public:
    IncomeFileManager(string incomeFileName) : INCOME_FILE_NAME(incomeFileName){
        ACCES_PATH_TO_INCOME_FILE = createPathToFile(INCOME_FILE_NAME);
    };

    vector <Transaction> loadIncomesFromFile(int idLoggedInUser);

    void saveNewIncomeToFile(Transaction newIncome);
    void openFileAndSaveNewIncome(Transaction newIncome);
    void creatIncomeFileAndAddFirstIncome(Transaction newIncome);
};

#endif
