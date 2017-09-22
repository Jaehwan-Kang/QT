#include "customwebsite.h"
#include "ui_customwebsite.h"

#include <QtWidgets>


#include <config.h>

customwebsite::customwebsite(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customwebsite)
{
    ui->setupUi(this);


    // button make
    daumButton = new QPushButton(tr("&DAUM"));
    destinyButton = new QPushButton(tr("&Destiny2"));
    humanButton = new QPushButton(tr("&Human"));
    gmailButton = new QPushButton(tr("&Gmail"));
    closeButton = new QPushButton(tr("&CLOSE"));

    // signal==slot
    connect(daumButton, SIGNAL(clicked()), this, SLOT(daumView()));
    connect(destinyButton, SIGNAL(clicked()), this, SLOT(destinyConnect()));
    connect(humanButton, SIGNAL(clicked(bool)), this, SLOT(humanConnect()));
    connect(gmailButton, SIGNAL(clicked(bool)), this, SLOT(gmailConnect()));
    connect(closeButton, SIGNAL(clicked(bool)), this, SLOT(close()));

    QVBoxLayout * menuLayout = new QVBoxLayout;
    menuLayout->addWidget(daumButton, Qt::AlignTop);
    menuLayout->addWidget(destinyButton);
    menuLayout->addWidget(humanButton);
    menuLayout->addWidget(gmailButton);
    menuLayout->addWidget(closeButton);

    menuLayout->addStretch();

    QGridLayout * mainLayout = new QGridLayout;

    mainLayout->addLayout(menuLayout, 0, 0, Qt::AlignLeft);

    createSitebox();

    mainLayout->addWidget(sitebox, 0, 1);

    setLayout(mainLayout);
    setWindowTitle(tr("My Favorite Web Sites"));
}

customwebsite::~customwebsite()
{
    delete ui;
}

void customwebsite::daumConnect()
{
    QWebEngineView * view = new QWebEngineView;
    view->load(QUrl(DAUM));
    view->show();
}

void customwebsite::destinyConnect()
{
    QWebEngineView * view = new QWebEngineView;
    view->load(QUrl(DESTINY));
    view->show();
}

void customwebsite::humanConnect()
{
    QWebEngineView * view = new QWebEngineView;
    view->load(QUrl(HUMAN));
    view->show();
}

void customwebsite::gmailConnect()
{
    QWebEngineView * view = new QWebEngineView;
    view->load(QUrl(GMAIL));
    view->show();
}

void customwebsite::createSitebox()
{
    sitebox = new QGroupBox(tr("WEB PAGE"));
    websiteLayout = new QGridLayout;

    sitebox->setLayout(websiteLayout);
}

void customwebsite::daumView()
{
    daumConnect();
}
