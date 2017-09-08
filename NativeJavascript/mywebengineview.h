#ifndef MYWEBENGINEVIEW_H
#define MYWEBENGINEVIEW_H

#include <QWebEngineView>

#include "myclass.h"

class MyWebEngineView : public QWebEngineView
{
public:
    MyWebEngineView(QWidget * parent);
    MyClass helper;

};

#endif // MYWEBENGINEVIEW_H
