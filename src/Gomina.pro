#-------------------------------------------------
# Project created by QtCreator 2015-01-04T20:14:31
#-------------------------------------------------

# Included Qt modules
QT += core gui widgets network

# Create a MakeFile for building application
TEMPLATE = app

# manual conf of shadow build
CONFIG(debug, debug|release) {
    TARGET = Gomina_d
    DESTDIR = $${_PRO_FILE_PWD_}/../bin_d
    MODE_PWD = $${OUT_PWD}/debug
} else {
    TARGET = Gomina
    DESTDIR = $${_PRO_FILE_PWD_}/../bin
    MODE_PWD = $${OUT_PWD}/release
}

# Define custom output directories
OBJECTS_DIR = $${MODE_PWD}/obj
MOC_DIR = $${MODE_PWD}/moc
UI_DIR = $${MODE_PWD}/ui
RCC_DIR = $${MODE_PWD}/rcc

# All input files
SOURCES +=  main.cpp \
            gui/mainwindow.cpp \
            gui/gobanview.cpp \
            gui/gobanscene.cpp \
            gui/optionsdialog.cpp \
            gui/gamehud.cpp \
            gui/graphicstoneitem.cpp \
            gui/graphicsgobanitem.cpp \
            gui/graphicshitboxitem.cpp \
            gui/playerhud.cpp \
            gui/historicalhud.cpp \
            gameengine.cpp \
            goban.cpp \
            cpuplayer.cpp \
            gui/chatwindow.cpp \
            player.cpp \
            humanplayer.cpp \
            gamearbiter.cpp \
            gamehistory.cpp \
    pathprovider.cpp

HEADERS +=  gui/mainwindow.h \
            gui/gobanview.h \
            gui/gobanscene.h \
            gui/optionsdialog.h \
            gui/gamehud.h \
            gui/graphicstoneitem.h \
            gui/graphicsgobanitem.h \
            gui/graphicshitboxitem.h \
            gui/playerhud.h \
            gui/historicalhud.h \
            gameengine.h \
            goban.h \
            cpuplayer.h \
            gui/chatwindow.h \
            player.h \
            humanplayer.h \
            gamearbiter.h \
            gamehistory.h \
    pathprovider.h

FORMS   +=  gui/mainwindow.ui \
            gui/optionsdialog.ui \
            gui/gamehud.ui \
            gui/playerhud.ui \
            gui/historicalhud.ui \
            gui/chatwindow.ui

OTHER_FILES += vectorAddition.cu    # This makes the .cu files appear in your project

RESOURCES += res.qrc

RC_FILE = logo_link.rc

#--------------------------------------------------
# CUDA custom step
#--------------------------------------------------

## Liste of cuda sources files
#CUDA_SOURCES += vectorAddition.cu

## Cuda temp files directory
#CUDA_OBJ_DIR = $${MODE_PWD}/cuda
#message{$$CUDA_OBJ_DIR}

## Cuda parametres
#CUDA_ARCH = sm_30       # Type of CUDA architecture
#SYSTEM_NAME = Win32     # Depending on your system either 'Win32', 'x64', or 'Win64'
#SYSTEM_TYPE = 32        # '32' or '64', depending on your system

## Path to cuda toolkit install
#CUDA_DIR = "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v6.0"
#INCLUDEPATH += $$CUDA_DIR/include
#QMAKE_LIBDIR += $$CUDA_DIR/lib/$$SYSTEM_NAME
#LIBS += -lcuda -lcudart

## Location of cl.exe compiler for nvcc 'cause nvcc doesn't find it in its path env
#MSVC_DIR = "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/bin/cl.exe"

## The following makes sure all path names (which often include spaces) are put between quotation marks
#CUDA_INC = $$join(INCLUDEPATH,'" -I"','-I"','"')
#MSVC_DIR = $$join(MSVC_DIR, '"', '"', '"')


## The following library conflicts with something in Cuda
#QMAKE_LFLAGS_RELEASE = /NODEFAULTLIB:msvcrt.lib
#QMAKE_LFLAGS_DEBUG   = /NODEFAULTLIB:msvcrtd.lib

## Configuration of the Cuda compiler
#CONFIG(debug, debug|release) {
#    cuda_d.input = CUDA_SOURCES
#    cuda_d.output = $$CUDA_OBJ_DIR/${QMAKE_FILE_BASE}_cuda.o
#    cuda_d.commands = $$CUDA_DIR/bin/nvcc.exe $$CUDA_INC $$LIBS --cl-version 2010 -ccbin=$$MSVC_DIR --machine=$$SYSTEM_TYPE -arch=$$CUDA_ARCH -c -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME}
#    #-o vectorAddition.obj    ...    -D_DEBUG
#    cuda_d.dependency_type = TYPE_C
#    #QMAKE_EXTRA_COMPILERS += cuda_d
#}
#else {
#    cuda.input = CUDA_SOURCES
#    cuda.output = $$CUDA_OBJ_DIR\${QMAKE_FILE_BASE}_cuda.o
#    cuda.commands = $$CUDA_DIR\bin\nvcc.exe -ccbin $$MSVC_LOCATION $$NVCC_OPTIONS $$CUDA_INC $$NVCC_LIBS --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH -c -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME}
#    cuda.dependency_type = TYPE_C
#    #QMAKE_EXTRA_COMPILERS += cuda
#}
