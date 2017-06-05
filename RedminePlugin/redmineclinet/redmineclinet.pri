
QT += xml network
INCLUDEPATH += $$PWD

include($$PWD/issue/issue.pri)
include($$PWD/project/project.pri)

SOURCES += \
    $$PWD/imanager.cpp \
    $$PWD/check.cpp

HEADERS += \
    $$PWD/imanager.h \
    $$PWD/check.h
