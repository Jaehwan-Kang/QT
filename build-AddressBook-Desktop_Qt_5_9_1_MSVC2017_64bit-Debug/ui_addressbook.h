/********************************************************************************
** Form generated from reading UI file 'addressbook.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRESSBOOK_H
#define UI_ADDRESSBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addressbook
{
public:

    void setupUi(QWidget *addressbook)
    {
        if (addressbook->objectName().isEmpty())
            addressbook->setObjectName(QStringLiteral("addressbook"));
        addressbook->resize(448, 370);

        retranslateUi(addressbook);

        QMetaObject::connectSlotsByName(addressbook);
    } // setupUi

    void retranslateUi(QWidget *addressbook)
    {
        addressbook->setWindowTitle(QApplication::translate("addressbook", "addressbook", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addressbook: public Ui_addressbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESSBOOK_H
