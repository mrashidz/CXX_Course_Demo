#include <iostream>

int a = 22;

int addTwo(int a) {
    return addOne(a) + addOne (a);
}

int addOne(int a) {
    return a+a;
}

int main() {    
    a = 3 + 5;
    c = addThree(a);
    int b = 5 + c;
    int c = 4;
    return 0;
}

int addThree(int a) {
    return addTwo(a) + addOne(a);
}


