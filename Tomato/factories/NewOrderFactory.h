#include<`bits/stdc++.h>
using namespace std;  

#include "OrderFactory.h"
#include "../utils/TimeUtils.h"
class NewOrderFactory : public OrderFactory {
public:
  Order* createOrder(User user, Restaurant* restaurant, Cart* cart ,vector<MenuItem*> items, PaymentStrategy* paymentStrategy ,double totalAmount, const string& orderType) override {
      Order* order = nullptr;
      if (orderType == "Delivery") {
          string address = user.getAddress(); // Assuming User has a method getAddress()
            order = new DeliveryOrder(address); 
    }
    else if (orderType == "Pickup") {
            order = new PickupOrder(restaurant->getLocation());
    }
    else {
        throw invalid_argument("Invalid order type");
    }
    order->setUser(user);
    order->setRestaurant(restaurant);
    order->setCart(cart);
    order->setItems(items);
    order->setPaymentStrategy(paymentStrategy);
    order->setTotalAmount(totalAmount);
    order->setOrderTime(TimeUtils::getCurrentTime());
    return order;
  } 
};  