#include <iostream>
#include <cstring>
#include "userio/keyboard_reader/x11/x11keybindings.h"
#include "input_handler.h"

bool InputHandler::init(const std::string &_canIFname) {
    std::memset(this->ICONs.Data,0x00,sizeof (CAN::MSG::Iconss_t::_bits));
    return this->CANBUS_Writer.open(_canIFname);
}

bool InputHandler::run() {
    KeyboardReader::KeyBehaviour_t key = this->KeyboardReader.readKeyBehaviour();
    bool ret = this->encodKey(key);
    if (this->StateIsChanged) {
        this->printState();
        this->StateIsChanged = false;
    }
    ret = ret&&this->CANBUS_Writer.write(CAN::MSG::ICONSS_ID,
                                  sizeof (CAN::MSG::Iconss_t),
                                  this->ICONs.Data);
    return ret;
}

bool InputHandler::encodKey(const KeyboardReader::KeyBehaviour_t &_k) {
    bool ret = true;
    if(X11::DEFINED_KEYS.find(_k.second)==X11::DEFINED_KEYS.end())
        std::cout << "Key " << _k.second << " is not defined!" << std::endl;
    else if (_k.second == X11::EXIT) ret = false;
    else if (_k.first == KeyRelease) ret = this->keyIsReleased(_k.second);
    else if (_k.first == KeyPress)   ret = this->keyIsPressed(_k.second);
    return ret;
}

bool InputHandler::keyIsPressed(const unsigned int &_k) {
    bool ret = true;
    this->StateIsChanged = true;
    /*switch (_k) {
    case X11::ICN0:
            checkHazard();
        break;
    case X11::ICN1:
            checkHazard();
        break;
    case X11::GRCH:
            checkHazard();
        break;
    case X11::ACCL:
            this->State->InputState.ENGINE.ACCL_P=1;
        break;
    case X11::BREK:
            this->State->InputState.ENGINE.BREK_P=1;
        break;
    case X11::EXIT:
            ret = false;
        break;
    default:
        break;
    }*/
    std::cout << "Pressed Key is: " << X11::KeyToString(_k) << std::endl;
    return ret;
}

bool InputHandler::keyIsReleased(const unsigned int &_k) {
    this->StateIsChanged = true;
    switch (_k) {
    /* LEDs UP TOP */
    case X11::ICN0:
        this->ICONs.Bits.ICN0 =! this->ICONs.Bits.ICN0;
        break;
    case X11::ICN1:
            this->ICONs.Bits.ICN1=!this->ICONs.Bits.ICN1;
        break;
    case X11::ICN2:
            this->ICONs.Bits.ICN2=!this->ICONs.Bits.ICN2;
        break;
    case X11::ICN3:
            this->ICONs.Bits.ICN3=!this->ICONs.Bits.ICN3;
        break;
    case X11::ICN4:
            this->ICONs.Bits.ICN4=!this->ICONs.Bits.ICN4;
        break;
    case X11::ICN5:
            this->ICONs.Bits.ICN5=!this->ICONs.Bits.ICN5;
        break;
    case X11::ICN6:
            this->ICONs.Bits.ICN6=!this->ICONs.Bits.ICN6;
        break;
    case X11::ICN7:
            this->ICONs.Bits.ICN7=!this->ICONs.Bits.ICN7;
        break;
    case X11::ICN8:
            this->ICONs.Bits.ICN8=!this->ICONs.Bits.ICN8;
        break;
    case X11::ICN9:
            this->ICONs.Bits.ICN9=!this->ICONs.Bits.ICN9;
        break;
    /* Engine ACCL & BREK
    case X11::ACCL:
            this->State->InputState.ENGINE.ACCL_P=0;
        break;
    case X11::BREK:
            this->State->InputState.ENGINE.BREK_P=0;
        break;
    case X11::IGNT:
            this->State->InputState.ENGINE.IGNT=!this->State->InputState.ENGINE.IGNT;
        break;*/
    default:
            std::cout << "Released Key is: " << X11::KeyToString(_k) << std::endl;
        break;
    }
    return true;
}

void InputHandler::printState() {
    std::cout << ">>>>> Input Handler's State <<<<<" << std::endl;
    std::cout << "+++++ GAUGES:" << std::endl;
    CAN::MSG::printGauges(this->GAUGs);
    std::cout << "+++++ USERIN:" << std::endl;
    CAN::MSG::printUserIn(this->USRIn);
    std::cout << "+++++ ICONSS:" << std::endl;
    CAN::MSG::printIconss(this->ICONs.Bits);
    std::cout << std::endl;
}
