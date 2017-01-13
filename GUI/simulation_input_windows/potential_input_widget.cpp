#include "potential_input_widget.h"
#include <limits>
#include <cstddef>

potential_input_widget::potential_input_widget(QWidget *parent) : QGroupBox(parent)
{
    setTitle("Potentiel");
    main_layout = new QVBoxLayout;
    this->setLayout(main_layout);

    spin_box_param1 = new QDoubleSpinBox();
    spin_box_param2 = new QDoubleSpinBox();
    spin_box_param3 = new QDoubleSpinBox();
    spin_box_param4 = new QDoubleSpinBox();
    spin_box_param1->setPrefix("A : ");
    spin_box_param2->setPrefix("B : ");
    spin_box_param3->setPrefix("C : ");
    spin_box_param4->setPrefix("D : ");
    spin_box_param1->setRange(std::numeric_limits<double>::lowest(),std::numeric_limits<double>::max());
    spin_box_param2->setRange(std::numeric_limits<double>::lowest(),std::numeric_limits<double>::max());
    spin_box_param3->setRange(std::numeric_limits<double>::lowest(),std::numeric_limits<double>::max());
    spin_box_param4->setRange(std::numeric_limits<double>::lowest(),std::numeric_limits<double>::max());

    main_layout->addWidget(button_construction());
    main_layout->addWidget(constant_construct());
    main_layout->addWidget(parabol_construct());
    main_layout->addWidget(sinusoid_construct());
    main_layout->addWidget(file_construct());
    display_constant();
}

potential_input_widget::~potential_input_widget()
{
    delete spin_box_param1;
    delete spin_box_param2;
    delete spin_box_param3;
    delete spin_box_param4;

    delete but_constant;
    delete but_file;
    delete but_parabol;
    delete but_sinusoid;
    delete layout_type;
    delete box_type_potential;

    delete file_pot;

    delete label_constant;
    delete layout_constant;
    delete box_constant;

    delete label_parabol;
    delete layout_parabol;
    delete box_parabol;

    delete label_sinusoid;
    delete layout_sinusoid;
    delete box_sinusoid;

    delete main_layout;
}

QWidget* potential_input_widget::button_construction()
{
    box_type_potential = new QGroupBox("Choix du type de Potentiel");
    layout_type = new QHBoxLayout;
    box_type_potential->setLayout(layout_type);

    but_constant = new QRadioButton("Constant");
    but_file = new QRadioButton("Issu d'un fichier");
    but_parabol = new QRadioButton("Parabole");
    but_sinusoid = new QRadioButton("Sinusoid");

    layout_type->addWidget(but_constant);
    layout_type->addWidget(but_parabol);
    layout_type->addWidget(but_sinusoid);
    layout_type->addWidget(but_file);
    layout_type->addStretch();

    connect(but_constant,SIGNAL(pressed()),this,SLOT(display_constant()));
    connect(but_file,SIGNAL(pressed()),this,SLOT(display_file()));
    connect(but_parabol,SIGNAL(pressed()),this,SLOT(display_parabol()));
    connect(but_sinusoid,SIGNAL(pressed()),this,SLOT(display_sinusoid()));

    return box_type_potential;
}

QWidget* potential_input_widget::parabol_construct()
{
    box_parabol = new QGroupBox("Parabole");
    layout_parabol = new QHBoxLayout;
    box_parabol->setLayout(layout_parabol);

    label_parabol = new QLabel("V(x) = A*x^2+b*x+c");
    layout_parabol->addWidget(label_parabol);
    layout_parabol->addWidget(spin_box_param1);
    layout_parabol->addWidget(spin_box_param2);
    layout_parabol->addWidget(spin_box_param3);
    layout_parabol->addStretch();

    return box_parabol;
}

QWidget* potential_input_widget::constant_construct()
{
    box_constant = new QGroupBox("Constant");
    layout_constant = new QHBoxLayout;
    box_constant->setLayout(layout_constant);

    label_constant = new QLabel("V(x) = A");
    layout_constant->addWidget(label_constant);
    layout_constant->addWidget(spin_box_param1);
    layout_constant->addStretch();

    return box_constant;
}

QWidget* potential_input_widget::sinusoid_construct()
{
    box_sinusoid = new QGroupBox("Sinusoide");
    layout_sinusoid = new QHBoxLayout;
    box_sinusoid->setLayout(layout_sinusoid);

    label_sinusoid = new QLabel("V(x) = A*sin(C*x + D) + B");
    layout_sinusoid->addWidget(label_sinusoid);
    layout_sinusoid->addWidget(spin_box_param1);
    layout_sinusoid->addWidget(spin_box_param2);
    layout_sinusoid->addWidget(spin_box_param3);
    layout_sinusoid->addWidget(spin_box_param4);
    layout_sinusoid->addStretch();

    return box_sinusoid;
}

QWidget* potential_input_widget::file_construct()
{
    file_pot = new file_import_widget("Potentiel issu d'un fichier", false);

    return file_pot;
}

void potential_input_widget::display_constant()
{
    display_erase();
    box_constant->show();
    layout_constant->addWidget(spin_box_param1);
    layout_constant->addStretch();
}

void potential_input_widget::display_file()
{
    display_erase();
    file_pot->show();
}

void potential_input_widget::display_parabol()
{
    display_erase();
    box_parabol->show();
    layout_parabol->addWidget(spin_box_param1);
    layout_parabol->addWidget(spin_box_param2);
    layout_parabol->addWidget(spin_box_param3);
    layout_parabol->addStretch();
}

void potential_input_widget::display_sinusoid()
{
    display_erase();
    box_sinusoid->show();
    layout_sinusoid->addWidget(spin_box_param1);
    layout_sinusoid->addWidget(spin_box_param2);
    layout_sinusoid->addWidget(spin_box_param3);
    layout_sinusoid->addWidget(spin_box_param4);
    layout_sinusoid->addStretch();
}

void potential_input_widget::display_erase()
{
    box_constant->hide();
    box_parabol->hide();
    box_sinusoid->hide();
    file_pot->hide();
}
