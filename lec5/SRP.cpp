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

int main() {
    ShoppingCart* cart = new ShoppingCart();
    Product* p1 = new Product("Laptop", 1000);
    Product* p2 = new Product("Mouse", 50);

    cart->addProduct(p1);
    cart->addProduct(p2);

    PrintInvoice invoice(cart);
    invoice.printer();

    delete p1;
    delete p2;
    delete cart;

    return 0;
}
