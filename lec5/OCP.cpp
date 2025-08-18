#include <bits/stdc++.h>
using namespace std;

class Product {
private:
    string name;
    int price;

public:
    Product(string n, int p) {
        this->name = n;
        this->price = p;
    }

    string getName() const { return name; }
    int getPrice() const { return price; }
};

class ShoppingCart {
private:
    vector<Product*> products;

public:
    void addProduct(Product* p) {
        products.push_back(p);
    }

    const vector<Product*>& getProducts() const {
        return products;
    }

    int getTotalPrice() const {
        int t = 0;
        for (auto p : products) {
            t += p->getPrice();
        }
        return t;
    }
};

class PrintInvoice {
private:
    ShoppingCart* cart;

public:
    PrintInvoice(ShoppingCart* c) {
        cart = c;
    }

    void printer() {
        cout << "Invoice Details:" << endl;
        for (auto p : cart->getProducts()) {
            cout << "Product Name: " << p->getName() << ", Price: " << p->getPrice() << endl;
        }
        cout << "Total Price: " << cart->getTotalPrice() << endl;
    }
};

class DbSave{
    private:
    ShoppingCart* cart;
public:
    virtual void save(ShoppingCart* c) = 0; // pure virtual function
};

class saveToSQL: public DbSave {

    public:
    void save(ShoppingCart* c)  {
        cout<<"saving to the SQL database"<<endl;
    }
};

class saveToMongo: public DbSave {

    public:
    void save(ShoppingCart* c){
        cout<<"saving to the Mongo database"<<endl;
    }
};  

class saveToFile: public DbSave {

    public:
    void save(ShoppingCart* c){
        cout<<"saving to the file"<<endl;
    }
};
int main() {
    ShoppingCart* cart = new ShoppingCart();
    Product* p1 = new Product("Laptop", 1000);
    Product* p2 = new Product("Mouse", 50);

    cart->addProduct(p1);
    cart->addProduct(p2);

    PrintInvoice* invoice = new PrintInvoice(cart);
    invoice->printer();
    saveToSQL* sql = new saveToSQL();
    saveToMongo* mongo = new saveToMongo();
    saveToFile* file = new saveToFile();
    file->save(cart);
    mongo->save(cart);
    sql->save(cart);
    delete p1;
    delete p2;
    delete cart;
    delete invoice;
    delete sql;
    delete mongo;
    delete file;
    cout << "All resources cleaned up." << endl;
    return 0;
}
