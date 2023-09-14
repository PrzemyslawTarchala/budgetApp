#include "BalanceManager.h"

void BalanceManager::addIncome(){
    system ("cls");
    cout << "         NEW INCOME\n";
    cout << "----------------------------\n";
    Transaction newIncome;
    newIncome = specifyNewTransaction();
    incomeFileManager.saveNewIncomeToFile(newIncome);
    incomes.push_back(newIncome);
    sortingTransactionsByDate(incomes);
    cout << "Income added.\n\n";
    system("pause");
}

void BalanceManager::addExpense(){
    system ("cls");
    cout << "         NEW EXPENSE\n";
    cout << "----------------------------\n";
    Transaction newExpense;
    newExpense = specifyNewTransaction();
    expenseFileManager.saveNewExpenseToFile(newExpense);
    expenses.push_back(newExpense);
    sortingTransactionsByDate(expenses);
    cout << "Expense added.\n\n";
    system("pause");
}

Transaction BalanceManager::specifyNewTransaction(){

    Transaction newTransaction;
    newTransaction.setUserId(ID_LOGGEDIN_USER);
    do{
        newTransaction.setDate(getDate());
        cout << "Enter category: ";
        newTransaction.setCategory(AuxiliaryMethods::getWholeLine());
        cout << "Enter value of transaction: ";
        newTransaction.setValueOfTransaction(AuxiliaryMethods::getFloatNumber());
        cout << "\nSummary: ";
        displaySingleTransaction(newTransaction);
        cout << "Confirm 'y' / Enter again: press any key. Choice: ";
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

    system ("cls");
    cout << "   CURRENT MONTH BALANCE\n";
    cout << "----------------------------\n";
    dateAndTimeManager.getTimeFrameForCurrentMonth(searchFromDate, searchToDate);
    displayBalance(searchFromDate, searchToDate);
    system("pause");
}

void BalanceManager::displayPreviousMonthBalance(){
    int searchFromDate;
    int searchToDate;

    system ("cls");
    cout << "   PREVIOUS MONTH BALANCE\n";
    cout << "----------------------------\n";
    dateAndTimeManager.getTimeFrameForPrevoiusMonth(searchFromDate, searchToDate);
    displayBalance(searchFromDate, searchToDate);
    system("pause");
}

void BalanceManager::displaySpecificPeriodOfTimeBalance(){
    int searchFromDate;
    int searchToDate;

    system ("cls");
    cout << "   PREVIOUS MONTH BALANCE\n";
    cout << "----------------------------\n";
    dateAndTimeManager.getTimeFrameSpecificByUser(searchFromDate, searchToDate);
    displayBalance(searchFromDate, searchToDate);
    system("pause");
}

void BalanceManager::displayBalance(int fromDate, int toDate){
    int transactionIncomeNumber = 1;
    int transactionExpenseNumber = 1;
    float sumOfIncomes = 0;
    float sumOfExpenses = 0;

    cout << ">>> INCOMES <<<\n\n";
    for (Transaction singleIncome : incomes){
        if(singleIncome.getDate() >= fromDate && singleIncome.getDate() <= toDate){
            cout << "Income number: " << transactionIncomeNumber;
            displaySingleTransaction(singleIncome);
            sumOfIncomes += singleIncome.getValueOfTransaction();
            ++transactionIncomeNumber;
        }
    }

    cout << ">>> EXPENSES <<<\n\n";
    for (Transaction singleExpense : expenses){
        if(singleExpense.getDate() >= fromDate && singleExpense.getDate() <= toDate){
            cout << "Expense number: " << transactionExpenseNumber;
            displaySingleTransaction(singleExpense);
            sumOfExpenses += singleExpense.getValueOfTransaction();
            ++transactionExpenseNumber;
        }
    }
    cout << ">>> SUMARRY BALANCE <<<\n\n";
    cout << "Sum of incomes: " << sumOfIncomes << "\n";
    cout << "Sum of Expense: " << sumOfExpenses << "\n";
    cout << "FIANL CASH FLOW: " << sumOfIncomes - sumOfExpenses << "\n\n";
}

void BalanceManager::displaySingleTransaction(Transaction singleTransaction){
    cout << "\nDate: " << dateAndTimeManager.displayFormatData(singleTransaction.getDate());
    cout << "\nCategory: " << singleTransaction.getCategory();
    cout << "\nValue of transaction: " << singleTransaction.getValueOfTransaction() << "\n\n";
}

void BalanceManager::loadIncomesFromFile(){
    incomes = incomeFileManager.loadIncomesFromFile(ID_LOGGEDIN_USER);
    sortingTransactionsByDate(incomes);
}

void BalanceManager::loadExpenseFromFile(){
    expenses = expenseFileManager.loadExpenseFromFile(ID_LOGGEDIN_USER);
    sortingTransactionsByDate(expenses);
}

void BalanceManager::sortingTransactionsByDate(vector <Transaction> &transactions){
    if(transactions.empty()){
        return;
    }
    else{
        sort(transactions.begin( ), transactions.end( ), [ ]( const auto& lhs, const auto& rhs )
        {
           return lhs.getDate() < rhs.getDate();
        });
    }
}
