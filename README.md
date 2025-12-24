# Cpp Qml Module

Simple module on C++ for Qml!

## Cloning
```shell
git clone https://github.com/eandset/CppQmlModule.git
```

## Build on linux
```shell
cd CppQmlModule
mkdir build
cd build
cmake ..
make
sudo make install
```
The module will be installed to `/usr/lib/qt6/qml/SimpleCppModule`

## Using in qml
```qml
import SimpleCppModule 1.0
```

## Example
`shell.qml`
```qml
import Quickshell
import QtQuick 2.15

import SimpleCppModule 1.0

PanelWindow {
    anchors { left: true; right: true; top: true }
    implicitHeight: 37
    color: "transparent"

    Item {
        id: barContainer
        anchors.fill: parent
        height: parent.height

        CppText {
            id: cpptext
            visible: false
        }
    }
}
```

## TODO
- [ ] Cava
- [ ] Music controll (preview, play/pause, next)
- [x] Simple Text (clock)
