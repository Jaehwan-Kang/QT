/********************************************************************************
** Form generated from reading UI file 'customwebsite.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMWEBSITE_H
#define UI_CUSTOMWEBSITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customwebsite
{
public:

    void setupUi(QWidget *customwebsite)
    {
        if (customwebsite->objectName().isEmpty())
            customwebsite->setObjectName(QStringLiteral("customwebsite"));
        customwebsite->resize(668, 486);

        retranslateUi(customwebsite);

        QMetaObject::connectSlotsByName(customwebsite);
    } // setupUi

    void retranslateUi(QWidget *customwebsite)
    {
        customwebsite->setWindowTitle(QApplication::translate("customwebsite", "customwebsite", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class customwebsite: public Ui_customwebsite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMWEBSITE_H
