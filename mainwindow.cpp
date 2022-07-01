#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loginWindow = new login();
    insertWin = new insert();
    updateForm = new updateform();
    cursorWin = new class cursor();

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    loginWindow->show();
    connect(this, SIGNAL(sendDataInsert(int)), insertWin, SLOT(recieveData(int)));
    connect(this, SIGNAL(sendDataUpdate(int,int)), updateForm, SLOT(recieveData(int,int)));
    connect(this, SIGNAL(sendDataCursor(int)), cursorWin, SLOT(recieveData(int)));
    connect(insertWin,SIGNAL(refreshTable(int)),SLOT(refresh(int)));
    connect(loginWindow,SIGNAL(refreshTable(int)),SLOT(refresh(int)));
    connect(updateForm,SIGNAL(refreshTable(int)),SLOT(refresh(int)));
    connect(cursorWin,SIGNAL(refreshTable(int)),SLOT(refresh(int)));

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
    QSqlQuery query;

    ui->tableView->showColumn(0);
    ui->tableView->showColumn(3);
    ui->tableView->showColumn(4);
    ui->tableView->showColumn(5);
    ui->buttonInsert->setEnabled(true);
    ui->buttonUpdate->setEnabled(true);
    ui->buttonDelete->setEnabled(true);
    ui->buttonCursor->setEnabled(true);
    ui->filterButton->hide();
    ui->employeeAll->hide();
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
        queryModel->setHeaderData(4,Qt::Horizontal,"Отдел");
        queryModel->setHeaderData(6,Qt::Horizontal,"Специальность");
        queryModel->setHeaderData(7,Qt::Horizontal,"Выплата");
        queryModel->setHeaderData(8,Qt::Horizontal,"Стаж");
        ui->tableView->hideColumn(3);
        ui->tableView->hideColumn(5);
        break;
    case 1:
        queryModel->setQuery("SELECT EmployeeID, FirstName, MiddleName, LastName, CASE Sex WHEN 0 THEN 'Ж' ELSE 'М' END AS SexName, Age, DepartmentName, SpecialityName FROM employees JOIN departments ON DepartmentID = Department JOIN specialities ON SpecialityID = Speciality");
        currentTableName = "employees";
        ui->filterButton->show();
        ui->filterButton->setText("Показать ФИО работников из IT");
        queryModel->setHeaderData(1,Qt::Horizontal,"Имя");
        queryModel->setHeaderData(2,Qt::Horizontal,"Отчество");
        queryModel->setHeaderData(3,Qt::Horizontal,"Фамилия");
        queryModel->setHeaderData(4,Qt::Horizontal,"Пол");
        queryModel->setHeaderData(5,Qt::Horizontal,"Возраст");
        queryModel->setHeaderData(6,Qt::Horizontal,"Отдел");
        queryModel->setHeaderData(7,Qt::Horizontal,"Специальность");
        ui->tableView->hideColumn(0);
        break;
    case 2:
        queryModel->setQuery("SELECT EmployeeID, (SELECT LastName FROM employees WHERE employees.EmployeeID = employeeInformation.EmployeeID) AS employee, PhoneNumber, Email, HomeAddress, ChildrenAmount, PassportID, IndividualTaxpayerNumber, LengthOfService FROM employeeInformation");
        currentTableName = "employeeInformation";
        queryModel->setHeaderData(0,Qt::Horizontal,"№");
        queryModel->setHeaderData(1,Qt::Horizontal,"Фамилия\nсотрудника");
        queryModel->setHeaderData(2,Qt::Horizontal,"Номер телефона");
        queryModel->setHeaderData(3,Qt::Horizontal,"Электрнная почта");
        queryModel->setHeaderData(4,Qt::Horizontal,"Домашний адрес");
        queryModel->setHeaderData(5,Qt::Horizontal,"Количество детей");
        queryModel->setHeaderData(6,Qt::Horizontal,"№ паспорта");
        queryModel->setHeaderData(7,Qt::Horizontal,"ИНН");
        queryModel->setHeaderData(8,Qt::Horizontal,"Стаж");
        break;
    case 3:
        queryModel->setQuery("SELECT EmployeeID, (SELECT LastName FROM employees  WHERE employees.EmployeeID = salary.EmployeeID) AS employee, Wage, Premium, Summary  FROM salary");
        currentTableName = "salary";
        ui->filterButton->show();
        ui->employeeAll->show();
        ui->filterButton->setText("Процент выплат от общей");
        queryModel->setHeaderData(0,Qt::Horizontal,"№");
        queryModel->setHeaderData(1,Qt::Horizontal,"Фамилия\nсотрудника");
        queryModel->setHeaderData(2,Qt::Horizontal,"Заработная плата");
        queryModel->setHeaderData(3,Qt::Horizontal,"Премия");
        queryModel->setHeaderData(4,Qt::Horizontal,"Сумма выплат\nс учётом НДФЛ");
        query.exec("SELECT FirstName, MiddleName FROM employees, salary WHERE employees.EmployeeID = salary.EmployeeID AND Summary >= ALL (Select Summary from salary)");
        query.next();
        ui->employeeAll->setText(query.value("FirstName").toString() + " " + query.value("MiddleName").toString() + "<br> - самый оплачиваемый<br>работник предприятия");
        break;
    case 4:
        queryModel->setQuery("SELECT DepartmentID, DepartmentName, (SELECT COUNT(*) FROM employees WHERE DepartmentID = Department) AS EmpCount FROM departments");
        currentTableName = "departments";
        ui->filterButton->show();
        ui->filterButton->setText("Отделы с сред. возр. выше средн.");
        queryModel->setHeaderData(1,Qt::Horizontal,"Название отдела");
        queryModel->setHeaderData(2,Qt::Horizontal,"Количество\nработников");
        ui->tableView->hideColumn(0);
        break;
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

void MainWindow::on_buttonCursor_clicked()
{
    cursorWin->show();
    emit sendDataCursor(ui->tableChoose->currentIndex());
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
    ui->employeeAll->hide();
    ui->tableView->showColumn(0);
    ui->tableView->showColumn(3);
    ui->tableView->showColumn(4);
    ui->tableView->showColumn(5);
    ui->buttonInsert->setDisabled(true);
    ui->buttonUpdate->setDisabled(true);
    ui->buttonDelete->setDisabled(true);
    ui->buttonCursor->setDisabled(true);

    switch (currentTableID) {
    case 0:
        queryModel->setQuery("SELECT * FROM PersonnelOverview WHERE EmployeeID IN (SELECT EmployeeID FROM employeeInformation WHERE ChildrenAmount>2)");
        queryModel->setHeaderData(0,Qt::Horizontal,"№ сотр.");
        queryModel->setHeaderData(1,Qt::Horizontal,"Имя");
        queryModel->setHeaderData(7,Qt::Horizontal,"Фамилия");
        queryModel->setHeaderData(8,Qt::Horizontal,"Стаж");
        queryModel->setHeaderData(2,Qt::Horizontal,"Отчество");
        ui->tableView->hideColumn(3);
        queryModel->setHeaderData(4,Qt::Horizontal,"Отдел");
        ui->tableView->hideColumn(5);
        queryModel->setHeaderData(6,Qt::Horizontal,"Специальность");
        break;
    case 1:
        queryModel->setQuery("SELECT FirstName, MiddleName, LastName FROM employees WHERE Department = ANY (SELECT DepartmentID FROM departments WHERE DepartmentName LIKE '%IT%')");
        queryModel->setHeaderData(1,Qt::Horizontal,"Имя");
        queryModel->setHeaderData(2,Qt::Horizontal,"Отчество");
        queryModel->setHeaderData(3,Qt::Horizontal,"Фамилия");
        break;
    case 3:
        queryModel->setQuery("SELECT * FROM dbo.PercentSalary()");
        queryModel->setHeaderData(0,Qt::Horizontal,"Имя");
        queryModel->setHeaderData(1,Qt::Horizontal,"Отчество");
        queryModel->setHeaderData(2,Qt::Horizontal,"Процент");
        break;
    case 4:
        queryModel->setQuery("SELECT DepartmentName, AVG(Age) AS AvgAge FROM (SELECT DepartmentName, Age FROM departments,employees WHERE Department = DepartmentID) AS employee GROUP BY DepartmentName HAVING Avg(Age)>(SELECT avg(age) FROM employees)");
        queryModel->setHeaderData(0,Qt::Horizontal,"Отдел");
        queryModel->setHeaderData(1,Qt::Horizontal,"Средний\nвозраст");
        break;
    case 5:
        queryModel->setQuery("SELECT SpecialityName, AVG(Summary) AS AvgSalary from employees JOIN salary ON salary.EmployeeID = employees.EmployeeID FULL JOIN specialities ON specialities.SpecialityID = employees.Speciality group by SpecialityName HAVING AVG(Summary) is not null");
        queryModel->setHeaderData(0,Qt::Horizontal,"Специальность");
        queryModel->setHeaderData(1,Qt::Horizontal,"Средняя\nвыплата");
        break;
    }
    ui->tableView->setModel(queryModel);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


