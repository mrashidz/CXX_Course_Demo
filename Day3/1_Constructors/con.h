//#ifndef CON_H
//#define CON_H
#include <iostream>

class con {
public:
    con() {}
    con(const unsigned int &_c, const std::string &_n);
    ~con() {}
    void bla();
private:
    unsigned int Counter = 0;
    std::string Name = "No Name";
};

class con2 {
public:
    con2() = delete;
    con2(const unsigned int &_c, const std::string &_n):Counter(_c),Name(_n){};
    ~con2() = default;
    void bla();
private:
    unsigned int Counter;
    std::string Name;
};





//#endif /*CON_H*/