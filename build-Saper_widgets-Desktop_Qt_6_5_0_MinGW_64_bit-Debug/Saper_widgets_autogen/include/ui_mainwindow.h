/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Game;
    QAction *actionStart;
    QAction *actionRules;
    QAction *actionAbout_Game;
    QAction *actionAmateur;
    QAction *actionProfessional;
    QAction *actionCustom;
    QAction *action_hampions;
    QAction *actionExit;
    QAction *actionThemes;
    QAction *actionExit_2;
    QAction *actionSounds;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QMenuBar *menubar;
    QMenu *menu123;
    QMenu *menuFAQ;
    QMenu *menuView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(475, 436);
        MainWindow->setMinimumSize(QSize(475, 436));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/icons/Game_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName("actionNew_Game");
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName("actionStart");
        actionRules = new QAction(MainWindow);
        actionRules->setObjectName("actionRules");
        actionAbout_Game = new QAction(MainWindow);
        actionAbout_Game->setObjectName("actionAbout_Game");
        actionAmateur = new QAction(MainWindow);
        actionAmateur->setObjectName("actionAmateur");
        actionProfessional = new QAction(MainWindow);
        actionProfessional->setObjectName("actionProfessional");
        actionCustom = new QAction(MainWindow);
        actionCustom->setObjectName("actionCustom");
        action_hampions = new QAction(MainWindow);
        action_hampions->setObjectName("action_hampions");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionThemes = new QAction(MainWindow);
        actionThemes->setObjectName("actionThemes");
        actionExit_2 = new QAction(MainWindow);
        actionExit_2->setObjectName("actionExit_2");
        actionSounds = new QAction(MainWindow);
        actionSounds->setObjectName("actionSounds");
        actionSounds->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(210, 50, 62, 56));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/icons/happy1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(50, 50));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(70, 60, 64, 23));
        lcdNumber_2 = new QLCDNumber(centralwidget);
        lcdNumber_2->setObjectName("lcdNumber_2");
        lcdNumber_2->setGeometry(QRect(330, 60, 64, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 475, 21));
        menu123 = new QMenu(menubar);
        menu123->setObjectName("menu123");
        menuFAQ = new QMenu(menubar);
        menuFAQ->setObjectName("menuFAQ");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu123->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuFAQ->menuAction());
        menu123->addSeparator();
        menu123->addAction(actionNew_Game);
        menu123->addSeparator();
        menu123->addAction(actionStart);
        menu123->addAction(actionAmateur);
        menu123->addAction(actionProfessional);
        menu123->addAction(actionCustom);
        menu123->addAction(action_hampions);
        menu123->addSeparator();
        menu123->addAction(actionExit);
        menu123->addSeparator();
        menu123->addAction(actionExit_2);
        menuFAQ->addAction(actionRules);
        menuFAQ->addSeparator();
        menuFAQ->addAction(actionAbout_Game);
        menuView->addAction(actionThemes);
        menuView->addSeparator();
        menuView->addAction(actionSounds);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Saper", nullptr));
        actionNew_Game->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
#if QT_CONFIG(shortcut)
        actionNew_Game->setShortcut(QCoreApplication::translate("MainWindow", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStart->setText(QCoreApplication::translate("MainWindow", "Classic (8x8)", nullptr));
        actionRules->setText(QCoreApplication::translate("MainWindow", "Rules", nullptr));
        actionAbout_Game->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionAmateur->setText(QCoreApplication::translate("MainWindow", "Easy (9x9)", nullptr));
        actionProfessional->setText(QCoreApplication::translate("MainWindow", "Medium (16x16)", nullptr));
        actionCustom->setText(QCoreApplication::translate("MainWindow", "Hard (30x16)", nullptr));
        action_hampions->setText(QCoreApplication::translate("MainWindow", "Custom...", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Champions", nullptr));
        actionThemes->setText(QCoreApplication::translate("MainWindow", "Themes...", nullptr));
        actionExit_2->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionSounds->setText(QCoreApplication::translate("MainWindow", "Sounds", nullptr));
        pushButton->setText(QString());
        menu123->setTitle(QCoreApplication::translate("MainWindow", "Game", nullptr));
        menuFAQ->setTitle(QCoreApplication::translate("MainWindow", "FAQ", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
