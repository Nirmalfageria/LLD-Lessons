#include<bits/stdc++.h>
using namespace std;
#include "User.h"
#include "RestaurantManager.h"
#include "MenuItems.h"

class Order {

    static int nextId;
    int id;
    User* user;
    Restaurant* restaurant;
    vector<MenuItem*> items;
    double totalAmount;
    string status; // e.g., "Pending", "Completed", "Cancelled"
    string orderTime;
    PaymentStrategy* paymentStrategy;

public:
    Order() : id(nextId++), user(nullptr), restaurant(nullptr), totalAmount(0.0), status("Pending"), orderTime(""), paymentStrategy(nullptr) {
        // Set current time in real implementation
    }

    virtual ~Order() {
        delete paymentStrategy;
        cout << "Order " << id << " destroyed." << endl;
    }

    bool processPayment(double amount) {
        if (paymentStrategy == nullptr) {
            cout << "Payment strategy not set." << endl;
            return false;
        }
        return paymentStrategy->pay(amount);
    }

    virtual string getType() const = 0; // Pure virtual function to make Order an abstract class

    void setUser(User* u) {
        this->user = u;
    }

    User* getUser() const {
        return user;
    }

    void setRestaurant(Restaurant* r) {
        this->restaurant = r;
    }

    Restaurant* getRestaurant() const {
        return restaurant;
    }

    int getId() const {
        return id;
    }

    void addItem(MenuItem* item) {
        items.push_back(item);
        totalAmount += item->getPrice();
    }

    string getTime() const {
        return orderTime;
    }

    double getTotalAmount() const {
        return totalAmount;
    }

    string getStatus() const {
        return status;
    }

    void setStatus(const string& s) {
        status = s;
    }

    void setPaymentStrategy(PaymentStrategy* strategy) {
        if (paymentStrategy != nullptr) {
            delete paymentStrategy;
        }
        paymentStrategy = strategy;
    }
};