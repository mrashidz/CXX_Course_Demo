#include "cl.h"

template <> 
class Container<char> {
    public: 
        bool add (const char * _e) {
            Data+=_e;
            return true;
        }
        bool add (const char &_e) {
            Data+=_e;
            return true;
        }
        const char *fetch(size_t _from, size_t _to) {
            std::string ret = "";
            if (_from > Data.length() || _to > Data.length() || _from > _to);
            else {
                ret = Data.substr(_from,_to);
            }
            return ret.c_str();
        }
        char fetch(size_t _i) {
            char ret = 0x00;
            if (_i < Data.length()) ret = Data[_i];
            return ret;
        }
    private:
        std::string Data;

};

int main() {

    Container<int>   intPair;    
    Container<char>  charContainer;
    Container<int,5> intContainer;

    charContainer.add("Hello World!");

    for (size_t i = 0; intPair.add( i+((i+1)*10), i); i++) {
        std::cout << "Adding int to pair " << i+1 << " time." << std::endl;
    }
    for (size_t i = 0; intContainer.add(i,i); i++) {
        std::cout << "Adding int to container " << i+1 << " time." << std::endl;
    }

    std::cout << "Fetching from pair at location 0 = " << intPair.fetch(0);
    std::cout << " and location 12 = " << intPair.fetch(12) << std::endl;

    std::cout << "Fetching from container at location 3 = " << intContainer.fetch(3);
    std::cout << " and location 6 = " << intContainer.fetch(6) << std::endl;

    std::cout << "Fetching from charContainer at location 3 = \'" << charContainer.fetch(3);
    std::cout << "\' and location 32 = \'" << charContainer.fetch(32) << "\'." << std::endl;
    
    std::cout << "Fetching from charContainer between location 2 and 7 = \'" << charContainer.fetch(2,7);
    std::cout << "\' and between location 5 and 12 = \'" << charContainer.fetch(5,12) << "\'." << std::endl;    
    
    return 0;
}