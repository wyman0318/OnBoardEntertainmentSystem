#############################################################################
# Makefile for building: libBLEconnect_armeabi-v7a.so
# Generated by qmake (3.1) (Qt 5.14.1)
# Project:  BLEconnect.pro
# Template: app
#############################################################################

MAKEFILE      = Makefile

EQ            = =

####### Compiler, tools and options

CC            = C:\software\qtforAndroid\android-ndk-r20b/toolchains/llvm/prebuilt/windows-x86_64/bin/clang
CXX           = C:\software\qtforAndroid\android-ndk-r20b/toolchains/llvm/prebuilt/windows-x86_64/bin/clang++
DEFINES       = -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_BLUETOOTH_LIB -DQT_ANDROIDEXTRAS_LIB -DQT_CORE_LIB
CFLAGS        = -target armv7a-linux-androideabi21 -fno-limit-debug-info -fPIC -fstack-protector-strong -DANDROID -g -marm -O0 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -target armv7a-linux-androideabi21 -fno-limit-debug-info -fPIC -fstack-protector-strong -DANDROID -g -marm -O0 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -I..\..\qt\5.14.1\android\include -I..\..\qt\5.14.1\android\include\QtWidgets -I..\..\qt\5.14.1\android\include\QtGui -I..\..\qt\5.14.1\android\include\QtBluetooth -I..\..\qt\5.14.1\android\include\QtAndroidExtras -I..\..\qt\5.14.1\android\include\QtCore -Iarmeabi-v7a -I. -I..\..\qt\5.14.1\android\mkspecs\android-clang
QMAKE         = D:\qt\5.14.1\android\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
QINSTALL      = D:\qt\5.14.1\android\bin\qmake.exe -install qinstall
QINSTALL_PROGRAM = D:\qt\5.14.1\android\bin\qmake.exe -install qinstall -exe
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = cmd /c move
TAR           = 
COMPRESS      = 
DISTNAME      = libBLEconnect_armeabi-v7a.so1.0.0
DISTDIR = D:\qtprogram\BLEconnect\armeabi-v7a\libBLEconnect_armeabi-v7a.so1.0.0
LINK          = C:\software\qtforAndroid\android-ndk-r20b/toolchains/llvm/prebuilt/windows-x86_64/bin/clang++ -target armv7a-linux-androideabi21 -fno-limit-debug-info
LFLAGS        = -Wl,-soname,libBLEconnect_armeabi-v7a.so -Wl,-rpath-link=D:/qt/5.14.1/android/lib -Wl,--build-id=sha1 -Wl,--no-undefined -Wl,-z,noexecstack -shared
LIBS          = $(SUBLIBS) D:/qt/5.14.1/android/lib/libQt5Widgets_armeabi-v7a.so D:/qt/5.14.1/android/lib/libQt5Gui_armeabi-v7a.so D:/qt/5.14.1/android/lib/libQt5Bluetooth_armeabi-v7a.so D:/qt/5.14.1/android/lib/libQt5AndroidExtras_armeabi-v7a.so D:/qt/5.14.1/android/lib/libQt5Core_armeabi-v7a.so -lGLESv2   -llog -lz -lm -ldl -lc
AR            = C:\software\qtforAndroid\android-ndk-r20b/toolchains/llvm/prebuilt/windows-x86_64/bin/llvm-ar cqs
RANLIB        = C:\software\qtforAndroid\android-ndk-r20b/toolchains/llvm/prebuilt/windows-x86_64/bin/arm-linux-androideabi-ranlib
SED           = $(QMAKE) -install sed
STRIP         = 

####### Output directory

OBJECTS_DIR   = armeabi-v7a\\

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp armeabi-v7a\moc_mainwindow.cpp
OBJECTS       = armeabi-v7a\main.obj \
		armeabi-v7a\mainwindow.obj \
		armeabi-v7a\moc_mainwindow.obj
DIST          =  mainwindow.h main.cpp \
		mainwindow.cpp
QMAKE_TARGET  = libBLEconnect_armeabi-v7a.so
DESTDIR       = 
TARGET        = libBLEconnect_armeabi-v7a.so


first: all
####### Build rules

libBLEconnect_armeabi-v7a.so: ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

qmake: FORCE
	@$(QMAKE) -o Makefile BLEconnect.pro -spec android-clang "CONFIG+=debug" "CONFIG+=qml_debug" "ANDROID_ABIS=armeabi-v7a"

qmake_all: FORCE


all: Makefile libBLEconnect_armeabi-v7a.so

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`\$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@if not exist $(DISTDIR) mkdir $(DISTDIR) & if not exist $(DISTDIR) exit 1
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)\
	$(COPY_FILE) --parents ..\..\qt\5.14.1\android\mkspecs\features\data\dummy.cpp $(DISTDIR)\
	$(COPY_FILE) --parents mainwindow.h $(DISTDIR)\
	$(COPY_FILE) --parents main.cpp mainwindow.cpp $(DISTDIR)\
	$(COPY_FILE) --parents mainwindow.ui $(DISTDIR)\


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

aab: apk_install_target
	D:\qt\5.14.1\android\bin\androiddeployqt.exe --input D:/qtprogram/BLEconnect/android-BLEconnect-deployment-settings.json --output D:/qtprogram/BLEconnect/android-build --aab --apk D:\qtprogram\BLEconnect\android-build\BLEconnect.apk

apk: apk_install_target
	D:\qt\5.14.1\android\bin\androiddeployqt.exe --input D:/qtprogram/BLEconnect/android-BLEconnect-deployment-settings.json --output D:/qtprogram/BLEconnect/android-build --apk D:\qtprogram\BLEconnect\android-build\BLEconnect.apk

apk_install_target: first
	$(MAKE) -f $(MAKEFILE) INSTALL_ROOT=D:/qtprogram/BLEconnect/android-build install

mocclean: compiler_moc_header_clean compiler_moc_objc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_objc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_predefs_make_all: armeabi-v7a\moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) armeabi-v7a\moc_predefs.h
armeabi-v7a\moc_predefs.h: ..\..\qt\5.14.1\android\mkspecs\features\data\dummy.cpp
	C:\software\qtforAndroid\android-ndk-r20b/toolchains/llvm/prebuilt/windows-x86_64/bin/clang++ -target armv7a-linux-androideabi21 -fno-limit-debug-info -fPIC -fstack-protector-strong -DANDROID -g -marm -O0 -std=gnu++11 -Wall -W -dM -E -o armeabi-v7a\moc_predefs.h ..\..\qt\5.14.1\android\mkspecs\features\data\dummy.cpp

compiler_moc_header_make_all: armeabi-v7a\moc_mainwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) armeabi-v7a\moc_mainwindow.cpp
armeabi-v7a\moc_mainwindow.cpp: mainwindow.h \
		..\..\qt\5.14.1\android\include\QtWidgets\QMainWindow \
		..\..\qt\5.14.1\android\include\QtWidgets\qmainwindow.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qtwidgetsglobal.h \
		..\..\qt\5.14.1\android\include\QtGui\qtguiglobal.h \
		..\..\qt\5.14.1\android\include\QtCore\qglobal.h \
		..\..\qt\5.14.1\android\include\QtCore\qconfig-bootstrapped.h \
		..\..\qt\5.14.1\android\include\QtCore\qconfig.h \
		..\..\qt\5.14.1\android\include\QtCore\qtcore-config.h \
		..\..\qt\5.14.1\android\include\QtCore\qsystemdetection.h \
		..\..\qt\5.14.1\android\include\QtCore\qprocessordetection.h \
		..\..\qt\5.14.1\android\include\QtCore\qcompilerdetection.h \
		..\..\qt\5.14.1\android\include\QtCore\qtypeinfo.h \
		..\..\qt\5.14.1\android\include\QtCore\qsysinfo.h \
		..\..\qt\5.14.1\android\include\QtCore\qlogging.h \
		..\..\qt\5.14.1\android\include\QtCore\qflags.h \
		..\..\qt\5.14.1\android\include\QtCore\qatomic.h \
		..\..\qt\5.14.1\android\include\QtCore\qbasicatomic.h \
		..\..\qt\5.14.1\android\include\QtCore\qatomic_bootstrap.h \
		..\..\qt\5.14.1\android\include\QtCore\qgenericatomic.h \
		..\..\qt\5.14.1\android\include\QtCore\qatomic_cxx11.h \
		..\..\qt\5.14.1\android\include\QtCore\qatomic_msvc.h \
		..\..\qt\5.14.1\android\include\QtCore\qglobalstatic.h \
		..\..\qt\5.14.1\android\include\QtCore\qmutex.h \
		..\..\qt\5.14.1\android\include\QtCore\qnumeric.h \
		..\..\qt\5.14.1\android\include\QtCore\qversiontagging.h \
		..\..\qt\5.14.1\android\include\QtGui\qtgui-config.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qtwidgets-config.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qwidget.h \
		..\..\qt\5.14.1\android\include\QtGui\qwindowdefs.h \
		..\..\qt\5.14.1\android\include\QtCore\qobjectdefs.h \
		..\..\qt\5.14.1\android\include\QtCore\qnamespace.h \
		..\..\qt\5.14.1\android\include\QtCore\qobjectdefs_impl.h \
		..\..\qt\5.14.1\android\include\QtGui\qwindowdefs_win.h \
		..\..\qt\5.14.1\android\include\QtCore\qobject.h \
		..\..\qt\5.14.1\android\include\QtCore\qstring.h \
		..\..\qt\5.14.1\android\include\QtCore\qchar.h \
		..\..\qt\5.14.1\android\include\QtCore\qbytearray.h \
		..\..\qt\5.14.1\android\include\QtCore\qrefcount.h \
		..\..\qt\5.14.1\android\include\QtCore\qarraydata.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringliteral.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringalgorithms.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringview.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringbuilder.h \
		..\..\qt\5.14.1\android\include\QtCore\qlist.h \
		..\..\qt\5.14.1\android\include\QtCore\qalgorithms.h \
		..\..\qt\5.14.1\android\include\QtCore\qiterator.h \
		..\..\qt\5.14.1\android\include\QtCore\qhashfunctions.h \
		..\..\qt\5.14.1\android\include\QtCore\qpair.h \
		..\..\qt\5.14.1\android\include\QtCore\qvector.h \
		..\..\qt\5.14.1\android\include\QtCore\qcontainertools_impl.h \
		..\..\qt\5.14.1\android\include\QtCore\qpoint.h \
		..\..\qt\5.14.1\android\include\QtCore\qbytearraylist.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringlist.h \
		..\..\qt\5.14.1\android\include\QtCore\qregexp.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringmatcher.h \
		..\..\qt\5.14.1\android\include\QtCore\qcoreevent.h \
		..\..\qt\5.14.1\android\include\QtCore\qscopedpointer.h \
		..\..\qt\5.14.1\android\include\QtCore\qmetatype.h \
		..\..\qt\5.14.1\android\include\QtCore\qvarlengtharray.h \
		..\..\qt\5.14.1\android\include\QtCore\qcontainerfwd.h \
		..\..\qt\5.14.1\android\include\QtCore\qobject_impl.h \
		..\..\qt\5.14.1\android\include\QtCore\qmargins.h \
		..\..\qt\5.14.1\android\include\QtGui\qpaintdevice.h \
		..\..\qt\5.14.1\android\include\QtCore\qrect.h \
		..\..\qt\5.14.1\android\include\QtCore\qsize.h \
		..\..\qt\5.14.1\android\include\QtGui\qpalette.h \
		..\..\qt\5.14.1\android\include\QtGui\qcolor.h \
		..\..\qt\5.14.1\android\include\QtGui\qrgb.h \
		..\..\qt\5.14.1\android\include\QtGui\qrgba64.h \
		..\..\qt\5.14.1\android\include\QtGui\qbrush.h \
		..\..\qt\5.14.1\android\include\QtGui\qmatrix.h \
		..\..\qt\5.14.1\android\include\QtGui\qpolygon.h \
		..\..\qt\5.14.1\android\include\QtGui\qregion.h \
		..\..\qt\5.14.1\android\include\QtCore\qdatastream.h \
		..\..\qt\5.14.1\android\include\QtCore\qiodevice.h \
		..\..\qt\5.14.1\android\include\QtCore\qline.h \
		..\..\qt\5.14.1\android\include\QtGui\qtransform.h \
		..\..\qt\5.14.1\android\include\QtGui\qpainterpath.h \
		..\..\qt\5.14.1\android\include\QtGui\qimage.h \
		..\..\qt\5.14.1\android\include\QtGui\qpixelformat.h \
		..\..\qt\5.14.1\android\include\QtGui\qpixmap.h \
		..\..\qt\5.14.1\android\include\QtCore\qsharedpointer.h \
		..\..\qt\5.14.1\android\include\QtCore\qshareddata.h \
		..\..\qt\5.14.1\android\include\QtCore\qhash.h \
		..\..\qt\5.14.1\android\include\QtCore\qsharedpointer_impl.h \
		..\..\qt\5.14.1\android\include\QtGui\qfont.h \
		..\..\qt\5.14.1\android\include\QtGui\qfontmetrics.h \
		..\..\qt\5.14.1\android\include\QtGui\qfontinfo.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qsizepolicy.h \
		..\..\qt\5.14.1\android\include\QtGui\qcursor.h \
		..\..\qt\5.14.1\android\include\QtGui\qkeysequence.h \
		..\..\qt\5.14.1\android\include\QtGui\qevent.h \
		..\..\qt\5.14.1\android\include\QtCore\qvariant.h \
		..\..\qt\5.14.1\android\include\QtCore\qmap.h \
		..\..\qt\5.14.1\android\include\QtCore\qdebug.h \
		..\..\qt\5.14.1\android\include\QtCore\qtextstream.h \
		..\..\qt\5.14.1\android\include\QtCore\qlocale.h \
		..\..\qt\5.14.1\android\include\QtCore\qset.h \
		..\..\qt\5.14.1\android\include\QtCore\qcontiguouscache.h \
		..\..\qt\5.14.1\android\include\QtCore\qurl.h \
		..\..\qt\5.14.1\android\include\QtCore\qurlquery.h \
		..\..\qt\5.14.1\android\include\QtCore\qfile.h \
		..\..\qt\5.14.1\android\include\QtCore\qfiledevice.h \
		..\..\qt\5.14.1\android\include\QtGui\qvector2d.h \
		..\..\qt\5.14.1\android\include\QtGui\qtouchdevice.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qtabwidget.h \
		..\..\qt\5.14.1\android\include\QtGui\qicon.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QBluetoothDeviceDiscoveryAgent \
		..\..\qt\5.14.1\android\include\QtBluetooth\qbluetoothdevicediscoveryagent.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\qtbluetoothglobal.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\qtbluetooth-config.h \
		..\..\qt\5.14.1\android\include\QtCore\QObject \
		..\..\qt\5.14.1\android\include\QtBluetooth\QBluetoothDeviceInfo \
		..\..\qt\5.14.1\android\include\QtBluetooth\qbluetoothdeviceinfo.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QBluetoothAddress \
		..\..\qt\5.14.1\android\include\QtBluetooth\qbluetoothaddress.h \
		..\..\qt\5.14.1\android\include\QtCore\QByteArray \
		..\..\qt\5.14.1\android\include\QtCore\QString \
		..\..\qt\5.14.1\android\include\QtCore\QMetaType \
		..\..\qt\5.14.1\android\include\QtCore\QList \
		..\..\qt\5.14.1\android\include\QtWidgets\QListWidgetItem \
		..\..\qt\5.14.1\android\include\QtWidgets\qlistwidget.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qlistview.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qabstractitemview.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qabstractscrollarea.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qframe.h \
		..\..\qt\5.14.1\android\include\QtCore\qabstractitemmodel.h \
		..\..\qt\5.14.1\android\include\QtCore\qitemselectionmodel.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qabstractitemdelegate.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qstyleoption.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qabstractspinbox.h \
		..\..\qt\5.14.1\android\include\QtGui\qvalidator.h \
		..\..\qt\5.14.1\android\include\QtCore\qregularexpression.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qslider.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qabstractslider.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qstyle.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qtabbar.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qrubberband.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QLowEnergyController \
		..\..\qt\5.14.1\android\include\QtBluetooth\qlowenergycontroller.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QBluetoothUuid \
		..\..\qt\5.14.1\android\include\QtBluetooth\qbluetoothuuid.h \
		..\..\qt\5.14.1\android\include\QtCore\QtGlobal \
		..\..\qt\5.14.1\android\include\QtCore\QUuid \
		..\..\qt\5.14.1\android\include\QtCore\quuid.h \
		..\..\qt\5.14.1\android\include\QtCore\QDebug \
		..\..\qt\5.14.1\android\include\QtBluetooth\QLowEnergyAdvertisingData \
		..\..\qt\5.14.1\android\include\QtBluetooth\qlowenergyadvertisingdata.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QLowEnergyService \
		..\..\qt\5.14.1\android\include\QtBluetooth\qlowenergyservice.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QLowEnergyCharacteristic \
		..\..\qt\5.14.1\android\include\QtBluetooth\qlowenergycharacteristic.h \
		..\..\qt\5.14.1\android\include\QtCore\QSharedPointer \
		..\..\qt\5.14.1\android\include\QtBluetooth\qbluetooth.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QLowEnergyDescriptor \
		..\..\qt\5.14.1\android\include\QtBluetooth\qlowenergydescriptor.h \
		..\..\qt\5.14.1\android\include\QtCore\QVariantMap \
		..\..\qt\5.14.1\android\include\QtCore\QFileInfo \
		..\..\qt\5.14.1\android\include\QtCore\qfileinfo.h \
		..\..\qt\5.14.1\android\include\QtCore\QFile \
		..\..\qt\5.14.1\android\include\QtWidgets\QFileDialog \
		..\..\qt\5.14.1\android\include\QtWidgets\qfiledialog.h \
		..\..\qt\5.14.1\android\include\QtCore\qdir.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qdialog.h \
		..\..\qt\5.14.1\android\include\QtCore\QDir \
		..\..\qt\5.14.1\android\include\QtCore\QStringList \
		..\..\qt\5.14.1\android\include\QtWidgets\QMessageBox \
		..\..\qt\5.14.1\android\include\QtWidgets\qmessagebox.h \
		..\..\qt\5.14.1\android\include\QtAndroidExtras\QtAndroid \
		..\..\qt\5.14.1\android\include\QtAndroidExtras\qandroidfunctions.h \
		..\..\qt\5.14.1\android\include\QtAndroidExtras\qandroidextrasglobal.h \
		..\..\qt\5.14.1\android\include\QtAndroidExtras\qandroidjniobject.h \
		..\..\qt\5.14.1\android\include\QtAndroidExtras\qandroidjnienvironment.h \
		armeabi-v7a\moc_predefs.h \
		..\..\qt\5.14.1\android\bin\moc.exe
	D:\qt\5.14.1\android\bin\moc.exe $(DEFINES) --include D:/qtprogram/BLEconnect/armeabi-v7a/moc_predefs.h -ID:/qt/5.14.1/android/mkspecs/android-clang -ID:/qtprogram/BLEconnect -ID:/qt/5.14.1/android/include -ID:/qt/5.14.1/android/include/QtWidgets -ID:/qt/5.14.1/android/include/QtGui -ID:/qt/5.14.1/android/include/QtBluetooth -ID:/qt/5.14.1/android/include/QtAndroidExtras -ID:/qt/5.14.1/android/include/QtCore -IC:/software/qtforAndroid/android-ndk-r20b/toolchains/llvm/prebuilt/windows-x86_64/include/c++ -IC:/software/qtforAndroid/android-ndk-r20b/toolchains/llvm/prebuilt/windows-x86_64/lib64/clang/8.0.7/include -IC:/software/qtforAndroid/android-ndk-r20b/toolchains/llvm/prebuilt/windows-x86_64/include mainwindow.h -o armeabi-v7a\moc_mainwindow.cpp

compiler_moc_objc_header_make_all:
compiler_moc_objc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui \
		..\..\qt\5.14.1\android\bin\uic.exe
	D:\qt\5.14.1\android\bin\uic.exe mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_predefs_clean compiler_moc_header_clean compiler_uic_clean 

####### Compile

armeabi-v7a\main.obj: main.cpp mainwindow.h \
		..\..\qt\5.14.1\android\include\QtWidgets\QMainWindow \
		..\..\qt\5.14.1\android\include\QtWidgets\qmainwindow.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qtwidgetsglobal.h \
		..\..\qt\5.14.1\android\include\QtGui\qtguiglobal.h \
		..\..\qt\5.14.1\android\include\QtCore\qglobal.h \
		..\..\qt\5.14.1\android\include\QtCore\qconfig-bootstrapped.h \
		..\..\qt\5.14.1\android\include\QtCore\qconfig.h \
		..\..\qt\5.14.1\android\include\QtCore\qtcore-config.h \
		..\..\qt\5.14.1\android\include\QtCore\qsystemdetection.h \
		..\..\qt\5.14.1\android\include\QtCore\qprocessordetection.h \
		..\..\qt\5.14.1\android\include\QtCore\qcompilerdetection.h \
		..\..\qt\5.14.1\android\include\QtCore\qtypeinfo.h \
		..\..\qt\5.14.1\android\include\QtCore\qsysinfo.h \
		..\..\qt\5.14.1\android\include\QtCore\qlogging.h \
		..\..\qt\5.14.1\android\include\QtCore\qflags.h \
		..\..\qt\5.14.1\android\include\QtCore\qatomic.h \
		..\..\qt\5.14.1\android\include\QtCore\qbasicatomic.h \
		..\..\qt\5.14.1\android\include\QtCore\qatomic_bootstrap.h \
		..\..\qt\5.14.1\android\include\QtCore\qgenericatomic.h \
		..\..\qt\5.14.1\android\include\QtCore\qatomic_cxx11.h \
		..\..\qt\5.14.1\android\include\QtCore\qatomic_msvc.h \
		..\..\qt\5.14.1\android\include\QtCore\qglobalstatic.h \
		..\..\qt\5.14.1\android\include\QtCore\qmutex.h \
		..\..\qt\5.14.1\android\include\QtCore\qnumeric.h \
		..\..\qt\5.14.1\android\include\QtCore\qversiontagging.h \
		..\..\qt\5.14.1\android\include\QtGui\qtgui-config.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qtwidgets-config.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qwidget.h \
		..\..\qt\5.14.1\android\include\QtGui\qwindowdefs.h \
		..\..\qt\5.14.1\android\include\QtCore\qobjectdefs.h \
		..\..\qt\5.14.1\android\include\QtCore\qnamespace.h \
		..\..\qt\5.14.1\android\include\QtCore\qobjectdefs_impl.h \
		..\..\qt\5.14.1\android\include\QtGui\qwindowdefs_win.h \
		..\..\qt\5.14.1\android\include\QtCore\qobject.h \
		..\..\qt\5.14.1\android\include\QtCore\qstring.h \
		..\..\qt\5.14.1\android\include\QtCore\qchar.h \
		..\..\qt\5.14.1\android\include\QtCore\qbytearray.h \
		..\..\qt\5.14.1\android\include\QtCore\qrefcount.h \
		..\..\qt\5.14.1\android\include\QtCore\qarraydata.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringliteral.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringalgorithms.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringview.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringbuilder.h \
		..\..\qt\5.14.1\android\include\QtCore\qlist.h \
		..\..\qt\5.14.1\android\include\QtCore\qalgorithms.h \
		..\..\qt\5.14.1\android\include\QtCore\qiterator.h \
		..\..\qt\5.14.1\android\include\QtCore\qhashfunctions.h \
		..\..\qt\5.14.1\android\include\QtCore\qpair.h \
		..\..\qt\5.14.1\android\include\QtCore\qvector.h \
		..\..\qt\5.14.1\android\include\QtCore\qcontainertools_impl.h \
		..\..\qt\5.14.1\android\include\QtCore\qpoint.h \
		..\..\qt\5.14.1\android\include\QtCore\qbytearraylist.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringlist.h \
		..\..\qt\5.14.1\android\include\QtCore\qregexp.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringmatcher.h \
		..\..\qt\5.14.1\android\include\QtCore\qcoreevent.h \
		..\..\qt\5.14.1\android\include\QtCore\qscopedpointer.h \
		..\..\qt\5.14.1\android\include\QtCore\qmetatype.h \
		..\..\qt\5.14.1\android\include\QtCore\qvarlengtharray.h \
		..\..\qt\5.14.1\android\include\QtCore\qcontainerfwd.h \
		..\..\qt\5.14.1\android\include\QtCore\qobject_impl.h \
		..\..\qt\5.14.1\android\include\QtCore\qmargins.h \
		..\..\qt\5.14.1\android\include\QtGui\qpaintdevice.h \
		..\..\qt\5.14.1\android\include\QtCore\qrect.h \
		..\..\qt\5.14.1\android\include\QtCore\qsize.h \
		..\..\qt\5.14.1\android\include\QtGui\qpalette.h \
		..\..\qt\5.14.1\android\include\QtGui\qcolor.h \
		..\..\qt\5.14.1\android\include\QtGui\qrgb.h \
		..\..\qt\5.14.1\android\include\QtGui\qrgba64.h \
		..\..\qt\5.14.1\android\include\QtGui\qbrush.h \
		..\..\qt\5.14.1\android\include\QtGui\qmatrix.h \
		..\..\qt\5.14.1\android\include\QtGui\qpolygon.h \
		..\..\qt\5.14.1\android\include\QtGui\qregion.h \
		..\..\qt\5.14.1\android\include\QtCore\qdatastream.h \
		..\..\qt\5.14.1\android\include\QtCore\qiodevice.h \
		..\..\qt\5.14.1\android\include\QtCore\qline.h \
		..\..\qt\5.14.1\android\include\QtGui\qtransform.h \
		..\..\qt\5.14.1\android\include\QtGui\qpainterpath.h \
		..\..\qt\5.14.1\android\include\QtGui\qimage.h \
		..\..\qt\5.14.1\android\include\QtGui\qpixelformat.h \
		..\..\qt\5.14.1\android\include\QtGui\qpixmap.h \
		..\..\qt\5.14.1\android\include\QtCore\qsharedpointer.h \
		..\..\qt\5.14.1\android\include\QtCore\qshareddata.h \
		..\..\qt\5.14.1\android\include\QtCore\qhash.h \
		..\..\qt\5.14.1\android\include\QtCore\qsharedpointer_impl.h \
		..\..\qt\5.14.1\android\include\QtGui\qfont.h \
		..\..\qt\5.14.1\android\include\QtGui\qfontmetrics.h \
		..\..\qt\5.14.1\android\include\QtGui\qfontinfo.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qsizepolicy.h \
		..\..\qt\5.14.1\android\include\QtGui\qcursor.h \
		..\..\qt\5.14.1\android\include\QtGui\qkeysequence.h \
		..\..\qt\5.14.1\android\include\QtGui\qevent.h \
		..\..\qt\5.14.1\android\include\QtCore\qvariant.h \
		..\..\qt\5.14.1\android\include\QtCore\qmap.h \
		..\..\qt\5.14.1\android\include\QtCore\qdebug.h \
		..\..\qt\5.14.1\android\include\QtCore\qtextstream.h \
		..\..\qt\5.14.1\android\include\QtCore\qlocale.h \
		..\..\qt\5.14.1\android\include\QtCore\qset.h \
		..\..\qt\5.14.1\android\include\QtCore\qcontiguouscache.h \
		..\..\qt\5.14.1\android\include\QtCore\qurl.h \
		..\..\qt\5.14.1\android\include\QtCore\qurlquery.h \
		..\..\qt\5.14.1\android\include\QtCore\qfile.h \
		..\..\qt\5.14.1\android\include\QtCore\qfiledevice.h \
		..\..\qt\5.14.1\android\include\QtGui\qvector2d.h \
		..\..\qt\5.14.1\android\include\QtGui\qtouchdevice.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qtabwidget.h \
		..\..\qt\5.14.1\android\include\QtGui\qicon.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QBluetoothDeviceDiscoveryAgent \
		..\..\qt\5.14.1\android\include\QtBluetooth\qbluetoothdevicediscoveryagent.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\qtbluetoothglobal.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\qtbluetooth-config.h \
		..\..\qt\5.14.1\android\include\QtCore\QObject \
		..\..\qt\5.14.1\android\include\QtBluetooth\QBluetoothDeviceInfo \
		..\..\qt\5.14.1\android\include\QtBluetooth\qbluetoothdeviceinfo.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QBluetoothAddress \
		..\..\qt\5.14.1\android\include\QtBluetooth\qbluetoothaddress.h \
		..\..\qt\5.14.1\android\include\QtCore\QByteArray \
		..\..\qt\5.14.1\android\include\QtCore\QString \
		..\..\qt\5.14.1\android\include\QtCore\QMetaType \
		..\..\qt\5.14.1\android\include\QtCore\QList \
		..\..\qt\5.14.1\android\include\QtWidgets\QListWidgetItem \
		..\..\qt\5.14.1\android\include\QtWidgets\qlistwidget.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qlistview.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qabstractitemview.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qabstractscrollarea.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qframe.h \
		..\..\qt\5.14.1\android\include\QtCore\qabstractitemmodel.h \
		..\..\qt\5.14.1\android\include\QtCore\qitemselectionmodel.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qabstractitemdelegate.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qstyleoption.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qabstractspinbox.h \
		..\..\qt\5.14.1\android\include\QtGui\qvalidator.h \
		..\..\qt\5.14.1\android\include\QtCore\qregularexpression.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qslider.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qabstractslider.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qstyle.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qtabbar.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qrubberband.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QLowEnergyController \
		..\..\qt\5.14.1\android\include\QtBluetooth\qlowenergycontroller.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QBluetoothUuid \
		..\..\qt\5.14.1\android\include\QtBluetooth\qbluetoothuuid.h \
		..\..\qt\5.14.1\android\include\QtCore\QtGlobal \
		..\..\qt\5.14.1\android\include\QtCore\QUuid \
		..\..\qt\5.14.1\android\include\QtCore\quuid.h \
		..\..\qt\5.14.1\android\include\QtCore\QDebug \
		..\..\qt\5.14.1\android\include\QtBluetooth\QLowEnergyAdvertisingData \
		..\..\qt\5.14.1\android\include\QtBluetooth\qlowenergyadvertisingdata.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QLowEnergyService \
		..\..\qt\5.14.1\android\include\QtBluetooth\qlowenergyservice.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QLowEnergyCharacteristic \
		..\..\qt\5.14.1\android\include\QtBluetooth\qlowenergycharacteristic.h \
		..\..\qt\5.14.1\android\include\QtCore\QSharedPointer \
		..\..\qt\5.14.1\android\include\QtBluetooth\qbluetooth.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QLowEnergyDescriptor \
		..\..\qt\5.14.1\android\include\QtBluetooth\qlowenergydescriptor.h \
		..\..\qt\5.14.1\android\include\QtCore\QVariantMap \
		..\..\qt\5.14.1\android\include\QtCore\QFileInfo \
		..\..\qt\5.14.1\android\include\QtCore\qfileinfo.h \
		..\..\qt\5.14.1\android\include\QtCore\QFile \
		..\..\qt\5.14.1\android\include\QtWidgets\QFileDialog \
		..\..\qt\5.14.1\android\include\QtWidgets\qfiledialog.h \
		..\..\qt\5.14.1\android\include\QtCore\qdir.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qdialog.h \
		..\..\qt\5.14.1\android\include\QtCore\QDir \
		..\..\qt\5.14.1\android\include\QtCore\QStringList \
		..\..\qt\5.14.1\android\include\QtWidgets\QMessageBox \
		..\..\qt\5.14.1\android\include\QtWidgets\qmessagebox.h \
		..\..\qt\5.14.1\android\include\QtAndroidExtras\QtAndroid \
		..\..\qt\5.14.1\android\include\QtAndroidExtras\qandroidfunctions.h \
		..\..\qt\5.14.1\android\include\QtAndroidExtras\qandroidextrasglobal.h \
		..\..\qt\5.14.1\android\include\QtAndroidExtras\qandroidjniobject.h \
		..\..\qt\5.14.1\android\include\QtAndroidExtras\qandroidjnienvironment.h \
		..\..\qt\5.14.1\android\include\QtWidgets\QApplication \
		..\..\qt\5.14.1\android\include\QtWidgets\qapplication.h \
		..\..\qt\5.14.1\android\include\QtCore\qcoreapplication.h \
		..\..\qt\5.14.1\android\include\QtCore\qeventloop.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qdesktopwidget.h \
		..\..\qt\5.14.1\android\include\QtGui\qguiapplication.h \
		..\..\qt\5.14.1\android\include\QtGui\qinputmethod.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o armeabi-v7a\main.obj main.cpp

armeabi-v7a\mainwindow.obj: mainwindow.cpp mainwindow.h \
		..\..\qt\5.14.1\android\include\QtWidgets\QMainWindow \
		..\..\qt\5.14.1\android\include\QtWidgets\qmainwindow.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qtwidgetsglobal.h \
		..\..\qt\5.14.1\android\include\QtGui\qtguiglobal.h \
		..\..\qt\5.14.1\android\include\QtCore\qglobal.h \
		..\..\qt\5.14.1\android\include\QtCore\qconfig-bootstrapped.h \
		..\..\qt\5.14.1\android\include\QtCore\qconfig.h \
		..\..\qt\5.14.1\android\include\QtCore\qtcore-config.h \
		..\..\qt\5.14.1\android\include\QtCore\qsystemdetection.h \
		..\..\qt\5.14.1\android\include\QtCore\qprocessordetection.h \
		..\..\qt\5.14.1\android\include\QtCore\qcompilerdetection.h \
		..\..\qt\5.14.1\android\include\QtCore\qtypeinfo.h \
		..\..\qt\5.14.1\android\include\QtCore\qsysinfo.h \
		..\..\qt\5.14.1\android\include\QtCore\qlogging.h \
		..\..\qt\5.14.1\android\include\QtCore\qflags.h \
		..\..\qt\5.14.1\android\include\QtCore\qatomic.h \
		..\..\qt\5.14.1\android\include\QtCore\qbasicatomic.h \
		..\..\qt\5.14.1\android\include\QtCore\qatomic_bootstrap.h \
		..\..\qt\5.14.1\android\include\QtCore\qgenericatomic.h \
		..\..\qt\5.14.1\android\include\QtCore\qatomic_cxx11.h \
		..\..\qt\5.14.1\android\include\QtCore\qatomic_msvc.h \
		..\..\qt\5.14.1\android\include\QtCore\qglobalstatic.h \
		..\..\qt\5.14.1\android\include\QtCore\qmutex.h \
		..\..\qt\5.14.1\android\include\QtCore\qnumeric.h \
		..\..\qt\5.14.1\android\include\QtCore\qversiontagging.h \
		..\..\qt\5.14.1\android\include\QtGui\qtgui-config.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qtwidgets-config.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qwidget.h \
		..\..\qt\5.14.1\android\include\QtGui\qwindowdefs.h \
		..\..\qt\5.14.1\android\include\QtCore\qobjectdefs.h \
		..\..\qt\5.14.1\android\include\QtCore\qnamespace.h \
		..\..\qt\5.14.1\android\include\QtCore\qobjectdefs_impl.h \
		..\..\qt\5.14.1\android\include\QtGui\qwindowdefs_win.h \
		..\..\qt\5.14.1\android\include\QtCore\qobject.h \
		..\..\qt\5.14.1\android\include\QtCore\qstring.h \
		..\..\qt\5.14.1\android\include\QtCore\qchar.h \
		..\..\qt\5.14.1\android\include\QtCore\qbytearray.h \
		..\..\qt\5.14.1\android\include\QtCore\qrefcount.h \
		..\..\qt\5.14.1\android\include\QtCore\qarraydata.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringliteral.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringalgorithms.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringview.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringbuilder.h \
		..\..\qt\5.14.1\android\include\QtCore\qlist.h \
		..\..\qt\5.14.1\android\include\QtCore\qalgorithms.h \
		..\..\qt\5.14.1\android\include\QtCore\qiterator.h \
		..\..\qt\5.14.1\android\include\QtCore\qhashfunctions.h \
		..\..\qt\5.14.1\android\include\QtCore\qpair.h \
		..\..\qt\5.14.1\android\include\QtCore\qvector.h \
		..\..\qt\5.14.1\android\include\QtCore\qcontainertools_impl.h \
		..\..\qt\5.14.1\android\include\QtCore\qpoint.h \
		..\..\qt\5.14.1\android\include\QtCore\qbytearraylist.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringlist.h \
		..\..\qt\5.14.1\android\include\QtCore\qregexp.h \
		..\..\qt\5.14.1\android\include\QtCore\qstringmatcher.h \
		..\..\qt\5.14.1\android\include\QtCore\qcoreevent.h \
		..\..\qt\5.14.1\android\include\QtCore\qscopedpointer.h \
		..\..\qt\5.14.1\android\include\QtCore\qmetatype.h \
		..\..\qt\5.14.1\android\include\QtCore\qvarlengtharray.h \
		..\..\qt\5.14.1\android\include\QtCore\qcontainerfwd.h \
		..\..\qt\5.14.1\android\include\QtCore\qobject_impl.h \
		..\..\qt\5.14.1\android\include\QtCore\qmargins.h \
		..\..\qt\5.14.1\android\include\QtGui\qpaintdevice.h \
		..\..\qt\5.14.1\android\include\QtCore\qrect.h \
		..\..\qt\5.14.1\android\include\QtCore\qsize.h \
		..\..\qt\5.14.1\android\include\QtGui\qpalette.h \
		..\..\qt\5.14.1\android\include\QtGui\qcolor.h \
		..\..\qt\5.14.1\android\include\QtGui\qrgb.h \
		..\..\qt\5.14.1\android\include\QtGui\qrgba64.h \
		..\..\qt\5.14.1\android\include\QtGui\qbrush.h \
		..\..\qt\5.14.1\android\include\QtGui\qmatrix.h \
		..\..\qt\5.14.1\android\include\QtGui\qpolygon.h \
		..\..\qt\5.14.1\android\include\QtGui\qregion.h \
		..\..\qt\5.14.1\android\include\QtCore\qdatastream.h \
		..\..\qt\5.14.1\android\include\QtCore\qiodevice.h \
		..\..\qt\5.14.1\android\include\QtCore\qline.h \
		..\..\qt\5.14.1\android\include\QtGui\qtransform.h \
		..\..\qt\5.14.1\android\include\QtGui\qpainterpath.h \
		..\..\qt\5.14.1\android\include\QtGui\qimage.h \
		..\..\qt\5.14.1\android\include\QtGui\qpixelformat.h \
		..\..\qt\5.14.1\android\include\QtGui\qpixmap.h \
		..\..\qt\5.14.1\android\include\QtCore\qsharedpointer.h \
		..\..\qt\5.14.1\android\include\QtCore\qshareddata.h \
		..\..\qt\5.14.1\android\include\QtCore\qhash.h \
		..\..\qt\5.14.1\android\include\QtCore\qsharedpointer_impl.h \
		..\..\qt\5.14.1\android\include\QtGui\qfont.h \
		..\..\qt\5.14.1\android\include\QtGui\qfontmetrics.h \
		..\..\qt\5.14.1\android\include\QtGui\qfontinfo.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qsizepolicy.h \
		..\..\qt\5.14.1\android\include\QtGui\qcursor.h \
		..\..\qt\5.14.1\android\include\QtGui\qkeysequence.h \
		..\..\qt\5.14.1\android\include\QtGui\qevent.h \
		..\..\qt\5.14.1\android\include\QtCore\qvariant.h \
		..\..\qt\5.14.1\android\include\QtCore\qmap.h \
		..\..\qt\5.14.1\android\include\QtCore\qdebug.h \
		..\..\qt\5.14.1\android\include\QtCore\qtextstream.h \
		..\..\qt\5.14.1\android\include\QtCore\qlocale.h \
		..\..\qt\5.14.1\android\include\QtCore\qset.h \
		..\..\qt\5.14.1\android\include\QtCore\qcontiguouscache.h \
		..\..\qt\5.14.1\android\include\QtCore\qurl.h \
		..\..\qt\5.14.1\android\include\QtCore\qurlquery.h \
		..\..\qt\5.14.1\android\include\QtCore\qfile.h \
		..\..\qt\5.14.1\android\include\QtCore\qfiledevice.h \
		..\..\qt\5.14.1\android\include\QtGui\qvector2d.h \
		..\..\qt\5.14.1\android\include\QtGui\qtouchdevice.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qtabwidget.h \
		..\..\qt\5.14.1\android\include\QtGui\qicon.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QBluetoothDeviceDiscoveryAgent \
		..\..\qt\5.14.1\android\include\QtBluetooth\qbluetoothdevicediscoveryagent.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\qtbluetoothglobal.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\qtbluetooth-config.h \
		..\..\qt\5.14.1\android\include\QtCore\QObject \
		..\..\qt\5.14.1\android\include\QtBluetooth\QBluetoothDeviceInfo \
		..\..\qt\5.14.1\android\include\QtBluetooth\qbluetoothdeviceinfo.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QBluetoothAddress \
		..\..\qt\5.14.1\android\include\QtBluetooth\qbluetoothaddress.h \
		..\..\qt\5.14.1\android\include\QtCore\QByteArray \
		..\..\qt\5.14.1\android\include\QtCore\QString \
		..\..\qt\5.14.1\android\include\QtCore\QMetaType \
		..\..\qt\5.14.1\android\include\QtCore\QList \
		..\..\qt\5.14.1\android\include\QtWidgets\QListWidgetItem \
		..\..\qt\5.14.1\android\include\QtWidgets\qlistwidget.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qlistview.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qabstractitemview.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qabstractscrollarea.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qframe.h \
		..\..\qt\5.14.1\android\include\QtCore\qabstractitemmodel.h \
		..\..\qt\5.14.1\android\include\QtCore\qitemselectionmodel.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qabstractitemdelegate.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qstyleoption.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qabstractspinbox.h \
		..\..\qt\5.14.1\android\include\QtGui\qvalidator.h \
		..\..\qt\5.14.1\android\include\QtCore\qregularexpression.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qslider.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qabstractslider.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qstyle.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qtabbar.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qrubberband.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QLowEnergyController \
		..\..\qt\5.14.1\android\include\QtBluetooth\qlowenergycontroller.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QBluetoothUuid \
		..\..\qt\5.14.1\android\include\QtBluetooth\qbluetoothuuid.h \
		..\..\qt\5.14.1\android\include\QtCore\QtGlobal \
		..\..\qt\5.14.1\android\include\QtCore\QUuid \
		..\..\qt\5.14.1\android\include\QtCore\quuid.h \
		..\..\qt\5.14.1\android\include\QtCore\QDebug \
		..\..\qt\5.14.1\android\include\QtBluetooth\QLowEnergyAdvertisingData \
		..\..\qt\5.14.1\android\include\QtBluetooth\qlowenergyadvertisingdata.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QLowEnergyService \
		..\..\qt\5.14.1\android\include\QtBluetooth\qlowenergyservice.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QLowEnergyCharacteristic \
		..\..\qt\5.14.1\android\include\QtBluetooth\qlowenergycharacteristic.h \
		..\..\qt\5.14.1\android\include\QtCore\QSharedPointer \
		..\..\qt\5.14.1\android\include\QtBluetooth\qbluetooth.h \
		..\..\qt\5.14.1\android\include\QtBluetooth\QLowEnergyDescriptor \
		..\..\qt\5.14.1\android\include\QtBluetooth\qlowenergydescriptor.h \
		..\..\qt\5.14.1\android\include\QtCore\QVariantMap \
		..\..\qt\5.14.1\android\include\QtCore\QFileInfo \
		..\..\qt\5.14.1\android\include\QtCore\qfileinfo.h \
		..\..\qt\5.14.1\android\include\QtCore\QFile \
		..\..\qt\5.14.1\android\include\QtWidgets\QFileDialog \
		..\..\qt\5.14.1\android\include\QtWidgets\qfiledialog.h \
		..\..\qt\5.14.1\android\include\QtCore\qdir.h \
		..\..\qt\5.14.1\android\include\QtWidgets\qdialog.h \
		..\..\qt\5.14.1\android\include\QtCore\QDir \
		..\..\qt\5.14.1\android\include\QtCore\QStringList \
		..\..\qt\5.14.1\android\include\QtWidgets\QMessageBox \
		..\..\qt\5.14.1\android\include\QtWidgets\qmessagebox.h \
		..\..\qt\5.14.1\android\include\QtAndroidExtras\QtAndroid \
		..\..\qt\5.14.1\android\include\QtAndroidExtras\qandroidfunctions.h \
		..\..\qt\5.14.1\android\include\QtAndroidExtras\qandroidextrasglobal.h \
		..\..\qt\5.14.1\android\include\QtAndroidExtras\qandroidjniobject.h \
		..\..\qt\5.14.1\android\include\QtAndroidExtras\qandroidjnienvironment.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o armeabi-v7a\mainwindow.obj mainwindow.cpp

armeabi-v7a\moc_mainwindow.obj: armeabi-v7a\moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o armeabi-v7a\moc_mainwindow.obj armeabi-v7a\moc_mainwindow.cpp

####### Install

install_target: all FORCE
	@if not exist $(INSTALL_ROOT:@msyshack@%=%)\libs\armeabi-v7a mkdir $(INSTALL_ROOT:@msyshack@%=%)\libs\armeabi-v7a & if not exist $(INSTALL_ROOT:@msyshack@%=%)\libs\armeabi-v7a exit 1
	$(QINSTALL_PROGRAM) $(QMAKE_TARGET) $(INSTALL_ROOT:@msyshack@%=%)\libs\armeabi-v7a\$(QMAKE_TARGET)

uninstall_target: FORCE
	-$(DEL_FILE) $(INSTALL_ROOT:@msyshack@%=%)\libs\armeabi-v7a\$(QMAKE_TARGET)
	-$(DEL_DIR) $(INSTALL_ROOT:@msyshack@%=%)\libs\armeabi-v7a 


install: install_target  FORCE

uninstall: uninstall_target  FORCE

FORCE:

