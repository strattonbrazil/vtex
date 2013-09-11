#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString srcImage(":/images/vtex.jpg");
    ui->sourceDisplay->setImage(srcImage);
    ui->previewDisplay->setImage(srcImage);
}

MainWindow::~MainWindow()
{
    delete ui;
}
