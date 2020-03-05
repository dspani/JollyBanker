//
// Created by <Name> on <Date>.
//

#include "bank.h"

// empty

Bank::Bank() = default;

Bank::~Bank() = default;

//
void Bank::processTransactions(const string& fileName) {
    ifstream infile(fileName);
    string line;
    queue <string> transactions;
    if(infile.is_open()) {
        while(getline(infile, line)) {
            // adding in to queue
            transactions.push(line);
        }
        infile.close();
    }
/*    while (!transactions.empty()) {
        cout << transactions.front() <<endl;
        transactions.pop();
    }*/
}

void Bank::displayAllBankBalances() const {}