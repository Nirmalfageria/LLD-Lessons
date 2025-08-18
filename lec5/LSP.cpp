#include <bits/stdc++.h>
using namespace std;

class DepositeOnlyAccount {
public:
    virtual void deposite(double amount) = 0;
    virtual ~DepositeOnlyAccount() {}
};

class WithdrawOnlyAccount : public DepositeOnlyAccount {
public:
    virtual void withdraw(double amt) = 0;
    virtual ~WithdrawOnlyAccount() {}
};

class SavingAccount : public WithdrawOnlyAccount {
private:
    double bal;
public:
    SavingAccount() { bal = 0; }

    void deposite(double amt) override {
        bal += amt;
        cout << "Amount deposited to the saving account" << endl;
    }

    void withdraw(double amt) override {
        if (amt > bal) cout << "Insufficient balance" << endl;
        else {
            bal -= amt;
            cout << "Amount withdrawn from saving account" << endl;
        }
    }
};

class CurrentAccount : public WithdrawOnlyAccount {
private:
    double bal;
public:
    CurrentAccount() { bal = 0; }

    void deposite(double amt) override {
        bal += amt;
        cout << "Amount deposited to the current account" << endl;
    }

    void withdraw(double amt) override {
        if (amt > bal) cout << "Insufficient balance" << endl;
        else {
            bal -= amt;
            cout << "Amount withdrawn from current account" << endl;
        }
    }
};

class FixedAccount : public DepositeOnlyAccount {
private:
    double bal;
public:
    FixedAccount() { bal = 0; }

    void deposite(double amt) override {
        bal += amt;
        cout << "Amount deposited to the fixed account" << endl;
    }
};

class BankClients {
private:
    vector<WithdrawOnlyAccount*> withdrawAccounts;
    vector<DepositeOnlyAccount*> depositAccounts;
public:
    BankClients(vector<WithdrawOnlyAccount*> withdrawAccounts,
                vector<DepositeOnlyAccount*> depositAccounts) {
        this->withdrawAccounts = withdrawAccounts;
        this->depositAccounts = depositAccounts;
    }

    void processTransactions() {
        for (WithdrawOnlyAccount* acc : withdrawAccounts) {
            acc->deposite(1000);
            acc->withdraw(100);
        }
        for (DepositeOnlyAccount* acc : depositAccounts) {
            acc->deposite(1000);
        }
    }
};

int main() {
    vector<WithdrawOnlyAccount*> withdrawAccounts;
    withdrawAccounts.push_back(new SavingAccount());
    withdrawAccounts.push_back(new CurrentAccount());

    vector<DepositeOnlyAccount*> depositAccounts;
    depositAccounts.push_back(new FixedAccount());

    BankClients* client = new BankClients(withdrawAccounts, depositAccounts);
    client->processTransactions();

    // cleanup memory
    for (auto acc : withdrawAccounts) delete acc;
    for (auto acc : depositAccounts) delete acc;
    delete client;

    return 0;
}
