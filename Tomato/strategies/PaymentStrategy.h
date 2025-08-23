#ifndef PAYMENTSTRATEGY_H
#define PAYMENTSTRATEGY_H

class PaymentStrategy {
public:
    virtual bool pay(double amount) = 0; // Pure virtual function
    virtual ~PaymentStrategy() = default; // Virtual destructor
};

#endif
