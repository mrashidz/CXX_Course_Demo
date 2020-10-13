#include <iostream>


void print (int *arr, size_t s) {
    std::cout << ">>> The array of size: " << s << " has the content: ";
    for (size_t i = 0; i < s; i++) {
        std::cout << *(arr+i) << " ";        
    }
    std::cout << std::endl;
}

void print (char *arr, size_t s) {
    std::cout << ">>> The array of size: " << s << " has the content: ";
    for (size_t i = 0; i < s; i++) {
        std::cout << *(arr+i) << " ";        
    }
    std::cout << std::endl;
}


int main() {

    size_t size = std::rand()%50;
    int *arrP = new int[size],A[10] = {0,1,2,3,4,5,6,7,8,9}; 
    for (size_t i = 0; i < size; i++) {
        *(arrP+i) = std::rand();        
    }   
    print(arrP,size);
    print(A,10);
    
    size_t charSize = size * (sizeof(int)/sizeof(char));

    char *arrChar = reinterpret_cast<char*> (arrP);


    print(arrChar,charSize);


    delete [] arrChar;    
    delete [] arrP;
};