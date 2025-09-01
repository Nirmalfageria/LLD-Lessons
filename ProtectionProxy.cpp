#include<bits/stdc++.h>
using namespace std;

class IPdfDocument{
    public:
    virtual void display()=0;
};

class RealPdfDocument: public IPdfDocument{
    string filename;
    public:
    RealPdfDocument(string fname){
        filename = fname;
        loadfromDisk();
    }
    void loadfromDisk(){
        cout<<"Loading PDF document from disk: "<<filename<<endl;
    }
    void display(){
        cout<<"Displaying PDF document: "<<filename<<endl;
    }
};  

class User{
    // protected:
    string name;
    bool isSubscribed;
    public:
    User(string n, bool sub){
        name = n;
        isSubscribed = sub; 
    }
    bool getSubscriptionStatus(){
        return isSubscribed;
    }
};


class ProxyPdfDocument: public IPdfDocument{
    RealPdfDocument* realPdf;
    string filename;
    User* user;
    public:
    ProxyPdfDocument(string fname, User* u){
        filename = fname;
        user = u;
        realPdf = NULL;
    }
    void display(){
        // Assuming we have a method to check if user is subscribed
        if(user->getSubscriptionStatus()){
            if(realPdf == NULL){
                realPdf = new RealPdfDocument(filename);
            }
            realPdf->display();
        } else {
            cout<<"Access denied. Please subscribe to view the document: "<<filename<<endl;
        }
    }
    ~ProxyPdfDocument(){
        delete realPdf;
    }
};

int main(){
    User* user1 = new User("Alice", true); // Subscribed user
    User* user2 = new User("Bob", false);  // Non-subscribed user

    IPdfDocument* doc1 = new ProxyPdfDocument("document1.pdf", user1);
    IPdfDocument* doc2 = new ProxyPdfDocument("document2.pdf", user2);  
    // Document will be loaded from disk only when display is called by a subscribed user
    doc1->display(); // Loads and displays document1.pdf
    doc1->display(); // Displays document1.pdf from cache   
    doc2->display(); // Access denied message
    doc2->display(); // Access denied message
    delete doc1;
    delete doc2;
    delete user1;
    delete user2;
    return 0;
}