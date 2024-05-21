#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QMainWindow>
#include "champions.h"
#include "mainwindow.h"
#include "rules.h"
#include "constants_and_variables.h"



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

    void common();

private:
    Ui::Main_menu *ui;

    champions champ;
    rules rule;
};

#endif // MAIN_MENU_H
