#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&tim,SIGNAL(timeout()),this,SLOT(onTimOut()));
    tim.start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onTimOut()
{
    ui->label_frq_1->setText(QString::number(g->fre[0]));
    ui->label_frq_2->setText(QString::number(g->fre[1]));
    ui->label_pow_1->setText(QString::number(g->pow[0]));
    ui->label_pow_2->setText(QString::number(g->pow[1]));
    ui->label_tfu_1->setText(QString::number(g->tfu[0]));
    ui->label_tfu_2->setText(QString::number(g->tfu[1]));
    if(g->isWorking)
    {
        setStyleSheet("");
    }
    else
    {
        setStyleSheet("color: rgb(255, 0, 0);");
    }
}
