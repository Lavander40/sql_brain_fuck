#ifndef CURSOR_H
#define CURSOR_H

#include <QWidget>
#include <QMessageBox>
#include <QVector>
#include <QLineEdit>
#include <QSqlQuery>
#include <QComboBox>

namespace Ui {
class cursor;
}

class cursor : public QWidget
{
    Q_OBJECT

public:
    explicit cursor(QWidget *parent = nullptr);
    ~cursor();

private slots:

    void recieveData(int table);
    void clearWidgets();
    void fill_from(int table, int movement);

    void on_updateButton_clicked();

    void on_prevButton_clicked();

    void on_nextButton_clicked();

    void on_cancelButton_clicked();

signals:

    void refreshTable(int index);

private:

    QList<QLineEdit*> lineEdits;
    QList<QComboBox*> comboBoxes;
    Ui::cursor *ui;
};

#endif // CURSOR_H
