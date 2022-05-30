#ifndef INSERT_H
#define INSERT_H

#include <QWidget>
#include <QSqlQuery>
#include <QMessageBox>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>

namespace Ui {
class insert;
}

class insert : public QWidget
{
    Q_OBJECT

public:
    explicit insert(QWidget *parent = nullptr);
    ~insert();

private slots:
    void recieveData(int index);
    void clearWidgets();
    void on_pushButton_clicked();

signals:
    void refreshTable(int index);

private:
    QList<QLineEdit*> lineEdits;
    QList<QComboBox*> comboBoxes;
    Ui::insert *ui;
};

#endif // INSERT_H
