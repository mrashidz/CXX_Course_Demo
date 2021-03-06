#include <iostream>
#include <cstring>
#include "userio/keyboard_reader/x11/x11keybindings.h"
#include "input_handler.h"



bool InputHandler::init(const std::string &_canIFname) {
    std::memset(this->ICONs.Data,0x00,sizeof (CAN::MSG::Iconss_t::_bits));
    std::memset(this->GAUGs.Data,0x00,sizeof (CAN::MSG::Gauges_t::_inner));
    std::memset(&(this->USRIn),0x00,sizeof (CAN::MSG::UserIn_t));
    return this->CANBUS_Writer.open(_canIFname);
}


bool InputHandler::run() {
    bool ret = true;
    KeyboardReader::KeyBehaviour_t key = this->KeyboardReader.readKeyBehaviour();
    if (key.second != X11::NADA)   ret = ret &&this->encodKey(key);
    if (this->StateIsChanged) {
        this->printState();
        this->StateIsChanged = false;
    } else {
        this->USRIn.IGNT = this->USRIn.GRDN =  this->USRIn.GRLF =
                this->USRIn.GRRT = this->USRIn.GRUP = 0;
    }

    if(this->PushedKeys.size() && ++GaugeSensetivity > GAUGE_CHECK_SENSETIVITY)
        for(auto &_e: this->PushedKeys)
            this->keyIsPushed(_e);

/*
    if (this->USRIn.IGNT && !this->justSentIGNT) this->justSentIGNT = true;
    else if (this->USRIn.IGNT && this->justSentIGNT) this->USRIn.IGNT = 0;
    else if (!this->USRIn.IGNT && this->justSentIGNT) this->justSentIGNT = false;
*/
    /*ret = ret && this->CANBUS_Writer.write(CAN::MSG::ICONSS_ID,
                                         sizeof (CAN::MSG::Iconss_t),
                                         reinterpret_cast<uint8_t*>(&(this->ICONs)));
    ret = ret && this->CANBUS_Writer.write(CAN::MSG::GAUGES_ID,
                                         sizeof (CAN::MSG::GAUGES_ID),
                                         this->GAUGs.Data);*/
    ret = ret && this->CANBUS_Writer.write(CAN::MSG::USERIN_ID,
                                           sizeof (CAN::MSG::_userin),
                                           reinterpret_cast<uint8_t*>(&(this->USRIn)));
    if (this->USRIn.IGNT ) std::cout << "WE DID IT DUDE WE DID@@" << std::endl;
    return ret;
}

bool InputHandler::encodKey(const KeyboardReader::KeyBehaviour_t &_k) {
    bool ret = true;
    KeyboardReader::Key_t k = _k.second;
    if(X11::DEFINED_KEYS.find(k)==X11::DEFINED_KEYS.end())
        std::cout << "Key " << k << " is not defined!" << std::endl;

    else if (k == X11::EXIT)         ret = false;
    else if (_k.first == KeyPress)   ret = this->keyIsPressed(_k.second);
    else if (_k.first == KeyRelease) ret = this->keyIsReleased(_k.second);

    return ret;
}

bool InputHandler::keyIsPressed(const KeyboardReader::Key_t &_k) {
    bool ret = true;
    this->StateIsChanged = true;
    switch (_k) {/*
    case X11::ICN0:
            checkHazard();
        break;
    case X11::ICN1:
            checkHazard();
        break;
    case X11::GRCH:
            checkHazard();*/
    case X11::OLDN:
        this->PushedKeys.insert(X11::OLDN);
        break;
    case X11::OLUP:
        this->PushedKeys.insert(X11::OLUP);
        break;
    case X11::TMDN:
        this->PushedKeys.insert(X11::TMDN);
        break;
    case X11::TMUP:
        this->PushedKeys.insert(X11::TMUP);
        break;
    case X11::FLDN:
        this->PushedKeys.insert(X11::FLDN);
        break;
    case X11::FLUP:
        this->PushedKeys.insert(X11::FLUP);
        break;
    case X11::IGNT:
        this->USRIn.IGNT = 1;
        break;
    case X11::ACCL:
        this->USRIn.ACCL = 1;
        break;
    case X11::BREK:
        this->USRIn.BREK = 1;
        break;
    case X11::GRLF:
        this->USRIn.GRLF = 1;
        break;
    case X11::GRUP:
        this->USRIn.GRUP = 1;
        break;
    case X11::GRRT:
        this->USRIn.GRRT = 1;
        break;
    case X11::GRDN:
        this->USRIn.GRDN = 1;
        break;
    default:
        //ret = false;
        break;
    }
    std::cout << "Pressed Key is: " << X11::KeyToString(_k) << std::endl;
    return ret;
}

bool InputHandler::keyIsReleased(const KeyboardReader::Key_t &_k) {
    this->StateIsChanged = true;
    bool ret = true;
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
    case X11::OLDN:
        this->PushedKeys.erase(X11::OLDN);
        break;
    case X11::OLUP:
        this->PushedKeys.erase(X11::OLUP);
        break;
    case X11::TMDN:
        this->PushedKeys.erase(X11::TMDN);
        break;
    case X11::TMUP:
        this->PushedKeys.erase(X11::TMUP);
        break;
    case X11::FLDN:
        this->PushedKeys.erase(X11::FLDN);
        break;
    case X11::FLUP:
        this->PushedKeys.erase(X11::FLUP);
        break;
    case X11::IGNT:
        this->USRIn.IGNT = 0;
        break;
    case X11::ACCL:
        this->USRIn.ACCL = 0;
        break;
    case X11::BREK:
        this->USRIn.BREK = 0;
        break;
    case X11::GRLF:
        this->USRIn.GRLF = 0;
        break;
    case X11::GRUP:
        this->USRIn.GRUP = 0;
        break;
    case X11::GRRT:
        this->USRIn.GRRT = 0;
        break;
    case X11::GRDN:
        this->USRIn.GRDN = 0;
        break;

    default:
        //ret = false;
        std::cout << "Released Key is: " << X11::KeyToString(_k) << std::endl;
        break;
    }

    return ret;
}

void InputHandler::keyIsPushed(const unsigned int &_k) {
    switch (_k) {
    case X11::OLDN:
        this->decreaseGauge(this->GAUGs.Inner.G_OILT);
        break;
    case X11::OLUP:
        this->increaseGauge(this->GAUGs.Inner.G_OILT);
        break;
    case X11::TMDN:
        this->decreaseGauge(this->GAUGs.Inner.G_TEMP);
        break;
    case X11::TMUP:
        this->increaseGauge(this->GAUGs.Inner.G_TEMP);
        break;
    case X11::FLDN:
        this->decreaseGauge(this->GAUGs.Inner.G_FUEL);
        break;
    case X11::FLUP:
        this->increaseGauge(this->GAUGs.Inner.G_FUEL);
        break;
    default:
        std::cout << "Released Key is: " << X11::KeyToString(_k) << std::endl;
        break;
    }
    this->GaugeSensetivity = 0;
}

void InputHandler::printState() {
    std::cout << ">>>>> Input Handler's State <<<<<" << std::endl;
    std::cout << "+++++ GAUGES:" << std::endl;
    CAN::MSG::printGauges(&(this->GAUGs.Inner));
    std::cout << "+++++ USERIN:" << std::endl;
    CAN::MSG::printUserIn(&(this->USRIn));
    std::cout << "+++++ ICONSS:" << std::endl;
    //CAN::MSG::printIconss(&(this->ICONs.Bits));
    std::cout << std::endl;
}
