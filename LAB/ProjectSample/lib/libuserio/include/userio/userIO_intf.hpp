#ifndef UIO_INTF_H
#define UIO_INTF_H

template <typename KeyboardReader> 
class UserInputReader {
public:
    using KeyBehaviour_t = typename KeyboardReader::KeyBehaviour_t;
    using Key_t = typename KeyboardReader::Key_t;

    UserInputReader() = default;
    UserInputReader(const UserInputReader &) = delete;
    UserInputReader operator = (const UserInputReader&) = delete;
    inline typename KeyboardReader::KeyBehaviour_t readKeyBehaviour() {
        return _p_keyBoardReader.readKeyBehaviour();
    }
private:
    KeyboardReader _p_keyBoardReader;
};

#endif // UIO_INTF_H
