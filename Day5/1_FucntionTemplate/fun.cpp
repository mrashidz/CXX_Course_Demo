#include <iostream>

template <typename T>
void sum(const T &_a, const T &_b) {    
    std::cout << _a + _b << std::endl;
}
struct A {
    A() = default;
    A(const int &_a, const int &_b):a(_a),b(_b){}
    int a,b;
};
A operator +(const A  &_o, const A  &_f) {
    return A(_f.a + _o.a, _f.b + _o.b);
}
std::ostream& operator<<(std::ostream &_os,const A &_m) {
    return _os << _m.a << " " << _m.b;
}



struct C {
    int a;
    std::string s;
    C():a(-2),s("Initialized!"){}
};

template<>
void sum<C>(const C &_a, const C &_b) {
    std::cout << "Nothing to see here!" << std::endl;
}

int main() {
    sum<>(2.02,1.89);
    sum<int> (12,12);
    sum<std::string> ("Hello ", "World!");
    sum<A>(A(2,3),A(1,4));
    sum<C>(C(),C());
    return 0;
}
