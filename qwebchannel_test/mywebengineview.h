#ifndef MYWEBENGINEVIEW_H
#define MYWEBENGINEVIEW_H

#include <QWebEngineView>
#include <QWebChannel>
#include "myclass.h"
#include <QFileInfo>

class MyWebEngineView : public QWebEngineView
{
public:
    MyWebEngineView(QWidget * parent);

    MyClass helper;
};

#endif // MYWEBENGINEVIEW_H
