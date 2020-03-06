//
// Created by <Name> on <Date>.
//

#include "bank.h"

// empty

Bank::Bank() = default;

Bank::~Bank() = default;

//
void Bank::processTransactions(const string& fileName) {
    // adding to queue
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
   while (!transactions.empty()) {
        process(transactions.front());
        transactions.pop();
    }
}

//processes single transactions
//processes single transactions
void Bank::process(string transaction) {
    switch (transaction[0]) {
        case 'O': // open
            // takes first name, last name, account number
            break;
        case 'D': // deposit
            // takes account number, fund account, amount
            break;
        case 'W': // withdraw
            // takes account number, fund account, amount
            break;
        case 'T': // transfer
            // takes from account, from fund, amount, to account, to fund
            break;
        case 'H': // history
            // takes account number, or account number and fund
            break;
        default:
            break;// do nothing : invalid instruction
    }

}

void Bank::displayAllBankBalances() const {}