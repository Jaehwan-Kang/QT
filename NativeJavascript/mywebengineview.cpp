#include "mywebengineview.h"
#include <QWebChannel>
#include <QFileInfo>

MyWebEngineView::MyWebEngineView(QWidget *parent): QWebEngineView(parent)
{
    QWebChannel * channel = new QWebChannel(page());
    channel->registerObject(QStringLiteral("jshelper"), &helper);
    load(QUrl::fromLocalFile(QFileInfo(BUILD_DIR "/index.html").absoluteFilePath()));
    page()->setWebChannel(channel);
}
