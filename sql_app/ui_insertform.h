/********************************************************************************
** Form generated from reading UI file 'insertform.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTFORM_H
#define UI_INSERTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_insertform
{
public:
    QPushButton *pushButton;
    QLabel *tableName;
    QWidget *formLayoutWidget;
    QFormLayout *tableLayout;
    QPushButton *cancelButton;

    void setupUi(QWidget *insertform)
    {
        if (insertform->objectName().isEmpty())
            insertform->setObjectName(QString::fromUtf8("insertform"));
        insertform->resize(482, 462);
        pushButton = new QPushButton(insertform);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 430, 100, 21));
        tableName = new QLabel(insertform);
        tableName->setObjectName(QString::fromUtf8("tableName"));
        tableName->setGeometry(QRect(9, 5, 451, 20));
        formLayoutWidget = new QWidget(insertform);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 30, 461, 391));
        tableLayout = new QFormLayout(formLayoutWidget);
        tableLayout->setObjectName(QString::fromUtf8("tableLayout"));
        tableLayout->setContentsMargins(0, 0, 0, 0);
        cancelButton = new QPushButton(insertform);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(370, 430, 100, 21));

        retranslateUi(insertform);

        QMetaObject::connectSlotsByName(insertform);
    } // setupUi

    void retranslateUi(QWidget *insertform)
    {
        insertform->setWindowTitle(QCoreApplication::translate("insertform", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("insertform", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        tableName->setText(QString());
        cancelButton->setText(QCoreApplication::translate("insertform", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class insertform: public Ui_insertform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTFORM_H
