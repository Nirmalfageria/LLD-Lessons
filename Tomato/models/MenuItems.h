#ifndef MENUITEMS_H
#define MENUITEMS_H

#include <iostream>
#include <string>
using namespace std;

class MenuItem {
private:
    inline static int nextId = 1;  // ✅ C++17+ static member
    int id;
    string name;
    double price;

public:
    MenuItem(string name, double price) : name(name), price(price) {
        this->id = nextId++;
    }

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    void display() const {
        cout << id << ": " << name << " - $" << price << endl;
    }
};

#endif // MENUITEMS_H
