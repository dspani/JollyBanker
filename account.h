//
// Created by Robin Seo and Duncan Spani on 3/9/2020.
//
#pragma once
#ifndef JOLLYBANKER_ACCOUNT_H
#define JOLLYBANKER_ACCOUNT_H
#include <string>
#include <vector>
// ID number
// Name
// Funds[10]
// Funds history
using namespace std;

class Account {
  public:
    Account(string& last, string& first, int accNum);
    ~Account();
    int getAccNumber();
    string getName();
    static string fundName(int index);
    int getFundAccount(int index);
    bool setFundAccount(int index, int amount);
    void setFundHistory(string& transaction, int fund);
    vector <string> getFundHistory(int index);


  private:
    string firstName;
    string lastName;
    int accNum;
    int funds[10] = {0,0,0,0,0,0,0,0,0,0};
    std::vector<std::string> fundHistory[10];
    bool fundCover(int index, int amount);
};
#endif // JOLLYBANKER_ACCOUNT_H
