#include <iostream>

using my_string = char[12];
typedef char my_string2[12];


int main () {
    my_string foo;
    my_string2 bar;

    decltype(bar) fancy;

    for (size_t i = 0; i < 11; i++)
    {
        foo[i] = 'A' + i;
        bar[i] = 'Z' - i;
        fancy[i] = 'a' + i;
    }
    foo[11] = bar[11] = fancy[11] = 0x00;
    std::cout << foo << std::endl;
    std::cout << bar << std::endl;
    std::cout << fancy << std::endl;

    

    return 0;
}
