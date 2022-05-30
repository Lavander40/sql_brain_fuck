#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>
#include <QCompleter>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    //QMessageBox* messageBox;
private slots:
    void on_pushButton_clicked();
signals:
    void refreshTable(int index);
private:
    Ui::login *ui;
    QSqlDatabase db;
};

#endif // LOGIN_H
