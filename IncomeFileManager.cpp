#include "IncomeFileManager.h"

void IncomeFileManager::saveNewIncomeToFile(Transaction newIncome){

    ifstream file;
    file.open(ACCES_PATH_TO_INCOME_FILE);
    if(file){
        //cout << "file exists" << endl;
        openFileAndSaveNewIncome(newIncome);
        system("pause");
    }
    else {
        //cout << "file doesnt exists" << endl;
        creatIncomeFileAndAddFirstIncome(newIncome);
        system("pause");
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

    vector <Transaction> incomesSpecyficUser;
    Transaction singleTransactionFromFile;
    CMarkup xml;
    ifstream file;
    file.open(ACCES_PATH_TO_INCOME_FILE); //to jest na tyle czesto uzywane ze mozna zrobic metode "bool isFileExist()" w pomocnicznych metodach

    if(file){
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
    }
    else {
        return; //Tutaj trzba cos dorobic
    }
    return incomesSpecyficUser;
}
