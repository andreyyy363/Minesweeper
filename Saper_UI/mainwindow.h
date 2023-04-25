#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "champions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionExit_triggered();

    void on_actionExit_2_triggered();

private:
    Ui::MainWindow *ui;
    Champions champ;
    QPushButton*** xx = new QPushButton**[8];
};
#endif // MAINWINDOW_H

