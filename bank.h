//
// Created by <Name> on <Date>.
//

#pragma once

#include "accounttree.h"
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <queue>


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
    AccountTree accounts;
    static vector<string> parse(string& transactions);

    static void process(AccountTree& tree, string& transaction, ostringstream& ss);
};
