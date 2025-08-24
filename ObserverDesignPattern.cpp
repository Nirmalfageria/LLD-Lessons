#include <bits/stdc++.h>
using namespace std;

class IsSubscriber {
public:
    virtual void update(string message) = 0;
};

class IsChannel {
public:
    virtual void subscribe(IsSubscriber* subscriber) = 0;
    virtual void unsubscribe(IsSubscriber* subscriber) = 0;
    virtual void notifySubscribers(string message) = 0;
};

class Channel : public IsChannel {
private:
    vector<IsSubscriber*> subscribers;
    string name;
    string lastVideo;
public:
    Channel(string name) : name(name) {}

    void subscribe(IsSubscriber* subscriber) override {
        subscribers.push_back(subscriber);
    }

    void unsubscribe(IsSubscriber* subscriber) override {
        subscribers.erase(remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
    }

    void notifySubscribers(string message) override {
        for (auto subscriber : subscribers) {
            subscriber->update(message);
        }
    }

    void uploadVideo(string title) {
        lastVideo = title;
        cout << "New video uploaded: " << title << endl;
        notifySubscribers(title);
    }

    string getVideo() {
        return "Last uploaded video: " + lastVideo;
    }
};

class Subscriber : public IsSubscriber {
private:
    string name;
    Channel* channel;
public:
    Subscriber(string name, Channel* channel) : name(name), channel(channel) {}

    void update(string message) override {
        cout << "Notification for " << name << ": " << channel->getVideo() << endl;
    }
};

int main() {
    Channel* techChannel = new Channel("Tech Channel");

    Subscriber* alice = new Subscriber("Alice", techChannel);
    Subscriber* bob = new Subscriber("Bob", techChannel);

    techChannel->subscribe(alice);
    techChannel->subscribe(bob);

    techChannel->uploadVideo("Observer Design Pattern in C++");

    techChannel->unsubscribe(bob);

    techChannel->uploadVideo("Singleton Design Pattern in C++");

    delete techChannel;
    delete alice;
    delete bob;

    return 0;
}
