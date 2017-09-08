#include "mywebengineview.h"

MyWebEngineView::MyWebEngineView(QWidget * parent) : QWebEngineView(parent)
{
    QWebChannel * channel = new QWebChannel(page());
    channel->registerObject(QStringLiteral("jshelper"), &helper);
    load(QUrl("http://121.78.175.236:808"));
    page()->setWebChannel(channel);
}
