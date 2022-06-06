#ifndef UPDATE_H
#define UPDATE_H

#include <QWidget>
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <QLineEdit>
#include <QComboBox>

namespace Ui {
class update;
}

class update : public QWidget
{
    Q_OBJECT

public:
    explicit update(QWidget *parent = nullptr);
    ~update();
private slots:
    void recieveData(int table,int row);
private:
    Ui::update *ui;
};

#endif // UPDATE_H
