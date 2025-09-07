#include <iostream>
#include <string>
using namespace std;

// ❌ BAD: Violates Liskov Substitution Principle
// Base class promises fly(), but Ostrich cannot fly

class Bird {
public:
    string name;
    Bird(string n) : name(n) {}
    virtual void fly() {
        cout << name << " is flying" << endl;
    }
};

class Sparrow : public Bird {
public:
    Sparrow(string n) : Bird(n) {}
    void fly() override {
        cout << name << " (sparrow) is flying fast" << endl;
    }
};

class Ostrich : public Bird {
public:
    Ostrich(string n) : Bird(n) {}
    void fly() override {
        // This is wrong: we're forced to implement fly() for a bird that can't fly
        cout << name << " (ostrich) cannot fly! Throwing exception..." << endl;
        // In real code, we might throw or no-op, both break substitutability
    }
};

void makeBirdFly(Bird* b) {
    // LSP says: any Bird* should behave correctly here
    b->fly();
}

int main() {
    cout << "=== BAD LSP Example ===" << endl;
    Sparrow s("Jack");
    Ostrich o("Ozzy");

    makeBirdFly(&s); // OK
    makeBirdFly(&o); // ❌ Violates expectation: ostrich can't truly fly

    cout << "\nProblems:\n- Base type promises fly() for all birds\n- Some derived types cannot fulfill it (ostrich)\n- Clients relying on Bird::fly break for valid subtypes\n";
}
