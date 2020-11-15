#ifndef CLUSTERUPDATE_H
#define CLUSTERUPDATE_H
#include <QObject>
#include <QVariant>

struct _icons {
    unsigned short abs : 1;
    unsigned short hazard : 1;
    unsigned short battery : 1;
    unsigned short high_beam : 1;
    unsigned short oil_check : 1;
    unsigned short seat_belt : 1;
    unsigned short doors_open : 1;
    unsigned short hand_break : 1;
    unsigned short left_blinker : 1;
    unsigned short engine_check : 1;
    unsigned short right_blinker : 1;
    unsigned short _reserved_pad : 5;
};

class ClusterUpdater/* : public QObject*/ {
//    Q_OBJECT
public:
    ClusterUpdater() = default;
    inline void init(QObject*_){this->ValueSource=_;}


public:
    void setIcon(const _icons *_i);

    inline void setGear(const char &_s) {ValueSource->setProperty("gear",QVariant(_s));}
    inline void setRPM(const double &_s) {ValueSource->setProperty("rpm",QVariant(_s));}
    inline void setSpeed(const double &_s) {ValueSource->setProperty("kph",QVariant(_s));}
    inline void setGearPindle(const char &_p) {ValueSource->setProperty("pindle",QVariant(_p));}
    inline void setFuelGauges(const double &_f) {ValueSource->setProperty("fuel",QVariant(_f));}
    inline void setTemperatureGauges(const double &_t) {ValueSource->setProperty("temperature",QVariant(_t));}
    inline void setOilTemperatureGauges(const double &_t) {ValueSource->setProperty("oil_temp",QVariant(_t));}

private:
    unsigned short iconZ;
    QObject *ValueSource;
};

#endif // CLUSTERUPDATE_H
