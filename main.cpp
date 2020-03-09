//
// Created by Robin Seo and Duncan Spani on 3/9/2020.
//

#include "bank.h"

// empty
Bank::Bank() = default;

// empty
Bank::~Bank() = default;

// read in a string of transaction from a file in queue.
void Bank::processTransactions(const string & fileName) {
    // adding to queue
    ostringstream ss;
    ofstream outfile("BankTransOut.txt");
    ifstream infile(fileName);
    string line;
    queue<string> transactions;
    if (infile.is_open()) {
        while (getline(infile, line)) {
            // adding in to queue
            transactions.push(line);
        }
        infile.close();
    }
    // the program will read from the queue and process the transaction in order
    while (!transactions.empty()) {
        process(accounts, transactions.front(), ss);
        transactions.pop();
    }

    displayAllBankBalances(ss);
    outfile << ss.str();
    outfile.close();
    infile.close();
}


//processes single transactions
void Bank::process(AccountTree& tree, string& transaction, ostringstream& ss) {
    vector<string> parsed = parse(transaction);
    string transType = parsed[0];
    if (transType[0] == 'O') { // open
        // takes first name[1], last name[2], account numb
        int accNum = stoi(parsed[3]);
        if (!tree.openAccount(parsed[1], parsed[2], accNum)) {
            //fund 10 shows errors in opening accounts
            ss << "ERROR: Account " + parsed[3] +
                  " already open. Transaction refused." << endl;
        }
    } else if (transType[0] == 'D') { // deposit add it to history
        string accNum = parsed[1];
        int fundNumber = accNum.back() - 48;//change ascii umber to number
        accNum.pop_back();
        if (!tree.deposit(stoi(accNum), fundNumber,
                          stoi(parsed[2]))) {
            tree.addToHistory(transaction + " (Failed)",
                              stoi(accNum),
                              fundNumber);
        } else {
            tree.addToHistory(transaction, stoi(accNum), fundNumber);
        }

    } else if (transType[0] == 'W') { // withdraw
        // takes account number, fund account, amount
        string accNum = parsed[1];
        int fundNumber = accNum.back() - 48;//change ascii number to number
        accNum.pop_back();
        if (!tree.withdraw(stoi(accNum), fundNumber, stoi(parsed[2]))) {
            //and if width
            tree.addToHistory(transaction + " (Failed)", stoi(accNum), //
                              fundNumber);
        } else {
            tree.addToHistory(transaction, stoi(accNum), fundNumber);
        }
    } else if (transType[0] == 'T') { // transfer
        int toFund = stoi(parsed[3]) % 10;
        int fromFund = stoi(parsed[1]) % 10;
        int toAcc = stoi(parsed[3]) / 10;  // acc number ex)1234
        int fromAcc = stoi(parsed[1]) / 10;
        if (tree.transfer(fromAcc, fromFund, toAcc, toFund,
                          stoi(parsed[2]), ss)) {
            tree.addToHistory(transaction, toAcc, toFund);  //check this
            tree.addToHistory(transaction, fromAcc, fromFund);
        } else {
            tree.addToHistory(transaction + " (Failed)", toAcc, toFund);
            tree.addToHistory(transaction + " (Failed)", fromAcc, fromFund);
        }
    } else if (transType[0] == 'H') { // history
        if (parsed[1].length() == 4) {
            tree.displayHistory(stoi(parsed[1]), ss);
        } else {
            string accNum = parsed[1];
            int fundNumber = accNum.back() - 48;// turning ascii to number
            accNum.pop_back();
            tree.displayFundHistory(stoi(accNum), fundNumber, ss);
        }
    } else {
        cerr << "Invalid instruction";
    }
}

// parsing the data when there is a space
vector<string> Bank::parse(string& transactions){
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

// display all Bank balances
void Bank::displayAllBankBalances(ostringstream& ss)  {
    accounts.display(ss);
}



