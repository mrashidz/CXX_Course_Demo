#include <iostream>

int main() {

    int bar = 5;
    for (size_t i = 0; i < 3000; i++) {
        if (i%5) continue;
        std::cout << i << std::endl;
        if (i == 30) break;
    }

    for (;;);
    for(;bar < 0;)bar-=2;
    for (bar = 4; ; bar --) if(!bar)break;
    

    std::string foo = "Hello World!";

    for (char c: foo) {
        std::cout << c << std::endl;
    }


    
    return 0;
}