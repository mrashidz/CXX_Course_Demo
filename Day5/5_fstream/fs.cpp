#include <fstream>
#include <iostream>

int main() {
    std::fstream input, output;
    input.open("input.txt",std::fstream::in);
    if (!input.is_open()) {
        std::cout << "Input file is not open." << std::endl;
        return 0;
    }     
    
    std::string line;
    std::getline(input,line);
    std::streampos index = input.tellg();
    input.seekg(0,std::ios::end);
    std::streampos size = input.tellg() - index;
    std::cout << input.tellg()<< " "<< index<< " "<<size << std::endl;
    input.seekg(index);
    char *restOfTheFile = new char[size];
    input.read(restOfTheFile,size);
    output.open("output.txt",std::fstream::out | std::fstream::trunc);
    output << line;
    output.write(restOfTheFile,size);
    output.close();
    input.close();
    return 0;
}

