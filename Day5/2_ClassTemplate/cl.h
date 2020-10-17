#ifndef CL_H
#define CL_H

#include <iostream>

template <typename T, size_t SIZE = 2>
class Container {
    public:
        bool add (const T &_element, size_t _i) {
            bool ret = false;
            if (_i >= SIZE);
            else {
                Data[_i] = _element;
                ret = true;
            }
            return ret;
        }
        T fetch(size_t _i) {
            T ret{};
            if (_i < SIZE) ret = Data[_i];
            return ret;
        }
        ~Container() {delete [] Data;}

    private:
        T *Data = new T[SIZE];

};


#endif // CL_H