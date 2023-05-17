#include "mainwindow.h"
#include "main_menu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow wind;
    Main_menu menu;

    menu.show();

    return a.exec();
}
