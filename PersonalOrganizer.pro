QT       += core gui
QT  +=sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    budget.cpp \
    database.cpp \
    income.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    report.cpp \
    schedule.cpp \
    signup.cpp

HEADERS += \
    budget.h \
    database.h \
    income.h \
    mainwindow.h \
    menu.h \
    report.h \
    schedule.h \
    signup.h

FORMS += \
    budget.ui \
    income.ui \
    mainwindow.ui \
    menu.ui \
    report.ui \
    schedule.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

DISTFILES += \
    database.sql
