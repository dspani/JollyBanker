//
// Created by changyeon seo on 2020/03/02.
//

#include "account.h"

Account::Account(std::string first, std::string last, int acc) :
        firstName{ first }, lastName{ last }, accNum{ acc } {
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
    int total = this->funds(index);
    if (total + amount < 0) {
        return false;
    }
    else {
        funds[index] += amount;
        return true;
    }
}

ostream& operator<<(ostream& out, Account & acc) {

}