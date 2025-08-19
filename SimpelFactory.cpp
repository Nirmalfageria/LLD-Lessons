#include<bits/stdc++.h>
using namespace std;

class Burger{
public:
    virtual void prepare() = 0;
};

class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing a basic burger." << endl;
    }
};  

class CheeseBurger : public Burger {
public:
    void prepare() override {       
        cout << "Preparing a cheese burger." << endl;
    }
};   

class VeggieBurger : public Burger {
public:
    void prepare() override {        
        cout << "Preparing a veggie burger." << endl;
    }
};  

class BurgerFactory {
public:
     static Burger* createBurger(string type){

        if(type == "basic") {
            return new BasicBurger();
        } else if(type == "cheese") {
            return new CheeseBurger();
        } else if(type == "veggie") {
            return new VeggieBurger();
        } else {
            cout << "Unknown burger type." << endl;
            return nullptr;
        }   
     }

};
int main(){
    BurgerFactory factory;
    Burger* burger1 = factory.createBurger("basic");
    if(burger1) {
        burger1->prepare();
        delete burger1;
    }

    Burger* burger2 = factory.createBurger("cheese");
    if(burger2) {
        burger2->prepare();
        delete burger2;
    }

    Burger* burger3 = factory.createBurger("veggie");
    if(burger3) {
        burger3->prepare();
        delete burger3;
    }

    Burger* burger4 = factory.createBurger("unknown");
    if(burger4) {
        delete burger4; // Clean up if created
    }

    return 0;
}