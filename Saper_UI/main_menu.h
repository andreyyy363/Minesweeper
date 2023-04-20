#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QMainWindow>

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
    void on_label_linkActivated(const QString &link);

private:
    Ui::Main_menu *ui;
};

#endif // MAIN_MENU_H
