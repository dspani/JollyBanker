//
// Created by <Name> on <Date>.
//

#pragma once

#include "accounttree.h"
#include <fstream>
#include <string>
#include <queue>


using namespace std;
enum type {
    open = 'O', deposit = 'D', withdraw = 'W', transfer = 'T', history = 'H' };

class Bank {
  public:
    // Create Bank
    Bank();

    // Delete
    ~Bank();
    //bool openAccount (std::string firstName, std::string lastName , int accNum);

    // Reading a string line by line from a transaction file using a switch to
    // process it
    void processTransactions(const string& fileName);

    // Display all bank balances
    void displayAllBankBalances() const;

  private:
    AccountTree accounts;
    vector<string> parse(string transactions);

    void process(string transaction);
};
