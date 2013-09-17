TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    campmiddleware.cpp \
    thread.cpp

HEADERS += \
    campmiddleware.h \
    thread.h \
    socket_utils.h \
    config.h

