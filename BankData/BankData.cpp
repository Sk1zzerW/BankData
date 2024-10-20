#include <iostream>
#include <string>
#include <sstream>

class Account {
private:
    std::string ownerSurname;
    int accountNumber;
    double depositRate;
    double withdrawalRate;
    double balance;

    static int totalAccounts;

public:
    Account(const std::string& surname, int accNumber, double depRate, double withRate, double initialBalance)
        : ownerSurname(surname), accountNumber(accNumber), depositRate(depRate), withdrawalRate(withRate), balance(initialBalance) {
        totalAccounts++;
    }

    ~Account() {
        totalAccounts--;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }

    const std::string& getOwnerSurname() const {
        return ownerSurname;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getDepositRate() const {
        return depositRate;
    }

    double getWithdrawalRate() const {
        return withdrawalRate;
    }

    double getBalance() const {
        return balance;
    }

    void setOwnerSurname(const std::string& newSurname) {
        ownerSurname = newSurname;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Not enough money" << std::endl;
        }
        else {
            balance -= amount;
            std::cout << "Took " << amount << " hrn." << std::endl;
        }
    }

    void deposit(double amount) {
        balance += amount;
        std::cout << "Add " << amount << " hrn." << std::endl;
    }

    void applyInterest() {
        double interest = balance * (depositRate / 100);
        balance += interest;
        std::cout << "Percentage: " << interest << " hrn." << std::endl;
    }

    double toDollars(double exchangeRate) const {
        return balance / exchangeRate;
    }

    double toEuros(double exchangeRate) const {
        return balance / exchangeRate;
    }

    std::string getBalanceInWords() const {
        std::ostringstream oss;
        oss << balance << " hryvnas";
        return oss.str();
    }
};

int Account::totalAccounts = 0;

int main() {
    std::string surname;
    int accNumber;
    double depRate, withRate, initialBalance;

    std::cout << "name of the owner: ";
    std::getline(std::cin, surname);

    std::cout << "number of the account: ";
    std::cin >> accNumber;

    std::cout << "persentage of sending: ";
    std::cin >> depRate;

    std::cout << "percentage of taking: ";
    std::cin >> withRate;

    std::cout << "Enter a ballance: ";
    std::cin >> initialBalance;

    Account acc(surname, accNumber, depRate, withRate, initialBalance);

    std::cout << "Account owner: " << acc.getOwnerSurname() << std::endl;
    std::cout << "Balance: " << acc.getBalance() << " грн." << std::endl;

    int choice;
    do {
        std::cout << "\nChoose an option:\n";
        std::cout << "1. Take money\n";
        std::cout << "2. Put money\n";
        std::cout << "3. Count percentage\n";
        std::cout << "4. Show in $\n";
        std::cout << "5. Show in Euro\n";
        std::cout << "6. Show balance 2.0\n";
        std::cout << "0. Exit\n";
        std::cout << "Your choise: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            double amount;
            std::cout << "Enter a number for taking money: ";
            std::cin >> amount;
            acc.withdraw(amount);
            std::cout << "Your balance: " << acc.getBalance() << " hrn." << std::endl;
            break;
        }
        case 2: {
            double amount;
            std::cout << "Enter how much you wanna put: ";
            std::cin >> amount;
            acc.deposit(amount);
            std::cout << "Stock balance: " << acc.getBalance() << " hrn." << std::endl;
            break;
        }
        case 3: {
            acc.applyInterest();
            std::cout << "Stock balance after adding percentage: " << acc.getBalance() << " hrn." << std::endl;
            break;
        }
        case 4: {
            double dollarExchangeRate;
            std::cout << "Dollar cost: ";
            std::cin >> dollarExchangeRate;
            std::cout << "Ballance in dollars: " << acc.toDollars(dollarExchangeRate) << "$" << std::endl;
            break;
        }
        case 5: {
            double euroExchangeRate;
            std::cout << "Euro cost: ";
            std::cin >> euroExchangeRate;
            std::cout << "Balance in euros: " << acc.toEuros(euroExchangeRate) << "€" << std::endl;
            break;
        }
        case 6: {
            std::cout << "Balance 2.0: " << acc.getBalanceInWords() << std::endl;
            break;
        }
        case 0: {
            std::cout << "La revedere!" << std::endl;
            break;
        }
        default:
            std::cout << "Error" << std::endl;
        }

    } while (choice != 0);

    return 0;
}
