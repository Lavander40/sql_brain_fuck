/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionconnect_to_database;
    QWidget *centralwidget;
    QTableView *tableView;
    QComboBox *tableChoose;
    QPushButton *buttonUpdate;
    QPushButton *buttonInsert;
    QPushButton *buttonDelete;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1008, 635);
        actionconnect_to_database = new QAction(MainWindow);
        actionconnect_to_database->setObjectName(QString::fromUtf8("actionconnect_to_database"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 20, 761, 571));
        tableView->setSortingEnabled(false);
        tableView->horizontalHeader()->setCascadingSectionResizes(false);
        tableView->verticalHeader()->setVisible(false);
        tableChoose = new QComboBox(centralwidget);
        tableChoose->addItem(QString());
        tableChoose->addItem(QString());
        tableChoose->addItem(QString());
        tableChoose->addItem(QString());
        tableChoose->addItem(QString());
        tableChoose->setObjectName(QString::fromUtf8("tableChoose"));
        tableChoose->setGeometry(QRect(790, 20, 211, 22));
        buttonUpdate = new QPushButton(centralwidget);
        buttonUpdate->setObjectName(QString::fromUtf8("buttonUpdate"));
        buttonUpdate->setGeometry(QRect(840, 520, 141, 21));
        buttonInsert = new QPushButton(centralwidget);
        buttonInsert->setObjectName(QString::fromUtf8("buttonInsert"));
        buttonInsert->setGeometry(QRect(840, 480, 141, 21));
        buttonDelete = new QPushButton(centralwidget);
        buttonDelete->setObjectName(QString::fromUtf8("buttonDelete"));
        buttonDelete->setGeometry(QRect(840, 560, 141, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1008, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionconnect_to_database->setText(QCoreApplication::translate("MainWindow", "connect to database", nullptr));
        tableChoose->setItemText(0, QCoreApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\276\320\262", nullptr));
        tableChoose->setItemText(1, QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260\321\205", nullptr));
        tableChoose->setItemText(2, QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\273\320\260\321\202\321\213 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260\320\274", nullptr));
        tableChoose->setItemText(3, QCoreApplication::translate("MainWindow", "\320\236\321\202\320\264\320\265\320\273\321\213 \320\277\321\200\320\265\320\264\320\277\321\200\320\270\321\217\321\202\320\270\321\217", nullptr));
        tableChoose->setItemText(4, QCoreApplication::translate("MainWindow", "\320\241\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276\321\201\321\202\320\270", nullptr));

        tableChoose->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        buttonUpdate->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        buttonInsert->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        buttonDelete->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
