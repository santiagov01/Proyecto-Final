QT       += core gui
QT += multimedia
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arbol.cpp \
    auxiliares.cpp \
    enemigos.cpp \
    iniciar.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    mision.cpp \
    obstaculos.cpp \
    pause.cpp \
    personaje.cpp \
    protagonista.cpp \
    proyectil.cpp \
    selectcont.cpp \
    terreno.cpp

HEADERS += \
    arbol.h \
    auxiliares.h \
    enemigos.h \
    iniciar.h \
    mainwindow.h \
    menu.h \
    mision.h \
    obstaculos.h \
    pause.h \
    personaje.h \
    protagonista.h \
    proyectil.h \
    selectcont.h \
    terreno.h

FORMS += \
    mainwindow.ui \
    menu.ui \
    pause.ui \
    selectcont.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recursos.qrc

DISTFILES +=
