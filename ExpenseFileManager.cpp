#include "ExpenseFileManager.h"

void ExpenseFileManager::saveNewExpenseToFile(Transaction newExpense){

    ifstream file;
    file.open(ACCES_PATH_TO_EXPENSE_FILE);
    if(file){
        //cout << "file exists" << endl;
        openFileAndSaveNewExpense(newExpense);
    }
    else {
        //cout << "file doesnt exists" << endl;
        creatExpenseFileAndAddFirstExpense(newExpense);
    }
}
void ExpenseFileManager::openFileAndSaveNewExpense(Transaction newExpense){

    CMarkup xml;
    xml.Load(ACCES_PATH_TO_EXPENSE_FILE);

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("SingleExpense");
    xml.IntoElem();
    xml.AddElem("UserID", newExpense.getUserId());
    xml.AddElem("Date", newExpense.getDate());
    xml.AddElem("Category", newExpense.getCategory());
    xml.AddElem("Expense", AuxiliaryMethods::convertFloatToString((newExpense.getValueOfTransaction())));
    xml.Save(ACCES_PATH_TO_EXPENSE_FILE);
    xml.ResetMainPos();
}
void ExpenseFileManager::creatExpenseFileAndAddFirstExpense(Transaction newExpense){

    CMarkup xml;
    xml.AddElem("ExpenseList");
    xml.IntoElem();
    xml.AddElem("SingleExpense");
    xml.IntoElem();
    xml.AddElem("UserID", newExpense.getUserId());
    xml.AddElem("Date", newExpense.getDate());
    xml.AddElem("Category", newExpense.getCategory());
    xml.AddElem("Expense", AuxiliaryMethods::convertFloatToString((newExpense.getValueOfTransaction())));
    xml.Save(ACCES_PATH_TO_EXPENSE_FILE);
    xml.ResetMainPos();
}

vector <Transaction> ExpenseFileManager::loadExpenseFromFile(int idLoggedInUser){

    vector <Transaction> expensesSpecyficUser;
    Transaction singleTransactionFromFile;
    CMarkup xml;
    ifstream file;
    file.open(ACCES_PATH_TO_EXPENSE_FILE); //to jest na tyle czesto uzywane ze mozna zrobic metode "bool isFileExist()" w pomocnicznych metodach

    if(file){
        xml.Load(ACCES_PATH_TO_EXPENSE_FILE);
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("SingleExpense")){
            xml.IntoElem();
            xml.FindElem("UserID");
            if (atoi(MCD_2PCSZ(xml.GetData())) == idLoggedInUser){
                singleTransactionFromFile.setUserId(idLoggedInUser);
                xml.FindElem("Date");
                singleTransactionFromFile.setDate(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("Category");
                singleTransactionFromFile.setCategory(xml.GetData());
                xml.FindElem("Expense");
                singleTransactionFromFile.setValueOfTransaction(AuxiliaryMethods::convertStringToFloat(xml.GetData()));
                xml.OutOfElem();
                expensesSpecyficUser.push_back(singleTransactionFromFile);
            }
            else{
                xml.OutOfElem();
            }
        }
    }
    else {
        return {};
    }
    return expensesSpecyficUser;
}
