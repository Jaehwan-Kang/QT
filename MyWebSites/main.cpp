#include "mywebsites.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWebSites w;
    w.show();

    return a.exec();
}
