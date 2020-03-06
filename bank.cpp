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
void Bank::process(string transaction) {
    vector<string> parsed = parse(transaction);
    // "adad", "asda", "123"
    string transType = parsed[0];
    // 'O', 'w', 'T', etc
    char switchType = transType[0];
    switch (switchType) {
    case open: // open
        // takes first name[1], last name[2], account number
        if (!openAccount(parsed[1], parsed[2], stoi(parsed[3]))){
             cerr << "Error opening account";
         }
        break;
    case deposit: // deposit
        // takes account number, fund account, amount

        break;
    case withdraw: // withdraw
        // takes account number, fund account, amount
        break;
    case transfer: // transfer
        // takes from account, from fund, amount, to account, to fund
        break;
    case history: // history
        // takes account number, or account number and fund
        break;
    default: // do nothing : invalid instruction
        break;
    }
}
vector<string> Bank::parse(string transactions){
    vector<string> result;
    char breakPoint = ' ';
    string temp;
    for (auto &i: transactions)
        if (i != breakPoint) {
            temp += i;
        } else {
            result.push_back(temp);
            temp = "";
        }
    result.push_back(temp);
    return result;
}

void Bank::displayAllBankBalances() const {}

bool Bank::openAccount(string a, string b, int c) {
    bool openAccount1();
    void display();
}

