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
void Bank::process(AccountTree& tree, string transaction) {
    cout << transaction << endl;
    vector<string> parsed = parse(transaction);
    string transType = parsed[0];
    if (transType[0] == 'O') { // open
        // takes first name[1], last name[2], account numb
        int accNum = stoi(parsed[3]);
        if (!tree.openAccount(parsed[1], parsed[2], accNum)) {
            cerr << "Error opening account" << endl;
        }
        else {
            //add to history
        }
    } else if (transType[0] == 'D') {// deposit add it to history
        string accNum = parsed[1];
        int fundNumber = accNum.back() -48;
        accNum.pop_back();
        if (!tree.deposit(stoi(accNum), fundNumber,stoi(parsed[2]))) {
            cerr << "Error: deposit not allowed" << endl;
        }
        else {
            //add to history
        }


    } else if (transType[0] == 'W') {// withdraw
        // takes account number, fund account, amount
        string accNum = parsed[1];
        int fundNumber = accNum.back() -48;
        accNum.pop_back();
        if (!tree.withdraw(stoi(accNum), fundNumber, stoi(parsed[2]))) {
            cerr << "Error: withdraw not allowed" << endl;
        }
        else {
            //add to history
        }
    } 
    else if (transType[0] == 'T') {// transfer
        
        if (tree.transfer(stoi(parsed[1]), stoi(parsed[3]), stoi(parsed[2]))) {
            //add to history
        }
    } 
    else if (transType[0] == 'H') {// history
        /*if (parsed[1].length() == 4) {
            tree.displayHistory(parsed[1]);
        }
        else {
            tree.displayFundHistory(parsed[1]);
        }*/
    } 
    else{
        cerr << "Invalid instruction";
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

