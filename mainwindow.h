#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "login.h"
#include "ui_login.h"
#include "insert.h"
#include "ui_insert.h"
#include "updateform.h"
#include "ui_updateform.h"
#include "update.h"
#include "ui_update.h"
#include "cursor.h"
#include "ui_cursor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    login* loginWindow;
    insert* insertWin;
    updateform* updateForm;
    class cursor* cursorWin;

signals:
    void sendDataInsert(int index);

    void sendDataUpdate(int tableIndex, int rowIndex);

    void sendDataCursor(int index);

private slots:

    void on_tableChoose_activated(int index);

    void on_buttonInsert_clicked();

    void refresh(int index);

    void on_buttonUpdate_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_buttonDelete_clicked();

    void on_filterButton_clicked();

    void on_buttonCursor_clicked();

private:
    Ui::MainWindow *ui;
    //QSqlTableModel* tableModel;
    QSqlQueryModel* queryModel;
};
#endif // MAINWINDOW_H
