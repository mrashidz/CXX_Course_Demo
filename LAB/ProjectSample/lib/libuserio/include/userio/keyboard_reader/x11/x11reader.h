#ifndef X11READER_H
#define X11READER_H
#include <X11/Xlib.h>
#include <utility>
//#include <cstdint>

class KeyboardReader {
public:
    using KeyBehaviour_t = std::pair<int,unsigned int>;
    KeyboardReader();
    KeyboardReader(const KeyboardReader&) = delete;
    KeyboardReader operator = (const KeyboardReader&) = delete;
    ~KeyboardReader();
    KeyBehaviour_t readKeyBehaviour();
private:

    XEvent   event;
    Display  *display;
};

#endif // X11READER_H
