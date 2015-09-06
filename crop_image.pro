#-------------------------------------------------
#
# Project created by QtCreator 2015-09-04T14:16:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = crop_image

TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp\
        CroppedImage.cpp

HEADERS  += widget.h\
            CroppedImage.hpp

FORMS    += widget.ui

CONFIG += link_pkgconfig
PKGCONFIG += opencv