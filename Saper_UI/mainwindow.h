#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include "champions.h"
#include "main_menu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr, int length = 8, int width = 8);

    ~MainWindow();

private slots:


    void on_actionExit_triggered();
    void fnc();


    void on_actionExit_2_triggered();

    void onButtonClicked();

    void on_lcdNumber_2_overflow();

    void on_pushButton_pressed();

private:
    Ui::MainWindow *ui;
    champions champ;
    QPushButton *buttons[64];
    QPushButton*** xx;
};
#endif // MAINWINDOW_H

