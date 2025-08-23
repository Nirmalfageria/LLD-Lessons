#ifndef CART_H
#define CART_H

#include <bits/stdc++.h>
using namespace std;
#include "Restaurant.h"

class Cart {
private:
    Restaurant* restaurant;
    vector<MenuItem*> items;

public:
    Cart() : restaurant(nullptr) {}

    void setRestaurant(Restaurant* rest) {
        restaurant = rest;
    }

    Restaurant* getRestaurant() const {
        return restaurant;
    }

    void addItem(MenuItem* item) {
        if (restaurant == nullptr) {
            cout << "Set a restaurant before adding items to the cart." << endl;
            return;
        }
        items.push_back(item);
    }

    void display() const {
        cout << "Cart Items:" << endl;
        for (const auto& item : items) {
            item->display();
        }
    }

    void clear() {
        items.clear();
    }

    vector<MenuItem*> getItems() const {
        return items;
    }

    double getTotal() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item->getPrice();
        }
        return total;
    }

    ~Cart() {
        for (auto item : items) {
            delete item;
        }
    }
};

#endif // CART_H
