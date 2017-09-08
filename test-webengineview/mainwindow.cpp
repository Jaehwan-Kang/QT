#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWebEngineView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QWebEngineView * view = new QWebEngineView(parent);
    view->load(QUrl("http://www.daum.net"));
    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
