#include "BalanceManager.h"

void BalanceManager::addIncome(){
    Income newIncome;
    newIncome = specifyNewIncome();
    incomeFileManager.saveNewIncomeToFile(newIncome);
}

Income BalanceManager::specifyNewIncome(){

    Income newIncome;
    newIncome.setUserId(ID_LOGGEDIN_USER);
    newIncome.setDate(getDate());
    cout << "Enter category: ";
    newIncome.setCategory(AuxiliaryMethods::getWholeLine());
    cout << "Enter income: ";
    newIncome.setIncome(AuxiliaryMethods::getFloatNumber()); //mozna pobrac stringa -> do wekttora przekonwerotwac na floata, a do pliku stringa
    cout << "\n\n";
    cout << newIncome.getUserId() << " ";
    cout << newIncome.getDate() << " ";
    cout << newIncome.getCategory() << " ";
    cout << newIncome.getIncome() << " ";
    return newIncome;
}

string BalanceManager::getDate(){
    char choice;
    string date;
    cout << "\nDate selection: \n";
    cout << "1. Today's transaction\n";
    cout << "2. Select specific date of transaction\n";
    choice = AuxiliaryMethods::getSign();
    switch(choice){
    case '1': dateAndTimeManager.getTodaysDate(date);
        break;
    case '2': dateAndTimeManager.specificDateOfTransaction(date);
        break;
    }
    return date;
}

void BalanceManager::addExpense(){
    cout << "Add expense.\n"; system("pause");
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
