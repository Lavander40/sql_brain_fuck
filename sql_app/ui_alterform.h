/********************************************************************************
** Form generated from reading UI file 'alterform.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALTERFORM_H
#define UI_ALTERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_alterform
{
public:

    void setupUi(QWidget *alterform)
    {
        if (alterform->objectName().isEmpty())
            alterform->setObjectName(QString::fromUtf8("alterform"));
        alterform->resize(400, 300);

        retranslateUi(alterform);

        QMetaObject::connectSlotsByName(alterform);
    } // setupUi

    void retranslateUi(QWidget *alterform)
    {
        alterform->setWindowTitle(QCoreApplication::translate("alterform", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class alterform: public Ui_alterform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALTERFORM_H
