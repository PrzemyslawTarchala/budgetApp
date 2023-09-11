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
    int searchFromDate;
    int searchToDate;
    int transactionNumber = 1;
    float sumOfIncomes = 0;
    float sumOfExpenses = 0;
    dateAndTimeManager.getTimeFrameForCurrentMonth(searchFromDate, searchToDate);

    system ("cls");
    cout << "   CURRENT MONTH BALANCE\n";
    cout << "----------------------------\n";
    for (Transaction singleIncome : incomes){
        if(singleIncome.getDate() >= searchFromDate && singleIncome.getDate() <= searchToDate){
            cout << "Transaction number: " << transactionNumber;
            displaySingleTransaction(singleIncome);
            sumOfIncomes += singleIncome.getValueOfTransaction();
            ++transactionNumber;
        }
    }
    //setprecision(2);
    cout << "\nSum of incomes: " << sumOfIncomes << "\n\n";
    system("pause");
}

void BalanceManager::displayPreviousMonthBalance(){
    cout << "DisplayPreviousMonthBalance.\n"; system("pause");
}

void BalanceManager::displaySpecificPeriodOfTimeBalance(){
    cout << "DisplaySpecificPeriodOfTimeBalance.\n"; system("pause");
}

void BalanceManager::vectorSortingByDate(vector <Transaction> &transactions){
    sort(transactions.begin( ), transactions.end( ), [ ]( const auto& lhs, const auto& rhs )
    {
       return lhs.getDate() < rhs.getDate();
    });
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
    cout << "\nDate: " << singleTransaction.getDate();
    cout << "\nCategory: " << singleTransaction.getCategory();
    cout << "\nValue of transaction: " << singleTransaction.getValueOfTransaction() << "\n\n";
}
