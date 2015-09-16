#-------------------------------------------------
#
# Project created by QtCreator 2015-09-07T08:33:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TechParser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        token.cpp \
        parser.cpp

HEADERS  += expr.hpp mainwindow.h parser.hpp token.hpp

FORMS    += mainwindow.ui
