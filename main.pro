TEMPLATE = app
TARGET = 2048

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
!exists( src/main.cpp ) {
    error( "No main.cpp file found" )
}

HEADERS += src/gui/grid.h
HEADERS += src/gui/qtile.h
HEADERS += src/engine/tile.h
HEADERS += src/engine/game.h
SOURCES += src/main.cpp
SOURCES += src/gui/grid.cpp
SOURCES += src/gui/qtile.cpp
SOURCES += src/engine/tile.cpp
SOURCES += src/engine/game.cpp