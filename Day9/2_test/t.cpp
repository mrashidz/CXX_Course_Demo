#include <iostream>

void findAnElement(int *p, size_t s, size_t e) {
    bool b = false;
    for (size_t i = 0; i < s; i++) 
        if (*(p+i) == e) {
            std::cout << "FOUND" << std::endl;
            b = true;
            break;
        }            
    if(b);else std::cout << "NOT FOUND" << std::endl;
}

void test0() {
    int a[45] = {0};
    findAnElement(a,45,0);
}

void test1() {
    int *a[45]={0};
    findAnElement(a,45,1);
}

void test2() {
    int *a;
    findAnElement(a,45,0);
}

void test3() {
    int *a = new int [3];
    findAnElement(a,-2,11);
}


int main () {


}