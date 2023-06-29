######################################################################
# Automatically generated by qmake (3.1) Thu Jun 29 06:52:11 2023
######################################################################

TEMPLATE = app
TARGET = food_organizer_frontend
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += src/classes/InitialWidget.h \
           src/classes/LoginWidget.h \
           src/classes/MainWindow.h \
           src/classes/SigninWidget.h \
           src/forms/ui_InitialWidget.h \
           src/forms/ui_LoginWidget.h \
           src/forms/ui_MainWindow.h \
           src/forms/ui_SigninWidget.h
FORMS += src/forms/InitialWidget.ui \
         src/forms/LoginWidget.ui \
         src/forms/MainWindow.ui \
         src/forms/SigninWidget.ui
SOURCES += src/main.cpp \
           src/classes/InitialWidget.cpp \
           src/classes/LoginWidget.cpp \
           src/classes/MainWindow.cpp \
           src/classes/SigninWidget.cpp \
           build/CMakeFiles/3.22.1/CompilerIdCXX/CMakeCXXCompilerId.cpp
