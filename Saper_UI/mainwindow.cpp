#include "mainwindow.h"
#include "main_menu.h"
#include "./ui_mainwindow.h"
#include "constants_and_variables.h"
#include "field.h"
#include "check.h"

void MainWindow::fnc()
{
     qDebug() << "Button clicked at row " << '1' << " and column " << '2';
}

MainWindow::MainWindow(QWidget *parent, int length, int width)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    parameters params;
    bools bool_parameters;
    params.length = length;
    params.width = width;
    Field f;
    Check ch;


//    QPushButton* buttons[params.length][params.width];
    xx = new QPushButton**[params.length];

//    ui->horizontalLayout->SetMaximumSize(1000, 20);
    ui->gridLayout_2->setRowStretch(0, 1);
    for (int i = 0; i < params.length; i++)
    {
        xx[i] = new QPushButton*[params.width];
        for (int j = 0; j < params.width; j++)
        {
            xx[i][j] = new QPushButton();
            connect(xx[i][j], SIGNAL(clicked(bool)), this, SLOT(fnc()));
            xx[i][j]->setMinimumSize(45, 45);

            xx[i][j]->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

            ui->gridLayout->addWidget(xx[i][j], i, j);
        }
    }
    int** arr = f.create_field(params);

    for (int i = 0; i < params.length; i++)
    {
        for (int j = 0; j < params.width; j++)
        {
            qDebug() << arr[i][j];
        }
        qDebug() << "\n";
    }

   int** check = ch.arrcheck(params);

    bool_parameters.checker = false, bool_parameters.win = false;
    bool_parameters.lose = false, bool_parameters.mistake = false, bool_parameters.choice = false;
    /*
    qDebug() <<params.length<<" "<<params.width;
    for(int i=0; i< params.length; i++){

        for(int j=0; j<params.width; j++){
            QPushButton* button = new QPushButton();
            buttons[i][j] = button;
            connect(button, &QPushButton::clicked, [i,j](){ qDebug() << "Button clicked at row " << i << " and column " << j; });
            gridLayout->addWidget(button, i, j);
            buttons[i][j]->setFixedSize(45, 45);

        }
    }*/

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
    close();
}

void timer()
{

}

void MainWindow::onButtonClicked()
{
    /*
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    QGridLayout *layout = qobject_cast<QGridLayout *>(button->parentWidget()->layout());
    int row, col, rowSpan, colSpan;
    layout->getItemPosition(layout->indexOf(button), &row, &col, &rowSpan, &colSpan);
    int x = row;
    int y = col;
    qDebug() << "Button clicked at row " << x << ", y " << col;*/



    static bool executed = false;
    if (!executed)
    {
        QTimer* timer = new QTimer(this);
        timer->setInterval(1000); // 1 секунда


        connect(timer, &QTimer::timeout, this, [=]() {

            int currentValue = ui->lcdNumber->value();

            ui->lcdNumber->display(currentValue + 1);
        });

        timer->start();
        executed = true;
    }
}

void MainWindow::on_lcdNumber_2_overflow()
{


}

void MainWindow::on_pushButton_pressed()
{

}

