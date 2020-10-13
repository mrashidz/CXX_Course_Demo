#ifndef BAR_H
#define BAR_H
#include <iostream>

void appropriate1();
void appropriate2(int a, int b);

inline void advanceStuff() {
    std::cout << "Inline functions would be inserted wherever used!" << std::endl;
}


void badWayOfDoingThings(int a, int b) {
    if (a > b) std::cout << a << " is bigger than " << b << std::endl;
    else std::cout << a << " is not bigger than " << b << std::endl;
}

#endif // BAR_H



