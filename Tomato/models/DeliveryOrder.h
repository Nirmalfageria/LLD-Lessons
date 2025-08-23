#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

#include <bits/stdc++.h>
using namespace std;

#include "Order.h"

class DeliveryOrder : public Order {
    string deliveryAddress;

public:
    // Constructor
    DeliveryOrder(const string& address) : deliveryAddress(address) {}

    // Override base class method
    string getType() const override {
        return "Delivery";
    }

    // Getter
    string getDeliveryAddress() const {
        return deliveryAddress;
    }

    // Setter
    void setDeliveryAddress(const string& address) {
        deliveryAddress = address;
    }
};

#endif // DELIVERYORDER_H
