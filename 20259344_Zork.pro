QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
        Command.cpp \
        CommandWords.cpp \
        Parser.cpp \
        Room.cpp \
        ZorkUL.cpp \
        dialogue.cpp \
        image.cpp \
        item.cpp \
        main.cpp \
        mainwindow.cpp \
        npc.cpp \
        wordle.cpp

DISTFILES += \
    20259344_Zork.pro.user \
    img/lr_n.png \
    wordle_words

HEADERS += \
    Command.h \
    CommandWords.h \
    Parser.h \
    Room.h \
    ZorkUL.h \
    dialogue.h \
    exception.h \
    image.h \
    item.h \
    mainwindow.h \
    npc.h \
    wordle.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc
