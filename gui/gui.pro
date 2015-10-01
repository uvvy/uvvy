######################################################################
# Automatically generated by qmake (3.0) ??? ??? 30 01:21:04 2015
######################################################################

TEMPLATE = app
TARGET = gui
INCLUDEPATH += .

CONFIG(debug, debug|release) {
	DESTDIR = debug
}
else {
	DESTDIR = release
}

PRECOMPILED_HEADER = stdafx.h

CONFIG += precompile_header

DEFINES += USING_PCH

QMAKE_CXXFLAGS += -std=c++11

QT += widgets quick

# Input
HEADERS += exceptions.h AccountManager.h MainWindow.h QmlWindow.h Root.h UserInfo.h UserManager.h WindowManager.h
SOURCES += main.cpp AccountManager.cpp MainWindow.cpp QmlWindow.cpp Root.cpp UserInfo.cpp UserManager.cpp WindowManager.cpp

HEADERS += Contact.h Chat/ChatWidget.h Chat/ChatTextEdit.h Chat/ChatItem.h Chat/ChatItemModel.h Chat/ChatItemDelegate.h
SOURCES += Contact.cpp Chat/ChatWidget.cpp Chat/ChatTextEdit.cpp Chat/ChatItem.cpp Chat/ChatItemModel.cpp Chat/ChatItemDelegate.cpp
