#include <iostream>
#include <thread>
#include "input_handler.h"

int main() {
    InputHandler ih;
    ih.init("vcan0");
    while(ih.run())
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::cout << "I am going home" << std::endl;

    return 0;
}
