#-------------------------------------------------
#
# Project created by QtCreator 2015-09-04T14:16:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = crop_image

TEMPLATE = app

SOURCES += src/main.cpp\
        src/widget.cpp\
        src/CroppedImage.cpp

HEADERS  += src/widget.h\
            src/CroppedImage.hpp

FORMS    += src/widget.ui

CONFIG += link_pkgconfig
PKGCONFIG += opencv
