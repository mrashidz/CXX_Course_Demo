#include <iostream>
class Abstract {
public:
    virtual void f() = 0;
    virtual void g() {
        std::cout << "Abstract::g" << std::endl;
    };

    ~Abstract() {
        g();
        //f(); UDB
        Abstract::f();
    }
};
void Abstract::f() {
    std::cout << "Abstract::f" << std::endl;
}


class Concrete : public Abstract {
public:
    virtual void f() {
        std::cout << "Concrete::f()" << std::endl;
    }
    virtual void g() {
        std::cout << "Concrete::g()" << std::endl;
    }
    ~Concrete() {
        g();
        f();
    }
};
class Abstract2 : public Concrete {
public:
    virtual void g() = 0;
};



int main() {
    Abstract * p = new Concrete;
    delete p;
    std::cout << " ------------ " << std::endl;
    Concrete C;
    return 0;
}