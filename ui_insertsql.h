/********************************************************************************
** Form generated from reading UI file 'insertsql.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTSQL_H
#define UI_INSERTSQL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_insertsql
{
public:
    QPushButton *buttonExe;

    void setupUi(QWidget *insertsql)
    {
        if (insertsql->objectName().isEmpty())
            insertsql->setObjectName(QString::fromUtf8("insertsql"));
        insertsql->resize(404, 300);
        buttonExe = new QPushButton(insertsql);
        buttonExe->setObjectName(QString::fromUtf8("buttonExe"));
        buttonExe->setGeometry(QRect(140, 250, 121, 21));

        retranslateUi(insertsql);

        QMetaObject::connectSlotsByName(insertsql);
    } // setupUi

    void retranslateUi(QWidget *insertsql)
    {
        insertsql->setWindowTitle(QCoreApplication::translate("insertsql", "Form", nullptr));
        buttonExe->setText(QCoreApplication::translate("insertsql", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class insertsql: public Ui_insertsql {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTSQL_H
