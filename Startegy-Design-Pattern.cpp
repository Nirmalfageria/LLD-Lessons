#include<bits/stdc++.h>
using namespace std;

class talkable{
public:
    virtual void talk() = 0;
};

class normalTalk : public talkable {
public:
    void talk() override {
        cout << "Talking normally." << endl;
    }
};  

class noTalk: public talkable {
public:
    void talk() override {
        cout << "No talking allowed." << endl;
    }
};

class walkable {
public:
    virtual void walk() = 0;
};

class normalWalk : public walkable {
public:
    void walk() override {
        cout << "Walking normally." << endl;
    }
};

class noWalk : public walkable {
public:
    void walk() override {
        cout << "No walking allowed." << endl;
    }
};

class flyable {
public:
    virtual void fly() = 0;
};
    class normalFly : public flyable {
public:
    void fly() override {
        cout << "Flying normally." << endl;
    }
};

class noFly : public flyable {
public:
    void fly() override {
        cout << "No flying allowed." << endl;
    }
};

class robot{
    talkable* talkBehavior;
    walkable* walkBehavior;
    flyable* flyBehavior;
public:
robot(talkable* t, walkable* w, flyable* f) {
    talkBehavior = t;
    walkBehavior = w;
    flyBehavior = f;
}
void projection() {
    cout << "Robot is ready for action!" << endl;
}

void performTalk() {
    talkBehavior->talk();
}

void performWalk() {
    walkBehavior->walk();
}

void performFly() {
    flyBehavior->fly();
}
};

int main(){
    robot* r1 = new robot(new normalTalk(), new normalWalk(), new normalFly());
    r1->projection();
    r1->performTalk();
    r1->performWalk();
    r1->performFly();   

    robot* r2 = new robot(new noTalk(), new noWalk(), new noFly()); 
    r2->projection();
    r2->performTalk();      
    r2->performWalk();
    r2->performFly();       

    delete r1;
    delete r2;
    return 0;   
}