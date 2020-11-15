#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H
#include <unordered_set>
#include "canio/canio.h"
#include "canio/can_common.h"
#include "userio/uio_types.h"

const unsigned char GAUGE_STEP = 1;
const unsigned char GAUGE_CHECK_SENSETIVITY = 50;
// Takes user input and generates CAN messages
class InputHandler {
public:
    InputHandler() = default;
    bool init(const std::string &_canIFname);
    bool run();

private:
    using X11keys = x11KeyboardReader::KeyBehaviour_t::second_type;
    bool encodKey(const KeyboardReader::KeyBehaviour_t &_k);
    bool keyIsPressed(const unsigned int &_k);
    bool keyIsReleased(const unsigned int &_k);
    inline void decreaseGauge(unsigned char &_v) {(_v < GAUGE_STEP) ? _v=0X00:_v-=GAUGE_STEP;}
    inline void increaseGauge(unsigned char &_v) {(_v + GAUGE_STEP > 0xFF) ? _v=0XFF:_v+=GAUGE_STEP;}    
    void keyIsPushed(const unsigned int &_k);

    void printState();
    CAN::MSG::Iconss_t ICONs;
    CAN::MSG::UserIn_t USRIn;
    CAN::MSG::Gauges_t GAUGs;
    std::unordered_set<X11keys> PushedKeys;
    CANio CANBUS_Writer;
    x11KeyboardReader KeyboardReader;
    bool StateIsChanged = false;

    uint8_t GaugeSensetivity = 0;
};

#endif // INPUT_HANDLER_H
