#include <iostream>

class Animal {
public:
    Animal() = default;
    void eat() {
        std::cout << "Eating." << std::endl;
    }
    int Weight;
};
class Dog : public virtual Animal {
public:
    Dog() = default;
    void Woof() {
        std::cout << "WOOF!" << std::endl;
    }
};
class Cat : public virtual Animal {
public:
    Cat() = default;
    void Meow() {
        std::cout << "MEOW!" << std::endl;
    }
};

class CatDog : public Cat, public Dog {
public:
    CatDog() = default;   
};

int main() {
    CatDog catDog;

    catDog.Woof();
    catDog.Meow();
    catDog.eat();
    //catDog.Weight = 3;

    return 0;
}


