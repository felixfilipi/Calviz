#
#-------------------------------------------------
# Project created by QtCreator 2022-09-07T21:55:59
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calviz
TEMPLATE = app


SOURCES += \
        src/main.cpp \
        src/calviz.cpp\
        src/Processing.cpp\
        src/Differrential.cpp\
        src/Polynomial.cpp\
        src/RSD.cpp\
        src/Utility.cpp\
        src/tmp.cpp\
        libs/tinyexpr.c\

HEADERS  += include/calviz.h\
        include/Polynomial.hpp\
        include/RSD.hpp\
        include/Differrential.hpp\
        include/Processing.hpp\
        include/Utility.hpp\
        libs/tinyexpr.h\

FORMS    += calviz.ui
