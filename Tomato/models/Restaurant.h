 #include<bits/stdc++.h>
 using namespace std;
 #include "MenuItems.h"

 #define RESTAURANT_H
 class Restaurant {
    private:
    static int nextId;
    int id;
    string name;
    vector<MenuItem*> menu;
    string location;
    public:
    Restaurant(string name, string location) : name(name), location(location) {
        this->id = nextId++;
    }       
    ~Restaurant() {
        for(auto item : menu) {
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
        for(const auto& item : menu) {
            item->display();
        }
    }   
 };

 Restaurant::nextId = 1;