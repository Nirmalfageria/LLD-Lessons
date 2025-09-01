#include<bits/stdc++.h>
using namespace std;

class IImage{
    public:
    virtual void display()=0;
};  

class RealImage: public IImage{
    string filename;
    public:
    RealImage(string fname){
        filename = fname;
        loadfromDisk();
    }
    void loadfromDisk(){
        cout<<"Loading image from disk: "<<filename<<endl;
    }
    void display(){
        cout<<"Displaying image: "<<filename<<endl;
    }
};

class ProxyImage: public IImage{
    RealImage* realImage;
    string filename;
    public:
    ProxyImage(string fname){
        filename = fname;
        realImage = NULL;
    }
    void display(){
        if(realImage == NULL){
            realImage = new RealImage(filename);
        }
        realImage->display();
    }
    ~ProxyImage(){
        delete realImage;
    }
};


int main(){
    IImage* image1 = new ProxyImage("photo1.jpg");
    IImage* image2 = new ProxyImage("photo2.jpg");

    // Image will be loaded from disk only when display is called
    image1->display(); // Loads and displays photo1.jpg
    image1->display(); // Displays photo1.jpg from cache

    image2->display(); // Loads and displays photo2.jpg
    image2->display(); // Displays photo2.jpg from cache

    delete image1;
    delete image2;
    return 0;
}