#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "finddialog.h"

#include <QWidget>
#include <QMap>

class QLabel;
class QLineEdit;
class QPushButton;
class QTextEdit;



namespace Ui {
class addressbook;
}

class addressbook : public QWidget
{
    Q_OBJECT

public:
    explicit addressbook(QWidget *parent = 0);
    ~addressbook();

    enum Mode {
        NavigationMode,
        AddingMode,
        EditingMode
    };


public slots:
    void addContact();
    void submitContact();
    void cancel();
    void next();
    void previous();
    void editContact();
    void removeContact();
    void findContact();
    void saveToFile();
    void loadFromFile();
    void exportAsVcard();

private:
    Ui::addressbook *ui;

    void updateInterface(Mode mode);
    QPushButton *editButton;
    QPushButton *removeButton;

    QPushButton *addButton;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QPushButton *nextButton;
    QPushButton *previousButton;

    QPushButton *findButton;
    FindDialog * dialog;

    QPushButton *loadButton;
    QPushButton *saveButton;

    QPushButton *exportButton;

    QLineEdit * nameLine;
    QTextEdit * addressText;

    QMap<QString, QString> contacts;

    QString oldName;
    QString oldAddress;

    Mode currentMode;
};

#endif // ADDRESSBOOK_H
