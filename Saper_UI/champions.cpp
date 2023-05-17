#include "champions.h"
#include "ui_champions.h"

champions::champions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::champions)
{
    ui->setupUi(this);
}

champions::~champions()
{
    delete ui;
}
