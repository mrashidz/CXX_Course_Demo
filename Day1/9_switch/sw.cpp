#include <iostream>


void checkChar (char a) {
    switch (a) {
    case 1:
        std::cout << "First Alternative" << std::endl;
        break;    
    default:
        std::cout << "No Match Found!" << std::endl;
        break;
    }
}


void checkInt (int a) {
    switch (a) {
    case 1:
        std::cout << "First Alternative" << std::endl;
        break;
    
    default:
        std::cout << "No Match Found!" << std::endl;
        break;
    }
}

int main() {
    checkInt(1);
    checkChar('a');

    switch ('b') {
    case 'a':
        std::cout << ">>> a " << std::endl;        
    case 'b':
        std::cout << ">>> b " << std::endl;   
    case 'c':
        std::cout << ">>> c " << std::endl;     
    }

    switch (0) {
    case 1:
        std::cout << "First Alternative" << std::endl;
        break;
    }
/*
    std::string test = "test";
    switch (test) {
    case "test":
        std::cout << "This is a test" << std::endl;
        break;    
    default:
        std::cout << "No Match Found!" << std::endl;
        break;
    } 
 */   
    return 0;
}