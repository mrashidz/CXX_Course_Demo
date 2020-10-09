#include <iostream>


void printArray(int a[8]) {
    for (size_t i = 0; i < 8; i ++) {
        std::cout << a[i] << " ";
    }        
    std::cout << std::endl;
}

int main () {
    int count,a[count],b[8],c[8][8]/*c[3][8]*/;    
    count = 8;
    for (size_t i = 0; i < count; i++) {
        b[i] = i;
    }
    std::cout << "Printing b" << std::endl;
    printArray(b);
    std::cout << "--------" << std::endl;
    std::cout << "Printing c" << std::endl;
    for (size_t i = 0; i < count; i++) {
        for (size_t j = 0; j < count; j++)
        {
            c[i][j] = i+j;
        }        
        printArray(c[i]);
    }
    std::cout << "--------" << std::endl;
    return 0;
}