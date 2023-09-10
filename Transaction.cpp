#include "Transaction.h"

int Transaction::getUserId(){
    return userId;
}

string Transaction::getCategory(){
    return category;
}

int Transaction::getDate(){
    return date;
}

float Transaction::getValueOfTransaction(){
    return valueOfTransaction;
}

void Transaction::setUserId(int newUserId){
    userId = newUserId;
}

void Transaction::setCategory(string newCategory){
    category = newCategory;
}

void Transaction::setDate(int newDate){
    date = newDate;
}

void Transaction::setValueOfTransaction(float newValueOfTransaction){
    valueOfTransaction = newValueOfTransaction;
}





