#ifndef INSERTSQL_H
#define INSERTSQL_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class insertsql;
}

class insertsql : public QWidget
{
    Q_OBJECT

public:
    explicit insertsql(QWidget *parent = nullptr);
    ~insertsql();

private slots:
    void on_buttonExe_clicked();

private:
    Ui::insertsql *ui;
};

#endif // INSERTSQL_H
