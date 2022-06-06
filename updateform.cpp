#include "updateform.h"
#include "ui_updateform.h"

updateform::updateform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updateform)
{
    ui->setupUi(this);
    lineEdits = *new QList<QLineEdit*>();
    comboBoxes = *new QList<QComboBox*>();
    this->setWindowFlags(Qt::WindowTitleHint);
    //this->setWindowFlags(Qt::WindowSystemMenuHint);
    this->setWindowModality(Qt::ApplicationModal);
    connect(ui->cancelButton,SIGNAL(clicked()),SLOT(clearWidgets()));
}

updateform::~updateform()
{
    delete ui;
}

int currentTable;
int currentRow = 0;

void updateform::recieveData(int table, int row)
{
    QSqlQuery query;
    currentTable = table;
    currentRow = row;
    switch (table) {
    case 0 :
    {
        query.exec("SELECT EmployeeID, FirstName, MiddleName, Department, DepartmentName, Speciality, SpecialityName, Summary, LengthOfService FROM PersonnelOverview WHERE EmployeeID = " + QString::number(row));
        query.next();

        QLabel *FirstNameLable = new QLabel();
        QLabel *MiddleNameLable = new QLabel();
        QLabel *DepartmentLable = new QLabel();
        QLabel *SpecialityLable = new QLabel();
        //QLabel *SummaryLable = new QLabel();
        QLabel *LengthOfServiceLable = new QLabel();

        QLineEdit *FirstName = new QLineEdit();
        QLineEdit *MiddleName = new QLineEdit();
        //QLineEdit *Summary = new QLineEdit();
        QLineEdit *LengthOfService = new QLineEdit();

        QComboBox *Department = new QComboBox();
        QComboBox *Speciality = new QComboBox();

        FirstNameLable->setObjectName("FirstNameLable");
        MiddleNameLable->setObjectName("MiddleNameLable");
        DepartmentLable->setObjectName("DepartmentLable");
        SpecialityLable->setObjectName("SpecialityLable");
        //SummaryLable->setObjectName("SummaryLable");
        LengthOfServiceLable->setObjectName("LengthOfServiceLable");


        FirstNameLable->setText("Имя");
        MiddleNameLable->setText("Отчество");
        DepartmentLable->setText("Отдел");
        SpecialityLable->setText("Специальность");
        //SummaryLable->setText("Выплата");
        LengthOfServiceLable->setText("Стаж");


        FirstName->setObjectName("FirstName");
        MiddleName->setObjectName("MiddleName");
        Department->setObjectName("Department");
        Speciality->setObjectName("Speciality");
        //Summary->setObjectName("Summary");
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
        //ui->tableLayout->addWidget(SummaryLable);
        //ui->tableLayout->addWidget(Summary);
        ui->tableLayout->addWidget(LengthOfServiceLable);
        ui->tableLayout->addWidget(LengthOfService);

        Department->setMaxVisibleItems(5);
        Speciality->setMaxVisibleItems(5);

        lineEdits.append(FirstName);
        lineEdits.append(MiddleName);
        //lineEdits.append(Summary);
        lineEdits.append(LengthOfService);

        comboBoxes.append(Department);
        comboBoxes.append(Speciality);

        FirstName->setText(query.value(1).toString());
        MiddleName->setText(query.value(2).toString());
        Department->setCurrentText(query.value(3).toString() + ". " + query.value(4).toString());
        Speciality->setCurrentText(query.value(5).toString() + ". " + query.value(6).toString());
        //Summary->setText(query.value(7).toString());
        LengthOfService->setText(query.value(8).toString());
        break;
    }
    case 1:
    {
        query.exec("SELECT FirstName, MiddleName, LastName, Sex, Age, Department, DepartmentName, Speciality, SpecialityName FROM employees JOIN departments ON DepartmentID = Department JOIN specialities ON SpecialityID = Speciality WHERE EmployeeID = " + QString::number(row));
        query.next();

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
        //QLineEdit *Sex = new QLineEdit();
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
        //lineEdits.append(Sex);
        lineEdits.append(Age);

        comboBoxes.append(Sex);
        comboBoxes.push_back(Department);
        comboBoxes.push_back(Speciality);

        FirstName->setText(query.value(0).toString());
        MiddleName->setText(query.value(1).toString());
        LastName->setText(query.value(2).toString());
        //Sex->setText(query.value(3).toString());
        Sex->setCurrentIndex(query.value(3).toInt());
        Age->setText(query.value(4).toString());
        Department->setCurrentText(query.value(5).toString() + ". " + query.value(6).toString());
        Speciality->setCurrentText(query.value(7).toString() + ". " + query.value(8).toString());
        break;
    }
    case 2:
    {
        query.exec("SELECT FirstName, MiddleName, PhoneNumber, Email, HomeAddress, ChildrenAmount, PassportID, IndividualTaxpayerNumber, LengthOfService FROM employeeInformation JOIN employees ON employees.EmployeeID = employeeInformation.EmployeeID WHERE employeeInformation.EmployeeID = " + QString::number(row));
        query.next();

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

        ui->tableLabel->setText("Изменение информации о сотруднике " + query.value(0).toString()+ " " + query.value(1).toString());
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

        PhoneNumber->setText(query.value(2).toString());
        Email->setText(query.value(3).toString());
        HomeAddress->setText(query.value(4).toString());
        ChildrenAmount->setText(query.value(5).toString());
        PassportID->setText(query.value(6).toString());
        IndividualTaxpayerNumber->setText(query.value(7).toString());
        LengthOfService->setText(query.value(8).toString());
        break;
    }
    case 3:
    {
        query.exec("SELECT FirstName, MiddleName, Wage, Premium FROM salary JOIN employees ON employees.EmployeeID = salary.EmployeeID WHERE salary.EmployeeID = " + QString::number(row));
        query.next();

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

        ui->tableLabel->setText("Изменение выплат сотруднику " + query.value(0).toString()+ " " + query.value(1).toString());
        ui->tableLayout->addWidget(WageLable);
        ui->tableLayout->addWidget(Wage);
        ui->tableLayout->addWidget(PremiumLable);
        ui->tableLayout->addWidget(Premium);

        lineEdits.append(Wage);
        lineEdits.append(Premium);

        Wage->setText(query.value(2).toString());
        Premium->setText(query.value(3).toString());
        break;
    }
    case 4:
    {
        query.exec("SELECT DepartmentName FROM departments WHERE DepartmentID = " + QString::number(row));
        query.next();

        QLabel *DepartmentNameLable = new QLabel();

        QLineEdit *DepartmentName = new QLineEdit();

        DepartmentNameLable->setObjectName("DepartmentNameLable");

        DepartmentNameLable->setText("Название отдела");

        DepartmentName->setObjectName("DepartmentName");

        ui->tableLabel->setText("Изменение информации об отделе");
        ui->tableLayout->addWidget(DepartmentNameLable);
        ui->tableLayout->addWidget(DepartmentName);

        lineEdits.append(DepartmentName);

        DepartmentName->setText(query.value(0).toString());
        break;
    }
    case 5:
    {
        query.exec("SELECT SpecialityName FROM specialities WHERE SpecialityID = " + QString::number(row));
        query.next();

        QLabel *SpecialityNameLable = new QLabel();

        QLineEdit *SpecialityName = new QLineEdit();

        SpecialityNameLable->setObjectName("SpecialityNameLable");

        SpecialityNameLable->setText("Название специальности");

        SpecialityName->setObjectName("SpecialityName");

        ui->tableLabel->setText("Изменение информации о специальности");
        ui->tableLayout->addWidget(SpecialityNameLable);
        ui->tableLayout->addWidget(SpecialityName);

        lineEdits.append(SpecialityName);

        SpecialityName->setText(query.value(0).toString());
        break;
    }
    default:
        QMessageBox::critical(this,"","choose table");
        this->close();
        break;
    }
}

void updateform::clearWidgets(){
    while (QLayoutItem* item = ui->tableLayout->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    lineEdits.clear();
    comboBoxes.clear();
    close();
}

void updateform::on_updateButton_clicked()
{
    QSqlQuery *queryInsert = new QSqlQuery();
    QString answer;

    switch (currentTable) {
    case 0:
    {
        if(QMessageBox::warning(this,"Внимание","Подтвердить изменение?",QMessageBox::Cancel | QMessageBox::Ok)==QMessageBox::Ok) answer = " COMMIT TRANSACTION";
        else answer = " ROLLBACK TRANSACTION";
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

    queryInsert->bindValue(0,currentRow);
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
    else {QMessageBox::warning(this,"","Ошибка<br>Запись не была обновлена,<br>проверьте правильность введённых данных");}

    emit refreshTable(currentTable);

    clearWidgets();
}

