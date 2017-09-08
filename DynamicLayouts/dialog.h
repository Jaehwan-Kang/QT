#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QQueue>

class QGroupBox;
class QGridLayout;
class QLabel;
class QComboBox;
class QDialogButtonBox;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
//    explicit Dialog(QWidget *parent = 0);
//    ~Dialog();
    Dialog(QWidget *parent = 0);

private slots:
    void buttonOrientationChanged(int index);
    void rotateWidgets();
    void help();

private:
//    Ui::Dialog *ui;

    void createRotableGroupBox();
    void createOptionsGroupBox();
    void createButtonBox();

    QGroupBox * rotableGroupBox;
    QQueue<QWidget *> rotableWidgets;
    QGridLayout * rotableLayout;

    QGroupBox * optionsGroupBox;
    QLabel * buttonsOrientationLabel;
    QComboBox * buttonsOrientationComboBox;

    QGridLayout * optionsLayout;

    QGridLayout * mainLayout;

    QDialogButtonBox * buttonBox;
    QPushButton * closeButton;
    QPushButton * helpButton;
    QPushButton * rotateWidgetsButton;
};

#endif // DIALOG_H
