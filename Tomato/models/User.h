#include<bits/stdc++.h>
using namespace std;
#include "Cart.h"
#define USER_H
class User {
    private:
    static int nextId;
    int id;
    string name;
    string email;
    Cart* cart;
    public:
    User(string name, string email) : name(name), email(email) {
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
    void display() const {
        cout << id << ": " << name << " - " << email << endl;
    }
    ~User() {
        delete cart;
        cout << "User " << name << " destroyed." << endl;
    }
    Cart* getCart() const {
        return cart;
    }
};

User::nextId = 1;