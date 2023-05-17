#ifndef CHAMPIONS_H
#define CHAMPIONS_H

#include <QDialog>

namespace Ui {
class champions;
}

class champions : public QDialog
{
    Q_OBJECT

public:
    explicit champions(QWidget *parent = nullptr);
    ~champions();

private:
    Ui::champions *ui;
};

#endif // CHAMPIONS_H
