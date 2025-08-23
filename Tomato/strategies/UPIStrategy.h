#include <bits/stdc++.h>
using namespace std;

#include "PaymentStrategy.h"

class UPI : public PaymentStrategy {
public:
    bool pay(double amount) override {
        // Implement UPI payment logic
        cout << "Paid " << amount << " using UPI." << endl;
        return true;
    }
};
