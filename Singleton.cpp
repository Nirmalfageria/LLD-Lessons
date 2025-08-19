#include<bits/stdc++.h>
using namespace std;

class Singleton{

static Singleton* instance;
static mutex mtx;

    // Private constructor to prevent instantiation
    Singleton() {
        cout << "Singleton instance created." << endl;
    }

    public :
    // Static method to get the instance of the Singleton class
    static Singleton* getInstance() {
        if(instance == nullptr) {
            lock_guard<mutex> lock(mtx); // Ensure thread safety
            if(instance == nullptr) {
                // to ensure that only one instance is created
                instance = new Singleton();
            }
        return instance;
    }
   else {
        return instance;
    }
    }
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;
int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    cout << (s1 == s2) << endl;
}
