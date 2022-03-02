#include <iostream>
#include <string>


using std::cout;
using std::string;

// 1. Define a class B1 with a virtual function vf() and a non-virtual function f() .

struct B1 {
    virtual void vf() { cout << "B1::vf()\n"; }
    void f() { cout << "B1::f()\n"; }
    // 5. Add a pure virtual function called pvf() to B1 
    virtual void pvf() =0;
};

//2. Derive a class D1 from B1 and override vf() .

struct D1 : B1 {
    void vf() override { cout << "D1::vf()\n"; }
    void f() { cout << "D1::f()\n"; }
};

//6. Define a class D2 derived from D1 and override pvf() in D2 .

struct D2 : D1 {
    void pvf() override { cout << "D2::pvf()\n"; }
};

//7. Define a class B2 with a pure virtual function pvf() .

struct B2 {
    virtual void pvf() =0;
};

// 7.Define a class D21 with a string data member and a member function that overrides pvf() ;

struct D21 : B2 {
    string s = "stuffs";
    // 7. D21::pvf() should output the value of the string .
    void pvf() override { cout << s << '\n'; }
};

// 7. Define a class D22 that is just like D21 except that its data member is an int .

struct D22 : B2 {
    int i = 37;
    void pvf() override { cout << i << '\n'; }
};

// 7. Define a function f() that takes a B2& argument and calls pvf() for its argument.

void f (B2& b)
{
    b.pvf();
}

int main()
{
    /*
    B1 b;
    b.vf();
    b.f();
    D1 d;
    d.vf();
    d.f();
    B1& r {d};
    r.vf();
    r.f();
    D2 dd;
    dd.vf();
    dd.f();
    dd.pvf();
    */

    D21 two_one;
    D22 two_two;

    // 7. Call f() with a D21 and a D22 .

    f(two_one);
    f(two_two);
}

// g++ drill14.cpp -o drill14