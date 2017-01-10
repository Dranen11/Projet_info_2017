#ifndef SIMULATION_INPUT_WINDOWS_H
#define SIMULATION_INPUT_WINDOWS_H

#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QRadioButton>

class Simulation_Input_Windows : public QWidget
{
    Q_OBJECT
public:
    explicit Simulation_Input_Windows(QWidget *parent = 0);
    ~Simulation_Input_Windows();

signals:

public slots:
    int Number_dimension();

protected:
    QWidget* dim_box_construction();

    QGridLayout *main_layout;

    QGroupBox *box_dim;
    QHBoxLayout *layout_dim;
    QRadioButton *button_1D;
    QRadioButton *button_2D;
    QRadioButton *button_3D;

};

#endif // SIMULATION_INPUT_WINDOWS_H
