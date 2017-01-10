#include "GUI/simulation_input_windows.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Simulation_Input_Windows w;
    w.show();

    return a.exec();
}
