#include "Income.h"

int Income::getUserId(){
    return userId;
}

float Income::getIncome(){
    return income;
}

string Income::getCategory(){
    return category;
}

void Income::setUserId(int newUserId){
    userId = newUserId;
}

void Income::setIncome(int newIncome){
    income = newIncome;
}

void Income::setCategory(int newCategory){
    category = newCategory;
}
