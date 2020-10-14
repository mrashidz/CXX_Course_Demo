#include <iostream>

enum Mode {INT, DBL};
enum Type {A, B};

typedef struct _a{
    Mode mode;
    union {
        int valueInt;
        double valueDbl;
    };
    struct {
        int a;
        int b;
    };    
}stuA;

typedef struct _b{
    typedef struct _c{
        int c;
    }c;
    c cc;    
    stuA a;    
}stuB;

void PrintA(stuA *a);
void PrintB(stuB *b);
void print(void *_p, Type _t) {
    if (_t == Type::A) {
        PrintA(reinterpret_cast<stuA*>(_p));
    } else if (_t == Type::B) {
        PrintB(reinterpret_cast<stuB*>(_p));
    }
}

int main() {

    stuB::c a;
    a.c = 12;

    stuB B;
    stuA *A = new stuA;

    A->mode = Mode::INT;
    A->valueInt = 3;
    A->a = 10;
    A->b = 11;

    B.cc.c = 2;
    B.a = *(A);
    B.a.mode = Mode::DBL;
    B.a.a = 11;
    
    

    print(static_cast<void*>(A),Type::A);
    print(static_cast<void*>(&B),Type::B);
}



void PrintA(stuA *a) {
    std::cout << "This is A:" << std::endl;
    std::cout << a->mode << std::endl;
    if (a->mode == Mode::INT) {
        std::cout << a->valueInt << std::endl;
    } else if (a->mode == Mode::DBL) {
        std::cout << a->valueDbl << std::endl;
    }
    std::cout << a->a << " " << a->b << std::endl;        
    std::cout << "---AAAA---" << std::endl << std::endl;
}

void PrintB(stuB *b) {
    std::cout << "This is B:" << std::endl;
    //std::cout << b->c.c << std::endl;
    std::cout << b->cc.c << std::endl;
    PrintA( &(b->a) );    
    std::cout << "---BBBB---" << std::endl << std::endl;

}