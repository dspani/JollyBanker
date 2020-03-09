//
// Created by Robin Seo and Duncan Spani on 3/9/2020.
//

#pragma once

#include "accounttree.h"
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <sstream>


using namespace std;

class Bank {
public:
    // Create Bank
    Bank();

    // Delete
    ~Bank();

    // Reading a string line by line from a transaction file using a switch to
    // process it
    void processTransactions(const string& fileName);

    // Display all bank balances
    void displayAllBankBalances(ostringstream& ss);

private:
    // AccountTree pointer
    AccountTree accounts;

    // parsing the data when there is a space
    static vector<string> parse(string& transactions);

    // process the transactions using the character beginning the line
    static void process(AccountTree& tree,
                        string& transaction, ostringstream& ss);
};
