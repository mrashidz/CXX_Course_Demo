#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>

struct struct_a {
    char a;
    char b;
    char c; 
    char d = 5;
};

typedef struct_a A;
struct struct_b {
    int a = 0;
};
//typedef struct_b B;
void struct_b();

typedef struct struct_c{
    void fun();    
}C;

typedef struct
{
    void fun() {
        std::cout << "This is D!" << std::endl;
    }
}D;


#endif // STRUCT_H