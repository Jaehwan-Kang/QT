#include "customwebsite.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    customwebsite w;
    w.show();

    return a.exec();
}
