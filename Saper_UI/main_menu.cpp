#include "main_menu.h"
#include "ui_main_menu.h"
#include "constants_and_variables.h"
//#include "field.h"



Main_menu::Main_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main_menu)
{
    ui->setupUi(this);
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(common()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(common()));
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(common()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(common()));


}

Main_menu::~Main_menu()
{
    delete ui;
}

void Main_menu::common()
{
    int length = sender()->property("blength").value<int>();
    int width = sender()->property("bwidth").value<int>();
    //close();
    MainWindow* wind = new MainWindow(this, length, width);
    wind->show();

}

