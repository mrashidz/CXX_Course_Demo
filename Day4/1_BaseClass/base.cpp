#include <iostream>

class Animal {
public:    
    virtual void speak() = 0;
};

class Cat : public Animal {
public:
    Cat() = default;
    void speak() {
        std::cout << "Meow" << std::endl;
    }    
};

class Dog : public Animal {
public:
    Dog() = default;
    virtual void speak() {
        std::cout << "Woof" << std::endl;
    }
};
 
class Chiwawa : public Dog {
public:
    Chiwawa() = default;
    void speak() {
        std::cout << "Soft_Woof" << std::endl;
    }
};


int main() {
    Animal **p;

    p = new Animal*[3];
    p[0] = new Cat;
    p[1] = new Dog;
    p[2] = new Chiwawa;

    for (size_t i = 0; i < 3; i++) {
        p[i]->speak();
        delete p[i]; 
    }
    
    return 0;

}
