#include<bits/stdc++.h>
using namespace std;

class MoneyHandler{
    protected:
    MoneyHandler* nextHandler;
    public:
    MoneyHandler(){
        nextHandler = NULL;
    }
    void setNextHandler(MoneyHandler* next){
        nextHandler = next;
    }
    virtual void handleRequest(double amount)=0;
};

class ThousandHandler: public MoneyHandler{
   int count;
    public: 
    ThousandHandler(int c){
          count = c;
     }
    void handleRequest(double amount){
        if(amount >= 1000 && count > 0){
            int num = min((int)(amount/1000), count);
            amount -= num * 1000;
            count -= num;
            cout<<"Dispensed "<<num<<" x 1000 notes"<<endl;
        }
        if(amount > 0 && nextHandler != NULL){
            nextHandler->handleRequest(amount);
        } else if(amount > 0){
            cout<<"Cannot dispense remaining amount: "<<amount<<endl;
        }
    }   
};
class FiveHundredHandler: public MoneyHandler{
   int count;
    public: 
    FiveHundredHandler(int c){
          count = c;
     }
    void handleRequest(double amount){
        if(amount >= 500 && count > 0){
            int num = min((int)(amount/500), count);
            amount -= num * 500;
            count -= num;
            cout<<"Dispensed "<<num<<" x 500 notes"<<endl;
        }
        if(amount > 0 && nextHandler != NULL){
            nextHandler->handleRequest(amount);
        } else if(amount > 0){
            cout<<"Cannot dispense remaining amount: "<<amount<<endl;
        }
    }   
};
class HundredHandler: public MoneyHandler{
   int count;
    public: 
    HundredHandler(int c){
          count = c;
     }
    void handleRequest(double amount){      
        if(amount >= 100 && count > 0){
            int num = min((int)(amount/100), count);
            amount -= num * 100;
            count -= num;
            cout<<"Dispensed "<<num<<" x 100 notes"<<endl;
        }
        if(amount > 0 && nextHandler != NULL){
            nextHandler->handleRequest(amount);
        } else if(amount > 0){
            cout<<"Cannot dispense remaining amount: "<<amount<<endl;
        }
    }   
};
class ATM{
    MoneyHandler* handler;
    public:
    ATM(MoneyHandler* h){
        handler = h;
    }
    void withdraw(double amount){
        cout<<"Requesting withdrawal of amount: "<<amount<<endl;
        handler->handleRequest(amount);
    }
};

int main(){
    ThousandHandler* th = new ThousandHandler(10);
    FiveHundredHandler* fh = new FiveHundredHandler(5);
    HundredHandler* hh = new HundredHandler(20);

    th->setNextHandler(fh);
    fh->setNextHandler(hh);

    ATM atm(th);
    atm.withdraw(7610);
    return 0;
}