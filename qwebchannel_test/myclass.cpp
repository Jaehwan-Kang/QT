#include "myclass.h"

#include <QMessageBox>

MyClass::MyClass(QObject *parent) : QObject(parent)
{
    num = 100;
}

void MyClass::print(QString strMsg)
{
    QMessageBox msg;
    msg.setText(strMsg);
    msg.exec();
}
