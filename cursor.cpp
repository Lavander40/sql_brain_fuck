#include "cursor.h"
#include "ui_cursor.h"

cursor::cursor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cursor)
{
    ui->setupUi(this);
    lineEdits = *new QList<QLineEdit*>();
    comboBoxes = *new QList<QComboBox*>();
    this->setWindowFlags(Qt::WindowSystemMenuHint);
    this->setWindowModality(Qt::ApplicationModal);
}

cursor::~cursor()
{
    delete ui;
}

int currentTableCur;
int currentRowCur;
int tableSize;
int currentCurIndex;
QString curName;
QString tableName;

void cursor::recieveData(int table)
{
    QSqlQuery query;
    QSqlQuery size;

    currentTableCur = table;
    currentCurIndex = 1;
    switch (table) {
    case 0 :
    {
        curName = "viewCur";
        tableName="PersonnelOverview";

        QLabel *FirstNameLable = new QLabel();
        QLabel *MiddleNameLable = new QLabel();
        QLabel *DepartmentLable = new QLabel();
        QLabel *SpecialityLable = new QLabel();
        QLabel *LengthOfServiceLable = new QLabel();

        QLineEdit *FirstName = new QLineEdit();
        QLineEdit *MiddleName = new QLineEdit();
        QLineEdit *LengthOfService = new QLineEdit();

        QComboBox *Department = new QComboBox();
        QComboBox *Speciality = new QComboBox();

        FirstNameLable->setObjectName("FirstNameLable");
        MiddleNameLable->setObjectName("MiddleNameLable");
        DepartmentLable->setObjectName("DepartmentLable");
        SpecialityLable->setObjectName("SpecialityLable");
        LengthOfServiceLable->setObjectName("LengthOfServiceLable");


        FirstNameLable->setText("Имя");
        MiddleNameLable->setText("Отчество");
        DepartmentLable->setText("Отдел");
        SpecialityLable->setText("Специальность");
        LengthOfServiceLable->setText("Стаж");


        FirstName->setObjectName("FirstName");
        MiddleName->setObjectName("MiddleName");
        Department->setObjectName("Department");
        Speciality->setObjectName("Speciality");
        LengthOfService->setObjectName("LengthOfService");

        QSqlQuery departments;
        departments.exec("SELECT * FROM departments");
        while(departments.next()){
            Department->addItem(departments.value("DepartmentID").toString() + ". " + departments.value("DepartmentName").toString());
        }
        QSqlQuery specialities;
        specialities.exec("SELECT * FROM specialities");
        while(specialities.next()){
            Speciality->addItem(specialities.value("SpecialityID").toString() + ". " + specialities.value("SpecialityName").toString());
        }

        ui->tableLabel->setText("Изменение информации через общую форму");
        ui->tableLayout->addWidget(FirstNameLable);
        ui->tableLayout->addWidget(FirstName);
        ui->tableLayout->addWidget(MiddleNameLable);
        ui->tableLayout->addWidget(MiddleName);
        ui->tableLayout->addWidget(DepartmentLable);
        ui->tableLayout->addWidget(Department);
        ui->tableLayout->addWidget(SpecialityLable);
        ui->tableLayout->addWidget(Speciality);
        ui->tableLayout->addWidget(LengthOfServiceLable);
        ui->tableLayout->addWidget(LengthOfService);

        Department->setMaxVisibleItems(5);
        Speciality->setMaxVisibleItems(5);

        lineEdits.append(FirstName);
        lineEdits.append(MiddleName);
        lineEdits.append(LengthOfService);

        comboBoxes.append(Department);
        comboBoxes.append(Speciality);
        query.exec("DECLARE viewCur CURSOR SCROLL FOR SELECT * FROM PersonnelOverview OPEN viewCur");
        break;
    }
    case 1:
    {
        curName="employeesCur";
        tableName="employees";

        QLabel *FirstNameLable = new QLabel();
        QLabel *MiddleNameLable = new QLabel();
        QLabel *LastNameLable = new QLabel();
        QLabel *SexLable = new QLabel();
        QLabel *AgeLable = new QLabel();
        QLabel *DepartmentLable = new QLabel();
        QLabel *SpecialityLable = new QLabel();

        QLineEdit *FirstName = new QLineEdit();
        QLineEdit *MiddleName = new QLineEdit();
        QLineEdit *LastName = new QLineEdit();
        QLineEdit *Age = new QLineEdit();

        QComboBox *Sex = new QComboBox();
        QComboBox *Department = new QComboBox();
        QComboBox *Speciality = new QComboBox();

        FirstNameLable->setObjectName("FirstNameLable");
        MiddleNameLable->setObjectName("MiddleNameLable");
        LastNameLable->setObjectName("LastNameLable");
        SexLable->setObjectName("SexLable");
        AgeLable->setObjectName("AgeLable");
        DepartmentLable->setObjectName("DepartmentNameLable");
        SpecialityLable->setObjectName("SpecialityNameLable");

        FirstNameLable->setText("Имя");
        LastNameLable->setText("Фамилия");
        MiddleNameLable->setText("Отчество");
        SexLable->setText("Пол");
        AgeLable->setText("Возраст");
        DepartmentLable->setText("Отдел");
        SpecialityLable->setText("Специальность");

        FirstName->setObjectName("FirstName");
        MiddleName->setObjectName("MiddleName");
        LastName->setObjectName("LastName");
        Sex->setObjectName("Sex");
        Age->setObjectName("Age");
        Department->setObjectName("Department");
        Speciality->setObjectName("Speciality");

        Sex->addItem("0. Ж");
        Sex->addItem("1. М");
        QSqlQuery departments;
        departments.exec("SELECT * FROM departments");
        while(departments.next()){
            Department->addItem(departments.value("DepartmentID").toString() + ". " + departments.value("DepartmentName").toString());
        }
        QSqlQuery specialities;
        specialities.exec("SELECT * FROM specialities");
        while(specialities.next()){
            Speciality->addItem(specialities.value("SpecialityID").toString() + ". " + specialities.value("SpecialityName").toString());
        }

        ui->tableLabel->setText("Изменение информации о сотруднике");
        ui->tableLayout->addWidget(FirstNameLable);
        ui->tableLayout->addWidget(FirstName);
        ui->tableLayout->addWidget(MiddleNameLable);
        ui->tableLayout->addWidget(MiddleName);
        ui->tableLayout->addWidget(LastNameLable);
        ui->tableLayout->addWidget(LastName);
        ui->tableLayout->addWidget(SexLable);
        ui->tableLayout->addWidget(Sex);
        ui->tableLayout->addWidget(AgeLable);
        ui->tableLayout->addWidget(Age);
        ui->tableLayout->addWidget(DepartmentLable);
        ui->tableLayout->addWidget(Department);
        ui->tableLayout->addWidget(SpecialityLable);
        ui->tableLayout->addWidget(Speciality);

        Department->setMaxVisibleItems(5);
        Speciality->setMaxVisibleItems(5);

        lineEdits.append(FirstName);
        lineEdits.append(MiddleName);
        lineEdits.append(LastName);
        lineEdits.append(Age);

        comboBoxes.append(Sex);
        comboBoxes.push_back(Department);
        comboBoxes.push_back(Speciality);

        query.exec("DECLARE employeesCur CURSOR SCROLL FOR SELECT EmployeeID, FirstName, MiddleName, LastName, Age, Sex, CASE Sex WHEN 0 THEN 'Ж' ELSE 'М' END AS SexName, Department, DepartmentName, Speciality, SpecialityName FROM employees JOIN departments ON DepartmentID = Department JOIN specialities ON SpecialityID = Speciality OPEN employeesCur");
        break;
    }
    case 2:
    {
        curName="infoCur";
        tableName="employeeInformation";

        QLabel *PhoneNumberLable = new QLabel();
        QLabel *EmailLable = new QLabel();
        QLabel *HomeAddressLable = new QLabel();
        QLabel *ChildrenAmountLable = new QLabel();
        QLabel *PassportIDLable = new QLabel();
        QLabel *IndividualTaxpayerNumberLable = new QLabel();
        QLabel *LengthOfServiceLable = new QLabel();

        QLineEdit *PhoneNumber = new QLineEdit();
        QLineEdit *Email = new QLineEdit();
        QLineEdit *HomeAddress = new QLineEdit();
        QLineEdit *ChildrenAmount = new QLineEdit();
        QLineEdit *PassportID = new QLineEdit();
        QLineEdit *IndividualTaxpayerNumber = new QLineEdit();
        QLineEdit *LengthOfService = new QLineEdit();

        PhoneNumberLable->setObjectName("PhoneNumberLable");
        EmailLable->setObjectName("EmailLable");
        HomeAddressLable->setObjectName("HomeAddressLable");
        ChildrenAmountLable->setObjectName("ChildrenAmountLable");
        PassportIDLable->setObjectName("PassportIDLable");
        IndividualTaxpayerNumberLable->setObjectName("IndividualTaxpayerNumberLable");
        LengthOfServiceLable->setObjectName("LengthOfServiceLable");

        PhoneNumberLable->setText("Номер телефона");
        EmailLable->setText("Электронная почта");
        HomeAddressLable->setText("Домашний адрес");
        ChildrenAmountLable->setText("Количество детей");
        PassportIDLable->setText("Номер паспорта");
        IndividualTaxpayerNumberLable->setText("ИНН");
        LengthOfServiceLable->setText("Стаж");

        PhoneNumber->setObjectName("PhoneNumber");
        Email->setObjectName("Email");
        HomeAddress->setObjectName("HomeAddress");
        ChildrenAmount->setObjectName("ChildrenAmount");
        PassportID->setObjectName("PassportID");
        IndividualTaxpayerNumber->setObjectName("IndividualTaxpayerNumber");
        LengthOfService->setObjectName("LengthOfService");

        ui->tableLabel->setText("Изменение информации о сотруднике №");// + query.value(0).toString()+ " " + query.value(1).toString());
        ui->tableLayout->addWidget(PhoneNumberLable);
        ui->tableLayout->addWidget(PhoneNumber);
        ui->tableLayout->addWidget(EmailLable);
        ui->tableLayout->addWidget(Email);
        ui->tableLayout->addWidget(HomeAddressLable);
        ui->tableLayout->addWidget(HomeAddress);
        ui->tableLayout->addWidget(ChildrenAmountLable);
        ui->tableLayout->addWidget(ChildrenAmount);
        ui->tableLayout->addWidget(PassportIDLable);
        ui->tableLayout->addWidget(PassportID);
        ui->tableLayout->addWidget(IndividualTaxpayerNumberLable);
        ui->tableLayout->addWidget(IndividualTaxpayerNumber);
        ui->tableLayout->addWidget(LengthOfServiceLable);
        ui->tableLayout->addWidget(LengthOfService);

        lineEdits.append(PhoneNumber);
        lineEdits.append(Email);
        lineEdits.append(HomeAddress);
        lineEdits.append(ChildrenAmount);
        lineEdits.append(PassportID);
        lineEdits.append(IndividualTaxpayerNumber);
        lineEdits.append(LengthOfService);

        query.exec("DECLARE infoCur CURSOR SCROLL FOR SELECT * FROM employeeInformation OPEN infoCur");
        break;
    }
    case 3:
    {
        curName="salaryCur";
        tableName="salary";

        QLabel *WageLable = new QLabel();
        QLabel *PremiumLable = new QLabel();

        QLineEdit *Wage = new QLineEdit();
        QLineEdit *Premium = new QLineEdit();

        WageLable->setObjectName("WageLable");
        PremiumLable->setObjectName("PremiumLable");

        WageLable->setText("Заработная плата (указывать без учета НДФЛ)");
        PremiumLable->setText("Премия");

        Wage->setObjectName("Wage");
        Premium->setObjectName("Premium");

        ui->tableLabel->setText("Изменение выплат сотруднику №");
        ui->tableLayout->addWidget(WageLable);
        ui->tableLayout->addWidget(Wage);
        ui->tableLayout->addWidget(PremiumLable);
        ui->tableLayout->addWidget(Premium);

        lineEdits.append(Wage);
        lineEdits.append(Premium);

        query.exec("DECLARE salaryCur CURSOR SCROLL FOR SELECT * FROM salary OPEN salaryCur");
        break;
    }
    case 4:
    {
        curName="departmentsCur";
        tableName="departments";

        QLabel *DepartmentNameLable = new QLabel();

        QLineEdit *DepartmentName = new QLineEdit();

        DepartmentNameLable->setObjectName("DepartmentNameLable");

        DepartmentNameLable->setText("Название отдела");

        DepartmentName->setObjectName("DepartmentName");

        ui->tableLabel->setText("Изменение информации об отделе");
        ui->tableLayout->addWidget(DepartmentNameLable);
        ui->tableLayout->addWidget(DepartmentName);

        lineEdits.append(DepartmentName);

        query.exec("DECLARE departmentsCur CURSOR SCROLL FOR SELECT * FROM departments OPEN departmentsCur");
        break;
    }
    case 5:
    {
        curName="specialitiesCur";
        tableName="specialities";

        QLabel *SpecialityNameLable = new QLabel();

        QLineEdit *SpecialityName = new QLineEdit();

        SpecialityNameLable->setObjectName("SpecialityNameLable");

        SpecialityNameLable->setText("Название специальности");

        SpecialityName->setObjectName("SpecialityName");

        ui->tableLabel->setText("Изменение информации о специальности");
        ui->tableLayout->addWidget(SpecialityNameLable);
        ui->tableLayout->addWidget(SpecialityName);

        lineEdits.append(SpecialityName);

        query.exec("DECLARE specialitiesCur CURSOR SCROLL FOR SELECT SpecialityID, SpecialityName FROM specialities OPEN specialitiesCur");
        break;
    }
    default:
        QMessageBox::critical(this,"","choose table");
        this->close();
        break;
    }
    size.exec("SELECT COUNT(*) FROM " + tableName);
    size.next();
    tableSize = size.value(0).toInt();
    if(tableSize==0){
        QMessageBox::warning(this,"Ошибка","Выбранная таблица пуста");
        clearWidgets();
    }
    fill_from(table,currentCurIndex);
}

void cursor::fill_from(int table, int movement){

    QSqlQuery queryCursor;

    switch (table) {
    case 0:
    {
        queryCursor.exec("DECLARE @EmployeeID INT, @FirstName NVARCHAR(40), @MiddleName NVARCHAR(40), @Department INT, @DepartmentName NVARCHAR(40), @Speciality INT, @SpecialityName NVARCHAR(40), @Summary INT, @LengthOfService INT FETCH ABSOLUTE " + QString::number(movement) + " FROM viewCur INTO @EmployeeID, @FirstName, @MiddleName, @Department, @DepartmentName, @Speciality, @SpecialityName, @Summary, @LengthOfService SELECT @EmployeeID, @FirstName, @MiddleName, @LengthOfService, @Department, @DepartmentName, @Speciality, @SpecialityName");
        break;
    }
    case 1:
    {
        queryCursor.exec("DECLARE @EmployeeID INT, @FirstName NVARCHAR(40), @MiddleName NVARCHAR(40), @LastName NVARCHAR(40), @Age INT, @Sex BIT, @SexName NVARCHAR(1), @Department INT, @DepartmentName NVARCHAR(40), @Speciality INT, @SpecialityName NVARCHAR(40) FETCH ABSOLUTE " + QString::number(movement) + " FROM employeesCur INTO @EmployeeID, @FirstName, @MiddleName, @LastName, @Age, @Sex, @SexName, @Department, @DepartmentName, @Speciality, @SpecialityName SELECT @EmployeeID, @FirstName, @MiddleName, @LastName, @Age, @Sex, @SexName, @Department, @DepartmentName, @Speciality, @SpecialityName");
        break;
    }
    case 2:
    {
        queryCursor.exec("DECLARE @EmployeeID INT, @PhoneNumber NVARCHAR(40), @Email NVARCHAR(40), @HomeAddress NVARCHAR(80), @ChildrenAmount SMALLINT, @PassportID NVARCHAR(10), @IndividualTaxpayerNumber NVARCHAR(12), @LengthOfService INT FETCH ABSOLUTE " + QString::number(movement) + " FROM infoCur INTO @EmployeeID, @PhoneNumber, @Email, @HomeAddress, @ChildrenAmount, @PassportID, @IndividualTaxpayerNumber, @LengthOfService SELECT @EmployeeID, @PhoneNumber, @Email, @HomeAddress, @ChildrenAmount, @PassportID, @IndividualTaxpayerNumber, @LengthOfService");
        break;
    }
    case 3:
    {
        queryCursor.exec("DECLARE @EmployeeID INT, @Wage INT, @Premium INT, @Summary INT FETCH ABSOLUTE " + QString::number(movement) + " FROM salaryCur INTO @EmployeeID, @Wage, @Premium, @Summary SELECT @EmployeeID, @Wage, @Premium");
        break;
    }
    case 4:
    {
        queryCursor.exec("DECLARE @DepartmentID INT, @DepartmentName NVARCHAR(40) FETCH ABSOLUTE " + QString::number(movement) + " FROM departmentsCur INTO @DepartmentID, @DepartmentName SELECT @DepartmentID, @DepartmentName");
        break;
    }
    case 5:
    {
        queryCursor.exec("DECLARE @SpecialityID INT, @SpecialityName NVARCHAR(40) FETCH ABSOLUTE " + QString::number(movement) + " FROM specialitiesCur INTO @SpecialityID, @SpecialityName SELECT @SpecialityID, @SpecialityName");
        break;
    }
    }
    queryCursor.next();
    currentRowCur = queryCursor.value(0).toInt();
    if(currentTableCur==2||currentTableCur==3) ui->tableLabel->setText(ui->tableLabel->text().left(ui->tableLabel->text().indexOf("№")+1) + QString::number(currentRowCur));
    int i = 1;
    foreach(QLineEdit* line,lineEdits){
        line->setText(queryCursor.value(i).toString());
        i++;
    }
    foreach(QComboBox* line,comboBoxes){
        line->setCurrentText(queryCursor.value(i).toString() + ". " + queryCursor.value(i+1).toString());
        i+=2;
    }
}

void cursor::clearWidgets(){
    while (QLayoutItem* item = ui->tableLayout->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    lineEdits.clear();
    comboBoxes.clear();
    close();
}

void cursor::on_updateButton_clicked()
{
    QSqlQuery *queryInsert = new QSqlQuery();
    QString answer;

    switch (currentTableCur) {
    case 0:
    {
        //if(QMessageBox::warning(this,"Внимание","Подтвердить изменение?",QMessageBox::Cancel | QMessageBox::Ok)==QMessageBox::Ok) answer = " COMMIT TRANSACTION";
        queryInsert->prepare("BEGIN TRANSACTION EXEC PersonnelOverviewUpdate @RowID = ?, @FirstName = ?, @MiddleName = ?, @LengthOfService = ?, @Department = ?, @Speciality = ?" + answer);
        break;
    }
    case 1:
    {
        queryInsert->prepare("EXEC employeesUpdate @RowID = ?, @FirstName = ?, @MiddleName = ?, @LastName = ?, @Age = ?, @Sex = ?, @Department = ?, @Speciality = ?");
        break;
    }
    case 2:
    {
        queryInsert->prepare("EXEC employeeInformationUpdate @RowID = ?, @PhoneNumber = ?, @Email = ?, @HomeAddress = ?, @ChildrenAmount = ?, @PassportID = ?, @IndividualTaxpayerNumber = ?, @LengthOfService = ?");
        break;
    }
    case 3:
    {
        queryInsert->prepare("EXEC salaryUpdate @RowID = ?, @Wage = ?, @Premium = ?");
        break;
    }
    case 4:
    {
        queryInsert->prepare("EXEC departmentsUpdate @RowID = ?, @DepartmentName = ?");
        break;
    }
    case 5:
    {
        queryInsert->prepare("EXEC specialitiesUpdate @RowID = ?, @SpecialityName = ?");
        break;
    }
    }

    queryInsert->bindValue(0,currentRowCur);
    int i = 1;
    foreach(QLineEdit* line,lineEdits){
        if(!line->text().isEmpty()) queryInsert->bindValue(i,line->text());
        else{
            QMessageBox::critical(this,"critical","не все поля заполнены,<br>повторите ввод");
            break;
        }
        i++;
    }
    foreach(QComboBox* line,comboBoxes){
        QString dot = line->currentText();
        queryInsert->bindValue(i,dot.left(dot.indexOf(".")));
        i++;
    }

    if(queryInsert->exec()) QMessageBox::about(this,"","Запись была успешно обновлена");
    else {
        if(currentTableCur==0) {if(QMessageBox::warning(this,"Внимание","Подтвердить изменение?",QMessageBox::Cancel | QMessageBox::Ok)==QMessageBox::Ok) queryInsert->exec("COMMIT");
        else{ queryInsert->exec("ROLLBACK");}}
        else QMessageBox::warning(this,"","Ошибка<br>Запись не была обновлена,<br>проверьте правильность введённых данных");
    }

    emit refreshTable(currentTableCur);
}

void cursor::on_prevButton_clicked()
{
    //fill_from(currentTableCur,"PRIOR");
    currentCurIndex == 1 ? currentCurIndex = tableSize : currentCurIndex--;
    fill_from(currentTableCur,currentCurIndex);
}

void cursor::on_nextButton_clicked()
{
    currentCurIndex == tableSize ? currentCurIndex = 1 : currentCurIndex++;
    fill_from(currentTableCur,currentCurIndex);
}

void cursor::on_cancelButton_clicked()
{
    QSqlQuery end;
    end.exec("CLOSE " + curName + " DEALLOCATE " + curName);
    clearWidgets();
}

