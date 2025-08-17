#include<bits/stdc++.h>
using namespace std;

class Car{
    public:
    virtual void start()=0;
    virtual void stop()=0;
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual void shiftgear(int gear)=0;
    virtual ~Car(){
        cout << "Car destructor called" << endl;
    }
};

class SportsCar: public Car{
    private:
    string name;
    string model;
    bool isstart =false;
    bool isstop = true;
    int currentGear = 0;
    public:
    SportsCar(string n,string m){
        this->name = n;
        this->model = m;
        cout << "SportsCar constructor called for " << name << " " << model << endl;
    }
  void start(){
    isstart = true;
    isstop  = false;
    cout << "SportsCar " << name << " " << model << " started." << endl;
  }
  void stop(){
    isstart = false;
    isstop = true;
    cout << "SportsCar " << name << " " << model << " stopped." << endl;    
  }
  void shiftgear(int n){
    if(isstop){
        cout << "Cannot shift gear while the car is stopped." << endl;
        return;
    }
    currentGear = n;
    cout<<"Gear shifted to the "<<n << " gear." << endl;
  }
  void accelerate(){
    if(!isstart){
        cout << "Cannot accelerate, the car is not started." << endl;
        return;
    }
    cout << "SportsCar " << name << " " << model << " is accelerating." << endl;    
  }
  void brake(){
    if(!isstart){
        cout<<"car is not started"<<endl;
        return;
    }
    cout<<"brake applied to the car"<<endl;
  }

};
int main(){
    Car* mycar = new SportsCar("Ferrari", "488");
    mycar->start();
    mycar->shiftgear(3);
    mycar->accelerate();
    mycar->brake();
    mycar->stop();
    delete mycar;
    return 0;
}