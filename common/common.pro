QT -= gui widgets

TARGET = QTacitGame
TEMPLATE = lib

include (../QTacitGame.pri)

INCLUDEPATH += ..

OBJECTS_DIR = $$QTACITGAME_OBJ_COMMON
MOC_DIR= $$QTACITGAME_MOC_COMMON

SOURCES += \ 
    gamemap.cpp

HEADERS  += \ 
    gamemap.hpp
