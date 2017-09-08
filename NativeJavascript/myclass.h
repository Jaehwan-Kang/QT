#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT

public:
    MyClass(QObject * parent = 0);
    void print();

    int num;

signals:

public slots:

};

#endif // MYCLASS_H
