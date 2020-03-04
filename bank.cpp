//
// Created by <Name> on <Date>.
//

#include "bank.h"

// empty

Bank::Bank() = default;

Bank::~Bank() = default;

void Bank::processTransactions(const string& fileName) {
    ifstream infile(fileName);
    string line;
    vector<string> data;
    if(infile.is_open()) {
        while(getline(infile, line)) {
            // adding in to queue
            data.push_back(line);
        }
        infile.close();
    }
}

void Bank::displayAllBankBalances() const {}