#include "VehicleEmulator.h"
//#include <QCanBus>
//#include <QThread>
#include <cstring>
#include<iostream>


VehicleEmulator::VehicleEmulator()
{
    this->shutdownEngine();

}
/*
void VehicleEmulator::init(std::string _serial, std::string _can)
{
    this->Config.CANdev = _can;
    this->Config.SERport = _serial;
    this->readConfig();
    QString err;
    this->CANbus = QCanBus::instance()->createDevice(QStringLiteral("socketcan"),this->Config.CANdev, &err);
    if (!this->CANbus->connectDevice()) {
        qDebug() << "OPENNING CAN" << err;
        exit(-1);
    }
    qDebug() << "THIS GOT HEAR" <<std::endl;
    this->SERIAL.setPortName(this->Config.SERport);
    this->SERIAL.setBaudRate(this->Config.Baudrate);
    if (!this->SERIAL.open(QIODevice::ReadOnly)) {
           qDebug() << QObject::tr("Failed to open port %1, error: %2").arg(this->Config.SERport) << endl;
           exit(-1);
    }
    connect(&this->SERIAL, &QSerialPort::errorOccurred, this, &VehicleEmulator::serialCOM_err);
    connect(&this->SERIAL, &QSerialPort::readyRead, this, &VehicleEmulator::readSerial);

    this->TIMER_ID_ECU =  this->startTimer(500);
//    this->TIMER_ID_GEAR =  this->startTimer(200);
    this->TIMER_ID_WHEEL =  this->startTimer(800);
    this->TIMER_ID_CABIN =  this->startTimer(1000);
    this->TIMER_ID_ENGINE =  this->startTimer(100);
}


*/


void VehicleEmulator::igniteEngine()
{/*
    if (this->InputState.IGNT) {
        if (this->Speed_MPH) {

        } else {
            this->shutdownEngine();
        }
    } else {
        this->InputState.IGNT = 1;
    }
*/
            std::cout << "ignt" << std::endl;
    this->RPM = 900;
    this->GearNo = VEHICLE::GEAR::ONE;
    this->GearPindle = VEHICLE::GEAR_PINDLE::P;
    this->Running = true;
}

void VehicleEmulator::runPowerTrain(const CAN::MSG::UserIn_t *_ui)
{
    double rpm = this->RPM;
    if (_ui->ACCL) this->accl();
    else           this->resist();

    if (_ui->GRDN) this->gearDown();
    if (_ui->GRUP) this->gearUP();

    if (_ui->GRLF) this->pindleDown();
    if (_ui->GRRT) this->pindleUp();

    if (_ui->BREK) this->brek();
    std::cout << "run" << std::endl;


    if (this->RPM < 800) this->RPM = 900;
    if (this->Running && this->Speed_MPH == 0 && this->GearPindle == VEHICLE::GEAR_PINDLE::M) this->shutdownEngine();
    if (this->RPM == rpm) this->RPM -= 100;
//    if (this->RPM > 8000) this->RPM -= 1000;
}

void VehicleEmulator::accl()
{
    std::cout << "accl" << std::endl;

    if (this->GearPindle == VEHICLE::GEAR_PINDLE::P) return;
    if (this->RPM > 8900) this->RPM -=700;
    this->revUpEngine();
    double speed = 0;
    if (this->GearPindle != VEHICLE::GEAR_PINDLE::N) {
        speed = VEHICLE::CalcSpeed(this->RPM,this->GearNo);
        if (this->GearPindle == VEHICLE::GEAR_PINDLE::D && this->RPM> 7400) {
            std::cout << "HERE: " << this->RPM <<std::endl;
                this->GearNo = VEHICLE::gear_up(this->GearNo);
                this->RPM = VEHICLE::CalcEngRev(speed,this->GearNo);
        }
    }
    this->Speed_MPH = static_cast<uint8_t>(speed);
}

void VehicleEmulator::brek()
{
    double ratio = VEHICLE::GetGearRatio(this->GearNo);
    if (this->RPM > 900)
        this->RPM-=1.1*ratio;
}

void VehicleEmulator::resist()
{
    double ratio = VEHICLE::GetGearRatio(this->GearNo);
    this->RPM-=(ratio/2);
    if (this->GearPindle == VEHICLE::GEAR_PINDLE::N) return;
    double speed = VEHICLE::CalcSpeed(this->RPM, this->GearNo);
    if (this->GearPindle == VEHICLE::GEAR_PINDLE::D) {
        VEHICLE::GEAR lower = VEHICLE::gear_down(this->GearNo);
        uint16_t lower_gear_rpm = VEHICLE::CalcEngRev(speed,lower);
        if (lower_gear_rpm < 4700) {
            this->GearNo = lower;
            this->RPM = lower_gear_rpm;
        }
    }

    this->Speed_MPH = static_cast<uint8_t>(speed);
}


void VehicleEmulator::revUpEngine()
{
    double ratio;
    (this->GearPindle == VEHICLE::GEAR_PINDLE::N) ? ratio = 4.5 :ratio = VEHICLE::GetGearRatio(this->GearNo);

    if (RPM < 1500) {
        RPM+=(1*(ratio));
    } else if (RPM < 2500) {
        RPM+=(1.05*ratio);
    }
    else if (RPM < 3100) {
        RPM+=(1.2*ratio);
    }
    else if (RPM < 4000) {
        RPM+=(1.4*ratio);
    }
    else if (RPM < 4900) {
        RPM+=(1.8*ratio);
    }
    else if (RPM < 5500) {
        RPM+=(2.1*ratio);
    }
    else if (RPM < 6200) {
        RPM+=(2.4*ratio);
    }
    else if (RPM < 7700) {
        RPM+=(1.6*ratio);
    }
    else if (RPM < 8200) {
        RPM+=(1.3*ratio);
    }
    else if (RPM < 9000) {
        RPM+=(1.1*ratio);
    }
}

void VehicleEmulator::shutdownEngine()
{
    std::cout << "shtt" << std::endl;

//    memset(&this->InputState,0x00,5);
    this->GearPindle = VEHICLE::GEAR_PINDLE::P;
    this->GearNo = VEHICLE::GEAR::RESERVED;
    this->Speed_MPH = 0;
    this->RPM = 0;
    this->Running = false;
}

CAN::MSG::Engine_t VehicleEmulator::generateEngineCAN() {
    CAN::MSG::Engine_t e;
    e.SPD = static_cast<uint16_t>(this->Speed_MPH);
    e.RPM = this->RPM;
    e.RUN = this->Running;
    return e;
}

CAN::MSG::Gearbx_t VehicleEmulator::generateGearbxCAN() {
    CAN::MSG::Gearbx_t g;
    g.Bits.GEAR_N = VEHICLE::GearToInt(this->GearNo);
    g.Bits.GEAR_P = VEHICLE::PindleToInt(this->GearPindle);
    return g;
}

void VehicleEmulator::gotInput(const CAN::MSG::UserIn_t *_ui) {
    if (_ui->IGNT) {
        std::cout << "ignt1" << std::endl;

        (this->Running)?this->shutdownEngine():this->igniteEngine();
    }
    if (this->Running) this->runPowerTrain(_ui);
}
/*

void VehicleEmulator::gear() {
//    qDebug() << "g " << _cmd;

    if (_cmd.length() == 2) {
        ((this->GearPindle == VEHICLE::GEAR_PINDLE::D || this->GearPindle == VEHICLE::GEAR_PINDLE::M)
                && (_cmd[1] == "L"))?this->changeTransmitionMode():this->gearDown();
    } else if (_cmd.length() == 1) {
        this->gearUP();
//    qDebug() << "Pindle: " << APP::PindleToInt(this->GearPindle) << " Gear No. " << APP::GearToInt(this->GearNo);

}


void VehicleEmulator::controlCMD(QStringList _cmd)
{
    QString ctrl_cmd = _cmd[0];
    qDebug() << "controli  " << ctrl_cmd;
    if (_cmd.size() == 2) {
        QString act = _cmd[1];
        if (ctrl_cmd == "ACCL") {
            act == "P" ? this->InputState.ACCL_P = 1:this->InputState.ACCL_P = 0;
        } else if (ctrl_cmd == "BREK") {
            act == "P" ? this->InputState.BREK_P = 1:this->InputState.BREK_P = 0;
        }
    } else if (ctrl_cmd == "HZRD") {
        this->InputState.HZRD = !this->InputState.HZRD;
        if (this->InputState.HZRD) {
            this->InputState.ICON_0 = 1;
            this->InputState.ICON_9 = 1;
        } else {
            this->InputState.ICON_0 = 0;
            this->InputState.ICON_9 = 0;
        }
    }
}


void VehicleEmulator::timerEvent(QTimerEvent *event)
{
//    return;
//    DEBUG_VE::PrintVehicleInputState(this->InputState);
    if (event->timerId() == this->TIMER_ID_ENGINE) {
        this->runPowerTrain();
        this->sendEngine_CANmsg();
        this->sendGearBox_CANmsg();
    } else if (event->timerId() == this->TIMER_ID_GEAR) {
    } else if (event->timerId() == this->TIMER_ID_ECU) {
        this->sendECU_CANmsg();
    } else if (event->timerId() == this->TIMER_ID_WHEEL) {
        this->sendWHEEL_CANmsg();
    } else if (event->timerId() == this->TIMER_ID_CABIN) {
        this->sendCABIN_CANmsg();
    }
}
*/
