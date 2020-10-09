#include <iostream>

int X = 22;

int addTwo(int a) {
    return addOne(a) + addOne (a);
}

int addOne(int a) {
    return a+a;
}

int main() {    
    X = 3 + 5;
    c = addThree(X);
    int b = 5 + c;
    int c = 4;
    std::cout << "X: " << X << " b: " << b << " c: " << c << std::endl;
    return 0;
}

int addThree(int a) {
    return addTwo(a) + addOne(a);
}


