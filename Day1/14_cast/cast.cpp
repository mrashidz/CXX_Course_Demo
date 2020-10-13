#include <iostream>

int main() {

    
    float  f = 33.21;
    int    i = -10;

    
    float ff  = i;
    int ii = f;
    char c = i;
    unsigned ui = c;
    unsigned char uc = ui;
    


    float fff = i/ii;
    // C-Style Casting
    float ffff = (float) i/ii;
    
    std::cout << "i: " << i <<  " c: " << c << " c value: " << static_cast<int> (c) << std::endl;
    std::cout << "ui: " << ui << " uc: " << uc << " uc value: " << static_cast<int> (uc)<< std::endl;
    std::cout << "ff: " << f << " ii: " << ii << std::endl;    
    std::cout << "fff: " << fff << " ffff: " << ffff << std::endl;
    

    return 0;
}