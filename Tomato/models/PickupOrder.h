#include<bits/stdc++.h>
using namespace std;    

#include "Order.h"

class PickupOrder : public Order {
    private:
    string restaurantAddress;
public:
    PickupOrder(const string& address) : restaurantAddress(address) {}

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