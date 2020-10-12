#include <iostream>

int main() {
    unsigned int max,array[8][9][11];
    std::cout << "Type in the max:" << std::endl;
    std::cin >> max;

    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 9; j++) {
            for (size_t k = 0; k < 11; k++) {
                array[i][j][k] = std::rand() % max;
            }            
        }        
    }
    
    std::cout << "The max number is: " << max << std::endl;

    std::cout << "Here is the array:" << std::endl;
    
    for (size_t i = 0; i < 8; i++) {
        std::cout << "[ ";    
        for (size_t j = 0; j < 9; j++) {
            std::cout << "[ ";
            for (size_t k = 0; k < 11; k++) {
                std::cout << array[i][j][k] << " ";
            }
            if (j==8)
                std::cout << "]";                
            else
                std::cout << "], ";                
            
        }        
        std::cout << " ]" << std::endl;                
    }


    return 0;
}