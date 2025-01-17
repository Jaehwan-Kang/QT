#include "addressbook.h"
#include "ui_addressbook.h"

#include <QtWidgets>

addressbook::addressbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addressbook)
{
    ui->setupUi(this);

    QLabel * nameLabel = new QLabel(tr("Name:"));
    nameLine = new QLineEdit;
    nameLine->setReadOnly(true);

    QLabel * addressLabel = new QLabel(tr("Address:"));
    addressText = new QTextEdit;
    addressText->setReadOnly(true);

    addButton = new QPushButton(tr("&Add"));
    submitButton = new QPushButton(tr("&Submit"));
    submitButton->hide();
    cancelButton = new QPushButton(tr("&Cancel"));
    cancelButton->hide();

    nextButton = new QPushButton(tr("&Next"));
    nextButton->setEnabled(false);
    previousButton = new QPushButton(tr("&Previous"));
    previousButton->setEnabled(false);

    editButton = new QPushButton(tr("&Edit"));
    editButton->setEnabled(false);
    removeButton = new QPushButton(tr("&Remove"));
    removeButton->setEnabled(false);

    findButton = new QPushButton(tr("&Find"));
    findButton->setEnabled(false);

    dialog = new FindDialog(this);

    loadButton = new QPushButton(tr("&Load"));
    loadButton->setToolTip(tr("Load contacts from a file"));

    saveButton = new QPushButton(tr("&Save"));
    saveButton->setToolTip(tr("Save contacts to a file"));
    saveButton->setEnabled(false);

    exportButton = new QPushButton(tr("&Export"));
    exportButton->setToolTip(tr("Export as vCard"));
    exportButton->setEnabled(false);

    connect(addButton, SIGNAL(clicked()), this, SLOT(addContact()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submitContact()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(nextButton, SIGNAL(clicked()), this, SLOT(next()));
    connect(previousButton, SIGNAL(clicked()), this, SLOT(previous()));
    connect(editButton, SIGNAL(clicked()), this, SLOT(editContact()));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeContact()));
    connect(findButton, SIGNAL(clicked()), this, SLOT(findContact()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveToFile()));
    connect(loadButton, SIGNAL(clicked()), this, SLOT(loadFromFile()));
    connect(exportButton, SIGNAL(clicked()), this, SLOT(exportAsVcard()));

    QVBoxLayout * buttonLayout1 = new QVBoxLayout;
    buttonLayout1->addWidget(addButton, Qt::AlignTop);
    buttonLayout1->addWidget(submitButton);
    buttonLayout1->addWidget(cancelButton);
    buttonLayout1->addWidget(editButton);
    buttonLayout1->addWidget(removeButton);
    buttonLayout1->addWidget(findButton);
    buttonLayout1->addWidget(saveButton);
    buttonLayout1->addWidget(loadButton);
    buttonLayout1->addWidget(exportButton);
    buttonLayout1->addStretch();

    QHBoxLayout * buttonLayout2 = new QHBoxLayout;
    buttonLayout2->addWidget(previousButton);
    buttonLayout2->addWidget(nextButton);

    QGridLayout * mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel, 0, 0);
    mainLayout->addWidget(nameLine, 0, 1);
    mainLayout->addWidget(addressLabel, 1, 0, Qt::AlignTop);
    mainLayout->addWidget(addressText, 1, 1);

    mainLayout->addLayout(buttonLayout1, 1, 2);
    mainLayout->addLayout(buttonLayout2, 2, 1);

    setLayout(mainLayout);
    setWindowTitle(tr("Simple Address Book"));


}

void addressbook::addContact()
{
    oldName = nameLine->text();
    oldAddress = addressText->toPlainText();

    nameLine->clear();
    addressText->clear();

    updateInterface(AddingMode);
}

void addressbook::submitContact()
{
    QString name = nameLine->text();
    QString address = addressText->toPlainText();

    if(name.isEmpty() || address.isEmpty())
    {
        QMessageBox::information(this, tr("Empty Field"),
                tr("Please enter a name and address."));
        return;
    }

    if(currentMode == AddingMode)
    {
        if(!contacts.contains(name))
        {
            contacts.insert(name, address);
            QMessageBox::information(this, tr("Add Successful"), tr("\"%1\" has been added to your address book.").arg(name));
        }
        else
        {
            QMessageBox::information(this, tr("Add Unsuccessful"), tr("Sorry, \"%1\" is already in your address book.").arg(name));
            return;
        }

    }
    else if(currentMode == EditingMode)
    {
        if(oldName != name)
        {
            if(!contacts.contains(name))
            {
                QMessageBox::information(this, tr("Edit Successful"),tr("\"%1\" has been edited in your address book.").arg(oldName));
                contacts.remove(oldName);
                contacts.insert(name, address);
            } else {
                QMessageBox::information(this, tr("Edit Unsuccessful"), tr("Sorry, \"%1\" is already in your adress book.").arg(name));
            }
        } else if(oldAddress != address)
        {
            QMessageBox::information(this, tr("Edit Sucessful"), tr("\"%1\" has been edited in your address book.").arg(name));
            contacts[name] = address;
        }

    }

    updateInterface(NavigationMode);

}


void addressbook::cancel()
{
    nameLine->setText(oldName);
    nameLine->setReadOnly(true);

    updateInterface(NavigationMode);
}

void addressbook::next()
{
    QString name = nameLine->text();
    QMap<QString, QString>::iterator i = contacts.find(name);

    if(i != contacts.end())
        i++;

    if(i == contacts.end())
        i = contacts.begin();

    nameLine->setText(i.key());
    addressText->setText(i.value());
}

void addressbook::previous()
{
    QString name = nameLine->text();
    QMap<QString, QString>::iterator i = contacts.find(name);

    if(i == contacts.end())
    {
        nameLine->clear();
        addressText->clear();
        return;
    }

    if(i == contacts.begin())
        i = contacts.end();

    i--;
    nameLine->setText(i.key());
    addressText->setText(i.value());

}

void addressbook::editContact()
{
    oldName = nameLine->text();
    oldAddress = addressText->toPlainText();

    updateInterface(EditingMode);
}

void addressbook::removeContact()
{
    QString name = nameLine->text();
    QString address = addressText->toPlainText();

    if(contacts.contains(name))
    {
        int button = QMessageBox::question(this, tr("Confirm Remove"), tr("Are you sure you want to remove \"%1\"?").arg(name), QMessageBox::Yes | QMessageBox::No);
        if(button == QMessageBox::Yes)
        {
            previous();
            contacts.remove(name);

            QMessageBox::information(this, tr("Remove Successful."), tr("\"%1\" has been removed from your address book.").arg(name));
        }
    }

    updateInterface(NavigationMode);
}

void addressbook::findContact()
{
    dialog->show();

    if(dialog->exec() == QDialog::Accepted)
    {
        QString contactName = dialog->getFindText();

        if(contacts.contains(contactName))
        {
            nameLine->setText(contactName);
            addressText->setText(contacts.value(contactName));
        }
        else
        {
            QMessageBox::information(this, tr("Contact Not Found"),
                                     tr("Sorry, \"%1\" is not in your address book.").arg(contactName));
            return;
        }
    }

    updateInterface(NavigationMode);
}

void addressbook::updateInterface(Mode mode)
{
    currentMode = mode;

    switch(currentMode)
    {
    case AddingMode:
    case EditingMode:
        nameLine->setReadOnly(false);
        nameLine->setFocus(Qt::OtherFocusReason);
        addressText->setReadOnly(false);

        addButton->setEnabled(false);
        editButton->setEnabled(false);
        removeButton->setEnabled(false);

        nextButton->setEnabled(false);
        previousButton->setEnabled(false);

        submitButton->show();
        cancelButton->show();

        saveButton->setEnabled(false);
        loadButton->setEnabled(false);
        exportButton->setEnabled(false);
        break;

    case NavigationMode:
        if(contacts.isEmpty())
        {
            nameLine->clear();
            addressText->clear();
        }

        nameLine->setReadOnly(true);
        addressText->setReadOnly(true);
        addButton->setEnabled(true);

        int number = contacts.size();
        editButton->setEnabled(number >= 1);
        removeButton->setEnabled(number >= 1);
        nextButton->setEnabled(number > 1);
        previousButton->setEnabled(number > 1);
        findButton->setEnabled(number > 2);


        submitButton->hide();
        cancelButton->hide();

        loadButton->setEnabled(true);
        saveButton->setEnabled(number >= 1);

        exportButton->setEnabled(number >= 1);
        break;

    }
}

void addressbook::saveToFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Address Book"), "",
                                                    tr("Address Book (*.abk);;All Files (*)"));
    if(fileName.isEmpty())
        return;
    else
    {
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());

            return;
        }

        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_5);
        out << contacts;
    }

}

void addressbook::loadFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Address Book"),
                                                    tr("Address Book (*.abk);;All Files"));
    if(fileName.isEmpty())
    {
        return;
    }
    else
    {
        QFile file(fileName);

        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);
        contacts.clear();
        in >> contacts;

        if(contacts.isEmpty())
        {
            QMessageBox::information(this, tr("No contacts in file"),
                                     tr("The file you are attempting to open contains no contacts."));
        }
        else
        {
            QMap<QString, QString>::iterator i = contacts.begin();
            nameLine->setText(i.key());
            addressText->setText(i.value());
        }
    }

    updateInterface(NavigationMode);
}

void addressbook::exportAsVcard()
{
    QString name = nameLine->text();
    QString address = addressText->toPlainText();
    QString firstName;
    QString lastName;
    QStringList nameList;

    int index = name.indexOf(" ");

    if(index != -1)
    {
        nameList = name.split(QRegularExpression("\\s+"), QString::SkipEmptyParts);
        firstName = nameList.first();
        lastName = nameList.last();
    }
    else
    {
        firstName = name;
        lastName = "";
    }

    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Export Contact"), "",
                                                    tr("vCard Files (*.vcf);;All Files (*)"));

    if(fileName.isEmpty())
        return;

    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }

    QTextStream out(&file);

    out << "BEGIN:VCARD" << '\n';
    out << "VERSION:2.1" << '\n';
    out << "N:" << lastName << ';' << firstName << '\n';

    if(!nameList.isEmpty())
        out << "FN: " << nameList.join(' ') << '\n';
    else
        out << "FN: " << firstName << '\n';

    address.replace(";", "\\;", Qt::CaseInsensitive);
    address.replace("\n", ";", Qt::CaseInsensitive);
    address.replace(",", " ", Qt::CaseInsensitive);

    out << "ADR;HOME:;" << address << '\n';
    out << "END:VCARD" << '\n';

    QMessageBox::information(this, tr("Export Successful"),
                         tr("\"%1\" has been expoted as a vCard").arg(name));

}

addressbook::~addressbook()
{
    delete ui;
}
