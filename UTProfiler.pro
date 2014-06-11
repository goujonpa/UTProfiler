#-------------------------------------------------
#
# Project created by QtCreator 2014-05-13T17:41:48
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += core
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UTProfiler
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    semestre.cpp \
    note.cpp \
    categorie.cpp \
    uv.cpp \
    profil.cpp \
    inscription.cpp \
    cursus.cpp \
    branche.cpp \
    filiere.cpp \
    etranger.cpp \
    user.cpp \
    simulation.cpp \
    desiruv.cpp \
    bonusuv.cpp \
    dbmanager.cpp \
    xmlmanager.cpp

HEADERS  += mainwindow.h \
    semestre.h \
    note.h \
    categorie.h \
    uv.h \
    profil.h \
    inscription.h \
    cursus.h \
    branche.h \
    filiere.h \
    etranger.h \
    user.h \
    simulation.h \
    desiruv.h \
    bonusuv.h \
    dbmanager.h \
    xmlmanager.h

FORMS    += mainwindow.ui
