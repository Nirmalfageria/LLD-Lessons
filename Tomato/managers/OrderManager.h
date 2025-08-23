#include<bits/stdc++.h>
using namespace std;

#include "Order.h"
#include "DeliveryOrder.h"
#include "PickupOrder.h"

class OrderManager {
    vector<Order*> orders;
    static OrderManager* instance;
    static mutex mtx;
    OrderManager() {}
public:
    static OrderManager* getInstance() {
        if (instance == nullptr) {
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr) {
                instance = new OrderManager();
            }
        }
        return instance;
    }

    void addOrder(Order* order) {
        orders.push_back(order);
    }

    void processOrders() {
        for (auto order : orders) {
            // Process each order
        }
    }

    ~OrderManager() {
        for (auto order : orders) {
            delete order;
        }
    }
};
OrderManager* OrderManager::instance = nullptr;
mutex OrderManager::mtx;
