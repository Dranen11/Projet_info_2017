#ifndef POTENTIAL_INPUT_WIDGET_H
#define POTENTIAL_INPUT_WIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QLabel>
#include <QDoubleSpinBox>

#include "../file_import_widget.h"

class potential_input_widget : public QGroupBox
{
    Q_OBJECT
public:
    explicit potential_input_widget(QWidget *parent = 0);
    ~potential_input_widget();

signals:

public slots:

protected slots:
    void display_constant();
    void display_file();
    void display_parabol();
    void display_sinusoid();
    void display_erase();

protected:
    QWidget* file_construct();
    QWidget* constant_construct();
    QWidget* parabol_construct();
    QWidget* sinusoid_construct();
    QWidget* button_construction();


    QVBoxLayout *main_layout;

    QGroupBox *box_type_potential;
    QHBoxLayout *layout_type;
    QRadioButton *but_constant;
    QRadioButton *but_file;
    QRadioButton *but_parabol;
    QRadioButton *but_sinusoid;

    QDoubleSpinBox *spin_box_param1;
    QDoubleSpinBox *spin_box_param2;
    QDoubleSpinBox *spin_box_param3;
    QDoubleSpinBox *spin_box_param4;

    file_import_widget* file_pot;

    QGroupBox *box_constant;
    QHBoxLayout *layout_constant;
    QLabel *label_constant;

    QGroupBox *box_parabol;
    QHBoxLayout *layout_parabol;
    QLabel *label_parabol;

    QGroupBox *box_sinusoid;
    QHBoxLayout *layout_sinusoid;
    QLabel *label_sinusoid;

};

#endif // POTENTIAL_INPUT_WIDGET_H
