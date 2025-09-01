#include <iostream>
#include <string>
using namespace std;

// Subject interface
class BankAccount {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual double getBalance() = 0;
    virtual ~BankAccount() {}
};

// Real Subject (on remote server)
class RealBankAccount : public BankAccount {
    double balance;
public:
    RealBankAccount(double initial) : balance(initial) {}

    void deposit(double amount) override {
        balance += amount;
        cout << "[Server] Deposited: " << amount << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "[Server] Withdrawn: " << amount << endl;
        } else {
            cout << "[Server] Insufficient funds!" << endl;
        }
    }

    double getBalance() override {
        return balance;
    }
};

// Remote Proxy (represents client-side stub)
class BankAccountProxy : public BankAccount {
    RealBankAccount* realAccount; // In real-world, this would be a network call
public:
    BankAccountProxy(double initial) {
        // Simulating a "remote object" creation
        realAccount = new RealBankAccount(initial);
    }

    void deposit(double amount) override {
        cout << "[Proxy] Sending deposit request to server..." << endl;
        realAccount->deposit(amount);
    }

    void withdraw(double amount) override {
        cout << "[Proxy] Sending withdraw request to server..." << endl;
        realAccount->withdraw(amount);
    }

    double getBalance() override {
        cout << "[Proxy] Requesting balance from server..." << endl;
        return realAccount->getBalance();
    }

    ~BankAccountProxy() {
        delete realAccount;
    }
};

int main() {
    BankAccount* account = new BankAccountProxy(100.0); // client thinks it's local
    
    account->deposit(50.0);
    account->withdraw(30.0);
    cout << "Balance: " << account->getBalance() << endl;

    delete account;
    return 0;
}
