;//
// Created by <Name> on <Date>.
//

#include "accounttree.h"

// empty

AccountTree::AccountTree() : root{ nullptr } {
}

// Delete all nodes in BST
AccountTree::~AccountTree() = default;

// Insert new account
bool AccountTree::insert(Account* account) {
    
    root = insertRecursive(account, root);
    return true;
}

AccountTree::Node* AccountTree::insertRecursive(Account* account, AccountTree::Node * node) {
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

bool AccountTree::retrieveHelper(AccountTree::Node* node, int& accountNumber, Account*& account) const{
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
void AccountTree::display() const {
}
void AccountTree::displayHistory(int accountNumber) const {
    Account* acc;
    retrieve(accountNumber, acc);
    cout << "Displaying Transaction History for " << acc->getName() << " by fund." << endl;
    for (int i = 0; i < 10; i++) {
        cout << acc->fundName(i) << ": $" << acc->getFundAccount(i) << endl;
        vector<string> fundHistory = acc->getFundHistory(i);
        for (int j = 0; j < fundHistory.size(); j++) {
            cout << "        " << fundHistory[j] << endl;

        }
    }
}
void AccountTree::addToHistory(string trans, int accNum, int fund) const {
    Account* acc;
    retrieve(accNum, acc);
    acc->setFundHistory(trans, fund);
}

void AccountTree::displayFundHistory(int accountNumber, int fund) const {
    Account *acc;
    //cout << "Displaying Transaction History for " << acc->getName() << "'s " << acc->
}
// delete all information in AccountTree
void AccountTree::clear() {}

// check if tree is empty
bool AccountTree::isEmpty() const { return true; }

bool AccountTree::openAccount(std::string &last, std::string &first, int accNum) {
    //if root = null
    // add at root
    // if not go left or right based on account number
    Account *acc = new Account(last, first, accNum);
    return insert(acc);
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
        if (acc->setFundAccount(fund, amount)) {
            return true;
        } // w 20000 should return false?
        return false;
    }
}


// Transfer money from x account to y account
bool AccountTree::transfer(int fromAcc, int fromFund, int toAcc, int toFund, int amount) {
    //int toFund = toAcc % 10;
    //int fromFund = fromAcc % 10;
    //toAcc /= 10;
    //fromAcc /= 10;
    Account* to;
    Account* from;
    
    if (retrieve(fromAcc, from) && retrieve(toAcc, to)) {
        if (from->getFundAccount(fromFund) - amount >= 0) {
            from->setFundAccount(fromFund, from->getFundAccount(fromFund) - amount - (amount * 2));
            to->setFundAccount(toFund, to->getFundAccount(toFund) + amount);
            return true;
        }
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