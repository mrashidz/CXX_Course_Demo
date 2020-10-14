#include "acc.h"

void externalPrint(const Foo &_f) {
    std::cout << "External print, printing FOO: "<< _f.x << std::endl;
}

void externalPrint2(const Foo &_f) {
    //std::cout << "External print2, printing FOO: "<< _f.x << std::endl;
}

void Foo::printBar(const Bar &_b) {
    std::cout << "Printing BAR from within FOO: "<< _b.x << std::endl;
}

int main() {
    Foo f;
    Bar b;
    externalPrint(f);
    externalPrint2(f);
    f.printBar(b);
    return 0;
}

