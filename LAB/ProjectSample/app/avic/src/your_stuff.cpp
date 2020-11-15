//#include <chrono>
#include <thread>
#include <iostream>
#include "your_stuff.h"
namespace CANID {
const canid_t ENGINE_AND_GEARBOX = 0x123;
const canid_t ICONZ = 0x213;
}

void yourStuff::YouHaveJustRecievedACANFrame(const canfd_frame * const _frame) {
    switch (_frame->can_id) {
    case CANID::ENGINE_AND_GEARBOX:
        std::cout << _frame->can_id << "is recieved" << std::endl;
        this->readMyEngineFrame(_frame->data);
        break;
    case CANID::ICONZ:
        this->InstrumentCluster.setIcon(reinterpret_cast<const struct _icons * >((_frame->data)));
    default:
        break;
    }

}

void yourStuff::readMyEngineFrame(const unsigned char * const _data) {
    this->InstrumentCluster.setSpeed(static_cast<double>(_data[0]));
}














/******************************* ANYTHING BELOW THIS LINE IS JUST BORING STUFF *******************************/

yourStuff::yourStuff(const std::string &_ifName, QObject *_vs) {
    if(!(this->CANReader.open(_ifName))) exit(-1);//emit die();
    this->InstrumentCluster.init(_vs);
    this->startTimer(3);
}

bool yourStuff::run() {
    bool ret = true;
    canfd_frame frame;    
    CANOpener::ReadStatus status = this->CANReader.read(&frame);    

    if (status == CANOpener::ReadStatus::ERROR) ret = false;

    else if (status == CANOpener::ReadStatus::NAVAL ||
             status == CANOpener::ReadStatus::ENDOF) this->Counter++;

    else if (status == CANOpener::ReadStatus::OK) {
        this->Counter = 0;
        this->YouHaveJustRecievedACANFrame(&frame);
    }
    //if (this->Counter > 200) ret = false;
    return ret;
}

void yourStuff::timerEvent(QTimerEvent*) {
    if(this->run());
    else {
//    emit this->die();
    exit(-1);
    }
}

