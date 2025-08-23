#include "Restaurant.h"
#include<bits/stdc++.h>
using namespace std;

#define RESTAURANTMANAGER_H

class RestaurantManager {

    vector<Restaurant*> restaurants;
    static RestaurantManager* instance;
    static mutex mtx;
    RestaurantManager() {}
    public: 
    static RestaurantManager* getInstance() {
        if(instance == nullptr) {
            lock_guard<mutex> lock(mtx);
            if(instance == nullptr) {
                instance = new RestaurantManager();
            }
        }
        return instance;
    }

    void addRestaurant(Restaurant* restaurant) {
        restaurants.push_back(restaurant);
    }

    vector<Restaurant*> getByLocation(const string& location) {
        vector<Restaurant*> result;
        transform(location.begin(), location.end(), location.begin(), ::tolower);
        for(auto& restaurant : restaurants) {
            string restLocation = restaurant->getLocation();
            transform(restLocation.begin(), restLocation.end(), restLocation.begin(), ::tolower);
            if(restLocation == location) {
                result.push_back(restaurant);
            }
        }
        return result;
    }

};

RestaurantManager* RestaurantManager::instance = nullptr;
mutex RestaurantManager::mtx;