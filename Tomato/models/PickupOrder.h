#ifndef PICKUPORDER_H
#define PICKUPORDER_H

#include <string>
#include "Order.h"

class PickupOrder : public Order {
private:
    string restaurantAddress;

public:
    PickupOrder(const string& address) 
        : Order(), restaurantAddress(address) {}   // ✅ call base constructor

    string getType() const override {
        return "Pickup";
    }

    string getRestaurantAddress() const {
        return restaurantAddress;
    }

    void setRestaurantAddress(const string& address) {
        restaurantAddress = address;
    }
};

#endif // PICKUPORDER_H
