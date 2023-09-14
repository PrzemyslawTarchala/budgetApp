#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Transaction.h"
#include "IncomeFileManager.h"
#include "ExpenseFileManager.h"
#include "DateAndTimeManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BalanceManager{

    vector <Transaction> incomes;
    vector <Transaction> expenses;
    const int ID_LOGGEDIN_USER;

    DateAndTimeManager dateAndTimeManager;
    IncomeFileManager incomeFileManager;
    ExpenseFileManager expenseFileManager;

    Transaction specifyNewTransaction();
    int getDate();
    void displaySingleTransaction(Transaction singleTransaction);
    void vectorSortingByDate(vector <Transaction> &transactions);
    void displayBalance(int fromDate, int toDate);

    void loadIncomesFromFile();
    void loadExpenseFromFile();
    void sortingTransactionsByDate(vector <Transaction> &transaction);

public:
    BalanceManager(string incomeFileName, string expensesFileName, int idLoggedInUser)
            :  incomeFileManager(incomeFileName), expenseFileManager(expensesFileName), ID_LOGGEDIN_USER(idLoggedInUser){
                loadIncomesFromFile();
                loadExpenseFromFile();
                setprecision(2);
    };

    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySpecificPeriodOfTimeBalance();
};

#endif
