#ifndef X11KEYBINDINGS_H
#define X11KEYBINDINGS_H
#include <unordered_set>

namespace X11 {
    const unsigned int EXIT = 9;
    const unsigned int ACCL = 111;
    const unsigned int BREK = 116;
    const unsigned int GRUP = 38;
    const unsigned int GRDN = 52;
    const unsigned int GRLF = 59;
    const unsigned int GRRT = 60;
    const unsigned int ICN9 = 18;
    const unsigned int ICN8 = 17;
    const unsigned int ICN7 = 16;
    const unsigned int ICN6 = 15;
    const unsigned int ICN5 = 14;
    const unsigned int ICN4 = 13;
    const unsigned int ICN3 = 12;
    const unsigned int ICN2 = 11;
    const unsigned int ICN1 = 10;
    const unsigned int ICN0 = 19;
    const unsigned int IGNT = 104;

    const unsigned int TMUP = 35;
    const unsigned int TMDN = 51;
    const unsigned int OLUP = 34;
    const unsigned int OLDN = 48;
    const unsigned int FLUP = 33;
    const unsigned int FLDN = 47;

    const unsigned int NADA = 0;
    std::string KeyToString(const unsigned int &_k);
    static const std::unordered_set<unsigned int> DEFINED_KEYS = {9,10,11,12,13,14,15,16,17,18,19,38,
                                                                  52,59,60,111,116,104,33,34,35,47,48,51};
} // namespace X11
#endif // X11KEYBINDINGS_H
