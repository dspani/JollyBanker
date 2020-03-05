//
// Created by changyeon seo on 2020/03/02.
//

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
    Account(std::string first, std::string last, int acc);
    ~Account();
    int getAccNumber();
    string getName();
    int getFundAccount(int index);
    bool setFundAccount(int index, int amount);

    friend ostream & operator<<(ostream& out, Account & acc);
private:
    string firstName;
    string lastName;
    int accNum;
    int funds[10];
    std::vector<std::string> fundHistory[10];
};

#endif // JOLLYBANKER_ACCOUNT_H
