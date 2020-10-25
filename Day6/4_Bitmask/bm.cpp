#include <iostream>
#include <bitset>


int main() {
    unsigned char MASK = 0b00111100, Data[2] = {0b10100100,0b10110101};
    std::cout << std::bitset<8>(MASK) << " ^\t" <<
                 std::bitset<8>(Data[0]) << " = " <<
                 std::bitset<8>(Data[0] ^ MASK) << std::endl;

    std::cout << std::bitset<8>(MASK) << " |\t" <<
                 std::bitset<8>(Data[1]) << " = " <<
                 std::bitset<8>(Data[1] | MASK) << std::endl;

    std::cout << std::bitset<8>(MASK) << " &\t" <<
                 std::bitset<8>(Data[0]) << " = " <<
                 std::bitset<8>(Data[0] & MASK) << std::endl;

    std::cout << std::bitset<8>(MASK) << " &\t" <<
                 std::bitset<8>(Data[0]) << " = " <<
                 std::bitset<8>(Data[0] & (~MASK)) << std::endl;

    std::cout << std::bitset<8>(MASK) << " &>>2\t" <<
                 std::bitset<8>(Data[0]) << " = " <<
                 std::bitset<8>( (Data[0] & MASK) >> 2) << std::endl;

    std::cout << std::bitset<8>(MASK) << " >>2&\t" <<
                 std::bitset<8>(Data[1]) << " = " <<
                 std::bitset<8>((Data[1] >> 2 ) & 0b00001111) << std::endl;

    return 0;
}