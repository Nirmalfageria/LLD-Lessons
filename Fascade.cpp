#include<bits/stdc++.h>
using namespace std;

class Subsystem1{
    public:
    void operation1(){
        cout<<"Subsystem1: Ready!"<<endl;
    }
};

class Subsystem2{
    public:
    void operation2(){
        cout<<"Subsystem2: Get ready!"<<endl;
    }
};

class Subsystem3{
    public:
    void operation3(){
        cout<<"Subsystem3: Fire!"<<endl;
    }
};

class Facade{
    Subsystem1* subsystem1;
    Subsystem2* subsystem2;
    Subsystem3* subsystem3;
    public:
    Facade(){
        subsystem1=new Subsystem1();
        subsystem2=new Subsystem2();
        subsystem3=new Subsystem3();
    }
    void operation(){
        subsystem1->operation1();
        subsystem2->operation2();
        subsystem3->operation3();
    }
    ~Facade(){
        delete subsystem1;
        delete subsystem2;
        delete subsystem3;
    }
};

int main(){
    Facade* facade=new Facade();
    facade->operation();
    delete facade;
    return 0;
}