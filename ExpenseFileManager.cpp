#include "ExpenseFileManager.h"

ExpenseFileManager::ExpenseFileManager(){
    string filename = "Expense.xml";
    ACCES_PATH_TO_EXPENSE_FILE = createPathToFile(filename);
}
