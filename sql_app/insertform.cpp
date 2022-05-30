#include "insertform.h"
#include "ui_insertform.h"

insertform::insertform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::insertform)
{
    ui->setupUi(this);
    //messageBox = new QMessageBox();
    funcName = new QString();
    lineEdits = *new QVector<QLineEdit*>();
    this->setWindowFlags(Qt::WindowSystemMenuHint);
    this->setWindowFlags(Qt::WindowTitleHint);
    this->setWindowModality(Qt::ApplicationModal);
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(clearWidgets()));
}

insertform::~insertform()
{
    delete ui;
}

void insertform::recieveData(int index)
{
    switch (index) {
    case 1:
        ui->tableName->setText("Таблица сотрудников");
        inTableInsert("employees");
        *funcName = "AddEmployees";
        break;
    case 2:
        ui->tableName->setText("Информация о сотрудниках");
        inTableInsert("employeeinformation");
        *funcName = "AddEmployeeInfo";
        break;
    case 3:
        ui->tableName->setText("Выплаты сотрудникам");
        inTableInsert("salary");
        *funcName = "AddSalary";
        break;
    case 4:
        ui->tableName->setText("Отделы предприятия");
        inTableInsert("departments");
        *funcName = "AddDepartments";
        break;
    case 5:
        ui->tableName->setText("Специальности");
        inTableInsert("specialities");
        *funcName = "AddSpecialities";
        break;
    default:
        QMessageBox::critical(this,"","choose table");
        this->close();
        break;
    }
}

void insertform::clearWidgets(){
    while (QLayoutItem* item = ui->tableLayout->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    close();
}

void insertform::inTableInsert(QString tableName){
    QSqlQuery queryCol, queryKey; //query = new QSqlQuery();
    QString foreighKeys="";

    QString sqlQueryCol = "SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '" + tableName + "'";
    queryCol.exec(sqlQueryCol);

    QString sqlQueryKey = "SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE WHERE CONSTRAINT_NAME LIKE 'FK_%' AND TABLE_NAME = '" + tableName + "'";
    queryKey.exec(sqlQueryKey);

    while(queryKey.next()) {
        foreighKeys = foreighKeys + queryKey.value("COLUMN_NAME").toString();
    }

    if((tableName=="departments")||(tableName=="specialities")||(tableName=="employees")) queryCol.next();
    while(queryCol.next()){
        QString colName = queryCol.value("COLUMN_NAME").toString();

        QLabel *label = new QLabel(this);
        label->setObjectName("label" + colName);
        label->setText("@" + colName);
        ui->tableLayout->addWidget(label);

        if(foreighKeys.indexOf(colName)>=0){//проверка на FK
            QComboBox *chooseForeignValue = new QComboBox();

            QSqlQuery getForeignValue;
            QString sqlQueryGetValue = "SELECT столбец_значения_которого_нужны FROM таблица_к_которой_идёт_ключ";
            getForeignValue.exec(sqlQueryGetValue);

            chooseForeignValue->setObjectName(colName);
            while(getForeignValue.next()) {
                 chooseForeignValue->addItem(getForeignValue.value("DepartmentID").toString());
            }
            ui->tableLayout->addWidget(chooseForeignValue);
        }else{
            QLineEdit *lineEdit = new QLineEdit();
            lineEdit->setObjectName(colName);
            lineEdit->setMaxLength(40);
            ui->tableLayout->addWidget(lineEdit);
            lineEdits.push_back(lineEdit);
        }
    }
}

void insertform::on_pushButton_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    QString sqlQuery ="EXEC " + *funcName;
    foreach(QLineEdit* line,lineEdits){
        if(true)//проверка на дурака (дурак я)
        sqlQuery = sqlQuery + " @" + line->objectName() + " = '" + line->text() + "',";
    }
    sqlQuery.resize(sqlQuery.length()-1);
    //query->prepare(sqlQuery);

    if(query->exec(sqlQuery)) QMessageBox::about(this,"yes, ",sqlQuery);
    else {QMessageBox::warning(this,"","no, " + sqlQuery);}

    emit refreshTable();//НЕ РАБОТАЕТ, ПОЧИНИТЬ!!!

    clearWidgets();
}

