#include<bits/stdc++.h>
using namespace std;   

#include "Order.h"

class DeliveryOrder : public Order {
    string deliveryAddress;
public:
DeliveryOrder(const string& address) : deliveryAddress(address) {}

    string getType() const override {
        return "Delivery";
    }

    string getDeliveryAddress() const {
        return deliveryAddress;
    }

    void setDeliveryAddress(const string& address) {
        deliveryAddress = address;
    }
};
