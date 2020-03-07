;//
// Created by <Name> on <Date>.
//

#include "accounttree.h"

// empty

AccountTree::AccountTree() = default;

// Delete all nodes in BST
AccountTree::~AccountTree() = default;

// Insert new account
bool AccountTree::insert(Account* account) {
    Node *newNode = new Node(account);
    Node * temp = root;
    if (root == nullptr){
        root = newNode;
        return true;
    }
    while (newNode != nullptr) {
        if (newNode->getAccountNumber() < temp->getAccountNumber()) {
            newNode = newNode->getLeft();
        } else if (newNode->getAccountNumber() > temp->getAccountNumber()) {
            newNode = newNode->getRight();
        } else if (newNode->getAccountNumber() == temp->getAccountNumber()){
            return false;
        }
        return true;
    }
}

// Retrieve account
// returns true if successful AND *account points to account
bool AccountTree::retrieve(const int& accountNumber, Account*& account) const {
    Node *curr = root;
    while (curr->getAccountNumber() != accountNumber && curr != nullptr) {
        if (curr->getAccountNumber() < accountNumber) {
            curr = curr->getRight();
        } else if ( curr->getAccountNumber() > accountNumber && curr->getRight() != nullptr) {
            curr = curr->getLeft();
        } else if (accountNumber == curr->getAccountNumber() && curr->getLeft() != nullptr){
            account = curr->getAccount();
            return true;
        } else {
            return false;
        }
    }
    return false;
}


// Display information on all accounts
void AccountTree::display() const {
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
        acc->setFundAccount(fund, amount);
        return true;
    }
    return false;
}
// Transfer money from x account to y account
bool AccountTree::transfer(int toAcc, int fromAcc, int amount) {
    return true;
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