#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    //this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::WindowSystemMenuHint);
    this->setWindowModality(Qt::ApplicationModal);

//    QCompleter* completerAddr = new QCompleter(addresses,this);
//    QCompleter* completerDB = new QCompleter(databases,this);
//    completerAddr->setCaseSensitivity(Qt::CaseInsensitive);
//    completerDB->setCaseSensitivity(Qt::CaseInsensitive);
//    ui->dbaddress->setCompleter(completerAddr);
//    ui->dbname->setCompleter(completerDB);

    ui->name->setText("HeadAdmin");
    ui->password->setText("admin2020");
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    if((ui->name->text().isEmpty())||(ui->password->text().isEmpty())){
        if(QMessageBox::critical(this,"Ошибка","Не все поля заполнены,<br>повторите ввод данных",QMessageBox::Cancel | QMessageBox::Ok)==QMessageBox::Cancel)
            QApplication::quit();
    }else{
        db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("DRIVER={SQL Server};SERVER=DESKTOP-G2VLRFB\\SQLEXPRESS;DATABASE=PersonnelDepartment;");
        db.setUserName(ui->name->text());
        db.setPassword(ui->password->text());

        if(db.open()) {
            QMessageBox::about(this,"","Соединение с базой данных установлено!");
            emit refreshTable(0);
            emit refreshTable(0);
            this->close();
        }
        else
            if(QMessageBox::critical(this,"Ошибка","Соединение не установлено,<br>проверте правильность введённых данных",QMessageBox::Cancel | QMessageBox::Ok)==QMessageBox::Cancel)
                QApplication::quit();
    }
}

