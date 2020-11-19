#ifndef VEHICLEEMULATOR_H
#define VEHICLEEMULATOR_H
#include <cstdint>

#include <string>


#include "canio/can_common.h"

namespace VEHICLE {

//TODO: use template and classes instead of this shit!

enum class GEAR_PINDLE : unsigned char {
    P=0x01,
    N=0x02,
    R=0x03,
    D=0x04,
    M=0x05
};
static GEAR_PINDLE pindle_up(const GEAR_PINDLE& g) {
    switch(g) {
        case GEAR_PINDLE::P: return GEAR_PINDLE::N;
        case GEAR_PINDLE::N: return GEAR_PINDLE::R;
        case GEAR_PINDLE::R: return GEAR_PINDLE::D;
        case GEAR_PINDLE::D: return GEAR_PINDLE::M;
        case GEAR_PINDLE::M: return GEAR_PINDLE::M;
    }
}
static GEAR_PINDLE pindle_down(const GEAR_PINDLE& g) {
    switch(g) {
        case GEAR_PINDLE::P: return GEAR_PINDLE::P;
        case GEAR_PINDLE::N: return GEAR_PINDLE::P;
        case GEAR_PINDLE::R: return GEAR_PINDLE::N;
        case GEAR_PINDLE::D: return GEAR_PINDLE::R;
        case GEAR_PINDLE::M: return GEAR_PINDLE::D;
    }
}


enum class GEAR: unsigned char {
    RESERVED=0x00,
    ONE=0x01,
    TWO=0x02,
    THREE=0x03,
    FOUR=0x04,
    FIVE=0x05,
    SIX=0x06,
    SEV=0x07
};
static GEAR gear_up(const GEAR& g) {
    switch(g) {
        case GEAR::ONE: return GEAR::TWO;
        case GEAR::TWO: return GEAR::THREE;
        case GEAR::THREE: return GEAR::FOUR;
        case GEAR::FOUR: return GEAR::FIVE;
        case GEAR::FIVE: return GEAR::SIX;
        case GEAR::SIX: return GEAR::SEV;
        case GEAR::SEV: return GEAR::SEV;
    }
}
static GEAR gear_down(const GEAR& g) {
    switch(g) {
        case GEAR::ONE: return  GEAR::ONE;
        case GEAR::TWO: return GEAR::ONE;
        case GEAR::THREE: return  GEAR::TWO;
        case GEAR::FOUR: return GEAR::THREE;
        case GEAR::FIVE: return GEAR::FOUR;
        case GEAR::SIX: return GEAR::FIVE;
        case GEAR::SEV: return GEAR::SIX;
    }
}


static const double DRIVE_SHAFT_REV_PER_MILE = 7413.5;
static const double RATIO_1stGEAR = 3.98;
static const double RATIO_2ndGEAR = 2.61;
static const double RATIO_3rdGEAR = 1.90;
static const double RATIO_4thGEAR = 1.48;
static const double RATIO_5thGEAR = 1.16;
static const double RATIO_6thGEAR = 0.91;
static const double RATIO_7thGEAR = 0.71;

static const double RATIO_RGEAR = 2.80;
static const double TIRE_REV_PER_MILE = 741.35;
static const double RATIO_FINAL_SHAFT = 3.30;

static double GetGearRatio(GEAR _g) {
    switch(_g) {
        case GEAR::ONE: return RATIO_1stGEAR;
        case GEAR::TWO: return RATIO_2ndGEAR;
        case GEAR::THREE: return RATIO_3rdGEAR;
        case GEAR::FOUR: return RATIO_4thGEAR;
        case GEAR::FIVE: return RATIO_5thGEAR;
        case GEAR::SIX: return RATIO_6thGEAR;
        case GEAR::SEV: return RATIO_7thGEAR;

        case GEAR::RESERVED: return RATIO_RGEAR;
    }
}

//shall be cached!

static double CalcSpeed(uint32_t _engine_rev, GEAR _g) {
    if ( _engine_rev <= 900) return 0;
    double speed_mph = -1;
    double currentGearRatio = GetGearRatio(_g);
    double currentGearRevs = _engine_rev / currentGearRatio;
    double finalShaftRevs = currentGearRevs / RATIO_FINAL_SHAFT;
    double tire_DistanceCoverdInMiles = finalShaftRevs / TIRE_REV_PER_MILE;
    speed_mph = tire_DistanceCoverdInMiles * 60;
    if (speed_mph < 1) speed_mph = 0;
    return speed_mph;
}
static uint16_t CalcEngRev(double speed, GEAR _g) {
    double currentGearRatio = GetGearRatio(_g);
    double speed_perMin = speed /60;
    double tireRevsPerMin = speed_perMin * TIRE_REV_PER_MILE;
    double currentGearRevs = tireRevsPerMin * RATIO_FINAL_SHAFT;
    double engineRevs = currentGearRevs * currentGearRatio;
    return static_cast<uint16_t>(engineRevs);
}

static uint8_t PindleToInt(VEHICLE::GEAR_PINDLE _p) {
    switch (_p) {
    case VEHICLE::GEAR_PINDLE::P: return 0;
    case VEHICLE::GEAR_PINDLE::N: return 1;
    case VEHICLE::GEAR_PINDLE::R: return 2;
    case VEHICLE::GEAR_PINDLE::D: return 3;
    case VEHICLE::GEAR_PINDLE::M: return 4;
    }
}

static uint8_t GearToInt(VEHICLE::GEAR _g) {
    switch (_g) {
    case VEHICLE::GEAR::RESERVED: return 0;

    case VEHICLE::GEAR::ONE: return 1;
    case VEHICLE::GEAR::TWO: return 2;
    case VEHICLE::GEAR::THREE: return 3;
    case VEHICLE::GEAR::FOUR: return 4;
    case VEHICLE::GEAR::FIVE: return 5;
    case VEHICLE::GEAR::SIX: return 6;
    }
}

} // namespace VEHICLE



class VehicleEmulator {
public:
    VehicleEmulator();

    void init(std::string SERport, std::string CANdev);
    void gotInput(const CAN::MSG::UserIn_t *_ui);

private:

    void readConfig();
    //serial
    void icon(/*QStringList _cmd*/);
    void gear(/*QStringList _cmd*/);
    void gauge(/*QStringList _cmd*/);
    void controlCMD(/*QStringList _cmd*/);
    void bufferSerialCOM(/*QString _msg*/);
    void processSerialCOM(/*QString _serialMSG*/);
    //can
    //void sendCan(quint32 _id, QByteArray _payload);




    //engine and stuff(break)
    void igniteEngine();
    void runPowerTrain(const CAN::MSG::UserIn_t *_ui);
    void accl();
    void brek();
    void resist();
    void revUpEngine();
    void shutdownEngine();
    //gear box
    inline void pindleDown(){this->GearPindle = VEHICLE::pindle_down(this->GearPindle);}
    inline void pindleUp()  {this->GearPindle = VEHICLE::pindle_up(this->GearPindle);}
    inline void gearDown()  {
        if (this->GearPindle == VEHICLE::GEAR_PINDLE::M) {
            this->GearNo = VEHICLE::gear_down(this->GearNo);
            if (this->Speed_MPH)
                this->RPM = VEHICLE::CalcEngRev(this->Speed_MPH,this->GearNo);
        }
    }
    inline void gearUP() {
        if (this->GearPindle == VEHICLE::GEAR_PINDLE::M) {
            this->GearNo = VEHICLE::gear_up(this->GearNo);
            if (this->Speed_MPH)
                this->RPM = VEHICLE::CalcEngRev(this->Speed_MPH,this->GearNo);
        }
    }
    inline void changeTransmitionMode() {
        if (this->GearPindle == VEHICLE::GEAR_PINDLE::M) this->GearPindle = VEHICLE::GEAR_PINDLE::D;
        else if (this->GearPindle == VEHICLE::GEAR_PINDLE::D) this->GearPindle = VEHICLE::GEAR_PINDLE::M;


    }

//private:
public:
    double RPM = 0;
    CAN::MSG::Engine_t generateEngineCAN();
    CAN::MSG::Gearbx_t generateGearbxCAN();
    VEHICLE::GEAR_PINDLE GearPindle;
    VEHICLE::GEAR GearNo;
    uint8_t Speed_MPH;

    bool Running  = false;
};


#endif // VEHICLEEMULATOR_H
