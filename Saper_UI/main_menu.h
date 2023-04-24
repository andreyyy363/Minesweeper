#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QMainWindow>
#include "champions.h"
#include "mainwindow.h"

namespace Ui {
class Main_menu;
}

class Main_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main_menu(QWidget *parent = nullptr);
    ~Main_menu();

private slots:

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Main_menu *ui;
    Champions champ;
    MainWindow wind;
};

#endif // MAIN_MENU_H
