/********************************************************************************
** Form generated from reading UI file 'champions.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAMPIONS_H
#define UI_CHAMPIONS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Champions
{
public:
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Champions)
    {
        if (Champions->objectName().isEmpty())
            Champions->setObjectName("Champions");
        Champions->resize(391, 463);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/icons/Champions.png"), QSize(), QIcon::Normal, QIcon::Off);
        Champions->setWindowIcon(icon);
        listWidget = new QListWidget(Champions);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(60, 130, 256, 192));
        pushButton = new QPushButton(Champions);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 380, 101, 24));
        pushButton_2 = new QPushButton(Champions);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 380, 101, 24));

        retranslateUi(Champions);

        QMetaObject::connectSlotsByName(Champions);
    } // setupUi

    void retranslateUi(QWidget *Champions)
    {
        Champions->setWindowTitle(QCoreApplication::translate("Champions", "Champions", nullptr));
        pushButton->setText(QCoreApplication::translate("Champions", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Champions", "Clear all rezults", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Champions: public Ui_Champions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAMPIONS_H
