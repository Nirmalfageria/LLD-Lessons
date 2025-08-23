#include <bits/stdc++.h>
using namespace std;
#include "TomatoApp.h"


int main(){

    TomatoApp* app = new TomatoApp();
    User* user = new User("John Doe", "john@example.com", "123 Main St");
    // user creation

    vector<Restaurant*> restaurants = app->searchRestaurantsByLocation("123 Main St");
    cout << "Restaurants in your area:" << endl;
    for (const auto& rest : restaurants) {
        cout << rest->getId() << ": " << rest->getName() << " - " << rest->getLocation() << endl;
    }
    // select a restaurant
    if (!restaurants.empty()) {
        app->selectRestaurant(user, restaurants[0]);
        restaurants[0]->displayMenu();
    }
    app->printUserCart(user);
    Order* order = app->checkOutNow(user, new CreditCard(), "Delivery");
    if(order) {
        cout << "Order ID: " << order->getId() << " placed successfully." << endl;
    }   

    app->payForOrder(order, user);
    delete app;
    delete user;
 
    return 0;
}
