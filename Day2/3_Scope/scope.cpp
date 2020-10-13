#include <iostream>

int a = 222;
namespace Test {
    int a = 22, *c = new int,d = 1;
    int *f2() {
        *c = 33;
        return c;
    }

}

int &f1() {
    int a = 2;
    return a;
}

int &f1(int &a) {    
    return ++a;
}

int *f2() {
    int a = 2;
    return &a;
}

int *f3() {
    int *a = new int;
    *a = 3;
    return a;
}
/*
int *&f4(int *a) {
    *a = 7;
    return a;
}
*/
int *&f4(int *&a) {
    *a = 7;
    return a;
}
/*
int &*f5(int &*a) {
    *a = 7;
    return a;
}
*/
int main() {
    int a = 2, *b = new int, *& bRef =f4(b) , *c= f3(); 
    //std::cout << f1() << std::endl;
    //std::cout << f2() << std::endl;
    

    f1(a)++;
    std::cout << a << std::endl;   
    std::cout << *(c) << std::endl;
    std::cout << *(bRef) << std::endl;
    //std::cout << *(f4(new int)) << std::endl;    

    //std::cout << *(f4(&a)) << std::endl;

    {
        int a = 222222;    
        std::cout << a << std::endl;
        std::cout << ::a << std::endl;
        std::cout << Test::a << std::endl;
        std::cout << *(Test::f2()) << std::endl;
    }
    std::cout << a << std::endl;
    std::cout << d << std::endl;
    using namespace Test;
    std::cout << d << std::endl;
    std::cout << a << std::endl;
    

    
    

    delete c;
    delete bRef;
    delete Test::f2();
    return 0;
}