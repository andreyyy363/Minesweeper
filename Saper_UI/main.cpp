#include "mainwindow.h"
#include "main_menu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Main_menu h;
    w.show();
    h.show();



    return a.exec();
}
