#include "simulation_input_windows.h"

Simulation_Input_Windows::Simulation_Input_Windows(QWidget *parent) : QWidget(parent)
{
    main_layout = new QGridLayout;
    this->setLayout(main_layout);

    file_parameter_import = new file_import_widget("Importation d'un fichier de parametre");
    main_layout->addWidget(file_parameter_import,0,0);
    connect(file_parameter_import, SIGNAL(import_file(QString)), this, SIGNAL(import_file_parameter(QString)));

    main_layout->addWidget(dim_box_construction(),1,0);
}

Simulation_Input_Windows::~Simulation_Input_Windows()
{
    delete button_1D;
    delete button_2D;
    delete button_3D;
    delete layout_dim;
    delete box_dim;

    delete file_parameter_import;

    delete main_layout;
}

QWidget* Simulation_Input_Windows::dim_box_construction()
{
    box_dim = new QGroupBox("Dimension");

    layout_dim = new QHBoxLayout;
    box_dim->setLayout(layout_dim);

    button_1D = new QRadioButton("1 Dimension");
    button_2D = new QRadioButton("2 Dimension");
    button_3D = new QRadioButton("3 Dimension");
    layout_dim->addWidget(button_1D);
    layout_dim->addWidget(button_2D);
    layout_dim->addWidget(button_3D);
    button_1D->setChecked(true);
    button_2D->setEnabled(false);
    button_3D->setEnabled(false);

    layout_dim->addStretch();
    return box_dim;
}

int Simulation_Input_Windows::Number_dimension()
{
    if(button_1D->isChecked())
    {
        return 1;
    }
    else if(button_2D->isChecked())
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
