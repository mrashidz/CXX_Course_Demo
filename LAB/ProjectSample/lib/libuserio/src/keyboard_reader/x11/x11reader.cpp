#include <iostream>
#include "x11reader.h"
#include "x11keybindings.h"


//TODO: this is x11 server not only keyboard -- could be moved elsewhere if other inputs become interseting
KeyboardReader::KeyboardReader() {
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        std::cout <<  "Cannot open display" << std::endl;
        exit(1);
    }
    int screen = DefaultScreen(display);
    Window window = XCreateSimpleWindow(display, RootWindow(display, screen), 1, 1, 10, 10, 0,
                                        BlackPixel(display, screen), WhitePixel(display, screen));
    XSelectInput(display, window, KeyPressMask | KeyReleaseMask );
    XMapWindow(display, window);
    XAutoRepeatOff(display);
}

KeyboardReader::~KeyboardReader() {
    XAutoRepeatOn(display);
    XCloseDisplay(display);
}

KeyboardReader::KeyBehaviour_t KeyboardReader::readKeyBehaviour() {
    KeyBehaviour_t k = std::make_pair(-1, X11::NADA);
    if(XCheckMaskEvent(display, KeyPressMask | KeyReleaseMask, &event))
        k = std::make_pair(event.type,event.xkey.keycode);
    return k;
}

namespace X11 {


std::string KeyToString(const unsigned int &_k)  {
    std::string ret;
    switch (_k) {
    case  9:
        ret = "EXIT";
        break;
    case  111:
        ret = "ACCL";
        break;
    case  116:
        ret = "BREK";
        break;
    case  38:
        ret = "GRUP";
        break;
    case  52:
        ret = "GRDN";
        break;
    case  58:
        ret = "GRCH";
        break;
    case  18:
        ret = "ICN9";
        break;
    case  17:
        ret = "ICN8";
        break;
    case  16:
        ret = "ICN7";
        break;
    case  15:
        ret = "ICN6";
        break;
    case  14:
        ret = "ICN5";
        break;
    case  13:
        ret = "ICN4";
        break;
    case  12:
        ret = "ICN3";
        break;
    case  11:
        ret = "ICN2";
        break;
    case  10:
        ret = "ICN1";
        break;
    case  19:
        ret = "ICN0";
        break;
    case  36:
        ret = "IGNT";
        break;
    case 35:
        ret = "TMUP";
        break;
    case 51 :
        ret = "TMDN";
        break;
    case 34:
        ret = "OLUP";
        break;
    case 48:
        ret = "OLDN";
        break;
    case 33:
        ret = "FLUP";
        break;
    case 47:
        ret = "FLDN";
        break;
    default:
        break;
    }
    return ret.c_str();
}
} // namespace X11
