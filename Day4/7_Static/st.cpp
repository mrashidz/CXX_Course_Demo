#include <iostream>

class Foo {
public:
    static int static_int /*= 0*/;
    int        normal_int = 9;
    static void printStatic() {
        std::cout << /*this->*/static_int << std::endl;
//      std::cout << /*this->*/ normal_int << std::endl;
    }
    void printNormal() {
        std::cout << this->static_int << std::endl;
        std::cout << this->normal_int << std::endl;

    }
};

int Foo::static_int = 0;

int main () {
    Foo::printStatic();
//  Foo::printNormal();
    std::cout << " -------- " << std::endl;
    Foo A,B;    
    A.static_int ++;
    A.normal_int --;
    
    A.printNormal();    
    std::cout << " -------- " << std::endl;
    B.printNormal();

    return 0;
}