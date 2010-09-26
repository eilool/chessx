# Main application
include(../common.pro)
CONFIG += uic
QT += xml
FORMS += playerdialog.ui \
	 preferences.ui \
	 boardsetup.ui \
	 quicksearch.ui \
	 savedialog.ui \
	 analysiswidget.ui \
	 copydialog.ui \
	 commentdialog.ui
HEADERS += mainwindow.h \
	 playerdialog.h \
	 preferences.h \
	 helpwindow.h \
	 boardview.h \
	 boardtheme.h \
	 boardsetup.h \
	 colorlist.h \
	 savedialog.h \
	 gamelist.h \
	 chessbrowser.h \
	 ecothread.h \
	 quicksearch.h \
	 analysiswidget.h \
	 tableview.h \
	 copydialog.h \
	 messagedialog.h \
	 commentdialog.h \
plaintextedit.h
SOURCES += mainwindow.cpp \
	 mainwindowactions.cpp \
	 mainwindowabout.cpp \
	 playerdialog.cpp \
	 colorlist.cpp \
	 preferences.cpp \
	 boardview.cpp \
	 boardtheme.cpp \
	 boardsetup.cpp \
	 helpwindow.cpp \
	 savedialog.cpp \
	 gamelist.cpp \
	 quicksearch.cpp \
	 chessbrowser.cpp \
	 analysiswidget.cpp \
	 main.cpp \
	 tableview.cpp \
	 copydialog.cpp \
	 messagedialog.cpp \
	 commentdialog.cpp \
	plaintextedit.cpp
TEMPLATE = app
INCLUDEPATH += ../database
INCLUDEPATH += ../guess
DEPENDPATH = ../database
RESOURCES += helpwindow.qrc
win32 {
	 TARGET = ../../../bin/chessx
	 release {
		  LIBS += ../database/release/libdatabase.a
		  PRE_TARGETDEPS += ../database/release/libdatabase.a
		  LIBS += ../guess/release/libguess.a
		  PRE_TARGETDEPS += ../guess/release/libguess.a
	 }
	 else {
		  LIBS += ../database/debug/libdatabase.a
		  PRE_TARGETDEPS += ../database/debug/libdatabase.a
		  LIBS += ../guess/debug/libguess.a
		  PRE_TARGETDEPS += ../guess/debug/libguess.a
	 }
}
else {
	 TARGET = ../../bin/chessx
	 LIBS += ../database/libdatabase.a
	 PRE_TARGETDEPS += ../database/libdatabase.a
	 LIBS += ../guess/libguess.a
	 PRE_TARGETDEPS += ../guess/libguess.a
}
macx {
 INSTALLATION_DATA.files = ../../data
 INSTALLATION_DATA.path = Contents/MacOS
 QMAKE_BUNDLE_DATA += INSTALLATION_DATA
 ICON = ../../data/images/chessx.icns
}
TRANSLATIONS = chessx_pl.ts \
	 chessx_de.ts
