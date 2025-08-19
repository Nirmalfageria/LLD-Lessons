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

class Bread {
public:
    virtual void bake() = 0;    
};

class NormalBread : public Bread {
public:
    void bake() override {
        cout << "Baking normal bread." << endl;
    }
};
class WholeGrainBread : public Bread {
public:
    void bake() override {        
        cout << "Baking whole grain bread." << endl;
    }       
};  

class factory{
    public:
    virtual Burger* createBurger(string type) = 0;
    virtual Bread* createBread(string type) = 0;
};

class SinghFactory : public factory {
public:
    Burger* createBurger(string type) override {    
        if(type == "basic") {
            return new BasicBurger();
        }  else {
            cout << "Unknown burger type." << endl;
            return nullptr;
        }
    }

    Bread* createBread(string type) override {
        if(type == "normal") {
            return new NormalBread();
        } else {
            cout << "Unknown bread type." << endl;
            return nullptr;
        }
    }
};  

class KingFactory : public factory {
public:
    Burger* createBurger(string type) override {
         if(type == "cheese") {
            return new CheeseBurger();
        } else {    
            cout << "Unknown burger type." << endl;
            return nullptr;
        }
    }               

    Bread* createBread(string type) override {
    if(type == "whole grain") {
            return new WholeGrainBread();
        } else {
            cout << "Unknown bread type." << endl;
            return nullptr;
        }
    }
};

int main(){

    factory * singhFactory = new SinghFactory();
    factory * kingFactory = new KingFactory();

    Burger* burger1 = singhFactory->createBurger("basic");
    if(burger1) {
        burger1->prepare();
        delete burger1;     
    }

    Burger* burger2 = kingFactory->createBurger("cheese");
    if(burger2) {       
        burger2->prepare();
        delete burger2;
    }   
    Bread* bread1 = singhFactory->createBread("normal");
    if(bread1) {
        bread1->bake();
        delete bread1;      

}

    Bread* bread2 = kingFactory->createBread("whole grain");
    if(bread2) {
        bread2->bake();
        delete bread2;
    }

    delete singhFactory;
    delete kingFactory;

    return 0;
};
