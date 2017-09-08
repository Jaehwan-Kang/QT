#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyWebEngineView * view = new MyWebEngineView(this);
    view->setGeometry(200, 200, 500, 500);
    view->load(QUrl::fromLocalFile(QFileInfo(BUILD_DIR "/index.html").absoluteFilePath()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
