#include <iostream>

int fact(int n = 1) {
    int ret = 1;
    std::cout << ">>> Getting into the function wiht n: " << n  << std::endl;
    if (n > 1) 
        ret = n * fact(n-1);
    std::cout << "<<< Getting out of the function wiht n: " << n << " and ret: "<< ret << std::endl;
    return ret;
}



int f3(int foo, int bar) {
    return foo + bar;
}

void f2(int foo = 1) {
    std::cout << "Foo is: " << foo << std::endl;
}

void f1() {

}

int main() {
    f1();

    f2();

    //f3();

    f2(f3(f3(0,3),3));

    int a = f3(9,-3);
    f2(a);

    if (f3(0,0)) f2(11);
    else         f2();     

    std::cout << "+++ Default Factorial:\n"  << fact() << std::endl << std::endl;
    std::cout << "+++ Factorial     10:\n"   << fact(10) << std::endl << std::endl;
    std::cout << "+++ Factorial     1000:\n" << fact(1000) << std::endl << std::endl;

    return 0;
}