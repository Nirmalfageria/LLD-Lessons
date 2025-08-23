#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include <bits/stdc++.h>
using namespace std;

#include "../models/Order.h"
#include "../models/Cart.h"
#include "../models/Restaurant.h"
#include "../strategies/PaymentStrategy.h"

class User; // forward declaration

class OrderFactory {
public:
    virtual ~OrderFactory() {}

    virtual Order* createOrder(
        const User* user,
        Restaurant* restaurant,
        Cart* cart,
        const vector<MenuItem*>& items,
        PaymentStrategy* paymentStrategy,
        double totalAmount,
        const string& orderType
    ) = 0;
};

#endif // ORDER_FACTORY_H
