#ifndef MYWEBSITES_H
#define MYWEBSITES_H

#include <QWidget>

class QPushButton;
class QLabel;

namespace Ui {
class MyWebSites;
}

class MyWebSites : public QWidget
{
    Q_OBJECT

public:
    explicit MyWebSites(QWidget *parent = 0);
    ~MyWebSites();

private:
    Ui::MyWebSites *ui;

    QPushButton *firstButton;
    QPushButton *secondButton;

public slots:
    void firstSiteButton();
    void secondSiteButton();

};

#endif // MYWEBSITES_H
