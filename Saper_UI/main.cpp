#include "mainwindow.h"
#include "main_menu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow wind;
    Main_menu menu;
/*
    // Создание кнопок
    QPushButton* buttons[12];
    for(int i = 0; i < 12; i++) {
        buttons[i] = new QPushButton(QString("Button %1").arg(i+1));
    }

    // Установка размеров кнопок
    for(int i = 0; i < 12; i++) {
        buttons[i]->setFixedSize(100, 100);
    }

    // Добавление кнопок в Grid Layout
    QGridLayout* gridLayout = ui->gridLayout; // ui - это указатель на объект Ui::MainWindow, созданный Qt Designer
    int row = 0, col = 0;
    for(int i = 0; i < 12; i++) {
        gridLayout->addWidget(buttons[i], row, col);
        col++;
        if(col == 3) {
            col = 0;
            row++;
        }
    }*/
    //wind.show();
    menu.show();

    return a.exec();
}
