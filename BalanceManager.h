#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include "Transaction.h"
#include "IncomeFileManager.h"
#include "ExpenseFileManager.h"
#include "DateAndTimeManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BalanceManager{

    const int ID_LOGGEDIN_USER;
    vector <Transaction> incomes;
    vector <Transaction> expenses;

    DateAndTimeManager dateAndTimeManager;
    IncomeFileManager incomeFileManager;
    ExpenseFileManager expenseFileManager;

    Transaction specifyNewTransaction();
    int getDate();
    void displaySingleTransaction(Transaction singleTransaction);

public:
    BalanceManager(int idLoggedInUser) : ID_LOGGEDIN_USER(idLoggedInUser){
        incomes = incomeFileManager.loadIncomesFromFile(ID_LOGGEDIN_USER);
        expenses = expenseFileManager.loadExpenseFromFile(ID_LOGGEDIN_USER);
    };

    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySpecificPeriodOfTimeBalance();

    //temp
    void displayAllIncomesLoggedInUser();
    void displayAllExpensesLoggedInUser();
};

#endif

