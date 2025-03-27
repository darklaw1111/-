/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actOpenDB;
    QAction *actQuit;
    QAction *actRecInsert;
    QAction *actRecDelete;
    QAction *actRecEdit;
    QAction *actSQLtest;
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(982, 538);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(10);
        MainWindow->setFont(font);
        actOpenDB = new QAction(MainWindow);
        actOpenDB->setObjectName(QString::fromUtf8("actOpenDB"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/open3.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actOpenDB->setIcon(icon);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font1.setPointSize(10);
        font1.setUnderline(true);
        actOpenDB->setFont(font1);
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon1);
        actQuit->setFont(font1);
        actRecInsert = new QAction(MainWindow);
        actRecInsert->setObjectName(QString::fromUtf8("actRecInsert"));
        actRecInsert->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/306.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actRecInsert->setIcon(icon2);
        actRecInsert->setFont(font1);
        actRecDelete = new QAction(MainWindow);
        actRecDelete->setObjectName(QString::fromUtf8("actRecDelete"));
        actRecDelete->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/delete1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actRecDelete->setIcon(icon3);
        actRecDelete->setFont(font1);
        actRecEdit = new QAction(MainWindow);
        actRecEdit->setObjectName(QString::fromUtf8("actRecEdit"));
        actRecEdit->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/812.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actRecEdit->setIcon(icon4);
        actRecEdit->setFont(font1);
        actSQLtest = new QAction(MainWindow);
        actSQLtest->setObjectName(QString::fromUtf8("actSQLtest"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/322.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSQLtest->setIcon(icon5);
        actSQLtest->setFont(font1);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/00.JPG"), QSize(), QIcon::Selected, QIcon::On);
        action->setIcon(icon6);
        action->setFont(font1);
        action->setMenuRole(QAction::NoRole);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_2->setIcon(icon);
        action_2->setMenuRole(QAction::TextHeuristicRole);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/704.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_3->setIcon(icon7);
        action_3->setMenuRole(QAction::TextHeuristicRole);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/706.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_4->setIcon(icon8);
        action_4->setMenuRole(QAction::TextHeuristicRole);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 160, 541, 214));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(211, 249, 248);"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setDefaultSectionSize(75);

        horizontalLayout->addWidget(tableView);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setFont(font1);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(actOpenDB);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_2);
        mainToolBar->addAction(action_3);
        mainToolBar->addAction(action_4);
        mainToolBar->addAction(actRecInsert);
        mainToolBar->addAction(actRecEdit);
        mainToolBar->addAction(actRecDelete);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action);
        mainToolBar->addAction(actQuit);

        retranslateUi(MainWindow);
        QObject::connect(actQuit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        actOpenDB->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\350\257\276\347\250\213\344\277\241\346\201\257", nullptr));
#if QT_CONFIG(tooltip)
        actOpenDB->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\225\260\346\215\256", nullptr));
#endif // QT_CONFIG(tooltip)
        actQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actQuit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
        actRecInsert->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\257\276\347\250\213", nullptr));
#if QT_CONFIG(tooltip)
        actRecInsert->setToolTip(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\350\256\260\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        actRecDelete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\257\276\347\250\213", nullptr));
#if QT_CONFIG(tooltip)
        actRecDelete->setToolTip(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\256\260\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        actRecEdit->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\350\257\276\347\250\213", nullptr));
#if QT_CONFIG(tooltip)
        actRecEdit->setToolTip(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\350\256\260\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        actSQLtest->setText(QCoreApplication::translate("MainWindow", "SQL\346\265\213\350\257\225", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
#if QT_CONFIG(tooltip)
        action->setToolTip(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245\347\274\226\345\217\267\346\237\245\346\211\276\345\257\271\345\272\224\345\255\246\345\217\267", nullptr));
#endif // QT_CONFIG(tooltip)
        action_2->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\345\255\246\347\224\237\344\277\241\346\201\257", nullptr));
#if QT_CONFIG(tooltip)
        action_2->setToolTip(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\344\277\241\346\201\257", nullptr));
#endif // QT_CONFIG(tooltip)
        action_3->setText(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\351\200\211\350\257\276", nullptr));
#if QT_CONFIG(tooltip)
        action_3->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\211\350\257\276", nullptr));
#endif // QT_CONFIG(tooltip)
        action_4->setText(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\351\200\200\350\257\276", nullptr));
#if QT_CONFIG(tooltip)
        action_4->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\350\257\276", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
