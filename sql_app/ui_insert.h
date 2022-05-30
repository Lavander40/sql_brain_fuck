/********************************************************************************
** Form generated from reading UI file 'insert.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERT_H
#define UI_INSERT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_insert
{
public:
    QPushButton *pushButton;
    QPushButton *cancelButton;
    QLabel *tableLabel;
    QWidget *formLayoutWidget;
    QFormLayout *tableLayout;

    void setupUi(QWidget *insert)
    {
        if (insert->objectName().isEmpty())
            insert->setObjectName(QString::fromUtf8("insert"));
        insert->resize(502, 553);
        pushButton = new QPushButton(insert);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 520, 111, 21));
        cancelButton = new QPushButton(insert);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(379, 520, 111, 21));
        tableLabel = new QLabel(insert);
        tableLabel->setObjectName(QString::fromUtf8("tableLabel"));
        tableLabel->setGeometry(QRect(10, 5, 481, 21));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        tableLabel->setFont(font);
        formLayoutWidget = new QWidget(insert);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 30, 481, 461));
        tableLayout = new QFormLayout(formLayoutWidget);
        tableLayout->setObjectName(QString::fromUtf8("tableLayout"));
        tableLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(insert);

        QMetaObject::connectSlotsByName(insert);
    } // setupUi

    void retranslateUi(QWidget *insert)
    {
        insert->setWindowTitle(QCoreApplication::translate("insert", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("insert", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        cancelButton->setText(QCoreApplication::translate("insert", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        tableLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class insert: public Ui_insert {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERT_H
