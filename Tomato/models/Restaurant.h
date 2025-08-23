#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <bits/stdc++.h>
#include "MenuItems.h"
using namespace std;

class Restaurant {
private:
    inline static int nextId = 1;
    int id;
    string name;
    vector<MenuItem*> menu;
    string location;

public:
    Restaurant(string name, string location) : name(name), location(location) {
        this->id = nextId++;
    }

    ~Restaurant() {
        for (auto item : menu) {
            delete item;
        }
        cout << "Restaurant " << name << " destroyed." << endl;
    }

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    string getLocation() const {
        return location;
    }

    void addMenuItem(MenuItem* item) {
        menu.push_back(item);
    }

    void displayMenu() const {
        cout << "Menu for " << name << " :" << endl;
        for (const auto& item : menu) {
            item->display();
        }
    }
    const vector<MenuItem*>& getMenuItems() const { return menuItems; }
};

#endif // RESTAURANT_H
