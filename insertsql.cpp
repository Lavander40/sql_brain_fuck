#include "insertsql.h"
#include "ui_insertsql.h"

insertsql::insertsql(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::insertsql)
{
    ui->setupUi(this);
}

insertsql::~insertsql()
{
    delete ui;
}

void insertsql::on_buttonExe_clicked()
{

}

