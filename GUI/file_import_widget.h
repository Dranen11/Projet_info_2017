#ifndef FILE_IMPORT_WIDGET_H
#define FILE_IMPORT_WIDGET_H

/*Classe définissant un widget pour importer un fichier
 * Contient un champ de texte pour le chemin, un bouton pour l'ouverture d'une fenetre pour choisir le chemin
 * et un bouton pur déclencher l'import
 * le signal import_file contient un QString avec le chemin du fichier et est le signal pour importer le fichier
*/

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>

class file_import_widget : public QGroupBox
{
    Q_OBJECT
public:
    explicit file_import_widget(QWidget *parent = 0);
    explicit file_import_widget(QString title, QWidget *parent = 0); //Pour définir un titre à la GroupBox
    explicit file_import_widget(QString title, bool button_import, QWidget *parent = 0); //Pour définir un titre à la GroupBox et désactiver le bouton import
    ~file_import_widget();

signals:
    void import_file(QString file); //signal de l'appui du bouton pour importer le fichier, le chemin étant contenu dans file

public slots:
    QString file_path();

protected slots:
    void _import_file();
    void choice_file();

protected:
    void widget_construction();

    QHBoxLayout *layout_file;
    QLineEdit *file_path_text;
    QPushButton *file_path_button;
    QPushButton *file_import_button;
    bool import_button;
};

#endif // FILE_IMPORT_WIDGET_H
