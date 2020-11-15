/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Copyright (C) 2018 Konsulko Group
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.2

Item {
    id: valueSource
//    property bool mphDisplay: true
//    property real speedScaling: mphDisplay == true ? 0.621 : 1.0
    property real kph: 0
    property real rpm: rpmHezar/1000
    property real rpmHezar: 0
    property real fuel: 0

    property real temperature: 0
    property real oil_temp: 0
    Behavior on kph { NumberAnimation { duration: 500 } }
    Behavior on rpm { NumberAnimation { duration: 200 } }
    Behavior on temperature { NumberAnimation { duration: 500 } }
    Behavior on fuel { NumberAnimation { duration: 500 } }
    Behavior on oil_temp { NumberAnimation { duration: 500 } }
    property string gear: "0"
    property int pindle_int: 0
    property string prindle:  {
        var g;//??
        if (pindle_int == 0) {
            return "P";
        } else if (pindle_int == 1) {
            return "N";
        } else if (pindle_int == 2) {
            return "R";
        } else if (pindle_int == 3) {
            return "D";
        } else if (pindle_int == 4) {
            return "M";
        }
    }
    property bool start: false
    property bool left_blinker: false
    property bool engine_check: false
    property bool oil_check: false
    property bool abs: false
    property bool battery: false
    property bool seat_belt: false
    property bool doors_open: false
    property bool high_beam: false
    property bool hand_break: false
    property bool right_blinker: false
    property bool startUp: false
    property string txt: "Nothing"


    function randomDirection() {
        return Math.random() > 0.5 ? Qt.LeftArrow : Qt.RightArrow;
    }
}
