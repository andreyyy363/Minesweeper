#include "champions.h"
#include "ui_champions.h"

Champions::Champions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Champions)
{
    ui->setupUi(this);
}

Champions::~Champions()
{
    delete ui;
}


/*void Champions::on_pushButton_clicked()
{
    Champions::close();
}
*/

void Champions::on_pushButton_clicked()
{
    close();
}

