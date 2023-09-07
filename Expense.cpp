#include "Expense.h"

int Expense::getUserId(){
    return userId;
}

float Expense::getIncome(){
    return income;
}

string Expense::getCategory(){
    return category;
}

void Expense::setUserId(int newUserId){
    userId = newUserId;
}

void Expense::setIncome(int newIncome){
    income = newIncome;
}

void Expense::setCategory(int newCategory){
    category = newCategory;
}
