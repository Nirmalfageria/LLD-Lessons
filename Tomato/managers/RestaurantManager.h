#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include "../models/Restaurant.h"
#include <bits/stdc++.h>
using namespace std;

class RestaurantManager {
    vector<Restaurant*> restaurants;

    // Private constructor for singleton
    RestaurantManager() {}

public:
    // Delete copy/move to enforce singleton
    RestaurantManager(const RestaurantManager&) = delete;
    RestaurantManager& operator=(const RestaurantManager&) = delete;

    static RestaurantManager* getInstance() {
        static RestaurantManager instance; // C++11 thread-safe
        return &instance;
    }

    void addRestaurant(Restaurant* restaurant) {
        restaurants.push_back(restaurant);
    }

    vector<Restaurant*> getByLocation(const string& location) {
        vector<Restaurant*> result;

        // Make a lowercase copy of location
        string loc = location;
        transform(loc.begin(), loc.end(), loc.begin(), ::tolower);

        for (auto& restaurant : restaurants) {
            string restLocation = restaurant->getLocation();
            transform(restLocation.begin(), restLocation.end(), restLocation.begin(), ::tolower);

            if (restLocation == loc) {
                result.push_back(restaurant);
            }
        }
        return result;
    }
};

#endif // RESTAURANTMANAGER_H
