#include "dialog.h"
#include "ui_dialog.h"

#include <QtWidgets>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
//    ui(new Ui::Dialog)
{
//    ui->setupUi(this);


    createRotableGroupBox();
    createOptionsGroupBox();
    createButtonBox();

    mainLayout = new QGridLayout;
    mainLayout->addWidget(rotableGroupBox, 0, 0);
    mainLayout->addWidget(optionsGroupBox, 1, 0);
    mainLayout->addWidget(buttonBox, 2, 0);

    setLayout(mainLayout);
    mainLayout->setSizeConstraint(QLayout::SetMinimumSize);

    setWindowTitle(tr("Dynamic Layouts"));
}

//Dialog::~Dialog()
//{
//    delete ui;
//}

void Dialog::buttonOrientationChanged(int index)
{
    mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
    setMinimumSize(0, 0);

    Qt::Orientation orientation = Qt::Orientation(buttonsOrientationComboBox->itemData(index).toInt());

    if(orientation == buttonBox->orientation())
    {
        return;
    }

    mainLayout->removeWidget(buttonBox);

    int spacing = mainLayout->spacing();

    QSize oldSizeHint = buttonBox->sizeHint() + QSize(spacing, spacing);
    buttonBox->setOrientation(orientation);
    QSize newSizeHint = buttonBox->sizeHint() + QSize(spacing, spacing);

    if(orientation == Qt::Horizontal)
    {
        mainLayout->addWidget(buttonBox, 2, 0);
        resize(size() + QSize(-oldSizeHint.width(), newSizeHint.height()));
    }
    else
    {
        mainLayout->addWidget(buttonBox, 0, 3, 2, 1);
        resize(size() + QSize(newSizeHint.width(), -oldSizeHint.height()));
    }

    mainLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
}

void Dialog::rotateWidgets()
{
    Q_ASSERT(rotableWidgets.count() % 2 == 0);

    foreach (QWidget *widget, rotableWidgets)
        rotableLayout->removeWidget(widget);

    rotableWidgets.enqueue(rotableWidgets.dequeue());

    const int n = rotableWidgets.count();
    for(int i=0; i<n /2; ++i)
    {
        rotableLayout->addWidget(rotableWidgets[n-i-1], 0, i);
        rotableLayout->addWidget(rotableWidgets[i], 1, i);
    }
}

void Dialog::help()
{
    QMessageBox::information(this, tr("Dynamic Layouts Help"),
                             tr("This example shows how to change layouts "
                                "dynamically"));
}


void Dialog::createRotableGroupBox()
{
    rotableGroupBox = new QGroupBox(tr("Rotable Widgets"));
    rotableWidgets.enqueue(new QSpinBox);
    rotableWidgets.enqueue(new QSlider);
    rotableWidgets.enqueue(new QDial);
    rotableWidgets.enqueue(new QProgressBar);

    int n = rotableWidgets.count();
    for(int i=0; i<n; ++i)
    {
        connect(rotableWidgets[i], SIGNAL(valueChanged(int)),
                rotableWidgets[(i + 1) % n], SLOT(setValue(int)));
    }

    rotableLayout = new QGridLayout;
    rotableGroupBox->setLayout(rotableLayout);

    rotateWidgets();

}


void Dialog::createOptionsGroupBox()
{
    optionsGroupBox = new QGroupBox(tr("Options"));

//    buttonsOrientationLabel = new QLabel(tr("Orientation of buttons: "));
//    buttonsOrientationComboBox = new QComboBox;
//    buttonsOrientationComboBox->addItem(tr("Horizontal"), Qt::Horizontal);
//    buttonsOrientationComboBox->addItem(tr("Vertical"), Qt::Vertical);

//    connect(buttonsOrientationComboBox, SIGNAL(currentIndexChanged(int)),
//            this, SLOT(buttonOrientationChanged(int)));

    optionsLayout = new QGridLayout;
//    optionsLayout->addWidget(buttonsOrientationLabel, 0, 0);
//    optionsLayout->addWidget(buttonsOrientationComboBox, 0, 1);
//    optionsLayout->setColumnStretch(2, 1);
    optionsGroupBox->setLayout(optionsLayout);
}

void Dialog::createButtonBox()
{
    buttonBox = new QDialogButtonBox;

    closeButton = buttonBox->addButton(QDialogButtonBox::Close);
    helpButton = buttonBox->addButton(QDialogButtonBox::Help);
    rotateWidgetsButton = buttonBox->addButton(tr("Rotate &Widgets"), QDialogButtonBox::AcceptRole);

    connect(rotateWidgetsButton, SIGNAL(clicked()), this, SLOT(rotateWidgets()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(helpButton, SIGNAL(clicked()), this, SLOT(help()));

}
