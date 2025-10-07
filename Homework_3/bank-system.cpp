#include <iostream>
#include <string>
#include <vector>
#include <optional>

using std::string;

class BankAccount{
        private:
        string accountNumber;
        double balance;
        string accountHolder;

        public:
        BankAccount(string accountNumber, double balance,string accountHolder) :
        accountNumber(accountNumber), balance(balance), accountHolder(accountHolder){}

        void deposit(double amount){
                balance += amount;
        }
        void withdraw(double amount){
                if(balance >= amount){
                        balance -= amount;
                }
                else {std::cout << "Insufficient funds" << std::endl;}
        }
        double getBalance() const {
                return balance;
        }
        string getAccountHolder() const {
                return accountHolder;
        }
        string getAccountNumber() const {
                return accountNumber;
        }
        void printAccountinfo() const {
                std::cout << "Account:" << getAccountHolder() << std::endl;
                std::cout << "ID:" << getAccountNumber() << std::endl;
                std::cout << "Balance:" << getBalance() << std::endl;
        }
};
class Bank {
private:
    std::vector<BankAccount> accounts;

public:
    void addAccount(const BankAccount& account) {
        accounts.push_back(account);
    }

    double getTotalBalance() const {
        double total = 0.0;
        for (const auto& acc : accounts) {
            total += acc.getBalance();
        }
        return total;
    }

    void printAllAccounts() const {
        for (const auto& acc : accounts) {
            acc.printAccountinfo();
            std::cout << "-----------------" << std::endl;
        }
    }
};

int main(){
	BankAccount vasya ("123", 0, "vasya");
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
	

