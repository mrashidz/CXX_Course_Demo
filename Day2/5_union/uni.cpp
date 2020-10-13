#include <iostream>
union uni {
    int a;
    char c[4];
};
/*
void uni(){

}
*/
int main() {
    std::cout << sizeof(union uni) << std::endl;
    uni a;
    a.a = -300;
    std::cout << "This is a: " << a.a  << std::endl;
    std::cout << "These are: ";
    for (size_t i = 0; i < 4; i++) {
        std::cout << "c[" << i << "]=" << static_cast<int>(a.c[i]) << " ";
    }
    std::cout << std::endl;
    return 0;
};


