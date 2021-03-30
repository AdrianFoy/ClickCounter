#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    button(nullptr),
    clickCounter(0)
{
    button = new QPushButton("Click me!");

    connect(button, SIGNAL(clicked(bool)), this, SLOT(countClick()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(button);

    QWidget *mainWidget = new QWidget(this);
    mainWidget->setLayout(mainLayout);

    setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::countClick()
{
    button->setText("Clicks: " + QString::number(++clickCounter));
}
