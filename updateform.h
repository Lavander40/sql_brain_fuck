#ifndef UPDATEFORM_H
#define UPDATEFORM_H

#include <QWidget>
#include <QMessageBox>
#include <QVector>
#include <QLineEdit>
#include <QSqlQuery>
#include <QComboBox>

namespace Ui {
class updateform;
}

class updateform : public QWidget
{
    Q_OBJECT

public:
    explicit updateform(QWidget *parent = nullptr);
    ~updateform();

private slots:

    void recieveData(int table, int row);
    void clearWidgets();
    void on_updateButton_clicked();

signals:

    void refreshTable(int index);

private:

    QList<QLineEdit*> lineEdits;
    QList<QComboBox*> comboBoxes;
    Ui::updateform *ui;
};

#endif // UPDATEFORM_H
