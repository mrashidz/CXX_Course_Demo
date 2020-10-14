#include <iostream>

class Polygon {
private:
    int width, height;    
protected:
    void set_values (int a, int b) { width=a; height=b;}
    int Width() {return this->width;}
    int Height() {return this->height;}
public:    
    Polygon (int a, int b) { width=a; height=b;}
    void print() {
        std::cout << this->width << " " << this->height << std::endl;
    }
};



class Rectangle: /*protected*/ Polygon {
    friend void modifyRectangle(Rectangle&);
public:
    Rectangle(int a,int b) : Polygon(a,b) {}
private:
    int area () { return Width() * Height(); }
};

class Triangle:  protected Polygon {
    friend void modifyTriangle(Triangle&);
public:
    Triangle(int a,int b) : Polygon(a,b) {}
private:
    int area () { return Width() * Height() / 2; }
};

void modifyRectangle(Rectangle &r) {
    std::cout << "Modifying Rectangle with Height and Width:";
    r.print();
    std::cout << "Hence the area is: " << r.area() << std::endl;
    
    r.set_values(r.Width()*2,r.Height()*2);

    std::cout << "After modification new Height and Width:";
    r.print();
    std::cout << "Hence the area is: " << r.area() << std::endl << std::endl;
}

void modifyTriangle(Triangle &t) {
    std::cout << "Modifying Rectangle with Height and Width:";
    t.print();
    std::cout << "Hence the area is: " << t.area() << std::endl;
    
    t.set_values(t.Width()*2,t.Height()*2);

    std::cout << "After modification new Height and Width:";
    t.print();
    std::cout << "Hence the area is: " << t.area() << std::endl << std::endl;
}


/*
class Square: public Rectangle {
    friend void modifySquare(Square&);
public:
    Square(int a) : Rectangle(a,a) {}
};

void modifySquare(Square &s) {
    std::cout << "Modifying Rectangle with Height and Width:";
    s.print();
    std::cout << "Hence the area is: " << s.area() << std::endl;
    
    s.set_values(s.Width()*2,s.Height()*2);

    std::cout << "After modification new Height and Width:";
    s.print();
    std::cout << "Hence the area is: " << s.area() << std::endl << std::endl;
}

*/

int main() {
    Rectangle r(3,4);
    Triangle t(3,4);
    /*Square s(3);
    t.print();
    r.print();
    s.print();*/
    modifyRectangle(r);
    modifyTriangle(t);
    //modifySquare(s);

    return 0;

}


