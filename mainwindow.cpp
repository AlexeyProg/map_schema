#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mp_wid = new MapWidget(":/schema.jpg");
    setCentralWidget(mp_wid);
    generateButtons();
    connect(butCircle, &QPushButton::clicked, mp_wid, &MapWidget::getCircle);
    connect(increase_but, &QPushButton::clicked, mp_wid, &MapWidget::increase_map);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateButtons()
{
    widg = new QWidget(this);
    QVBoxLayout *lay = new QVBoxLayout(widg);
    widg->setFixedSize(QSize(100,300));
    butCircle = new QPushButton(widg);
    butCircle->setText("Circle");

    increase_but = new QPushButton(widg);
    increase_but->setText("+");
    lay->addWidget(butCircle);
    lay->addWidget(increase_but);
}

