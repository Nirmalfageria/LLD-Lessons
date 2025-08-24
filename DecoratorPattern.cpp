#include <bits/stdc++.h>
using namespace std;

class IComponent {
public:
    virtual string getAbility() = 0;
    virtual ~IComponent() = default;
};

class Mario : public IComponent {
public:
    string getAbility() override {
        return "I am Mario";
    }
};

class Decorator : public IComponent {
protected:
    IComponent* component;
public:
    Decorator(IComponent* c) : component(c) {}
    string getAbility() override {
        return component->getAbility();
    }
    virtual ~Decorator() = default;
};

class HeightUp : public Decorator {
public:
    HeightUp(IComponent* c) : Decorator(c) {}
    string getAbility() override {
        return component->getAbility() + " with Height Up";
    }
};

class SpeedUp : public Decorator {
public:
    SpeedUp(IComponent* c) : Decorator(c) {}
    string getAbility() override {
        return component->getAbility() + " with Speed Up";
    }
};

int main() {
    IComponent* mario = new Mario();
    IComponent* heightUpMario = new HeightUp(mario);
    cout << heightUpMario->getAbility() << endl;
    IComponent* speedUpMario = new SpeedUp(heightUpMario);
    cout << speedUpMario->getAbility() << endl;

    delete mario;
    delete heightUpMario;
    delete speedUpMario;
    return 0;
}
