#include <iostream>

#include "BudgetManagerApp.h"

using namespace std;

int main(){

    BudgetManagerApp budgetAppManager;
    char choice;

    while(true){
        if(budgetAppManager.checkIfSomeoneIsLoggedIn() == false){
            system("cls");
            cout << "     BUDGET APP MANAGER\n";
            cout << "----------------------------\n";
            cout << "1. Sign In\n";
            cout << "2. Sign Up\n\n";
            cout << "9. Exit\n";
            cout << "-----------------------------\n\n";
            cout << "Choice: ";

            choice = AuxiliaryMethods::getSign();
            switch (choice){
                case '1': budgetAppManager.signIn();
                    break;
                case '2': budgetAppManager.signUp();
                    break;
                case '9': exit(0);
                    break;
                default: cout << "Wrong choice!\n"; system ("pause");
            }
        }
        else{
            system("cls");
            cout << "          MAIN MENU\n";
            cout << "----------------------------\n";
            cout << "1. Add income\n";
            cout << "2. Add expense\n";
            cout << "3. Display current month balance\n";
            cout << "4. Display previous month balance\n";
            cout << "5. Display specific period of time balance\n";
            cout << "6. Display all incomes of user\n";
            cout << "7. Display all incomes of user\n";
            cout << "9. Exit\n";
            cout << "-----------------------------\n\n";
            cout << "Choice: ";

            choice = AuxiliaryMethods::getSign();
            switch (choice){
                case '1': budgetAppManager.addIncome();
                    break;
                case '2': budgetAppManager.addExpense();
                    break;
                case '3': budgetAppManager.displayCurrentMonthBalance();
                    break;
                case '4': budgetAppManager.displayPreviousMonthBalance();
                    break;
                case '5': budgetAppManager.displaySpecificPeriodOfTimeBalance();
                    break;
                case '6': budgetAppManager.displayAllIncomesLoggedInUser();
                    break;
                case '7': budgetAppManager.displayAllExpensesLoggedInUser();
                    break;
                //case '8': budgetAppManager.changeLoggedInUserPassword();
                //    break;
                case '9': budgetAppManager.logout();
                    break;
                default: cout << "Wrong choice!\n"; system ("pause");
            }
        }
    }
    return 0;
}
