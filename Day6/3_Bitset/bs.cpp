#include <iostream>
#include <bitset>

int main() { 
    
    std::string bits = "10101100";
    std::bitset<8> set1(bits);   
    std::bitset<8> set2(255); 

    std::cout << "set1\t" << set1 << std::endl;
    std::cout << "set2\t" << set2 << std::endl;
    std::cout << "(~set2)\t" << (~set2) << std::endl;

    std::cout << "(set1 << 2)\t" << (set1 << 2)  << std::endl;
    std::cout << "(set2 >> 1)\t" << (set2 >> 1)  << std::endl; 
    std::cout << "(set1 & set2)\t" << (set1 & set2) << std::endl; 
    std::cout << "(set1 | set2)\t" << (set1 | set2) << std::endl; 
    std::cout << "(set1 ^ set2)\t" << (set1 ^ set2) << std::endl;  
    
    std::cout << "************ set3 ************" << std::endl; 
    std::bitset<8> set3; 
    std::cout << set3 << std::endl; 
    
    set3[1] = 1;
    set3[4] = set3[1]; 
    std::cout << set3 << std::endl; 
  
    return 0; 
} 