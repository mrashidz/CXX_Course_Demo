#include "bar.h"
void appropriate1() {
    std::cout << "Function Implementations";
    std::cout << "usually resides in source code." << std::endl;
}
void appropriate2(int a, int b){
    std::cout << "Between " << a << " and " << b << "..." << std::endl;
    if ( a > b ) {
        std::cout << "\n\t\t" << a << " is bigger!"<< std::endl;
    } else if ( a < b) {
        std::cout << "\n\t\t" << b << " is bigger!"<< std::endl;
    } else {
        std::cout << "\n\t\tNeither is bigger!"<< std::endl;
    }
}

