#include <iostream>
#include <thread>

const size_t S = 1;
int a[S];
int readIndex = 0;
int writeIndex = 0;
int writeIndex2 = 0;

void read() {
    while(true) {
        std::cout << "reading " << "a[" << readIndex << "]"<< a[readIndex] << std::endl << std::flush;
        if (++readIndex == S) readIndex=0;
    }
}
void write() {
    while(true) {        
        a[writeIndex] = std::rand();
        std::cout << "wrote " << "a[" << writeIndex << "]"<< a[writeIndex] << std::endl << std::flush;
        if (++writeIndex == S) writeIndex=0;
    }
}
void write2() {
    while(true) {        
        a[writeIndex] = std::rand();
        std::cout << "wrote " << "a[" << writeIndex << "]"<< a[writeIndex] << std::endl << std::flush;
        if (++writeIndex == S) writeIndex=0;
    }
}

int main() {

    //read();
    //write();
    //write2();

    std::thread t1(read);
    std::thread t2(write);

    std::thread t3(write2);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}
