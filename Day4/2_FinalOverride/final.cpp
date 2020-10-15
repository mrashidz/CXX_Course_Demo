#include <iostream>

class Base {
public:
    virtual void vMethod() {
        std::cout << "This is vMethod from Base Class!" << std::endl;
    }
    virtual void pMethod() = 0;
};
class Foo : public Base {
public:
    void vMethod() override /*optional*/ {
        std::cout << "This is vMethod from Foo!" << std::endl;
    };
    void pMethod() final {
        std::cout << "This is pMethod from Foo!" << std::endl;
    }
    void nonVirt() {
        std::cout << "This is nonVirt from Foo!" << std::endl;
    }
};

class Bar final : public Foo {
public:
    int vMethod() override { // Different signature from Foo::vMethod()
        std::cout << "This is vMethod from Bar!" << std::endl;
    };
    void pMethod() { // Final function
        std::cout << "This is pMethod from Foo!" << std::endl;
    }
    void nonVirt() override { // Non virtual function
        std::cout << "This is nonVirt from Foo!" << std::endl;
    }
};

class err : public Bar /*Bar is final*/{};

int main () {
    Foo f;
    Bar b;

    f.pMethod();
    f.vMethod();

    b.vMethod();
    //b.pMethod();
}