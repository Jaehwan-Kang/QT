#include "widget.h"
#include "ui_widget.h"

#include "config.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QWebEngineView * view = new QWebEngineView;
    QNetworkRequest request = QNetworkRequest();
    request.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache);
    request.setUrl(QUrl(DAUM));


//    view->load(request);
//    view->show();



//    view->load(QUrl("http://www.daum.net"));
//    view->show();
}

void Widget::on_pushButton_2_clicked()
{

}


//QNetworkRequest  request = QNetworkRequest();
//request.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache);
//request.setUrl(QUrl(URL_TOP100));
//m_webview.load(request);
