#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Cart.h"
using namespace std;

class User {
private:
    inline static int nextId = 1;   // ✅ works in C++17+
    int id;
    string name;
    string address;
    string email;
    Cart* cart;

public:
    User(string name, string email, string address)
        : name(name), email(email), address(address) {
        this->id = nextId++;
        cart = new Cart();
    }

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    string getEmail() const {
        return email;
    }

    string getAddress() const {
        return address;
    }

    void setAddress(const string& newAddress) {
        address = newAddress;
    }

    void display() const {
        cout << id << ": " << name << " - " << email << endl;
    }

    Cart* getCart() const {
        return cart;
    }

    ~User() {
        delete cart;
        cout << "User " << name << " destroyed." << endl;
    }
};

#endif // USER_H
