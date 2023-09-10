#ifndef INCOMEFILEMANAGER_H
#define INCOMEFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Transaction.h"
#include "Markup.h"
#include "FileManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomeFileManager : public FileManager{
    string ACCES_PATH_TO_INCOME_FILE;

public:
    IncomeFileManager();

    void saveNewIncomeToFile(Transaction newIncome);
    void openFileAndSaveNewIncome(Transaction newIncome);
    void creatIncomeFileAndAddFirstIncome(Transaction newIncome);
};

#endif
