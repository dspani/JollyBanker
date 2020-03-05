//
// Created by <Name> on <Date>.
//

#include "accounttree.h"

// empty

AccountTree::AccountTree() = default;

// Delete all nodes in BST
AccountTree::~AccountTree() = default;

// Insert new account
bool AccountTree::insert(Account* account) { return true; }

// Retrieve account
// returns true if successful AND *account points to account
bool AccountTree::retrieve(const int& accountNumber, Account*& account) const {
    return true;
}

// Display information on all accounts
void AccountTree::display() const {
}

// delete all information in AccountTree
void AccountTree::clear() {}

// check if tree is empty
bool AccountTree::isEmpty() const { return true; }

bool AccountTree::openAccount(std::string firstName, std::string lastName, int accNum) {
    return true;
}

// Deposit x amount to the account number
bool AccountTree::deposit(int accNum, int amount) {
    return true;
}

// Withdraw money from the account
bool AccountTree::withdraw(int accNum, int amount) {
    return true;
}

// Transfer money from x account to y account
bool AccountTree::transfer(int toAcc, int fromAcc, int amount) {
    return true;
}