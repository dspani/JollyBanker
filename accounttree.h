//
// Created by <Name> on <Date>.
//

#pragma once

#include "../../Downloads/banker-master12/account.h"
#include <iostream>

class AccountTree {
  public:
    // Create BST
    AccountTree();

    // Delete all nodes in BST
    ~AccountTree();

    // Insert new account
    bool insert(Account* account);

    // Retrieve account
    // returns true if successful AND *Account points to account
    bool retrieve(const int& accountNumber, Account*& account) const;

    // Display information on all accounts
    void display() const;

    // delete all information in AccountTree
    void clear();

    // check if tree is empty
    bool isEmpty() const;

    // Open an account
    bool openAccount (string firstName, string lastName , int accNum);

    // Deposit x amount to the account number
    bool deposit (int accNum, int amount);

    // Withdraw money from the account
    bool withdraw(int accNum, int amount);

    // Transfer money from x account to y account
    bool transfer(int toAcc, int fromAcc, int amount);

    // fund t




  private:
    class Node {
      public:
        explicit Node(Account* account)
            : account{account}, right{nullptr}, left{nullptr} {}

      private:
        Account* account;
        Node* right;
        Node* left;
    };

    Node* root;
};
