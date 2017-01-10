#include "simulation_input_windows.h"
#include <QFileDialog>

Simulation_Input_Windows::Simulation_Input_Windows(QWidget *parent) : QWidget(parent)
{
    main_layout = new QGridLayout;
    this->setLayout(main_layout);

    main_layout->addWidget(file_param_box_construction(),0,0);

    main_layout->addWidget(dim_box_construction(),1,0);
}

Simulation_Input_Windows::~Simulation_Input_Windows()
{
    delete button_1D;
    delete button_2D;
    delete button_3D;
    delete layout_dim;
    delete box_dim;

    delete file_import_button;
    delete file_path_button;
    delete file_path_text;
    delete layout_file_param;
    delete box_file_param;

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

    return box_dim;
}

QWidget* Simulation_Input_Windows::file_param_box_construction()
{
    box_file_param = new QGroupBox("Importer un fichier de parametre");

    layout_file_param = new QHBoxLayout(box_file_param);

    file_path_text = new QLineEdit;
    file_path_button = new QToolButton;
    file_import_button = new QPushButton("Importer");
    layout_file_param->addWidget(file_path_text);
    layout_file_param->addWidget(file_path_button);
    layout_file_param->addWidget(file_import_button);

    connect(file_import_button,SIGNAL(pressed()),this,SLOT(sig_import_file_parameter()));
    connect(file_path_button,SIGNAL(pressed()),this,SLOT(choice_file_parameter()));

    return box_file_param;
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

void Simulation_Input_Windows::choice_file_parameter()
{
    file_path_text->setText(QFileDialog::getOpenFileName(this, "Ouvrir un fichier"));
}

void Simulation_Input_Windows::sig_import_file_parameter()
{
    emit import_file_parameter(file_path_text->text());
}
