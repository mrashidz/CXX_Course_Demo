#include <iostream>


int main() {
    char a[3] = "bc";
    char b[3] = "YZ";
    std::cout << a << std::endl;
    a[2] = 'a';
    std::cout << a << std::endl;
    std::string a_string = "abc";
    return 0;
}

