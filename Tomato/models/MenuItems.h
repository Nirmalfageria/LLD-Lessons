#include<bits/stdc++.h>
using namespace std;
#define MENUITEMS_H
class MenuItem {
    private:
    static int nextId;
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

MenuItem::nextId = 1;