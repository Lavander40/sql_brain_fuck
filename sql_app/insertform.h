#ifndef INSERTFORM_H
#define INSERTFORM_H

#include <QWidget>
#include <QMessageBox>
#include <QVector>
#include <QLineEdit>
#include <QSqlQuery>
#include <QComboBox>

namespace Ui {
class insertform;
}

class insertform : public QWidget
{
    Q_OBJECT

public:
    explicit insertform(QWidget *parent = nullptr);
    ~insertform();
    //QMessageBox* messageBox;
    void inTableInsert(QString tableName);
    //QSqlQuery* query;
private slots:
    void on_pushButton_clicked();
    void recieveData(int index);
    void clearWidgets();
signals:
    void refreshTable();
private:
    Ui::insertform *ui;
    QString *funcName;
    QVector<QLineEdit*> lineEdits;
};

#endif // INSERTFORM_H
