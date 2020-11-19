#include <iostream>
#include <thread>
#include "VehicleEmulator.h"
#include "canio/canio.h"
int main() {
    VehicleEmulator ve;

    CANio canI/*,canO*/;
    canI.open("vcan0");
//    canO.open("vcan1");
    bool run = true;
    while (run) {
        struct canfd_frame frame;
        auto res = canI.read(&frame);

        if (res == READ_STATUS::ERROR) run = false;
        else if (res == READ_STATUS::OK) {
            if (frame.can_id == CAN::MSG::USERIN_ID) {
                ve.gotInput(reinterpret_cast<const CAN::MSG::UserIn_t *>(frame.data));
                //CAN::MSG::printUserIn(reinterpret_cast<const CAN::MSG::UserIn_t *>(frame.data));
            }

            std::cout << "s: " << (int)ve.Speed_MPH <<
                         " g: " << (int)VEHICLE::GearToInt(ve.GearNo) <<
                         " p: " << (int)VEHICLE::PindleToInt(ve.GearPindle) <<
                         " r: " << (int)ve.RPM <<
                         " i: " << (int)ve.Running << std::endl;
            //canI.write(CAN::MSG::GEARBX_ID,sizeof (CAN::MSG::Gearbx_t::_bits),ve.generateGearbxCAN().Data);
            auto a = ve.generateEngineCAN();
            canI.write(CAN::MSG::ENGINE_ID,sizeof (CAN::MSG::Engine_t),reinterpret_cast<uint8_t*>(&(a)));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));


    }

    return 0;
}

