#include "addressbook.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    addressbook addbook;
    addbook.show();

    return app.exec();
}
