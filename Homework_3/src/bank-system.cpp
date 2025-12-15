#include "bank-system.h"

#include <iostream>
#include <optional>
#include <string>
#include <vector>

BankAccount::BankAccount(std::string accountNumber, double balance,
                         std::string accountHolder)
    : accountNumber(accountNumber),
      balance(balance),
      accountHolder(accountHolder) {}

void BankAccount::deposit(double amount) {
  balance += amount;
}

void BankAccount::withdraw(double amount) {
  if (balance >= amount) {
    balance -= amount;
  } else {
    std::cout << "Insufficient funds" << std::endl;
  }
}

double BankAccount::getBalance() const {
  return balance;
}

std::string BankAccount::getAccountHolder() const {
  return accountHolder;
}

std::string BankAccount::getAccountNumber() const {
  return accountNumber;
}

void BankAccount::printAccountinfo() const {
  std::cout << "Account:" << getAccountHolder() << std::endl;
  std::cout << "ID:" << getAccountNumber() << std::endl;
  std::cout << "Balance:" << getBalance() << std::endl;
}

void Bank::addAccount(const BankAccount& account) {
  accounts.push_back(account);
}

double Bank::getTotalBalance() const {
  double total = 0.0;
  for (const auto& acc : accounts) {
    total += acc.getBalance();
  }
  return total;
}

void Bank::printAllAccounts() const {
  for (const auto& acc : accounts) {
    acc.printAccountinfo();
    std::cout << "-----------------" << std::endl;
  }
}
