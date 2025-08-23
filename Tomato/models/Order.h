#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "User.h"
#include "Restaurant.h"
#include "MenuItems.h"
#include "Cart.h"
#include "../strategies/PaymentStrategy.h"

class Order {
private:
    inline static int nextId = 1;   // ✅ requires C++17
    int id;
    User* user;
    Restaurant* restaurant;
    Cart* cart;
    vector<MenuItem*> items;
    double totalAmount;
    string status;       // "Pending", "Completed", "Cancelled"
    string orderTime;    // In real code: <chrono> should be used
    PaymentStrategy* paymentStrategy;
    string scheduledTime;   // for scheduled orders

public:
    Order() 
        : id(nextId++), user(nullptr), restaurant(nullptr), cart(nullptr),
          totalAmount(0.0), status("Pending"), orderTime(""), 
          paymentStrategy(nullptr), scheduledTime("") {}

    virtual ~Order() {
        delete paymentStrategy;
        cout << "Order " << id << " destroyed." << endl;
    }

    // Abstract type identifier
    virtual string getType() const = 0;

    // === Core ===
    int getOrderId() const { return id; }

    void setUser(User* u) { user = u; }
    User* getUser() const { return user; }

    void setRestaurant(Restaurant* r) { restaurant = r; }
    Restaurant* getRestaurant() const { return restaurant; }

    void setCart(Cart* c) { cart = c; }
    Cart* getCart() const { return cart; }

    void addItem(MenuItem* item) {
        items.push_back(item);
        totalAmount += item->getPrice();
    }

    void setItems(const vector<MenuItem*>& newItems) {
        items = newItems;
        totalAmount = 0.0;
        for (auto* item : items) totalAmount += item->getPrice();
    }
    const vector<MenuItem*>& getItems() const { return items; }

    // === Time & Status ===
    void setOrderTime(const string& t) { orderTime = t; }
    string getOrderTime() const { return orderTime; }

    void setScheduled(const string& t) { scheduledTime = t; }
    string getScheduled() { return scheduledTime; }
    

    string getStatus() const { return status; }
    void setStatus(const string& s) { status = s; }

    // === Payments ===
    double getTotal() const { return totalAmount; }
int getId() const { return id; }
    void setTotalAmount(double amount) { totalAmount = amount; }

    void setPaymentStrategy(PaymentStrategy* strategy) {
        if (paymentStrategy != nullptr) delete paymentStrategy;
        paymentStrategy = strategy;
    }

    bool processPayment(double amount) {
        if (paymentStrategy == nullptr) {
            cout << "Payment strategy not set." << endl;
            return false;
        }
        return paymentStrategy->pay(amount);
    }
};

#endif // ORDER_H
