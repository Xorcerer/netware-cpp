TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    campmiddleware.cpp \
    thread.cpp \
    protos/player.pb.cc \
    protos/common.pb.cc

HEADERS += \
    campmiddleware.h \
    thread.h \
    socket_utils.h \
    config.h \
    handler.h \
    serializer.h \
    protos/player.pb.h \
    protos/common.pb.h \
    message_ids.h \
    dispatcher.h

INCLUDEPATH += /usr/local/include/
LIBPATH += /usr/local/lib/
LIBS += -lprotobuf
