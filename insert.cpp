#include "insert.h"
#include "ui_insert.h"

insert::insert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::insert)
{
    ui->setupUi(this);

    lineEdits = *new QList<QLineEdit*>();
    comboBoxes = *new QList<QComboBox*>();
    this->setWindowFlags(Qt::WindowTitleHint);
    this->setWindowModality(Qt::ApplicationModal);
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(clearWidgets()));
}

insert::~insert()
{
    delete ui;
}

int currentTableIndex;

void insert::recieveData(int index)
{
    currentTableIndex = index;
    switch (index) {
    case 0:
    {
        break;
    }
    case 1:
    {
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

        ui->tableLabel->setText("Добавление сотрудника");
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
        comboBoxes.append(Department);
        comboBoxes.push_back(Speciality);
        break;
    }
    case 2:
    {
        QLabel *EmployeeIDLable = new QLabel();
        QLabel *PhoneNumberLable = new QLabel();
        QLabel *EmailLable = new QLabel();
        QLabel *HomeAddressLable = new QLabel();
        QLabel *ChildrenAmountLable = new QLabel();
        QLabel *PassportIDLable = new QLabel();
        QLabel *IndividualTaxpayerNumberLable = new QLabel();
        QLabel *LengthOfServiceLable = new QLabel();

        QComboBox *EmployeeID = new QComboBox();

        QLineEdit *PhoneNumber = new QLineEdit();
        QLineEdit *Email = new QLineEdit();
        QLineEdit *HomeAddress = new QLineEdit();
        QLineEdit *ChildrenAmount = new QLineEdit();
        QLineEdit *PassportID = new QLineEdit();
        QLineEdit *IndividualTaxpayerNumber = new QLineEdit();
        QLineEdit *LengthOfService = new QLineEdit();

        EmployeeIDLable->setObjectName("EmployeeIDLable");
        PhoneNumberLable->setObjectName("PhoneNumberLable");
        EmailLable->setObjectName("EmailLable");
        HomeAddressLable->setObjectName("HomeAddressLable");
        ChildrenAmountLable->setObjectName("ChildrenAmountLable");
        PassportIDLable->setObjectName("PassportIDLable");
        IndividualTaxpayerNumberLable->setObjectName("IndividualTaxpayerNumberLable");
        LengthOfServiceLable->setObjectName("LengthOfServiceLable");

        EmployeeIDLable->setText("Сотрудник");
        PhoneNumberLable->setText("Номер телефона");
        EmailLable->setText("Электронная почта");
        HomeAddressLable->setText("Домашний адрес");
        ChildrenAmountLable->setText("Количество детей");
        PassportIDLable->setText("Номер паспорта");
        IndividualTaxpayerNumberLable->setText("ИНН");
        LengthOfServiceLable->setText("Стаж");

        EmployeeID->setObjectName("EmployeeID");
        PhoneNumber->setObjectName("PhoneNumber");
        Email->setObjectName("Email");
        HomeAddress->setObjectName("HomeAddress");
        ChildrenAmount->setObjectName("ChildrenAmount");
        PassportID->setObjectName("PassportID");
        IndividualTaxpayerNumber->setObjectName("IndividualTaxpayerNumber");
        LengthOfService->setObjectName("LengthOfService");

        QSqlQuery employees;
        employees.exec("SELECT EmployeeID, FirstName, MiddleName FROM employees WHERE EmployeeID <> ALL (SELECT EmployeeID FROM employeeInformation)");
        while(employees.next()){
            EmployeeID->addItem(employees.value(0).toString() + ". " + employees.value(1).toString() + " " + employees.value(2).toString());
        }

        ui->tableLabel->setText("Добавление информации о сотруднике");
        ui->tableLayout->addWidget(EmployeeIDLable);
        ui->tableLayout->addWidget(EmployeeID);
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

        EmployeeID->setMaxVisibleItems(5);

        lineEdits.append(PhoneNumber);
        lineEdits.append(Email);
        lineEdits.append(HomeAddress);
        lineEdits.append(ChildrenAmount);
        lineEdits.append(PassportID);
        lineEdits.append(IndividualTaxpayerNumber);
        lineEdits.append(LengthOfService);

        comboBoxes.append(EmployeeID);
        break;
    }
    case 3:
    {
        QLabel *EmployeeIDLable = new QLabel();
        QLabel *WageLable = new QLabel();
        QLabel *PremiumLable = new QLabel();

        QComboBox *EmployeeID = new QComboBox();

        QLineEdit *Wage = new QLineEdit();
        QLineEdit *Premium = new QLineEdit();

        EmployeeIDLable->setObjectName("EmployeeIDLable");
        WageLable->setObjectName("WageLable");
        PremiumLable->setObjectName("PremiumLable");

        EmployeeIDLable->setText("Сотрудник");
        WageLable->setText("Заработная плата (указывать без учета НДФЛ)");
        PremiumLable->setText("Премия");

        EmployeeID->setObjectName("EmployeeID");
        Wage->setObjectName("Wage");
        Premium->setObjectName("Premium");

        QSqlQuery employees;
        employees.exec("SELECT EmployeeID, FirstName, MiddleName FROM employees WHERE EmployeeID <> ALL (SELECT EmployeeID FROM salary)");
        while(employees.next()){
            EmployeeID->addItem(employees.value("EmployeeID").toString() + ". " + employees.value("FirstName").toString() + " " + employees.value("MiddleName").toString());
        }

        ui->tableLabel->setText("Добавление месячной выплаты сотруднику");
        ui->tableLayout->addWidget(EmployeeIDLable);
        ui->tableLayout->addWidget(EmployeeID);
        ui->tableLayout->addWidget(WageLable);
        ui->tableLayout->addWidget(Wage);
        ui->tableLayout->addWidget(PremiumLable);
        ui->tableLayout->addWidget(Premium);

        EmployeeID->setMaxVisibleItems(5);

        comboBoxes.append(EmployeeID);

        lineEdits.append(Wage);
        lineEdits.append(Premium);
        break;
    }
    case 4:
    {
        QLabel *DepartmentNameLable = new QLabel();

        QLineEdit *DepartmentName = new QLineEdit();

        DepartmentNameLable->setObjectName("DepartmentNameLable");

        DepartmentNameLable->setText("Название отдела");

        DepartmentName->setObjectName("DepartmentName");

        ui->tableLabel->setText("Добавление отдела");
        ui->tableLayout->addWidget(DepartmentNameLable);
        ui->tableLayout->addWidget(DepartmentName);

        lineEdits.append(DepartmentName);
        break;
    }
    case 5:
    {
        QLabel *SpecialityNameLable = new QLabel();

        QLineEdit *SpecialityName = new QLineEdit();

        SpecialityNameLable->setObjectName("SpecialityNameLable");

        SpecialityNameLable->setText("Название специальности");

        SpecialityName->setObjectName("SpecialityName");

        ui->tableLabel->setText("Добавление отдела");
        ui->tableLayout->addWidget(SpecialityNameLable);
        ui->tableLayout->addWidget(SpecialityName);

        lineEdits.append(SpecialityName);
        break;
    }
    default:
        QMessageBox::critical(this,"","choose table");
        this->close();
        break;
    }
}

void insert::clearWidgets(){
    while (QLayoutItem* item = ui->tableLayout->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    lineEdits.clear();
    comboBoxes.clear();
    this->close();
}

void insert::on_pushButton_clicked()
{
    QSqlQuery *queryInsert = new QSqlQuery();

    switch (currentTableIndex) {
    case 1:
    {
        queryInsert->prepare("EXEC employeesAdd @FirstName = ?, @MiddleName = ?, @LastName = ?, @Age = ?, @Sex = ?, @Department = ?, @Speciality = ?");
        break;
    }
    case 2:
    {
        queryInsert->prepare("EXEC employeeInformationAdd @PhoneNumber = ?, @Email = ?, @HomeAddress = ?, @ChildrenAmount = ?, @PassportID = ?, @IndividualTaxpayerNumber = ?, @LengthOfService = ?, @EmployeeID = ?");
        break;
    }
    case 3:
    {
        queryInsert->prepare("EXEC salaryAdd @Wage = ?, @Premium = ?, @EmployeeID = ?");
        break;
    }
    case 4:
    {
        queryInsert->prepare("EXEC departmentsAdd @DepartmentName = ?");
        break;
    }
    case 5:
    {
        queryInsert->prepare("EXEC specialitiesAdd @SpecialityName = ?");
        break;
    }
    }

    int i = 0;
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

    if(queryInsert->exec()) QMessageBox::about(this,"","Запись была успешно добавлена");
    else {QMessageBox::warning(this,"","Ошибка<br>Запись не была добавлена,<br>проверьте правильность введённых данных");}

    emit refreshTable(currentTableIndex);

    clearWidgets();
}

