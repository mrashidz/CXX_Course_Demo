#include <iostream>

int main() {
    std::string input;

    std::cout << "Tell me something, and press enter..." << std::endl;
    std::cin >> input;
    std::cout << "What you said has " << input.length() << " characters in it and is:\n" << input << std::endl;
    getline(std::cin,input);
    std::cout << "The rest of what you said has " << input.length() << " characters in it and is:\n" << input << std::endl;
    return 0;
}