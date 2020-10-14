#include <iostream>

class Bar;
class Foo {
    int x = -1;
    friend void externalPrint(const Foo&);
public:
    void printBar(const Bar &_b); /*{ 
        std::cout << _b.x << std::endl;//Forward declaration does not specify Bar's interal
    }*/
    Foo() = default;
    
};
class Bar {
    friend class Foo;
    int x  = 2;
public:
    Bar() = default;
};





