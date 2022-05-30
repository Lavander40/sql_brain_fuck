/********************************************************************************
** Form generated from reading UI file 'updateform.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEFORM_H
#define UI_UPDATEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_updateform
{
public:
    QLabel *tableLabel;
    QPushButton *updateButton;
    QPushButton *cancelButton;
    QWidget *formLayoutWidget;
    QFormLayout *tableLayout;

    void setupUi(QWidget *updateform)
    {
        if (updateform->objectName().isEmpty())
            updateform->setObjectName(QString::fromUtf8("updateform"));
        updateform->resize(512, 522);
        tableLabel = new QLabel(updateform);
        tableLabel->setObjectName(QString::fromUtf8("tableLabel"));
        tableLabel->setGeometry(QRect(10, 10, 641, 21));
        updateButton = new QPushButton(updateform);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setGeometry(QRect(10, 490, 191, 21));
        cancelButton = new QPushButton(updateform);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(420, 490, 80, 21));
        formLayoutWidget = new QWidget(updateform);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 30, 491, 431));
        tableLayout = new QFormLayout(formLayoutWidget);
        tableLayout->setObjectName(QString::fromUtf8("tableLayout"));
        tableLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(updateform);

        QMetaObject::connectSlotsByName(updateform);
    } // setupUi

    void retranslateUi(QWidget *updateform)
    {
        updateform->setWindowTitle(QCoreApplication::translate("updateform", "Form", nullptr));
        tableLabel->setText(QString());
        updateButton->setText(QCoreApplication::translate("updateform", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        cancelButton->setText(QCoreApplication::translate("updateform", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class updateform: public Ui_updateform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEFORM_H
