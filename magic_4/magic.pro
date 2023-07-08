QT       += core gui
QT       += multimedia
QT       += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    main_menu.cpp \
    main_windows.cpp \
    my_label.cpp \
    tower_creature.cpp \
    widget.cpp \

HEADERS += \
    game.h \
    main_menu.h \
    main_windows.h \
    maps.h \
    my_Dialog.h \
    my_label.h \
    shopdialog.h \
    tower_creature.h \
    widget.h \

FORMS += \
    widget.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc \

DISTFILES += \
    ../pic/0.png \
    ../pic/1.png \
    ../pic/15.png \
    ../pic/2.png \
    ../pic/20.png \
    ../pic/21.png \
    ../pic/22.png \
    ../pic/23.png \
    ../pic/24.png \
    ../pic/25.png \
    ../pic/3.png \
    ../pic/30.png \
    ../pic/31.png \
    ../pic/32.png \
    ../pic/33.png \
    ../pic/34.png \
    ../pic/35.png \
    ../pic/36.png \
    ../pic/37.png \
    ../pic/38.png \
    ../pic/4.png \
    ../pic/41.png \
    ../pic/5.png \
    ../pic/6.png \
    ../pic/7.png \
    ../pic/8.png \
    ../pic/all.png
