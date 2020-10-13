#include <iostream>
int print() {
    std::cout << "An empty print." << std::endl;
    return -1;
}
int print(int a, int b) {
    std::cout << "Printing: " << a << " & " << b 
    << "and returning -1." << std::endl;
    return -1;
}
/*
int print(int a) {
    std::cout << "Printing: " << a << "and returning -1." << std::endl;
    return -1;
}*/
void print(int a) {
    std::cout << "This is an int: " << a << std::endl; 
}

void print(char a) {
    std::cout << "This is a char: " << a << std::endl; 
}
void print(std::string a) {
    std::cout << "This is a string: " << a << std::endl; 
}
void print(int a, char b) {
    std::cout << "These are an int: " << a << " and a char: " << b << std::endl; 
}

int main() {
    print();
    print(-1);
    print('d');
    print("d");
    //print(10,"d");
    return 0;
}