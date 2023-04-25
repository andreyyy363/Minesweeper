#include "main_menu.h"
#include "ui_main_menu.h"

Main_menu::Main_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main_menu)
{
    ui->setupUi(this);
}

Main_menu::~Main_menu()
{
    delete ui;
}



void Main_menu::on_pushButton_4_clicked()
{
    wind.show();
}


void Main_menu::on_pushButton_8_clicked()
{
    champ.show();
}

