#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 8; i++)
    {
        xx[i] = new QPushButton*[8];
        for (int j = 0; j < 8; j++)
        {
            xx[i][j] = new QPushButton();
            ui->verticalLayout->addWidget(xx[i][j]);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    champ.show();
}


void MainWindow::on_actionExit_2_triggered()
{

}

