//
// Created by <Name> on <Date>.
//

#pragma once

#include "account.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

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
    void display(ostringstream& ss) const;

    void displayHistory(int accountNumber, ostringstream& ss) const;
    void displayFundHistory(int accountNumber, int fund, ostringstream& ss) const;
    void addToHistory(basic_string<char> trans, int accNum, int fund) const;


    // delete all information in AccountTree
    void clear();


    // Open an account
    bool openAccount (std::string &lastName, std::string &firstName, int accNum);

    // Deposit x amount to the account number
    bool deposit (int accNum, int fund,  int amount);

    // Withdraw money from the account
    bool withdraw(int accNum, int fund, int amount);

    // Transfer money from x account to y account
    bool transfer(int fromAcc, int fromFund, int toAcc, int toFund, int amount, ostringstream& ss);





  private:
    class Node {
      public:
        explicit Node(Account* account)
            : account{account}, right{nullptr}, left{nullptr} {}
        int getAccountNumber();
        Node* getLeft();
        Node* getRight();
        void setLeft(AccountTree::Node* newNode);
        void setRight(AccountTree::Node* newNode);
        Account* getAccount();

      private:
        Account* account;
        Node* right;
        Node* left;

    };

    static AccountTree::Node* insertRecursive(Account* account, AccountTree::Node* node);
    bool retrieveHelper(AccountTree::Node* node, int& accountNumber, Account*& account) const;
    static void clearHelper(AccountTree::Node* node);
    void displayHelper(AccountTree::Node* temp, ostringstream& ss) const;

    Node* root;
};
