#include <iostream>
class Abstraction {
private:
    int x,y,z;
public:
    Abstraction () = delete;
    Abstraction (int _x,int _y,int _z):x(_x),y(_y),z(_z) { }
    int sum() { return x+y+z; }
};

class Encapsulation {
private:
    int x,y,z;
public:
    Encapsulation() = default;
    void SetX(int _x) { x = _x; }
    void SetY(int _y) { y = _y; }
    void SetZ(int _z) { z = _z; }
    int X() { return x; }
    int Y() { return y; }
    int Z() { return z; }
};



