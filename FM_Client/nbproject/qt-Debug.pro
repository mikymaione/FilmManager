# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = FM_Client
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += Commenti_Dettaglio.cpp Commenti_Ricerca.cpp Connessione.cpp ConversionFN.cpp Film_Dettaglio.cpp Film_Ricerca.cpp GlobalVar.cpp TableMacro.cpp Utente_Dettaglio.cpp Utente_Login.cpp form1.cpp main.cpp
HEADERS += Commenti_Dettaglio.h Commenti_Ricerca.h Connessione.h ConversionFN.h Film_Dettaglio.h Film_Ricerca.h GlobalVar.h TableMacro.h Utente_Dettaglio.h Utente_Login.h form1.h
FORMS += Commenti_Dettaglio.ui Commenti_Ricerca.ui Connessione.ui Film_Dettaglio.ui Film_Ricerca.ui Utente_Dettaglio.ui Utente_Login.ui form1.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += /home/michele/Documenti/LSO/FM_Core/Classi/ 
LIBS += /home/michele/Scrivania/LSO/FM_Core/dist/Debug/GNU-Linux-x86/libfm_core.a  
