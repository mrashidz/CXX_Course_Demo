#include "struct.h"

struct struct_aa
{
    char a;
    char b;
    char c; 
    char d = 50;
}AA,BB,CC;


void f0() {
    std::cout << AA.a << " " << AA.b << " " << AA.c << " " <<static_cast<int>( AA.d) << " " << std::endl;
}

void f0(struct_a a) {
    std::cout << a.a << " " << a.b << " " << a.c << " " << static_cast<int>(a.d) << " " << std::endl;
}

void f0(struct_a *a) {
    std::cout << a->a << " " << a->b << " " << a->c << " " << static_cast<int>(a->d) << " " << std::endl;
}

void f1(C c) {
    c.fun();
}


int main () {
    
    //struct_b b;
    A a;
    struct struct_b b;
    struct_a a2;
    
    //AA aaa;

    
    C c;
    D *d = new D;
    c.fun();
    d->fun();

    f0();
    f0(a);
    f0(reinterpret_cast<A*>(&b));
    

    return 0;
}