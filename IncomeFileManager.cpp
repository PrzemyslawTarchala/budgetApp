#include "IncomeFileManager.h"

void IncomeFileManager::saveNewIncomeToFile(Transaction newIncome){

    ifstream file;
    file.open(ACCES_PATH_TO_INCOME_FILE);
    if(file){
        openFileAndSaveNewIncome(newIncome);
    }
    else {
        creatIncomeFileAndAddFirstIncome(newIncome);
    }
}

void IncomeFileManager::openFileAndSaveNewIncome(Transaction newIncome){
    CMarkup xml;
    xml.Load(ACCES_PATH_TO_INCOME_FILE);

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("SingleIncome");
    xml.IntoElem();
    xml.AddElem("UserID", newIncome.getUserId());
    xml.AddElem("Date", newIncome.getDate());
    xml.AddElem("Category", newIncome.getCategory());
    xml.AddElem("Income", AuxiliaryMethods::convertFloatToString((newIncome.getValueOfTransaction())));
    xml.Save(ACCES_PATH_TO_INCOME_FILE);
    xml.ResetMainPos();
}

void IncomeFileManager::creatIncomeFileAndAddFirstIncome(Transaction newIncome){

    CMarkup xml;
    xml.AddElem("IncomeList");
    xml.IntoElem();
    xml.AddElem("SingleIncome");
    xml.IntoElem();
    xml.AddElem("UserID", newIncome.getUserId());
    xml.AddElem("Date", newIncome.getDate());
    xml.AddElem("Category", newIncome.getCategory());
    xml.AddElem("Income", AuxiliaryMethods::convertFloatToString((newIncome.getValueOfTransaction())));
    xml.Save(ACCES_PATH_TO_INCOME_FILE);
    xml.ResetMainPos();
}

vector <Transaction> IncomeFileManager::loadIncomesFromFile(int idLoggedInUser){

    CMarkup xml;
    ifstream file;
    file.open(ACCES_PATH_TO_INCOME_FILE);

    if(file){
        vector <Transaction> incomesSpecyficUser;
        Transaction singleTransactionFromFile;
        xml.Load(ACCES_PATH_TO_INCOME_FILE);
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("SingleIncome")){
            xml.IntoElem();
            xml.FindElem("UserID");
            if (atoi(MCD_2PCSZ(xml.GetData())) == idLoggedInUser){
                singleTransactionFromFile.setUserId(idLoggedInUser);
                xml.FindElem("Date");
                singleTransactionFromFile.setDate(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("Category");
                singleTransactionFromFile.setCategory(xml.GetData());
                xml.FindElem("Income");
                singleTransactionFromFile.setValueOfTransaction(AuxiliaryMethods::convertStringToFloat(xml.GetData()));
                xml.OutOfElem();
                incomesSpecyficUser.push_back(singleTransactionFromFile);
            }
            else{
                xml.OutOfElem();
            }
        }
        return incomesSpecyficUser;
    }
    else {
        return {};
    }
}
