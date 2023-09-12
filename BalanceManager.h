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

    const int ID_LOGGEDIN_USER;
    vector <Transaction> incomes;
    vector <Transaction> expenses;

    DateAndTimeManager dateAndTimeManager;
    IncomeFileManager incomeFileManager;
    ExpenseFileManager expenseFileManager;

    Transaction specifyNewTransaction();
    int getDate();
    void displaySingleTransaction(Transaction singleTransaction);
    void vectorSortingByDate(vector <Transaction> &transactions);
    void displayBalance(int fromDate, int toDate);


public:
    BalanceManager(string incomeFileName, string expensesFileName, int idLoggedInUser)
            :  incomeFileManager(incomeFileName), expenseFileManager(expensesFileName), ID_LOGGEDIN_USER(idLoggedInUser){
                incomes = incomeFileManager.loadIncomesFromFile(ID_LOGGEDIN_USER);
                vectorSortingByDate(incomes); //nie podoba mi sie to tutaj
                expenses = expenseFileManager.loadExpenseFromFile(ID_LOGGEDIN_USER);
                vectorSortingByDate(expenses);
                setprecision(2);
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

