#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWebEngineView>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_frame_objectNameChanged(const QString &objectName);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
