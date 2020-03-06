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
    AccountTree tree;
   while (!transactions.empty()) {
        process(tree, transactions.front());
        transactions.pop();
    }
}

//processes single transactions
void Bank::process(AccountTree tree, string transaction) {
    vector<string> parsed = parse(transaction);
    string transType = parsed[0];
    if (transType[0] == 'O') { // open
        // takes first name[1], last name[2], account numb
        int accNum = stoi(parsed[3]);
        if (!tree.openAccount(parsed[1], parsed[2], accNum)) {
            cerr << "Error opening account";
        }
    } else if (transType[0] == 'D') {// deposit

    } else if (transType[0] == 'W') {

    } else if (transType[0] == 'T') {

    } else if (transType[0] == 'H') {

    } else{
        cerr << "Invalid instruction";
            // takes account number, fund account, amount



            // takes account number, fund account, amount


            // takes from account, from fund, amount, to account, to fund


            // takes account number, or account number and fund




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

