#include<bitrs/stdc++.h>
using namespace std;    

#include "../models/Order.h"
#include "../models/Cart.h"
#include "../models/Restaurant.h"
#include "../strategies/PaymentStrategy.h"
class OrderFactory {
public:
    virtual Order* createOrder(User user, Restaurant* restaurant, Cart* cart ,vector<MenuItem*> items, PaymentStrategy* paymentStrategy ,double totalAmount, const string& orderType) = 0; // Pure virtual function
};