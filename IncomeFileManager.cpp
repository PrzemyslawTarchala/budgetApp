#include "IncomeFileManager.h"

IncomeFileManager::IncomeFileManager(){
    string filename = "Income.xml";
    ACCES_PATH_TO_INCOME_FILE = createPathToFile(filename);
}
