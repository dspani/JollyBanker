//
// Created by changyeon seo on 2020/03/02.
//

#include "account.h"

Account::Account(string& last, string& first, int accNum) :
        firstName{ first },lastName{ last },  accNum{ accNum } {
    for (auto& i: funds) {
        funds[i] = 0;
    }
}

Account::~Account() = default;

int Account::getAccNumber() {
    return this->accNum;
}

//returns full name on account
string Account::getName() {
    return this->lastName + " " + this->firstName;
}

//returns fund name based on index number
string Account::fundName(int index) {
    vector<string> fundName {"Monday Market", "Prime Money Market"
                             , "Long-Term Bond" , "Short-Term Bond",
                             "500 Index Fund", "Capital Value Fund",
                             "Growth Equity Fund", "Growth Index Fund",
                             "Value Fund", "Value Stock Index"};
     return fundName[index];
}

//returns a vector containing all instructions placed on that fund
vector <string> Account::getFundHistory(int index) {
    return fundHistory[index];
}

// returns current amount held in fund based on index
int Account::getFundAccount(int index) {
    return this->funds[index];
}

// sets fund to amount , amount can be positive or negative
// if fund 0,1 or 3,4 can call fund cover to cover an overdraft
bool Account::setFundAccount(int index, int amount){
    // correct to handle if [0] has insufficient funds
    // can pull the remaining amount from [1]
    // can also do other way around
    bool success = false;
    int total = this->funds[index];
    if (total + amount < 0) {
        success = fundCover(index, amount);
    }
    else {
        funds[index] += amount;
        success = true;
    }
    return success;
}

//sets fund history in vector<string> with transaction
void Account::setFundHistory(string& transaction, int fund) {
    fundHistory[fund].push_back(transaction);
}

//check if its possible to cover funds from other fund account
bool Account::fundCover(int index, int amount) {
    int alt;
    switch (index) {
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
    if (funds[index] + funds[alt] + amount >= 0) {
        int restAmount = amount + funds[index];
        funds[index] = 0;
        funds[alt] += restAmount;
        return true;
    }
    return false;
}

