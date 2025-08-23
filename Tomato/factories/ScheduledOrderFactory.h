#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H

#include "OrderFactory.h"

class ScheduledOrderFactory : public OrderFactory {
private:
    string scheduleTime;

public:
    ScheduledOrderFactory(const string& time) : scheduleTime(time) {}

    Order* createOrder(
        const User* user,
        Restaurant* restaurant,
        Cart* cart,
        const vector<MenuItem*>& items,
        PaymentStrategy* paymentStrategy,
        double totalAmount,
        const string& orderType
    ) override {
        // For simplicity, same as NowOrderFactory
        return new Order(totalAmount);
    }
};

#endif // SCHEDULED_ORDER_FACTORY_H
