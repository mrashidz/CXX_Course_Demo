#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "canio/canio.h"
#include "canio/can_common.h"
#include "userio/uio_types.h"


// Takes user input and generates CAN messages
class InputHandler {
public:
    InputHandler() = default;
    bool init(const std::string &_canIFname);
    bool run();

private:
    bool encodKey(const KeyboardReader::KeyBehaviour_t &_k);
    bool keyIsPressed(const unsigned int &_k);
    bool keyIsReleased(const unsigned int &_k);
    void printState();
    CAN::MSG::Iconss_t ICONs;
    CAN::MSG::UserIn_t USRIn;
    CAN::MSG::Gauges_t GAUGs;

    CANio CANBUS_Writer;
    x11KeyboardReader KeyboardReader;
    bool StateIsChanged = false;
};

#endif // INPUT_HANDLER_H
