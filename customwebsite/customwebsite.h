#ifndef CUSTOMWEBSITE_H
#define CUSTOMWEBSITE_H

#include <QWidget>
#include <QWebEngineView>
#include <QWebEnginePage>

class QPushButton;
class QLabel;
class QGroupBox;
class QGridLayout;

namespace Ui {
class customwebsite;
}

class customwebsite : public QWidget
{
    Q_OBJECT

public:
    explicit customwebsite(QWidget *parent = 0);
    ~customwebsite();

    void createSitebox();
    void daumConnect();

private:
    Ui::customwebsite *ui;

    QPushButton *daumButton;
    QPushButton *destinyButton;
    QPushButton *humanButton;
    QPushButton *gmailButton;

    QPushButton *closeButton;

    QGroupBox * sitebox;
    QGridLayout * websiteLayout;

public slots:
    void daumView();
    void destinyConnect();
    void humanConnect();
    void gmailConnect();

};

#endif // CUSTOMWEBSITE_H
