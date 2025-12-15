#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H

#include <iostream>
#include <string>
#include <vector>

class BankAccount {
 private:
  std::string accountNumber;
  double balance;
  std::string accountHolder;

 public:
  BankAccount(std::string accountNumber, double balance,
              std::string accountHolder);
  void deposit(double amount);
  void withdraw(double amount);
  double getBalance() const;
  std::string getAccountHolder() const;
  std::string getAccountNumber() const;
  void printAccountinfo() const;
};

class Bank {
 private:
  std::vector<BankAccount> accounts;

 public:
  void addAccount(const BankAccount& account);
  double getTotalBalance() const;
  void printAllAccounts() const;
};

#endif
