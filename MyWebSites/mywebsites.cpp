#include "mywebsites.h"
#include "ui_mywebsites.h"

#include <QtWidgets>

MyWebSites::MyWebSites(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWebSites)
{
    ui->setupUi(this);

    firstButton = new QPushButton(tr("&다음"));
    secondButton = new QPushButton(tr("&Destiny2"));

    connect(firstButton, SIGNAL(clicked()), this, SLOT(firstSiteButton()));
    connect(secondButton, SIGNAL(clicked()), this, SLOT(secondSiteButton()));

    QVBoxLayout * siteLayout = new QVBoxLayout;
    siteLayout->addWidget(firstButton, Qt::AlignTop);
    siteLayout->addWidget(secondButton);
    siteLayout->addStretch();

    QGridLayout * mainLayout = new QGridLayout;


    mainLayout->addLayout(siteLayout, 0, 0);


    setLayout(mainLayout);
    setWindowTitle(tr("My Favorite Web Sites"));
}

MyWebSites::~MyWebSites()
{
    delete ui;
}

void MyWebSites::firstSiteButton()
{

}

void MyWebSites::secondSiteButton()
{

}
