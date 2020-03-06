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
    if (temp == nullptr){
        temp = newNode;
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
    return true;
}

// Display information on all accounts
void AccountTree::display() const {
}

// delete all information in AccountTree
void AccountTree::clear() {}

// check if tree is empty
bool AccountTree::isEmpty() const { return true; }

bool AccountTree::openAccount(std::string &firstName, std::string &lastName, int accNum) {
    //if root = null
    // add at root
    // if not go left or right based on account number
    if (root == nullptr){
        root = new Node(new Account(firstName, lastName, accNum));
    }
    else {
        Node * temp = root;
    }
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