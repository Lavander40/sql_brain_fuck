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
    QPushButton *filterButton;
    QPushButton *buttonCursor;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1041, 609);
        actionconnect_to_database = new QAction(MainWindow);
        actionconnect_to_database->setObjectName(QString::fromUtf8("actionconnect_to_database"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 20, 801, 541));
        tableView->setSortingEnabled(false);
        tableView->horizontalHeader()->setCascadingSectionResizes(false);
        tableView->verticalHeader()->setVisible(false);
        tableChoose = new QComboBox(centralwidget);
        tableChoose->addItem(QString());
        tableChoose->addItem(QString());
        tableChoose->addItem(QString());
        tableChoose->addItem(QString());
        tableChoose->addItem(QString());
        tableChoose->addItem(QString());
        tableChoose->setObjectName(QString::fromUtf8("tableChoose"));
        tableChoose->setGeometry(QRect(830, 20, 201, 22));
        buttonUpdate = new QPushButton(centralwidget);
        buttonUpdate->setObjectName(QString::fromUtf8("buttonUpdate"));
        buttonUpdate->setGeometry(QRect(890, 460, 141, 21));
        buttonInsert = new QPushButton(centralwidget);
        buttonInsert->setObjectName(QString::fromUtf8("buttonInsert"));
        buttonInsert->setGeometry(QRect(890, 420, 141, 21));
        buttonDelete = new QPushButton(centralwidget);
        buttonDelete->setObjectName(QString::fromUtf8("buttonDelete"));
        buttonDelete->setGeometry(QRect(890, 540, 141, 21));
        filterButton = new QPushButton(centralwidget);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));
        filterButton->setGeometry(QRect(829, 50, 201, 21));
        buttonCursor = new QPushButton(centralwidget);
        buttonCursor->setObjectName(QString::fromUtf8("buttonCursor"));
        buttonCursor->setGeometry(QRect(890, 500, 141, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1041, 20));
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
        tableChoose->setItemText(0, QCoreApplication::translate("MainWindow", "\320\236\320\261\321\211\320\260\321\217 \321\204\320\276\321\200\320\274\320\260", nullptr));
        tableChoose->setItemText(1, QCoreApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\276\320\262", nullptr));
        tableChoose->setItemText(2, QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260\321\205", nullptr));
        tableChoose->setItemText(3, QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\273\320\260\321\202\321\213 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260\320\274", nullptr));
        tableChoose->setItemText(4, QCoreApplication::translate("MainWindow", "\320\236\321\202\320\264\320\265\320\273\321\213 \320\277\321\200\320\265\320\264\320\277\321\200\320\270\321\217\321\202\320\270\321\217", nullptr));
        tableChoose->setItemText(5, QCoreApplication::translate("MainWindow", "\320\241\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276\321\201\321\202\320\270", nullptr));

        tableChoose->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        buttonUpdate->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        buttonInsert->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        buttonDelete->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        filterButton->setText(QCoreApplication::translate("MainWindow", "filter", nullptr));
        buttonCursor->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\272\321\203\321\200\321\201\320\276\321\200\320\276\320\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
