#include "con.h"

int main() {
    con c;
    c.bla();

    //con2 c2;
    con2 c2(5,"The only constructor");
    c2.bla();

    con c3(11,"The 2nd Constructor");
    c3.bla();

    return 0;
}

