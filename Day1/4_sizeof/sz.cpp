#include <iostream>
#include <limits>

int main() {

    std::cout << "Size of int is: "<< sizeof (int) << " Bytes." << std::endl;
    std::cout << "Size of char is: "<< sizeof (char) << " Bytes." << std::endl;
    std::cout << "Size of int[10] is: "<< sizeof (int[10]) << " Bytes." << std::endl;
    std::cout << "Size of int64_t is: "<< sizeof (int64_t) << " Bytes." << std::endl;

    std::cout << "Rang of int is from "<< std::numeric_limits<int>::min() 
              << " to " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Rang of int64_t is from "<< std::numeric_limits<int64_t>::min() 
              << " to " << std::numeric_limits<int64_t>::max() << std::endl;





    char a = 0x100;
    return 0;

}