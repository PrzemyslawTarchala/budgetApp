#include <iostream>

#include "BudgetManagerApp.h"

using namespace std;

int main()
{
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
            system ("pause");
            exit(0);
        }
    }
    return 0;
}
