#include <cstring>
#include "bf.h"


void printField(const field &_f) {
    std::cout << "----------------" << std::endl;

    std::cout << "(int)_f.b1 " << (int)_f.b1 << std::endl; //BAD LAZY CAST
    std::cout << "(int)_f.b2 " << (int)_f.b2 << std::endl;
    std::cout << "(int)_f.b3 " << (int)_f.b3 << std::endl;
    std::cout << "(int)_f.b4 " << (int)_f.b4 << std::endl;
    std::cout << "----------------" << std::endl;

}

int main() {
    field a = {0xFF,0xFF,0xFF,0xFF},b,c[8],*d;



    b.b1 = 2;
    b.b2 = 2;
    b.b3 = 2;
    b.b4 = 2;

    std::cout << sizeof(field) << std::endl;
    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(c) << std::endl;
    

    printField(a);


    std::cout << "----------------" << std::endl;


    uint16_t Data[5] = { 0xffff, 0xffff,0xffff,0xffff,0xffff};
    std::memcpy(c, Data, 5*sizeof(uint16_t));
  
    for (size_t i = 0; i < 8; i++) {
        printField(c[i]);
    }
    std::cout << "----------------" << std::endl;
    d = reinterpret_cast<struct field*>(Data);
    for (size_t i = 0; i < 8; i++) {
        printField(*(d+i));
    }   

    return 0;
}
