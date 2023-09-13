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

void Transaction::setUserId(int userId){
    this -> userId = userId;
}

void Transaction::setCategory(string category){
    this -> category = category;
}

void Transaction::setDate(int date){
    this -> date = date;
}

void Transaction::setValueOfTransaction(float valueOfTransaction){
    this -> valueOfTransaction = valueOfTransaction;
}





