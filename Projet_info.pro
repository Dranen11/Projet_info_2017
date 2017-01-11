QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet_info
TEMPLATE = app

HEADERS += \
    #Simulation/Algebra.h \
    #Simulation/Numeric_solving.h \
    #Simulation/Potential.h \
    #Simulation/Writing.h \
    GUI/main_window.h \
    GUI/simulation_input_windows.h \
    GUI/simulation_input_windows/potential_input_widget.h \
    GUI/file_import_widget.h

SOURCES += \
    #Simulation/Algebra.cpp \
    #Simulation/Numeric_solving.cpp \
    GUI/main_window.cpp \
    GUI/simulation_input_windows.cpp \
    main.cpp \
    GUI/simulation_input_windows/potential_input_widget.cpp \
    GUI/file_import_widget.cpp
