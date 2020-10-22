#include "shape.h"

bool Shape::operator <(const Shape &s) {
    bool returnVal = false;
    if ( (this->Area < s.Area) ||
         ( (this->Area == s.Area) && (this->Perimiter < s.Perimiter) ) )
        returnVal = true;    
    return returnVal;
}

bool Shape::operator >(const Shape &s) {
    bool returnVal = false;
    if ( (this->Area > s.Area) ||
         ( (this->Area == s.Area) && (this->Perimiter > s.Perimiter) ) )
        returnVal = true;    
    return returnVal;
}

bool Shape::operator ==(const Shape &s) {
    bool returnVal = false;
    if ( (this->Area == s.Area) && (this->Perimiter == s.Perimiter) ) 
        returnVal = true;    
    return returnVal;
}
Shape::~Shape(){}