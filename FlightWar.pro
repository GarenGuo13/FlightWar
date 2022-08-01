QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    gamesetingtweight.cpp \
    health.cpp \
    main.cpp \
    player.cpp \
    score.cpp \
    scoreboard.cpp

HEADERS += \
    bullet.h \
    enemy.h \
    game.h \
    gamesetingtweight.h \
    health.h \
    main.h \
    player.h \
    score.h \
    scoreboard.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc

FORMS += \
    gamesetingtweight.ui \
    scoreboard.ui
