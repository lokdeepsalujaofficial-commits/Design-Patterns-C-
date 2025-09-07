#include <iostream>
#include <string>
using namespace std;

// ✅ GOOD: Liskov Substitution Principle
// Only flyers expose fly(); non-flyers do not.

class Bird {
public:
    string name;
    Bird(const string& n) : name(n) {}
    virtual void info() { cout << name << " is a bird" << endl; }
    virtual ~Bird() = default;
};

class FlyingBird {  // capability interface
public:
    virtual void fly() = 0;
    virtual ~FlyingBird() = default;
};

class Sparrow : public Bird, public FlyingBird {
public:
    Sparrow(const string& n) : Bird(n) {}
    void fly() override { cout << name << " (sparrow) is flying" << endl; }
};

class Ostrich : public Bird {
public:
    Ostrich(const string& n) : Bird(n) {}
    void info() override { cout << name << " (ostrich) is a non-flying bird" << endl; }
};

void letItFly(FlyingBird* fb) { fb->fly(); }
void showBird(Bird* b) { b->info(); }

int main() {
    cout << "=== GOOD LSP Example ===" << endl;

    Sparrow s("Jack");
    Ostrich o("Ozzy");

    showBird(&s);   // OK
    showBird(&o);   // OK

    letItFly(&s);   // OK: Sparrow can fly
    // letItFly(&o); // Compile-time safety: Ostrich is not a FlyingBird

    return 0;
}
