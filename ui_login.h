/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labellogin;
    QLineEdit *name;
    QLabel *labelpassword;
    QLineEdit *password;
    QLabel *labelempty2;
    QPushButton *pushButton;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(301, 152);
        verticalLayout = new QVBoxLayout(login);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labellogin = new QLabel(login);
        labellogin->setObjectName(QString::fromUtf8("labellogin"));

        verticalLayout->addWidget(labellogin);

        name = new QLineEdit(login);
        name->setObjectName(QString::fromUtf8("name"));

        verticalLayout->addWidget(name);

        labelpassword = new QLabel(login);
        labelpassword->setObjectName(QString::fromUtf8("labelpassword"));

        verticalLayout->addWidget(labelpassword);

        password = new QLineEdit(login);
        password->setObjectName(QString::fromUtf8("password"));
        password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(password);

        labelempty2 = new QLabel(login);
        labelempty2->setObjectName(QString::fromUtf8("labelempty2"));

        verticalLayout->addWidget(labelempty2);

        pushButton = new QPushButton(login);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Form", nullptr));
        labellogin->setText(QCoreApplication::translate("login", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        labelpassword->setText(QCoreApplication::translate("login", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        labelempty2->setText(QString());
        pushButton->setText(QCoreApplication::translate("login", "\320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
