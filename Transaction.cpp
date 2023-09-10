#include "Transaction.h"

int Transaction::getUserId(){
    return userId;
}

string Transaction::getCategory(){
    return category;
}

string Transaction::getDate(){
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

void Transaction::setDate(string newDate){
    date = newDate;
}

void Transaction::setValueOfTransaction(float newValueOfTransaction){
    valueOfTransaction = newValueOfTransaction;
}





