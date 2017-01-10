#ifndef SIMULATION_INPUT_WINDOWS_H
#define SIMULATION_INPUT_WINDOWS_H

#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QToolButton>
#include <QLineEdit>
#include <QPushButton>

class Simulation_Input_Windows : public QWidget
{
    Q_OBJECT
public:
    explicit Simulation_Input_Windows(QWidget *parent = 0);
    ~Simulation_Input_Windows();

signals:
    void import_file_parameter(QString);

public slots:
    int Number_dimension();

protected slots:
    void sig_import_file_parameter();
    void choice_file_parameter();

protected:
    QWidget* file_param_box_construction();
    QWidget* dim_box_construction();

    QGridLayout *main_layout;

    QGroupBox *box_file_param;
    QHBoxLayout *layout_file_param;
    QLineEdit *file_path_text;
    QToolButton *file_path_button;
    QPushButton *file_import_button;

    QGroupBox *box_dim;
    QHBoxLayout *layout_dim;
    QRadioButton *button_1D;
    QRadioButton *button_2D;
    QRadioButton *button_3D;

};

#endif // SIMULATION_INPUT_WINDOWS_H
