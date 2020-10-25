#ifndef BF_H
#define BF_H
#include <iostream>

struct field {
    unsigned  b1:1;
    unsigned  b2:2;
    unsigned  b3:3;
    unsigned  b4:4;           
}__attribute__((packed));

#endif //BF_H