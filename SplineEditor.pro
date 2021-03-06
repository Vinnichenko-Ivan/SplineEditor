QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GUI/addnewspline.cpp \
    GUI/knotsetting.cpp \
    GUI/mainwindow.cpp \
    GUI/setting.cpp \
    GUI/splinedisplay.cpp \
    GUI/splinesetting.cpp \
    Spline/Kochanek–Bartels/knotkonchakbartles.cpp \
    Spline/Kochanek–Bartels/splinekonchakbartles.cpp \
    Spline/knot.cpp \
    Spline/spline.cpp \
    Spline/splinehandler.cpp \
    main.cpp

HEADERS += \
    GUI/addnewspline.h \
    GUI/knotsetting.h \
    GUI/mainwindow.h \
    GUI/setting.h \
    GUI/splinedisplay.h \
    GUI/splinesetting.h \
    Spline/Kochanek–Bartels/knotkonchakbartles.h \
    Spline/Kochanek–Bartels/splinekonchakbartles.h \
    Spline/knot.h \
    Spline/spline.h \
    Spline/splineVisualing.h \
    Spline/splinehandler.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
