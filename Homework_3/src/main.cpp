#include "bank-system.h"

int main() {
  BankAccount vasya("123", 0, "vasya");
  BankAccount petya("001", 1000, "petya");

  vasya.deposit(500);
  petya.withdraw(100);
  petya.withdraw(1000);

  Bank bank;
  bank.addAccount(vasya);
  bank.addAccount(petya);
  std::cout << bank.getTotalBalance() << std::endl;
  bank.printAllAccounts();

  return 0;
}
