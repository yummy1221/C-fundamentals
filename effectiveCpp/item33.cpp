#include <iostream>

// Item 33: Avoid hiding inherited names
using namespace std;

class Base {
private:
    int x;

public:
    virtual void mf1() = 0;
    virtual void mf1(int i) { 
        cout << "in base mf1(int), int=" << i << "\n";
    }

    virtual void mf2() {
        cout << "in base mf2()" << "\n";
    }

    void mf3();
    void mf3(double d) {
        cout << "in base mf3(double), double=" << d << "\n";
    }
};

class Derived : public Base {
public:
    using Base::mf1;        // must have this, otherwise compiler error when calling d.mf1(int)
    using Base::mf3;
    virtual void mf1() {    
        // This will hide all functions in Base with name mf1, 
        // which is expected in public inheritance is-a relation
        // is-a need to inherit everything
        cout << "in Derived mf1()" << "\n";
    }

    void mf2() {
        cout << "in Derived mf2()" << "\n";
    }

    void mf4() {
        cout << "in Derived mf4()" << "\n";
    }
};



int main()
{
    Derived d;
    int x = 10;

    d.mf1();
    d.mf1(x);
}

