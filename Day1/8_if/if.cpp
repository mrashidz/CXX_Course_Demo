#include <iostream>

bool return_true() {
    std::cout << "True" << std::endl;
    return true;
}

bool return_false() {
    std::cout << "False" << std::endl;
    return false;
}

int main() {
    
    if (true)
        std::cout << __LINE__ << std::endl;
    if (0)
        std::cout << __LINE__ << std::endl;
    else if (100)
        std::cout << __LINE__ << std::endl;
    else
        std::cout << __LINE__ << std::endl;

    if (-1) {
        std::cout << __LINE__ << std::endl;
    }

    std::cout << "----" << std::endl;
    
    if (return_false() || return_true())
        std::cout << __LINE__ << std::endl;
    std::cout << "----" << std::endl;
    
    if (return_true()  || return_false())
        std::cout << __LINE__ << std::endl;
    std::cout << "----" << std::endl;
    
    if (return_false() && return_true())
        std::cout << __LINE__ << std::endl;
    std::cout << "----" << std::endl;
    
    if (return_true()  && return_false())
        std::cout << __LINE__ << std::endl;
    std::cout << "----" << std::endl;

    if (true  != false)
       std::cout << __LINE__ << std::endl;
    
    if ( (true == 1) && (false == 0) )
        std::cout << __LINE__ << std::endl;

    if (true  == 109)
        std::cout << __LINE__ << std::endl;
    


    return 0;
}