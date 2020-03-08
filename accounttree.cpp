;//
// Created by <Name> on <Date>.
//

#include <sstream>
#include "accounttree.h"

// empty

AccountTree::AccountTree() : root{ nullptr } {
}

// Delete all nodes in BST
AccountTree::~AccountTree() {
    clear();
}

// Insert new account
bool AccountTree::insert(Account* account) {
    root = insertRecursive(account, root);
    return true;
}

AccountTree::Node* AccountTree::insertRecursive(Account* account, AccountTree::Node* node) {
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
// returns true if successful AND *account points to account
bool AccountTree::retrieve(const int& accountNumber, Account*& account) const {
    int acc = accountNumber;
    return retrieveHelper(root, acc, account);

}

bool AccountTree::retrieveHelper(AccountTree::Node* node, int& accountNumber, Account*& account) const {
    bool success = false;
    if (node != nullptr) {
        if (accountNumber == node->getAccountNumber()) {
            success = true;
            account = node->getAccount();
        }
        else if (accountNumber < node->getAccountNumber()) {
            success = retrieveHelper(node->getLeft(), accountNumber, account);
        }
        else {
            success = retrieveHelper(node->getRight(), accountNumber, account);
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

void AccountTree::displayHelper(AccountTree::Node* temp, ostringstream& ss) const {
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

void AccountTree::displayHistory(int accountNumber, ostringstream& ss) const {
    Account* acc;
    retrieve(accountNumber, acc);
    ss << "Displaying Transaction History for " << acc->getName() << " by fund." << endl;
    for (int i = 0; i < 10; i++) {
        ss << Account::fundName(i) << ": $" << acc->getFundAccount(i) << endl;
        vector<string> fundHistory = acc->getFundHistory(i);
        for (auto it = fundHistory.begin();
        it != fundHistory.end(); ++it) {
            ss << "\t" << *it << endl;
        }
    }
}

void AccountTree::addToHistory(basic_string<char> trans, int accNum, int fund) const {
    Account* acc;
    if (retrieve(accNum, acc)) {
        acc->setFundHistory(trans, fund);
    }
}

void AccountTree::displayFundHistory(int accountNumber, int fund, ostringstream& ss) const {
    Account *acc;
    if (retrieve(accountNumber, acc)) {
        ss << "Displaying Transaction History for " << acc->getName()
             << "'s " << Account::fundName(fund) << ": $" << acc->getFundAccount(fund) << endl;
        vector<string> fundHistory = acc->getFundHistory(fund);

        for (auto it = fundHistory.begin();
             it != fundHistory.end(); ++it) {
            ss << "\t" << *it << endl;
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

bool AccountTree::openAccount(string &last, string &first, int accNum) {
    //if root = null
    // add at root
    // if not go left or right based on account number
    Account *acc;
    if (!retrieve(accNum, acc)) {
        acc = new Account(last, first, accNum);
        return insert(acc);
    }
    return false;
}

// Deposit x amount to the account number
bool AccountTree::deposit(int accNum, int fund, int amount) {
    Account *acc;
    retrieve(accNum, acc);
    acc->setFundAccount(fund, amount);
    return true;
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
bool AccountTree::transfer(int fromAcc, int fromFund, int toAcc, int toFund, int amount) {
    Account* to;
    Account* from;

    if (retrieve(fromAcc, from)) {
        if (retrieve(toAcc, to)) {
            if (from->getFundAccount(fromFund) - amount >= 0) {
                from->setFundAccount(fromFund, amount - (amount * 2));
                to->setFundAccount(toFund, to->getFundAccount(toFund) + amount);
                return true;
            }
        }
        else {
            cout << "ERROR: Could not find Account " << toAcc;
            cout << ". Transfer cancelled." << endl;
        }
    }
    else {
        cout << "ERROR: Could not find Account " << fromAcc;
        cout << ". Transfer cancelled." << endl;
    }
    return false;
}

int AccountTree::Node::getAccountNumber(){
    return this->account->getAccNumber();
}
AccountTree::Node* AccountTree::Node::getLeft(){
    return this->left;
}
void AccountTree::Node::setLeft(AccountTree::Node* newNode) {
    this->left = newNode;        // this is Node obj not AccountTree obj
}
//return type / location/ name/ arg
void AccountTree::Node::setRight(AccountTree::Node* newNode) {
    this->right = newNode;
}
AccountTree::Node* AccountTree::Node::getRight(){
    return this->right;
}

Account* AccountTree::Node::getAccount(){
    return this->account;
}