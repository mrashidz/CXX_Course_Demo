#include <iostream>

int main() {

    int a = 10, b = 0, c = a;
    while (b < 5) ++b;    
    do ++a; while (a < 0);
    while (c < 0) c++;

    std::cout << "This is a: " << a <<
                 " and this is b: " << b <<
                 " and this is c: " << c << std::endl;

    return 0;
}