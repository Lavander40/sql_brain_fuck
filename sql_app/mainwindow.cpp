#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loginWindow = new login();
    insertForm = new insertform();
    insertWin = new insert();
    updateForm = new updateform();

    loginWindow->show();
    connect(this, SIGNAL(sendDataInsert(int)), insertWin, SLOT(recieveData(int)));
    connect(this, SIGNAL(sendDataUpdate(int,int)), updateForm, SLOT(recieveData(int,int)));
    connect(insertWin,SIGNAL(refreshTable(int)),SLOT(refresh(int)));
    connect(loginWindow,SIGNAL(refreshTable(int)),SLOT(refresh(int)));
    connect(updateForm,SIGNAL(refreshTable(int)),SLOT(refresh(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//----------------------------------------------------------

QString currentTableName;
int currentTableID = 1;
int currentRowID = 0;

//----------------------------------------------------------
//tableView

void MainWindow::on_tableChoose_activated(int index)
{
    queryModel = new QSqlQueryModel();
    ui->buttonInsert->setEnabled(true);
    ui->buttonUpdate->setEnabled(true);
    ui->buttonDelete->setEnabled(true);
    ui->tableView->showColumn(0);
    ui->tableView->showColumn(3);
    ui->tableView->showColumn(4);
    ui->tableView->showColumn(5);
    ui->filterButton->hide();
    currentTableID = index;
    switch (index) {
    case 0:
        queryModel->setQuery("SELECT * from PersonnelOverview");
        currentTableName = "employees";
        ui->buttonInsert->setDisabled(true);
        ui->filterButton->show();
        ui->filterButton->setText("Показать многодетных");
        queryModel->setHeaderData(0,Qt::Horizontal,"№ сотр.");
        queryModel->setHeaderData(1,Qt::Horizontal,"Имя");
        queryModel->setHeaderData(2,Qt::Horizontal,"Отчество");
        ui->tableView->hideColumn(3);
        queryModel->setHeaderData(4,Qt::Horizontal,"Отдел");
        ui->tableView->hideColumn(5);
        queryModel->setHeaderData(6,Qt::Horizontal,"Специальность");
        queryModel->setHeaderData(7,Qt::Horizontal,"Выплата");
        queryModel->setHeaderData(8,Qt::Horizontal,"Стаж");
        break;
    case 1:
        queryModel->setQuery("SELECT EmployeeID, FirstName, MiddleName, LastName, Sex, CASE Sex WHEN 0 THEN 'Ж' ELSE 'М' END AS SexName, Age, DepartmentName, SpecialityName FROM employees JOIN departments ON DepartmentID = Department JOIN specialities ON SpecialityID = Speciality");
        currentTableName = "employees";
        ui->tableView->hideColumn(0);
        queryModel->setHeaderData(1,Qt::Horizontal,"Имя");
        queryModel->setHeaderData(2,Qt::Horizontal,"Отчество");
        queryModel->setHeaderData(3,Qt::Horizontal,"Фамилия");
        ui->tableView->hideColumn(4);
        queryModel->setHeaderData(5,Qt::Horizontal,"Пол");
        queryModel->setHeaderData(6,Qt::Horizontal,"Возраст");
        queryModel->setHeaderData(7,Qt::Horizontal,"Отдел");
        queryModel->setHeaderData(8,Qt::Horizontal,"Специальность");

        break;//
    case 2:
        queryModel->setQuery("SELECT EmployeeID, (SELECT LastName FROM employees WHERE employees.EmployeeID = employeeInformation.EmployeeID) AS employee, PhoneNumber, Email, HomeAddress, ChildrenAmount, PassportID, IndividualTaxpayerNumber, LengthOfService FROM employeeInformation");
        currentTableName = "employeeInformation";
        queryModel->setHeaderData(0,Qt::Horizontal,"№");
        queryModel->setHeaderData(1,Qt::Horizontal,"Фамилия\nсотрудника");
        //queryModel->setHeaderData(1,Qt::Horizontal,"Имя");
        //queryModel->setHeaderData(2,Qt::Horizontal,"Отчество");
        queryModel->setHeaderData(2,Qt::Horizontal,"Номер телефона");
        queryModel->setHeaderData(3,Qt::Horizontal,"Электрнная почта");
        queryModel->setHeaderData(4,Qt::Horizontal,"Домашний адрес");
        queryModel->setHeaderData(5,Qt::Horizontal,"Количество детей");
        queryModel->setHeaderData(6,Qt::Horizontal,"№ паспорта");
        queryModel->setHeaderData(7,Qt::Horizontal,"ИНН");
        queryModel->setHeaderData(8,Qt::Horizontal,"Стаж");
        break;
    case 3:
        //SELECT salary.EmployeeID, FirstName, MiddleName, Wage, Premium, Summary FROM salary JOIN employees ON employees.EmployeeID = salary.EmployeeID
        queryModel->setQuery("SELECT EmployeeID, (SELECT LastName FROM employees  WHERE employees.EmployeeID = salary.EmployeeID) AS employee, Wage, Premium, Summary  FROM salary");
        currentTableName = "salary";
        queryModel->setHeaderData(0,Qt::Horizontal,"№");
        queryModel->setHeaderData(1,Qt::Horizontal,"Фамилия\nсотрудника");
        //queryModel->setHeaderData(1,Qt::Horizontal,"Имя");
        //queryModel->setHeaderData(2,Qt::Horizontal,"Отчество");
        queryModel->setHeaderData(2,Qt::Horizontal,"Заработная плата");
        queryModel->setHeaderData(3,Qt::Horizontal,"Премия");
        queryModel->setHeaderData(4,Qt::Horizontal,"Сумма выплат\nс учётом НДФЛ");
        break;//
    case 4:
        queryModel->setQuery("SELECT * FROM departments");
        currentTableName = "departments";
        queryModel->setHeaderData(1,Qt::Horizontal,"Название отдела");
        ui->tableView->hideColumn(0);
        break;//
    case 5:
        queryModel->setQuery("SELECT * FROM specialities");
        currentTableName = "specialities";
        ui->filterButton->show();
        ui->filterButton->setText("Средние выплаты по спец.");
        queryModel->setHeaderData(1,Qt::Horizontal,"Название специальности");
        ui->tableView->hideColumn(0);
        break;
    }
    ui->tableView->setModel(queryModel);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    currentRowID = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toInt();
}

void MainWindow::refresh(int index)
{
    on_tableChoose_activated(index);
}

//----------------------------------------------------------
//insert, update, delete

void MainWindow::on_buttonInsert_clicked()
{
    insertWin->show();
    emit sendDataInsert(ui->tableChoose->currentIndex());
}

void MainWindow::on_buttonUpdate_clicked()
{
    if(currentRowID!=0){
    updateForm->show();
    emit sendDataUpdate(currentTableID,currentRowID);
    }
    else QMessageBox::critical(this,"Ошибка","Выберите строку для изменения");
    refresh(currentTableID);
}

void MainWindow::on_buttonDelete_clicked()
{
    if(currentRowID!=0){
        QSqlQuery query;
        if(query.exec("EXEC " + currentTableName + "DeleteRow @RowID = " + QString::number(currentRowID))) QMessageBox::about(this,"","Запись успешно удалена");
        else {QMessageBox::warning(this,"","exec error");}
    }
    else QMessageBox::critical(this,"Ошибка","Выберите строку для удаления");
    refresh(currentTableID);
}


void MainWindow::on_filterButton_clicked()
{
    queryModel = new QSqlQueryModel();
    ui->filterButton->hide();
    ui->tableView->showColumn(0);
    ui->tableView->showColumn(3);
    ui->tableView->showColumn(4);
    ui->tableView->showColumn(5);
    ui->buttonInsert->setDisabled(true);
    ui->buttonUpdate->setDisabled(true);
    ui->buttonDelete->setDisabled(true);

    switch (currentTableID) {
    case 0:
        queryModel->setQuery("SELECT * FROM PersonnelOverview WHERE EmployeeID IN (SELECT EmployeeID FROM employeeInformation WHERE ChildrenAmount>2)");
        currentTableName = "employees";
        queryModel->setHeaderData(0,Qt::Horizontal,"№ сотр.");
        queryModel->setHeaderData(1,Qt::Horizontal,"Имя");
        queryModel->setHeaderData(2,Qt::Horizontal,"Отчество");
        ui->tableView->hideColumn(3);
        queryModel->setHeaderData(4,Qt::Horizontal,"Отдел");
        ui->tableView->hideColumn(5);
        queryModel->setHeaderData(6,Qt::Horizontal,"Специальность");
        queryModel->setHeaderData(7,Qt::Horizontal,"Выплата");
        queryModel->setHeaderData(8,Qt::Horizontal,"Стаж");
        ui->tableView->setModel(queryModel);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->show();
        break;

    case 5:
        queryModel->setQuery("SELECT SpecialityName, AVG(Summary) AS AvgSalary from employees JOIN salary ON salary.EmployeeID = employees.EmployeeID FULL JOIN specialities ON specialities.SpecialityID = employees.Speciality group by SpecialityName HAVING AVG(Summary) is not null");
        currentTableName = "employees";
        queryModel->setHeaderData(0,Qt::Horizontal,"Специальность");
        queryModel->setHeaderData(1,Qt::Horizontal,"Средняя\nвыплата");
        ui->tableView->setModel(queryModel);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->show();
        break;
    }
}


