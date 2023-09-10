#ifndef INCOMEFILEMANAGER_H
#define INCOMEFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Income.h"
#include "Markup.h"
#include "FileManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomeFileManager : public FileManager{
    string ACCES_PATH_TO_INCOME_FILE;
    CMarkup xml;

public:
    IncomeFileManager();

    void saveNewIncomeToFile(Income newIncome);
    void openFileAndSaveNewIncome(Income newIncome);
    void creatIcomeFileAndAddFirstUser(Income newIncome);
};

#endif
