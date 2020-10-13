#include <iostream>

void f1 (int a) {
    a ++;
}
void f1 (int &a) {
    a ++;
}
void f2 (int &a) {
    a ++;
}
void f3 (const int &a) {
    a ++;
}
void f3 (int & const a) {
    a++;
}

void f4 (int *a) {
    (*a)++;
}
void f5 (int * const a) {
    (*a)++;
}
void f6 (int const * a) {
    (*a)++;
}
void f7 (const int * a) {
    (*a)++;
}


int main () {
    int a = 2;
    int &b = 3;
    const int &c = 11;
    std::cout << "a is: " << a << std::endl; 
    //f1(a);
    std::cout << "a is: " << a << std::endl; 
    f2(a);
    f2(3);
    std::cout << "a is: " << a << std::endl; 
    f3(a);
    std::cout << "a is: " << a << std::endl; 
    f4(&a);
    std::cout << "a is: " << a << std::endl; 
    f5(&a);
    std::cout << "a is: " << a << std::endl; 

    
    
    return 0;
}