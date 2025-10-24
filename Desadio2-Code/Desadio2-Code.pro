TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp\
        album.cpp\
        cancion.cpp\
        artista.cpp\
        metrica.cpp\
        listarp.cpp

HEADERS += \
        album.h\
        artista.h\
        cancion.h\
        readwrite.h\
        metrica.h\
        listarp.h

