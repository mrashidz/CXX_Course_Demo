#include "con.h"

con::con(const unsigned int &_c, const std::string &_n) {
    this->Counter = _c;
    this->Name = _n;
}
void con::bla() {
    std::cout << this->Name << " : " << this->Counter++ << std::endl;
}

void con2::bla() {
    std::cout << this->Name << " : " << this->Counter++ << std::endl;
}

