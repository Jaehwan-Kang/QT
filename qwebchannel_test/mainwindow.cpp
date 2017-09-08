#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "myclass.h"
#include "mywebengineview.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyWebEngineView * view = new MyWebEngineView(this);
    view->setGeometry(0, 0, 400, 400);
    view->load(QUrl("http://121.78.175.236:808"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
