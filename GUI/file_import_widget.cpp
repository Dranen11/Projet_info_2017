#include "file_import_widget.h"
#include <QFileDialog>

file_import_widget::file_import_widget(QWidget *parent) : QGroupBox(parent)
{
    widget_construction();
}

file_import_widget::file_import_widget(QString title, QWidget *parent) : QGroupBox(title, parent)
{
    widget_construction();
}

file_import_widget::~file_import_widget()
{
    delete file_path_text;
    delete file_path_button;
    delete file_import_button;
    delete layout_file;
}

void file_import_widget::choice_file()
{
    file_path_text->setText(QFileDialog::getOpenFileName(this, "Ouvrir un fichier"));
}

void file_import_widget::_import_file()
{
    emit import_file(file_path_text->text());
}

void file_import_widget::widget_construction()
{
    layout_file = new QHBoxLayout(this);

    file_path_text = new QLineEdit;
    file_path_button = new QPushButton("...");
    file_import_button = new QPushButton("Importer");
    layout_file->addWidget(file_path_text);
    layout_file->addWidget(file_path_button);
    layout_file->addWidget(file_import_button);

    connect(file_import_button,SIGNAL(pressed()),this,SLOT(_import_file()));
    connect(file_path_button,SIGNAL(pressed()),this,SLOT(choice_file()));
}
