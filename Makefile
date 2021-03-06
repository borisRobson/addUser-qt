#############################################################################
# Makefile for building: addUser
# Generated by qmake (2.01a) (Qt 4.7.3) on: Thu Oct 6 14:49:24 2016
# Project:  addUser.pro
# Template: app
# Command: /home/standby/QtSDK/Desktop/Qt/473/gcc/bin/qmake -spec ../QtSDK/Desktop/Qt/473/gcc/mkspecs/linux-g++-64 -o Makefile addUser.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../QtSDK/Desktop/Qt/473/gcc/mkspecs/linux-g++-64 -I. -I../QtSDK/Desktop/Qt/473/gcc/include/QtCore -I../QtSDK/Desktop/Qt/473/gcc/include/QtGui -I../QtSDK/Desktop/Qt/473/gcc/include -I/usr/include/gstreamer-0.10 -I/usr/include/gstreamer-0.10/gst/video -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/libxml2 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I../doorentry/ltib/rootfs/usr/include -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1 -Wl,-rpath,/home/standby/QtSDK/Desktop/Qt/473/gcc/lib
LIBS          = $(SUBLIBS)  -L/home/standby/QtSDK/Desktop/Qt/473/gcc/lib -L/usr/lib -lglib-2.0 -lgobject-2.0 -lgmodule-2.0 -lgthread-2.0 -lrt -lz -lxml2 -L/usr/lib/x86_64-linux-gnu -lgstreamer-0.10 -lgstbase-0.10 -lgstapp-0.10 -lgstvideo-0.10 -lgstinterfaces-0.10 -L/usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_video -lopencv_highgui -lopencv_objdetect -lopencv_contrib -lopencv_flann -lopencv_features2d -lopencv_calib3d -lopencv_ml -lopencv_legacy -lopencv_photo -lopencv_gpu -lopencv_ocl -lopencv_nonfree -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/standby/QtSDK/Desktop/Qt/473/gcc/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		captureimage.cpp \
		stream.cpp moc_mainwindow.cpp \
		moc_captureimage.cpp \
		moc_stream.cpp
OBJECTS       = main.o \
		mainwindow.o \
		captureimage.o \
		stream.o \
		moc_mainwindow.o \
		moc_captureimage.o \
		moc_stream.o
DIST          = ../QtSDK/Desktop/Qt/473/gcc/mkspecs/common/g++.conf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/common/unix.conf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/common/linux.conf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/qconfig.pri \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/modules/qt_webkit_version.pri \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/qt_functions.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/qt_config.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/exclusive_builds.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/default_pre.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/release.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/default_post.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/warn_on.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/qt.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/unix/thread.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/moc.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/resources.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/uic.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/yacc.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/lex.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/include_source_dir.prf \
		addUser.pro
QMAKE_TARGET  = addUser
DESTDIR       = 
TARGET        = addUser

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: addUser.pro  ../QtSDK/Desktop/Qt/473/gcc/mkspecs/linux-g++-64/qmake.conf ../QtSDK/Desktop/Qt/473/gcc/mkspecs/common/g++.conf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/common/unix.conf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/common/linux.conf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/qconfig.pri \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/modules/qt_webkit_version.pri \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/qt_functions.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/qt_config.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/exclusive_builds.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/default_pre.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/release.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/default_post.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/warn_on.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/qt.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/unix/thread.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/moc.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/resources.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/uic.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/yacc.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/lex.prf \
		../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -spec ../QtSDK/Desktop/Qt/473/gcc/mkspecs/linux-g++-64 -o Makefile addUser.pro
../QtSDK/Desktop/Qt/473/gcc/mkspecs/common/g++.conf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/common/unix.conf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/common/linux.conf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/qconfig.pri:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/modules/qt_webkit_version.pri:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/qt_functions.prf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/qt_config.prf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/exclusive_builds.prf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/default_pre.prf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/release.prf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/default_post.prf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/warn_on.prf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/qt.prf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/unix/thread.prf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/moc.prf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/resources.prf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/uic.prf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/yacc.prf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/lex.prf:
../QtSDK/Desktop/Qt/473/gcc/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec ../QtSDK/Desktop/Qt/473/gcc/mkspecs/linux-g++-64 -o Makefile addUser.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/addUser1.0.0 || $(MKDIR) .tmp/addUser1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/addUser1.0.0/ && $(COPY_FILE) --parents mainwindow.h captureimage.h stream.h .tmp/addUser1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp captureimage.cpp stream.cpp .tmp/addUser1.0.0/ && $(COPY_FILE) --parents mainwindow.ui .tmp/addUser1.0.0/ && (cd `dirname .tmp/addUser1.0.0` && $(TAR) addUser1.0.0.tar addUser1.0.0 && $(COMPRESS) addUser1.0.0.tar) && $(MOVE) `dirname .tmp/addUser1.0.0`/addUser1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/addUser1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_captureimage.cpp moc_stream.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_captureimage.cpp moc_stream.cpp
moc_mainwindow.cpp: mainwindow.h
	/home/standby/QtSDK/Desktop/Qt/473/gcc/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_captureimage.cpp: captureimage.h
	/home/standby/QtSDK/Desktop/Qt/473/gcc/bin/moc $(DEFINES) $(INCPATH) captureimage.h -o moc_captureimage.cpp

moc_stream.cpp: mainwindow.h \
		stream.h
	/home/standby/QtSDK/Desktop/Qt/473/gcc/bin/moc $(DEFINES) $(INCPATH) stream.h -o moc_stream.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui
	/home/standby/QtSDK/Desktop/Qt/473/gcc/bin/uic mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		stream.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		ui_mainwindow.h \
		captureimage.h \
		stream.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

captureimage.o: captureimage.cpp captureimage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o captureimage.o captureimage.cpp

stream.o: stream.cpp stream.h \
		mainwindow.h \
		captureimage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o stream.o stream.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_captureimage.o: moc_captureimage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_captureimage.o moc_captureimage.cpp

moc_stream.o: moc_stream.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_stream.o moc_stream.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

