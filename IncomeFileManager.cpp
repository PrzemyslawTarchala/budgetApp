#include "IncomeFileManager.h"

IncomeFileManager::IncomeFileManager(){
    string filename = "\\\\Income.xml";
    ACCES_PATH_TO_INCOME_FILE = createPathToFile(filename);
}

void IncomeFileManager::saveNewIncomeToFile(Income newIncome){

    ifstream file;
    file.open(ACCES_PATH_TO_INCOME_FILE);
    if(file){
        //cout << "file exists" << endl;
        openFileAndSaveNewIncome(newIncome);
        system("pause");
    }
    else {
        //cout << "file doesnt exists" << endl;
        creatIcomeFileAndAddFirstUser(newIncome);
        system("pause");
    }
}

void IncomeFileManager::openFileAndSaveNewIncome(Income newIncome){
    CMarkup xml;
    xml.Load(ACCES_PATH_TO_INCOME_FILE);

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("SingleIncome");
    xml.IntoElem();
    xml.AddElem("UserID", newIncome.getUserId());
    xml.AddElem("Date", newIncome.getDate());
    xml.AddElem("Category", newIncome.getCategory());
    xml.AddElem("Income", AuxiliaryMethods::convertFloatToString((newIncome.getIncome())));
    xml.Save(ACCES_PATH_TO_INCOME_FILE);
    xml.ResetMainPos();
}

void IncomeFileManager::creatIcomeFileAndAddFirstUser(Income newIncome){

    CMarkup xml;
    xml.AddElem("IncomeList");
    xml.IntoElem();
    xml.AddElem("SingleIncome");
    xml.IntoElem();
    xml.AddElem("UserID", newIncome.getUserId());
    xml.AddElem("Date", newIncome.getDate());
    xml.AddElem("Category", newIncome.getCategory());
    xml.AddElem("Income", AuxiliaryMethods::convertFloatToString((newIncome.getIncome())));
    xml.Save(ACCES_PATH_TO_INCOME_FILE);
    xml.ResetMainPos();
}
