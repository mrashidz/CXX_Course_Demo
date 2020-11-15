#include <QtQuickControls2/QQuickStyle>
#include <QtQml/QQmlApplicationEngine>
#include <QtCore/QCommandLineParser>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlContext>
#include <QtQml/qqml.h>
#include <QtCore/QUrlQuery>
#include <QtCore/QProcess>
//#include <QCanBus>
#include <iostream>
#include "include/your_stuff.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QCoreApplication::setApplicationName("AVC");
    QCoreApplication::setApplicationVersion("0.3");
    QCommandLineParser parser;
    parser.setApplicationDescription("ALTEN Virtual Cockpit (AVC)");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOptions({
                          {
                              {"c", "can-interface"},
                              QCoreApplication::translate("main", "CAN interface"),
                              QCoreApplication::translate("main", "CANBUS interface name e.g. vcan0")
                          }
       });
    parser.process(app);
    if (!parser.isSet("can-interface"))
       parser.showHelp();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/cluster-gauges.qml")));
    QList<QObject *> mobjs = engine.rootObjects();
    QObject *vs = mobjs.first()->findChild<QObject*>("valueSource");
    std::cout << parser.value("can-interface").toStdString() << std::endl;
    /***** Your Code Goes Below Here ******/
    yourStuff _(parser.value("can-interface").toStdString(),vs);
//    QObject::connect(&_,&yourStuff::die,&app,&QCoreApplication::quit,Qt::QueuedConnection);


    return app.exec();

}
