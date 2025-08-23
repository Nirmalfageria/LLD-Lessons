#ifndef NOTIFICATION_SERVICE_H
#define NOTIFICATION_SERVICE_H

#include <bits/stdc++.h>
using namespace std;

class User; // forward declaration
class Order;

class NotificationService {
public:
    static void notify(Order* order) {
        cout << "Order ID: " << order->getId() << " notification sent." << endl;
    }

    static void sendNotification(User& user, const string& message) {
        cout << "Notification to user: " << message << endl;
    }
};

#endif // NOTIFICATION_SERVICE_H
