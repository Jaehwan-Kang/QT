#include "myclass.h"
#include <QMessageBox>

MyClass::MyClass(QObject *parent) : QObject(parent)
{
    num = 100;
}

void MyClass::print()
{
    QMessageBox msg;
    msg.exec();
}
