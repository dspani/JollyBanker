;//
// Created by <Name> on <Date>.
//

#include "accounttree.h"

AccountTree::AccountTree() : root{ nullptr } {
}

// Delete all nodes in BST
AccountTree::~AccountTree() {
    clear();
}

//insert new account into account tree
bool AccountTree::insert(Account* account) {
    root = insertRecursive(account, root);
    return true;
}

//recursive function to find the correct place to insert an account
// sets right or sets left with new account
AccountTree::Node* AccountTree::insertRecursive(Account* account,
        AccountTree::Node* node) {
    if (node == nullptr) {
        node = new Node(account);
    }
    else if (account->getAccNumber() < node->getAccountNumber()) {
        node->setLeft(insertRecursive(account, node->getLeft()));
    }
    else {
        node->setRight(insertRecursive(account, node->getRight()));
    }
    return node;
}

// Retrieve account
// returns true if successful AND *account points to
// account containing account number
bool AccountTree::retrieve(const int& accountNumber, Account*& account) const {
    int acc = accountNumber;
    return retrieveHelper(root, acc, account);

}

//recursive function to find account
//recurses through tree until finds account containing accountNumber
// return true if account number found and points account to correct account
bool AccountTree::retrieveHelper(AccountTree::Node* node, int& accountNumber,
        Account*& account) const {
    bool success = false;
    if (node != nullptr) {
        if (accountNumber == node->getAccountNumber()) {
            success = true;
            account = node->getAccount();
        }
        else if (accountNumber < node->getAccountNumber()) {
            success = retrieveHelper(node->getLeft(), accountNumber,
                    account);
        }
        else {
            success = retrieveHelper(node->getRight(), accountNumber,
                    account);
        }
    }
    return success;
}

// Display information on all accounts
void AccountTree::display(ostringstream& ss) const{
    ss << "Displaying Transaction History for All Accounts: \n";
    AccountTree::Node* node = root;
    displayHelper(node, ss);
    
}

//goes through tree finding each account and displaying account information
void AccountTree::displayHelper(AccountTree::Node* temp,
        ostringstream& ss) const {
    if (temp != nullptr) {
        if (temp->getLeft() != nullptr) {
            displayHelper(temp->getLeft(), ss);
        }
        if (temp->getRight() != nullptr) {
            displayHelper(temp->getRight(), ss);
        }
        displayHistory(temp->getAccountNumber(), ss);
    }
}

//displays the account history for all accounts based on account number
void AccountTree::displayHistory(int accountNumber, ostringstream& ss) const {
    Account *acc;
    if (retrieve(accountNumber, acc)) {
        ss << "Displaying Transaction History for " <<
            acc->getName() << " by fund." << endl;
        for (int i = 0; i < 10; i++) {
            ss << Account::fundName(i) << ": $" <<
                acc->getFundAccount(i) << endl;
            vector<string> fundHistory = acc->getFundHistory(i);
            for (auto & it : fundHistory) {
                ss << "\t" << it << endl;
            }
        }
    }
    else {
        ss << "ERROR: Could not find account " << accountNumber << endl;
    }
}

//adds the current transaction to the history associated with that account
void AccountTree::addToHistory(basic_string<char> trans,
        int accNum, int fund) const {
    Account* acc;
    if (retrieve(accNum, acc)) {
        acc->setFundHistory(trans, fund);
    }
}

//displays history of account based on the fund number
void AccountTree::displayFundHistory(int accountNumber,
        int fund, ostringstream& ss) const {
    Account *acc;
    if (retrieve(accountNumber, acc)) {
        ss << "Displaying Transaction History for " << acc->getName()
             << "'s " << Account::fundName(fund) << ": $" <<
             acc->getFundAccount(fund) << endl;
        vector<string> fundHistory = acc->getFundHistory(fund);

        for (auto & it : fundHistory) {
            ss << "\t" << it << endl;
        }
    }
}

// delete all information in AccountTree
void AccountTree::clear() {
    //post order traversal
    if (root != nullptr) {
        clearHelper(root);
    }
}

void AccountTree::clearHelper(AccountTree::Node* node) {
    if (node != nullptr) {
        if (node->getLeft() != nullptr) {
            clearHelper(node->getLeft());
        }
        if (node->getRight() != nullptr) {
            clearHelper(node->getRight());
        }
        delete node->getAccount();
        delete node;
    }
}

bool AccountTree::openAccount(string &lastName,
        string &firstName, int accNum) {
    //if root = null
    // add at root
    // if not go left or right based on account number
    Account *acc;
    if (!retrieve(accNum, acc)) {
        acc = new Account(lastName, firstName, accNum);
        return insert(acc);
    }
    return false;
}

// Deposit x amount to the account number
bool AccountTree::deposit(int accNum, int fund, int amount) {
    Account *acc;
    if (retrieve(accNum, acc)) {
        acc->setFundAccount(fund, amount);
        return true;
    }
    return false;
}

// Withdraw money from the account
bool AccountTree::withdraw(int accNum, int fund, int amount) {
    // edge case:
    // if fund 0 or 1 does not have enough funds, check other fund
    Account* acc;
    amount -= amount * 2;
    if (retrieve(accNum, acc)) {
        return acc->setFundAccount(fund, amount);
    }
    return false;
}


// Transfer money from x account to y account
// utilizes cover from account 0 and 1 or account 3 and 4
bool AccountTree::transfer(int fromAcc, int fromFund, int toAcc,
        int toFund, int amount, ostringstream& ss) {
    Account* to;
    Account* from;

    if (retrieve(fromAcc, from)) {
        if (retrieve(toAcc, to)) {
            if (from->getFundAccount(fromFund) - amount >= 0) {
                from->setFundAccount(fromFund, amount - (amount * 2));
                to->setFundAccount(toFund,
                        to->getFundAccount(toFund) + amount);
                return true;
            }
        }
        else {
            ss << "ERROR: Could not find Account " << toAcc;
            ss << ". Transfer cancelled." << endl;
        }
    }
    else {
        ss << "ERROR: Could not find Account " << fromAcc;
        ss << ". Transfer cancelled." << endl;
    }
    return false;
}

//returns account number
int AccountTree::Node::getAccountNumber(){
    return this->account->getAccNumber();
}

//returns accounts left node
AccountTree::Node* AccountTree::Node::getLeft(){
    return this->left;
}

//sets current nodes left to a new node
void AccountTree::Node::setLeft(AccountTree::Node* newNode) {
    this->left = newNode;        // this is Node obj not AccountTree obj
}

//sets current nodes right node to new node
void AccountTree::Node::setRight(AccountTree::Node* newNode) {
    this->right = newNode;
}

//returns current nodes right node
AccountTree::Node* AccountTree::Node::getRight(){
    return this->right;
}

//returns a pointer to the account located in the node
Account* AccountTree::Node::getAccount(){
    return this->account;
}