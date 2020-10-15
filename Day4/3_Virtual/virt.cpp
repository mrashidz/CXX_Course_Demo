#include <iostream>

class Foo {
    /*virtual*/ void private_fun() {
        std::cout << "Foo Private" << std::endl;
    }    
 public:
    void interface_fun() { 
        std::cout << "Foo Interface" << std::endl;        
        private_fun();
    }
};

class Bar : public Foo {
public:
    void private_fun(){ //overrides
        std::cout << "Bar override private"<< std::endl;
    }
    void interface_fun(int) { //hides
        std::cout << "Bar override interface"<< std::endl;        
    }
};

class B : public Bar {
public:
    void interface_fun() {
        std::cout << "B override interface" << std::endl;
        Foo::interface_fun();
    }
};

class BB : public Bar {};
class FF : public Foo {};


struct A {
    virtual void f();
};
struct VB1 : virtual A {
    void f(); // overrides A::f
};
struct VB2 : virtual A {
    void f(); // overrides A::f
};
// struct Error : VB1, VB2 {
//     // Error: A::f has two final overriders in Error
// };
struct Okay : VB1, VB2 {
    void f(); // OK: this is the final overrider for A::f
};
struct VB1a : virtual A {}; // does not declare an overrider
struct Da : VB1a, VB2 {
    // in Da, the final overrider of A::f is VB2::f
};




int main() {
    Foo foo;
    Bar bar;
    BB bb;
    FF ff;
    B b;


/*
    foo.interface_fun();    
    std::cout << " ---------- " << std::endl << std::endl;

    bar.private_fun();
    bar.interface_fun(2);
    
    std::cout << " ---------- " << std::endl << std::endl;

    bb.private_fun();    
    bb.interface_fun(2);
    std::cout << " ---------- " << std::endl << std::endl;
    ff.interface_fun();
    std::cout << " ---------- " << std::endl << std::endl;*/
    b.interface_fun();
    
    //b.interface_fun(2);
    
    b.private_fun();
    std::cout << " ---------- " << std::endl << std::endl;


    return 0;
}