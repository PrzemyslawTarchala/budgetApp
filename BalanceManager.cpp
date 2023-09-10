#include "BalanceManager.h"

void BalanceManager::addIncome(){
    system ("cls");
    cout << "         NEW INCOME\n";
    cout << "----------------------------\n";
    Transaction newIncome;
    newIncome = specifyNewTransaction();
    incomes.push_back(newIncome);
    incomeFileManager.saveNewIncomeToFile(newIncome);
}

void BalanceManager::addExpense(){
    system ("cls");
    cout << "         NEW EXPENSE\n";
    cout << "----------------------------\n";
    Transaction newExpense;
    newExpense = specifyNewTransaction();
    expenseFileManager.saveNewExpenseToFile(newExpense);
}

Transaction BalanceManager::specifyNewTransaction(){

    Transaction newTransaction;
    newTransaction.setUserId(ID_LOGGEDIN_USER);
    do{
        newTransaction.setDate(getDate());
        cout << "Enter category: ";
        newTransaction.setCategory(AuxiliaryMethods::getWholeLine());
        cout << "Enter income: ";
        newTransaction.setValueOfTransaction(AuxiliaryMethods::getFloatNumber());
        cout << "\nSummary: ";
        displaySingleTransaction(newTransaction);
        cout << "\n\nConfirm 'y' / Enter again: press any key. Choice: ";
    }while(AuxiliaryMethods::getSign() != 'y');
    return newTransaction;
}

int BalanceManager::getDate(){
    char choice;
    string strDate;
    cout << "\nDate selection: \n";
    cout << "1. Today's transaction\n";
    cout << "2. Select specific date of transaction\n\n";
    cout << "Date selection choice: ";
    choice = AuxiliaryMethods::getSign();
    switch(choice){
    case '1': dateAndTimeManager.getTodaysDate(strDate);
        break;
    case '2': dateAndTimeManager.specificDateOfTransaction(strDate);
        break;
    }
    return AuxiliaryMethods::convertStringToInt(strDate);
}

void BalanceManager::displayCurrentMonthBalance(){
    cout << "DisplayCurrentMonthBalance.\n"; system("pause");
}

void BalanceManager::displayPreviousMonthBalance(){
    cout << "DisplayPreviousMonthBalance.\n"; system("pause");
}

void BalanceManager::displaySpecificPeriodOfTimeBalance(){
    cout << "DisplaySpecificPeriodOfTimeBalance.\n"; system("pause");
}

void BalanceManager::displayAllIncomesLoggedInUser(){
    for (Transaction singleTransaction : incomes){
        displaySingleTransaction(singleTransaction);
    }
    system("pause");
}

void BalanceManager::displayAllExpensesLoggedInUser(){
    for (Transaction singleTransaction : expenses){
        displaySingleTransaction(singleTransaction);
    }
    system("pause");
}

void BalanceManager::displaySingleTransaction(Transaction singleTransaction){
    cout << "\n\nDate: " << singleTransaction.getDate();
    cout << "\nCategory: " << singleTransaction.getCategory();
    cout << "\nValue of transaction: " << singleTransaction.getValueOfTransaction();
}
