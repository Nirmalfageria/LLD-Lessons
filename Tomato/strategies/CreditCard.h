#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <iostream>
#include "PaymentStrategy.h"

class CreditCard : public PaymentStrategy {
public:
    bool pay(double amount) override {
        std::cout << "Paid " << amount << " using Credit Card." << std::endl;
        return true;
    }
};

#endif
