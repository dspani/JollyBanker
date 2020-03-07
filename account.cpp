//
// Created by changyeon seo on 2020/03/02.
//

#include "account.h"

Account::Account(string last, std::string first, int acc) :
        lastName{ last }, firstName{ first }, accNum{ acc } {
}

Account::~Account() {

}

int Account::getAccNumber() {
    return this->accNum;
}

string Account::getName() {
    return this->firstName + this->lastName;
}

int Account::getFundAccount(int index) {
    return this->funds[index];
}

bool Account::setFundAccount(int index, int amount){
    // correct to handle if [0] has insufficient funds
    // can pull the remaining amount from [1]
    // can also do other way around
    int total = this->funds[index];
    if (total + amount < 0) {
        fundCover(index, amount);
        return false;
    }
    else {
        funds[index] += amount;
        return true;
    }
}
                                    // negative number
bool Account::fundCover(int index, int amount) {
    int alt;
    switch(index) {
    case 0:
        alt = 1;
        break;
    case 1:
        alt = 0;
        break;
    case 2:
        alt = 1;
        break;
    case 3:
        alt = 2;
        break;
    default:
        return false;
    }
    if (funds[index] + funds[alt]- amount >= 0) {
        funds[index] = 0;
        funds[alt] = funds[index] + funds[alt] - amount;
        return true;
    }
    // add to history with an error message
    return false;

}

ostream& operator<<(ostream& out, Account & acc) {
    return out;
}