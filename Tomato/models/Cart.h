#include<bits/stdc++.h>
using namespace std;

#define CART_H
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
        if(restaurant == nullptr) {
            cout << "Set a restaurant before adding items to the cart." << endl;
            return;
        }
        items.push_back(item);
    }
    void displayItems() const {
        cout << "Cart Items:" << endl;
        for(const auto& item : items) {
            item->display();
        }
    }
    ~Cart() {
        for(auto item : items) {
            delete item;
        }
    }
};
