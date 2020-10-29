#include <iostream>
int fun0() {
    std::rand();
    return std::rand()%9;
}
int *fun1(const size_t &_s) {
    return new int[_s];
}
void fun2(int *_d, const size_t &_s ) {
    for (int i = _s - 1; i >= 0; i--) {
        *(_d+i) = i+_s;
    }  


}
int main() {

    int a = fun0();
    int b = fun0();
    int *array = fun1(b);

    fun2(nullptr,a);    
}