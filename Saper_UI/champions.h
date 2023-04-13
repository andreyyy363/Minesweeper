#ifndef CHAMPIONS_H
#define CHAMPIONS_H

#include <QWidget>

namespace Ui {
class Champions;
}

class Champions : public QWidget
{
    Q_OBJECT

public:
    explicit Champions(QWidget *parent = nullptr);
    ~Champions();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Champions *ui;
};

#endif // CHAMPIONS_H
