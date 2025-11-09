QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CanvasWidget.cpp \
    CommandConsole.cpp \
    CommandProcessor.cpp \
    Connection.cpp \
    Line.cpp \
    LogWidget.cpp \
    Rectangle.cpp \
    ShapeFactory.cpp \
    Square.cpp \
    Triangle.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    CanvasWidget.h \
    CommandConsole.h \
    CommandProcessor.h \
    Connection.h \
    Line.h \
    LogWidget.h \
    Rectangle.h \
    Shape.h \
    ShapeFactory.h \
    Square.h \
    Triangle.h \
    mainwindow.h


TRANSLATIONS += \
    ShapesDrawer_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
