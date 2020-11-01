#include <iostream>
#include "socketcan_cpp.h"

// https://github.com/siposcsaba89/socketcan-cpp

int main() {
    scpp::SocketCan sockat_can;
    if (sockat_can.open("vcan0") != scpp::STATUS_OK) {
        std::cout << "Cannot open vcan0." << std::endl;
        std::cout << "Check whether the vcan0 interface is up!" << std::endl;
        exit (-1);
    }

    while (true) {
        scpp::CanFrame cf_to_write;
        
        cf_to_write.id = 123;
        cf_to_write.len = 8;
        for (int i = 0; i < 8; ++i)
            cf_to_write.data[i] = std::rand() % 256;
        auto write_sc_status = sockat_can.write(cf_to_write);
        if (write_sc_status != scpp::STATUS_OK)
            printf("something went wrong on socket write, error code : %d \n", int32_t(write_sc_status));
        else
            printf("Message was written to the socket \n");
    }


    return 0;
}