/********************************************************************************
** Form generated from reading UI file 'cursor.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURSOR_H
#define UI_CURSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cursor
{
public:
    QPushButton *prevButton;
    QPushButton *nextButton;
    QPushButton *updateButton;
    QPushButton *cancelButton;
    QWidget *formLayoutWidget;
    QFormLayout *tableLayout;
    QLabel *tableLabel;

    void setupUi(QWidget *cursor)
    {
        if (cursor->objectName().isEmpty())
            cursor->setObjectName(QString::fromUtf8("cursor"));
        cursor->resize(471, 551);
        prevButton = new QPushButton(cursor);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));
        prevButton->setGeometry(QRect(10, 10, 51, 21));
        nextButton = new QPushButton(cursor);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(410, 10, 51, 21));
        updateButton = new QPushButton(cursor);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setGeometry(QRect(10, 520, 151, 21));
        cancelButton = new QPushButton(cursor);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(380, 520, 80, 21));
        formLayoutWidget = new QWidget(cursor);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 40, 451, 461));
        tableLayout = new QFormLayout(formLayoutWidget);
        tableLayout->setObjectName(QString::fromUtf8("tableLayout"));
        tableLayout->setContentsMargins(0, 0, 0, 0);
        tableLabel = new QLabel(cursor);
        tableLabel->setObjectName(QString::fromUtf8("tableLabel"));
        tableLabel->setGeometry(QRect(70, 7, 331, 21));
        QFont font;
        font.setBold(true);
        tableLabel->setFont(font);
        tableLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(cursor);

        QMetaObject::connectSlotsByName(cursor);
    } // setupUi

    void retranslateUi(QWidget *cursor)
    {
        cursor->setWindowTitle(QCoreApplication::translate("cursor", "Form", nullptr));
        prevButton->setText(QCoreApplication::translate("cursor", "<", nullptr));
        nextButton->setText(QCoreApplication::translate("cursor", ">", nullptr));
        updateButton->setText(QCoreApplication::translate("cursor", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265", nullptr));
        cancelButton->setText(QCoreApplication::translate("cursor", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        tableLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cursor: public Ui_cursor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURSOR_H
