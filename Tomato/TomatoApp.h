#ifndef TOMATOAPP_H
#define TOMATOAPP_H

#include <bits/stdc++.h>
using namespace std;

#include "models/User.h"
#include "models/Restaurant.h"
#include "models/Cart.h"
#include "managers/RestaurantManager.h"
#include "managers/OrderManager.h"
#include "strategies/PaymentStrategy.h"
#include "strategies/UPIStrategy.h"
#include "factories/NowOrderFactory.h"
#include "factories/ScheduledOrderFactory.h"
#include "services/NotificationService.h"
#include "utils/TimeUtils.h"

class TomatoApp {
public:
    TomatoApp() {
        initialize();
    }

    void initialize() {
        Restaurant* restaurant1 = new Restaurant("Pasta Palace", "123 Main St");
        restaurant1->addMenuItem(new MenuItem("Spaghetti", 12.99));
        restaurant1->addMenuItem(new MenuItem("Fettuccine Alfredo", 14.99));

        Restaurant* restaurant2 = new Restaurant("Burger Barn", "456 Elm St");
        restaurant2->addMenuItem(new MenuItem("Classic Burger", 10.99));
        restaurant2->addMenuItem(new MenuItem("Cheese Burger", 11.99));

        Restaurant* restaurant3 = new Restaurant("Sushi Spot", "789 Oak St");
        restaurant3->addMenuItem(new MenuItem("California Roll", 8.99));
        restaurant3->addMenuItem(new MenuItem("Spicy Tuna Roll", 9.99));

        RestaurantManager* restaurantManager = RestaurantManager::getInstance();
        restaurantManager->addRestaurant(restaurant1);
        restaurantManager->addRestaurant(restaurant2);
        restaurantManager->addRestaurant(restaurant3);
    }

    vector<Restaurant*> searchRestaurantsByLocation(const string& location) {
        RestaurantManager* restaurantManager = RestaurantManager::getInstance();
        return restaurantManager->getByLocation(location);
    }

    void selectRestaurant(User* user, Restaurant* restaurant) {
        Cart* cart = user->getCart();
        cart->setRestaurant(restaurant);
    }

    void addItemsToCart(User* user, int itemId) {
        Cart* cart = user->getCart();
        if (cart->getRestaurant() == nullptr) {
            cout << "Please select a restaurant first." << endl;
            return;
        }
        for (auto item : cart->getRestaurant()->getMenuItems()) {
            if (item->getId() == itemId) {
                cart->addItem(item);
                cout << item->getName() << " added to cart." << endl;
                return;
            }
        }
        // 🔴 BUG FIX: Your code printed "Item not found" for *every* non-matching item.
        cout << "Item not found." << endl;
    }

    Order* checkOutNow(User* user, PaymentStrategy* paymentStrategy, const string& orderType) {
        return checkOut(user, paymentStrategy, orderType, new NowOrderFactory());
    }

    Order* scheduleOrder(User* user, PaymentStrategy* paymentStrategy, const string& orderType, const string& scheduleTime) {
        return checkOut(user, paymentStrategy, orderType, new ScheduledOrderFactory(scheduleTime));
    }

    Order* checkOut(User* user, PaymentStrategy* paymentStrategy, const string& orderType, OrderFactory* orderFactory) {
        Cart* cart = user->getCart();
        if (cart->getItems().empty()) {
            cout << "Cart is empty. Please add items to cart before checkout." << endl;
            return nullptr;
        }

        double totalAmount = 0.0;
        for (auto item : cart->getItems()) {
            totalAmount += item->getPrice();
        }

        Restaurant* restaurant = cart->getRestaurant();
        vector<MenuItem*> items = cart->getItems();

        Order* order = orderFactory->createOrder(*user, restaurant, cart, items, paymentStrategy, totalAmount, orderType);

        OrderManager* orderManager = OrderManager::getInstance();
        orderManager->addOrder(order);

        NotificationService::sendNotification(*user, "Order placed successfully. Order ID: " + to_string(order->getId()));

        cart->clear();
        return order;
    }

    void payForOrder(Order* order, User* user) {
        if (!order) {
            cout << "No order to pay for." << endl;
            return;
        }

        bool isPaid = order->processPayment(order->getTotalAmount()); // ✅ pass amount
        if (isPaid) {
            order->setStatus("Paid");
            NotificationService::sendNotification(*user, "Payment successful for Order ID: " + to_string(order->getId()));
        } else {
            order->setStatus("Payment Failed");
            NotificationService::sendNotification(*user, "Payment failed for Order ID: " + to_string(order->getId()));
        }
    }

    void printusercart(User* user) {
        Cart* cart = user->getCart();
        cart->display();
    }
};

#endif // TOMATOAPP_H
