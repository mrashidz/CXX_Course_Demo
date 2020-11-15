

import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4



ApplicationWindow {
    id: root
    width: 1920
    height: 842
    visible: true
    flags: Qt.FramelessWindowHint
    style: ApplicationWindowStyle {
        background: Rectangle {
            color: "#ffffff"
        }
    }

    ValueSource {
        id: valueSource
        objectName: "valueSource"
    }/*
    property string _API_str: "low-can"
    property string verb_str: "subscribe"
    property var _MSGID_enu: { "call":2, "retok":3, "reterr":4, "event":5 }
    property string request_str: ""
    property string status_str: ""
    property int counter: 0
    property string event_str: ""
*/

    Rectangle {
        id: statusFrame
        x: (parent.width - width) / 2
        y: 100
        width: 1552
        height: 90
        //radius: height / 5

        color: "#656565"
        border.width: 5
        border.color: "#3e3e3e"

        Row {
            width: parent.width
            height: parent.height * 0.75
            spacing: (parent.width - (12 * parent.height * 0.75)) / 13

            anchors.fill: parent
            anchors.topMargin: (parent.height - height) /2
            anchors.bottomMargin: (parent.height - height) /2
            anchors.leftMargin: (parent.width - (12 * parent.height * 0.75)) / 13
            anchors.rightMargin: (parent.width - (12 * parent.height * 0.75)) / 13

            Rectangle {
                width: height
                height: parent.height
                radius: height / 5

                color: "#656565"



                TurnIndicator {
                    id: leftIndicator
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: height
                    height: parent.height * 0.75

                    direction: Qt.LeftArrow
                    on: valueSource.left_blinker
                }
            }

            Rectangle {
                width: height
                height: parent.height
                radius: height / 5

                color: "#656565"



                Image {
                    source: valueSource.engine_check ? './images/AGL_Icons_Engine_yellow.svg' : './images/AGL_Icons_Engine.svg'
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: height
                    height: parent.height * 0.75
                    fillMode: Image.PreserveAspectFit
                }
            }

            Rectangle {
                width: height
                height: parent.height
                radius: height / 5
                color: "#656565"


                Image {
                    source: valueSource.oil_check ? './images/AGL_Icons_Oil_red.svg' : './images/AGL_Icons_Oil.svg'
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: height
                    height: parent.height * 0.75
                    fillMode: Image.PreserveAspectFit
                }
            }

            Rectangle {
                width: height
                height: parent.height
                radius: height / 5

                color: "#656565"


                Image {
                    source: valueSource.abs ? './images/AGL_Icons_ABS_red.svg' : './images/AGL_Icons_ABS.svg'
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: height
                    height: parent.height * 0.75
                    fillMode: Image.PreserveAspectFit
                }
            }

            Rectangle {
                width: height
                height: parent.height
                radius: height / 5

                color: "#656565"

                Image {
                    source: valueSource.battery ? './images/AGL_Icons_Battery_red.svg' : './images/AGL_Icons_Battery.svg'
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: height
                    height: parent.height * 0.75
                    fillMode: Image.PreserveAspectFit
                }
            }

            Rectangle {
                width: height
                height: parent.height
                radius: height / 5
                color: "#656565"



                Text {
                    id: prindle
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    horizontalAlignment: Text.AlignCenter

                    text: valueSource.prindle
                    color: "#c3c3c3"
                    font.pixelSize: parent.height * 0.85
                }
            }

            Rectangle {
                id: gearIndicatior
                width: height
                height: parent.height
                radius: height / 5
                color: "#656565"



                Text {
                    id: gear
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    horizontalAlignment: Text.AlignCenter

                    text: valueSource.gear
                    color: "#c3c3c3"
                    font.pixelSize: parent.height * 0.85
                }
            }

            Rectangle {
                width: height
                height: parent.height
                radius: height / 5
                color: "#656565"

                Image {
                    source: valueSource.seat_belt ? './images/AGL_Icons_Seatbelt_red.svg' : './images/AGL_Icons_Seatbelt.svg'
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: height
                    height: parent.height * 0.75
                    fillMode: Image.PreserveAspectFit
                }
            }

            Rectangle {
                width: height
                height: parent.height
                radius: height / 5

                color: "#656565"


                Image {
                    source: valueSource.doors_open ? './images/AGL_Icons_OpenDoor_red.svg' : './images/AGL_Icons_OpenDoor.svg'
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: height
                    height: parent.height * 0.75
                    fillMode: Image.PreserveAspectFit
                }
            }

            Rectangle {
                width: height
                height: parent.height
                radius: height / 5
                color: "#656565"



                Image {
                    source: valueSource.high_beam ? './images/AGL_Icons_Lights_red.svg' : './images/AGL_Icons_Lights.svg'
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: height
                    height: parent.height * 0.75
                    fillMode: Image.PreserveAspectFit
                }
            }

            Rectangle {
                width: height
                height: parent.height
                radius: height / 5

                color: "#656565"

                Image {
                    source: valueSource.hand_break ? './images/AGL_Icons_ParkingBrake_red.svg' : './images/AGL_Icons_ParkingBrake.svg'
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: height
                    height: parent.height * 0.75
                    fillMode: Image.PreserveAspectFit
                }
            }

            Rectangle {
                width: height
                height: parent.height
                radius: height / 5

                color: "#656565"

                TurnIndicator {
                    id: rightIndicator
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: height
                    height: parent.height * 0.75

                    direction: Qt.RightArrow
                    on: valueSource.right_blinker
                }
            }
        }
    }

    Item {
        x: 36
        y: 240
        width: 600
        height: width

        CircularGauge {
            id: accelerometer
            x: 148
            y: 30
//            y: (parent.height - height) / 2
            width: parent.width * 0.9
            height: width

            maximumValue: 250
            value: valueSource.kph

            style: DashboardGaugeStyle {}
        }
    }

    Item {
        x: 1284
        y: 240
        width: 600
        height: width

        CircularGauge {
            id: tachometer
            x: -84
            y: 30
            width: parent.width * 0.9
            height: width

            maximumValue: 9
            value: valueSource.rpm

            style: TachometerStyle {

            }
        }

        CircularGauge {
            id: fuelGauge
            x: -623
            y: -31
            value: valueSource.fuel
            maximumValue: 1
            width: parent.width * 0.3
            height: parent.height * 0.3

            style: IconGaugeStyle {
                id: fuelGaugeStyle

                icon: "./images/fuel-icon.png"
                minWarningColor: valueSource.startUp ? "#f42d2d" : "gray"

                tickmarkLabel: Text {
                    color: "transparent"}


            }
        }

        CircularGauge {
            id: oilGauge
            x: -415
            y: -31
            value: valueSource.oil_temp
            maximumValue: 1
            width: parent.width * 0.3
            height: parent.height * 0.3

            style: IconGaugeStyle {
                id: oilGaugeStyle

                icon: "./images/AGL_Icons_Oil.svg"
                maxWarningColor: valueSource.startUp ? "#f42d2d" : "gray"
                minWarningColor: valueSource.startUp ? "#2487e4" : "gray"


                tickmarkLabel: Text {
                    color: "transparent"
                    visible: styleData.value === 0 || styleData.value === 1
                    font.pixelSize: fuelGaugeStyle.toPixels(0.225)
                    text: styleData.value === 0 ? "E" : (styleData.value === 1 ? "F" : "")
                }
            }
        }

    CircularGauge {
            id: tempGauge
            x: -205
            y: -31
            value: valueSource.temperature
            maximumValue: 1
            width: parent.width * 0.3
            height: parent.height * 0.3

            style: IconGaugeStyle {
                id: tempGaugeStyle

                icon: "./images/temperature-icon.png"
                maxWarningColor: valueSource.startUp ? "#f42d2d" : "gray"
                minWarningColor: valueSource.startUp ? "#2487e4" : "gray"

                tickmarkLabel: Text {
                    color: "transparent"
                    visible: styleData.value === 0 || styleData.value === 1
                    font.pixelSize: tempGaugeStyle.toPixels(0.225)
                    text: styleData.value === 0 ? "C" : (styleData.value === 1 ? "H" : "")
                }
            }
        }
    }

    Image {
        x: 740
        y: 451
        width: 441
        height: 190

        source: valueSource.startUp ? "images/logod.png" : "images/a.png"
        //x: 772
    }

    Rectangle {
        id: rectangle
        x: 740
        y: 664
        width: 441
        height: 98
        color: "black"
        Text {
            id: matn
            color: "white"
            text: valueSource.txt
            width: 441
            height: 98
            font.pixelSize: 12

        }
    }
}

