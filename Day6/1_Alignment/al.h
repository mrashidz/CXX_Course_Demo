#include <iostream>

enum class UserType: uint8_t {
    Admin, Manager, Developer, User
};

struct Task1 {
    uint8_t  uID;
    uint32_t ticketNo;
    uint32_t cardNo;
    UserType uType;
};

struct Task2 {
    uint32_t ticketNo;
    uint32_t cardNo;
    uint8_t  uID;
    UserType uType;
};

struct Task1_Revealed {
    uint8_t  uID;

    uint8_t  PAD1;
    uint16_t PAD2;

    uint32_t ticketNo;
    uint32_t cardNo;
    UserType uType;

    uint8_t  PAD3;
    uint16_t PAD4;
};

struct Task2_Revealed {
    uint32_t ticketNo;
    uint32_t cardNo;
    uint8_t  uID;
    UserType uType;
    uint16_t PAD;    
};


struct Task3 {
    uint8_t  uID;
    uint32_t ticketNo;
    uint32_t cardNo;
    UserType uType;
}__attribute__((packed));