#ifndef NOW_ORDER_FACTORY_H
#define NOW_ORDER_FACTORY_H

#include "OrderFactory.h"

class NowOrderFactory : public OrderFactory {
public:
    Order* createOrder(
        const User* user,
        Restaurant* restaurant,
        Cart* cart,
        const vector<MenuItem*>& items,
        PaymentStrategy* paymentStrategy,
        double totalAmount,
        const string& orderType
    ) override {
        return new Order(totalAmount); // basic example
    }
};

#endif // NOW_ORDER_FACTORY_H
