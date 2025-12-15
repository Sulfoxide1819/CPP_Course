#include <gtest/gtest.h>

#include <sstream>

#include "bank-system.h"

TEST(BankAccountTest, CreateAccountAndGetters) {
  BankAccount account("12345", 1000.0, "Иван Иванов");

  EXPECT_EQ(account.getAccountNumber(), "12345");
  EXPECT_EQ(account.getAccountHolder(), "Иван Иванов");
  EXPECT_DOUBLE_EQ(account.getBalance(), 1000.0);
}

TEST(BankAccountTest, SuccessfulDeposit) {
  BankAccount account("123", 500.0, "Вася");
  account.deposit(250.5);

  EXPECT_DOUBLE_EQ(account.getBalance(), 750.5);
}

TEST(BankAccountTest, SuccessfulWithdrawal) {
  BankAccount account("456", 1000.0, "Петя");
  account.withdraw(300.0);

  EXPECT_DOUBLE_EQ(account.getBalance(), 700.0);
}

TEST(BankAccountTest, InsufficientFundsWithdrawal) {
  BankAccount account("789", 100.0, "Маша");

  std::stringstream buffer;
  std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

  account.withdraw(200.0);

  std::cout.rdbuf(old);

  EXPECT_DOUBLE_EQ(account.getBalance(), 100.0);

  EXPECT_TRUE(buffer.str().find("Insufficient funds") != std::string::npos);
}

TEST(BankAccountTest, NegativeAmountOperations) {
  BankAccount account("999", 500.0, "Оля");

  account.deposit(-100.0);
  EXPECT_DOUBLE_EQ(account.getBalance(), 400.0);  // 500 + (-100) = 400

  account.withdraw(-50.0);
  EXPECT_DOUBLE_EQ(account.getBalance(), 450.0);  // 400 - (-50) = 450
}

TEST(BankTest, AddAccountsAndTotalBalance) {
  Bank bank;

  BankAccount account1("001", 100.0, "Клиент1");
  BankAccount account2("002", 200.0, "Клиент2");
  BankAccount account3("003", 300.0, "Клиент3");

  bank.addAccount(account1);
  bank.addAccount(account2);
  bank.addAccount(account3);

  EXPECT_DOUBLE_EQ(bank.getTotalBalance(), 600.0);  // 100 + 200 + 300 = 600
}

TEST(BankTest, PrintAllAccounts) {
  Bank bank;

  BankAccount account1("111", 500.0, "Алексей");
  BankAccount account2("222", 750.5, "Мария");

  bank.addAccount(account1);
  bank.addAccount(account2);

  std::stringstream buffer;
  std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

  bank.printAllAccounts();

  std::cout.rdbuf(old);

  std::string output = buffer.str();

  EXPECT_TRUE(output.find("Алексей") != std::string::npos);
  EXPECT_TRUE(output.find("Мария") != std::string::npos);
  EXPECT_TRUE(output.find("111") != std::string::npos);
  EXPECT_TRUE(output.find("222") != std::string::npos);
  EXPECT_TRUE(output.find("500") != std::string::npos);
  EXPECT_TRUE(output.find("750.5") != std::string::npos);
  EXPECT_TRUE(output.find("-----------------") != std::string::npos);
}

TEST(BankAccountTest, MultipleOperationsSequence) {
  BankAccount account("777", 1000.0, "Сергей");

  account.deposit(500.0);
  account.withdraw(200.0);
  account.withdraw(100.0);
  account.deposit(300.0);

  EXPECT_DOUBLE_EQ(account.getBalance(),
                   1500.0);  // 1000 + 500 - 200 - 100 + 300 = 1500
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
