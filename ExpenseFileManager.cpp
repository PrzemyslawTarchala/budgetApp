#include "ExpenseFileManager.h"

ExpenseFileManager::ExpenseFileManager(){
    string filename = "\\\\Expense.xml";
    ACCES_PATH_TO_EXPENSE_FILE = createPathToFile(filename);
}

void ExpenseFileManager::saveNewExpenseToFile(Transaction newExpense){

    ifstream file;
    file.open(ACCES_PATH_TO_EXPENSE_FILE);
    if(file){
        //cout << "file exists" << endl;
        openFileAndSaveNewExpense(newExpense);
        system("pause");
    }
    else {
        //cout << "file doesnt exists" << endl;
        creatExpenseFileAndAddFirstExpense(newExpense);
        system("pause");
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
