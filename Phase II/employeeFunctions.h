#include <iomanip>
#include<string.h>
int initial=0;
const float salaryAdvPercent = 5, taxPercent = 15, pensionPercent = 25, overtimeConstant = 1.5, otherExp = 20;   //constant values for calculations
int holdCounter=0;    //hold the last employee number
int* Index=new int[employee.size()];  //used in sorting function to hold sorted indices
/******************* Function Declaration *******************/

void sortEmpInfo();
void insertEmployeeRecord();
void editEmployeeRecord();
void deleteEmployeeRecord();
void current_employee(int select = 0, int searchedIndex = 0);
void searchbyId();
void searchbyName();
void calculate(int index);
void readFromFile();

/***********        Mieraf Jejew        ***************/
void sortEmpInfo()   //sort function
{
    char* names[employee.size()];
    char* Min= new char ('|');
    int temp,length,select;
    string fullname;

    //to enhance the performance
    if(employee.size()==holdCounter)    //jumps the for loop to enhance the performance and to save time if there is no change in the number of employees
        goto loop;                     //but if their is change on it, it goes to the for loop to update the sorting algorithm


    for(int i=0; i<employee.size(); i++)
    {
        length=sizeof(employee[i].fullName.firstName+employee[i].fullName.middleName+employee[i].fullName.lastName);
        names[i] = new char[length + 1];
        fullname=(employee[i].fullName.firstName+' '+employee[i].fullName.middleName+' '+employee[i].fullName.lastName);
        fullname.copy(names[i],length);
    }

    for(int k=0; k<employee.size(); k++)
    {
        for(int i=0; i<employee.size(); i++)
        {
            if(strcmp(Min,names[i])>=0)
            {
                strcpy(Min,names[i]);
                temp=i;
            }
        }

        Min[0]='}';
        Index[k]=temp;
        names[temp][0]='|';

    }
loop:
    select = arrowMenu(sortMenu, 3);

    if(employee.size()!=holdCounter)
    {
        for (int i = 0; i < employee.size(); i++)
        {
            delete [] names[i];
        }
        delete Min;
        holdCounter=employee.size();
    }

    switch(select)
    {
    case 1: //sort by Name
        current_employee(2);
        break;
    case 2: //sort by ID
        current_employee();
        break;
    case 3: //back to previous
        return;
    }
}

/***********        Mikeyas Alemu        ***************/
void current_employee(int select, int searchedIndex)  //display employee information when select= 0
//display sorted information(by name) when select different from 0
{
    int nameWidth = 16, numWidth = 16;
    char separator = ' ';
    system(displayTableScreenSize);
    cout<<"\t\t\t\t\t\t******************************************"<<endl;
    cout<<"\t\t\t\t\t\t****** Current Employee Information ******"<<endl;
    cout<<"\t\t\t\t\t\t******************************************"<<endl<<endl;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"ID" ;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"First Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Middle Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Last Name";
    cout <<left<< setw(nameWidth) << setfill(separator)<<"Age";
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"City";
    cout<<left << setw(nameWidth) << setfill(separator)<<"Phone";
    cout <<left << setw(nameWidth) << setfill(separator)<<"PO Box";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Department";
    cout <<left << setw(nameWidth+2) << setfill(separator)<<"Date";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Position";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Salary"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<endl;
    int i;
    for(int n=0; n<employee.size(); n++)
    {
        i=n;
        if(select==2)
        {
            i=Index[i];
        }
        else if(select == 1)
        {
            if(i != searchedIndex)
            {
                continue;
            }
        }
        if(employee[i].isDeleted == false)
        {
            cout  <<left<< setw(nameWidth) << setfill(separator)<<employee[i].emp_Id ;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<employee[i].fullName.firstName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<employee[i].fullName.middleName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<employee[i].fullName.lastName;
            cout <<left<< setw(nameWidth) << setfill(separator)<<employee[i].age;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<employee[i].address.city;
            cout<<left << setw(nameWidth) << setfill(separator)<<employee[i].address.phoneNo;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].address.poBox;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].department;
            cout <<employee[i].dOfEmployment<<"/"<<employee[i].mOfEmployment<<"/"<<setw(14)<<left<<employee[i].yOfEmployment;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].position;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].payroll.netPay;
            cout<<endl;
        }
    }
}

void former_Employees()   //display former employee informations
{
    int nameWidth = 16, numWidth = 16;
    char separator = ' ';
    cout<<"\n\t\t\t\t\t\t*****************************************"<<endl;
    cout<<"\t\t\t\t\t\t****** Former Employee Information ******"<<endl;
    cout<<"\t\t\t\t\t\t*****************************************"<<endl<<endl;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"ID" ;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"First Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Middle Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Last Name";
    cout <<left<< setw(nameWidth) << setfill(separator)<<"Age";
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"City";
    cout<<left << setw(nameWidth) << setfill(separator)<<"Phone";
    cout <<left << setw(nameWidth) << setfill(separator)<<"PO Box";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Department";
    cout <<left << setw(nameWidth+2) << setfill(separator)<<"Date";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Position";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Pension"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<endl;
    for(int i=0; i<employee.size(); i++)
    {
        if(employee[i].isDeleted == true)
        {
            cout  <<left<< setw(nameWidth) << setfill(separator)<<employee[i].emp_Id ;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<employee[i].fullName.firstName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<employee[i].fullName.middleName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<employee[i].fullName.lastName;
            cout <<left<< setw(nameWidth) << setfill(separator)<<employee[i].age;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<employee[i].address.city;
            cout<<left << setw(nameWidth) << setfill(separator)<<employee[i].address.phoneNo;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].address.poBox;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].department;
            cout <<employee[i].dOfEmployment<<"/"<<employee[i].mOfEmployment<<"/"<<setw(14)<<left<<employee[i].yOfEmployment;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].position;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].payroll.pension;
            cout<<endl;

        }
    }
}

void pension_Employees()   //display pension employee informations
{
    int nameWidth = 16, numWidth = 16;
    char separator = ' ';
    cout<<"\n\t\t\t\t\t\t*****************************************"<<endl;
    cout<<"\t\t\t\t\t\t****** Pension Employee Information ******"<<endl;
    cout<<"\t\t\t\t\t\t*****************************************"<<endl<<endl;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"ID" ;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"First Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Middle Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Last Name";
    cout <<left<< setw(nameWidth) << setfill(separator)<<"Age";
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"City";
    cout<<left << setw(nameWidth) << setfill(separator)<<"Phone";
    cout <<left << setw(nameWidth) << setfill(separator)<<"PO Box";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Department";
    cout <<left << setw(nameWidth+2) << setfill(separator)<<"Date";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Position";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Pension"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<endl;
    for(int i=0; i<employee.size(); i++)
    {
        if(employee[i].age > 65)
        {
            cout  <<left<< setw(nameWidth) << setfill(separator)<<employee[i].emp_Id ;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<employee[i].fullName.firstName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<employee[i].fullName.middleName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<employee[i].fullName.lastName;
            cout <<left<< setw(nameWidth) << setfill(separator)<<employee[i].age;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<employee[i].address.city;
            cout<<left << setw(nameWidth) << setfill(separator)<<employee[i].address.phoneNo;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].address.poBox;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].department;
            cout <<employee[i].dOfEmployment<<"/"<<employee[i].mOfEmployment<<"/"<<setw(14)<<left<<employee[i].yOfEmployment;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].position;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].payroll.pension;
            cout<<endl;

        }
    }
}

void payrolldisplay()     //display payroll data
{
    int nameWidth = 16, numWidth = 16;
    char separator = ' ';
    system(displayTableScreenSize);
    cout<<"\t\t\t\t\t\t**********************************"<<endl;
    cout<<"\t\t\t\t\t\t****** Payroll Information ******"<<endl;
    cout<<"\t\t\t\t\t\t**********************************"<<endl<<endl;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"ID" ;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"First Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Middle Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Last Name";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Department";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Tax";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Overtime";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Gross Pay";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Others";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Net Pay"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<endl;
    for(int i=0; i<employee.size(); i++)
    {
        if(employee[i].isDeleted == false)
        {
            cout  <<left<< setw(nameWidth) << setfill(separator)<<employee[i].emp_Id ;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<employee[i].fullName.firstName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<employee[i].fullName.middleName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<employee[i].fullName.lastName;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].department;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].payroll.tax;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].payroll.overtime;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].payroll.grossPay;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].payroll.otherExpenses;
            cout <<left << setw(nameWidth) << setfill(separator)<<employee[i].payroll.netPay<<endl;
        }
    }
}

/***********        Nahom Getachew        ***************/
void employee_staticReport()   //statistical report
{
    struct
    {
        int NoMale = 0, NoFemale = 0;
        int count_fixed = 0, count_con = 0, totalEmp = 0;
        int high = 0, low = 0, middle = 0, totalSalary = 0;
        int admin = 0, finance = 0, humanSource = 0, labor = 0, security = 0;
        int starter = 0, mid_level = 0, senior = 0, experience = 0;
    } info;

    for(int i=0; i<employee.size(); i++)
    {
        if(employee[i].isDeleted == false)
        {
            //gender
            if(employee[i].gender=='M' || employee[i].gender=='m')
                info.NoMale++;
            else if(employee[i].gender=='F' || employee[i].gender=='f')
                info.NoFemale++;
            info.totalEmp++;
            //type of employee
            if(employee[i].typeOfEmployee=="Fixed")
                info.count_fixed++;
            else if(employee[i].typeOfEmployee=="Contractual")
                info.count_con++;
            //payment level
            if(employee[i].payroll.grossPay >= 10000)
                info.high++;
            else if(employee[i].payroll.grossPay >= 5000 && employee[i].payroll.grossPay<10000)
                info.middle++;
            else if(employee[i].payroll.grossPay < 5000)
                info.low++;
            info.totalSalary += employee[i].payroll.grossPay;
            //experience level
            info.experience = employee[i].experienceYY.currentCompany + employee[i].experienceYY.formerCompany;
            if(info.experience>=1 && info.experience<=4)
                info.starter++;
            else if(info.experience>=5 && info.experience<=8)
                info.mid_level++;
            else if(info.experience>=9)
                info.senior++;
            //department
            if(employee[i].department == "Admin")
                info.admin++;
            else if(employee[i].department == "Finance")
                info.finance++;
            else if(employee[i].department == "HR")
                info.humanSource++;
            else if(employee[i].department == "Labor")
                info.labor++;
            else if(employee[i].department == "Security")
                info.security++;
        }
    }
    cout<<"******************************************"<<endl;
    cout<<"****** Employee Statistical Report ******"<<endl;
    cout<<"******************************************"<<endl<<endl;
    cout<<"Male employees: "<<info.NoMale<<endl;
    cout<<"Female employees: "<<info.NoFemale<<endl;
    cout<<"Total employees: "<<info.totalEmp<<endl;
    cout<<"\n----------------------------------\n";
    cout<<"Fixed employees: "<<info.count_fixed<<endl;
    cout<<"Contractual employees: "<<info.count_con<<endl;
    cout<<"\n----------------------------------\n";
    cout<<"Low paid Employees are(<5000 ETB): "<<info.low<<endl;
    cout<<"Medium paid employees(5000-9999 ETB): "<<info.middle<<endl;
    cout<<"High paid employees(>=10000 ETB): "<<info.high<<endl;
    cout<<"Total money paid to employees: "<<info.totalSalary<<endl;
    cout<<"\n-----------------------------------\n";
    cout<<"Relative Starter at company(1-4 years): "<<info.starter<<endl;
    cout<<"Intermediate experience at company(5-8 years): "<<info.mid_level<<endl;
    cout<<"Senior experience at company(>9 years): "<<info.senior<<endl;
    cout<<"\n------------------------------------------------------\n";
    cout<<"Number of employee in Administration Department: "<<info.admin<<endl;
    cout<<"Number of employee in Finance Department: "<<info.finance<<endl;
    cout<<"Number of employee in Human Resources Department: "<<info.humanSource<<endl;
    cout<<"Number of employee in Labor Department: "<<info.labor<<endl;
    cout<<"Number of employee in Security Department: "<<info.security<<endl;
    return;
}

void financial_staticReport()
{

    struct
    {
        int bronze=0, gold=0, platinum=0, tax;
        int lowPen=0, medPen=0, highPen=0, pension=0;
        int lowSpend=0, medSpend=0, highSpend=0, other_expense=0;

    } info;

    for(int i=0; i<employee.size(); i++)
    {
        info.tax= employee[i].payroll.tax;
        info.pension = employee[i].payroll.pension;
        info.other_expense = employee[i].payroll.otherExpenses;

        if(info.tax >= 100 && info.tax < 2000)
            info.bronze++;
        else if(info.tax >= 2000 && info.tax < 5000)
            info.gold++;
        else if(info.tax >= 5000)
            info.platinum++;

        if(info.pension >= 100 && info.pension < 4000)
            info.lowPen++;
        else if(info.pension >= 4000 && info.pension < 7000)
            info.medPen++;
        else if(info.pension >= 7000)
            info.highPen++;

        if(info.other_expense >= 600 && info.other_expense < 3000)
            info.lowSpend++;
        else if(info.other_expense >= 3000 && info.other_expense < 8000)
            info.medSpend++;
        else if(info.other_expense >= 8000)
            info.highSpend++;

    }
    cout<<"******************************************"<<endl;
    cout<<"\t****** Financial Report ******"<<endl;
    cout<<"******************************************"<<endl<<endl;
    cout<<"Bronze Tax payers(100-1999 ETB): "<<info.bronze<<endl;
    cout<<"Gold Tax payers(2000-4999 ETB): "<<info.gold<<endl;
    cout<<"Platinum Tax payers(>=5000 ETB): "<<info.platinum<<endl;
    cout<<"\n------------------------------------------------------\n";
    cout<<"Low amount pensioners(100-3999 ETB): "<<info.lowPen<<endl;
    cout<<"Medium amount pensioners(4000-6999 ETB): "<<info.medPen<<endl;
    cout<<"High amount pensioners(>=7000 ETB): "<<info.highPen<<endl;
    cout<<"\n------------------------------------------------------\n";
    cout<<"Low spenders(600-2999 ETB): "<<info.lowSpend<<endl;
    cout<<"Medium spenders(3000-7999 ETB): "<<info.medSpend<<endl;
    cout<<"High spenders(>=8000 ETB): "<<info.highSpend<<endl;
}

/***********        Nahom Habtamu        ***************/
void readFromFile()
{
    unsigned short int emp_Id;
    string phoneNo, email, country, city, poBox;
    string firstName, middleName, lastName;
    unsigned short int formerCompany, currentCompany;
    string typeOfEmployee;
    unsigned short int age;
    string eduLevel;
    string department;
    int dOfEmployment, mOfEmployment, yOfEmployment;
    char gender;
    string position;
    float initialSalary;
    bool isDeleted;
    float tax, overtime, grossPay, netPay, pension, otherExpenses;
//    employee.clear();

    fstream file("employees.txt", ios::ate);

    file.close();

    while(file>>emp_id)
    {
        file>>emp_Id>>firstName>>middleName>>lastName>>
            phoneNo>>email>>country>>city>>poBox>>
            formerCompany>>currentCompany>>
            typeOfEmployee>>age>>eduLevel>>department>>
            dOfEmployment>>mOfEmployment>>yOfEmployment>>
            gender>>position>>
            initialSalary>>isDeleted>>
            tax>>overtime>>grossPay>>
            netPay>>pension>>
            otherExpenses;
        employee.push_back({emp_Id, firstName, middleName, lastName,
                            phoneNo, email, country, city, poBox,
                            formerCompany, currentCompany,
                            typeOfEmployee, age, eduLevel, department,
                            dOfEmployment, mOfEmployment, yOfEmployment,
                            gender, position,
                            initialSalary, isDeleted,
                            tax, overtime, grossPay,
                            netPay, pension,
                            otherExpenses});
    }
    file.close();
}

void addToFile()
{
    fstream fileAdd("employees.txt", ios::app);

    for(int i = initial; i<employee.size(); i++)
    {
        fileAdd<<employee[i].emp_Id<<" "<<employee[i].fullName.firstName<<" "<<employee[i].fullName.middleName<<" "<<employee[i].fullName.lastName<<" "<<
               employee[i].address.phoneNo<<" "<<employee[i].address.email<<" "<<employee[i].address.country<<" "<<employee[i].address.city<<" "<<employee[i].address.poBox<<" "<<
               employee[i].experienceYY.formerCompany<<" "<<employee[i].experienceYY.currentCompany<<" "<<
               employee[i].typeOfEmployee<<" "<<employee[i].age<<" "<<employee[i].eduLevel<<" "<<employee[i].department<<" "<<
               employee[i].dOfEmployment<<" "<<employee[i].mOfEmployment<<" "<<employee[i].yOfEmployment<<" "<<
               employee[i].gender<<" "<<employee[i].position<<" "<<

               employee[i].initialSalary<<" "<<employee[i].isDeleted<<" "<<
               employee[i].payroll.tax<<" "<<employee[i].payroll.overtime<<" "<<employee[i].payroll.grossPay<<" "<<
               employee[i].payroll.netPay<<employee[i].payroll.pension<<" "<<
               employee[i].payroll.otherExpenses<<endl;
    }
 
    fileAdd.close();
}

void calculatePayroll(int i)
{
    employee[i].payroll.grossPay = ((employee[i].experienceYY.currentCompany/salaryAdvPercent) * (salaryAdvPercent/100) * employee[i].initialSalary) + employee[i].initialSalary;
    employee[i].payroll.tax = (taxPercent/100) * employee[i].payroll.grossPay;
    employee[i].payroll.otherExpenses = employee[i].payroll.grossPay * (otherExp/100);
    if(employee[i].age >= 65)
        employee[i].payroll.pension = (pensionPercent/100) * employee[i].payroll.grossPay;
    else
        employee[i].payroll.pension = 0;
    employee[i].payroll.netPay = employee[i].payroll.grossPay + (employee[i].payroll.overtime * overtimeConstant) - (employee[i].payroll.otherExpenses + employee[i].payroll.tax);

}

void insertEmployeeRecord()  //insert employee record
{
    for(int i = employee.size(); ; i++)
    {
        initial = employee.size();
        employee.push_back(Employee()); //this increments the vector size'
        employee[i].emp_Id = employee.size();
        cout<<"Add Employee Information"<<endl<<endl;
        cout<<"Full Name"<<endl;
        cout<<"First Name: ";
        cin>>employee[i].fullName.firstName;
        cout<<"Middle Name: ";
        cin>>employee[i].fullName.middleName;
        cout<<"Last Name: ";
        cin>>employee[i].fullName.lastName;
        cout<<"Gender(M or F): ";
        cin>>employee[i].gender;
        cout<<"Age: ";
        cin>>employee[i].age;
        cout<<"\nEmployee Address"<<endl;
        cout<<"Phone: ";
        cin>>employee[i].address.phoneNo;
        cout<<"Email: ";
        cin>>employee[i].address.email;
        cout<<"Country:  ";
        cin>>employee[i].address.country;
        cout<<"City: ";
        cin>>employee[i].address.city;
        cout<<"P.O. Box: ";
        cin>>employee[i].address.poBox;
        cout<<"Education Level: ";
        cin>>employee[i].eduLevel;
        cout<<"Job Department: ";
        cin>>employee[i].department;
        cout<<"Initial Salary: ";
        cin>>employee[i].initialSalary;
        cout<<"Employee Position: ";
        cin>>employee[i].position;
        cout<<"Date of Employment: ";
        cin>>employee[i].dOfEmployment>>employee[i].mOfEmployment>>employee[i].yOfEmployment;
        cout<<"Salary Payment Type: ";
        cin>>employee[i].typeOfEmployee;
        cin.ignore();
        cout<<"Work Experience at former company(in Years): ";
        cin>>employee[i].experienceYY.formerCompany;
        cout<<"Work Experience at current company(in Years): ";
        cin>>employee[i].experienceYY.currentCompany;
        employee[i].isDeleted = false;
        cout<<"\nPayroll Information"<<endl<<endl;
        cout<<"Overtime (in hours): ";
        cin>>employee[i].payroll.overtime;
        calculatePayroll(i);
        addToFile();
        cout<<"Employee added. Continue adding(y/n): ";
        char addEmp;
        cin>>addEmp;
        if(addEmp=='n')
            break;
        system("pause>0");
        system("cls");
    }
}

void editEmployeeRecord()    //edit record
{
    int id;
    cout<<"Enter the id you're going to edit: ";
    cin>>id;
    for(int i = 0; i<employee.size(); i++)
    {
        if(id == employee[i].emp_Id && employee[i].isDeleted == false)
        {
            system("cls");
            int ch = arrowMenu(editMenu, 4);
            if(ch == 1)     //edit full name
            {
                current_employee(1, i);
                cout<<"\nEditing Full Name"<<endl;
                cout<<"First Name: ";
                cin>>employee[i].fullName.firstName;
                cout<<"Middle Name: ";
                cin>>employee[i].fullName.middleName;
                cout<<"Last Name: ";
                cin>>employee[i].fullName.lastName;
                cout<<"\nEditing Complete! Press ENTER to continue"<<endl;
                return;
            }
            else if(ch == 2)    //edit address
            {

                current_employee(1, i);
                cout<<"\nEditing Address"<<endl;
                cout<<"Phone: ";
                cin>>employee[i].address.phoneNo;
                cout<<"Email: ";
                cin>>employee[i].address.email;
                cout<<"Country:  ";
                cin>>employee[i].address.country;
                cout<<"City: ";
                cin>>employee[i].address.city;
                cout<<"P.O. Box: ";
                cin>>employee[i].address.poBox;
                cout<<"\nEditing Completed! Press ENTER to continue"<<endl;
                return;
            }
            else if(ch == 3)    //edit department
            {
                current_employee(1, i);
                cout<<"\nEditing Department"<<endl;
                cout<<"Job Department: ";
                cin>>employee[i].department;
                cout<<"Position: ";
                cin>>employee[i].position;
                cout<<"\nEditing Completed! Press ENTER to continue"<<endl;
                return;
            }
            else if(ch == 4)    //back to previous
                return;
        }
    }
    cout<<"Error! Employee NOT found!"<<endl;
}

void deleteEmployeeRecord()  //delete record
{
    int id;
    cout<<"Id: ";
    cin>>id;
    for(int i = 0; i<employee.size(); i++)
    {
        if(id == employee[i].emp_Id && employee[i].isDeleted == false)
        {
            employee[i].isDeleted = true;
            cout<<"Record Deleted"<<endl;
            return;
        }
    }
    cout<<"No employee found!"<<endl;
}

/***********        Namus Shukra        ***************/
void searchbyName()     //search by name
{
    string name1,name2,name3;
    cout<<"ENTER THE FULL NAME OF EMPLOYEE YOU WANT TO FIND: "<<"\n";
    cout<<"First Name: ";
    cin>>name1;
    cout<<"Middle Name: ";
    cin>>name2;
    cout<<"Last Name: ";
    cin>>name3;
    for(int i = 0; i<name1.length(); i++)
        name1.at(i) = char(tolower(name1.at(i)));
    for(int i = 0; i<name2.length(); i++)
        name2.at(i) = char(tolower(name2.at(i)));
    for(int i = 0; i<name3.length(); i++)
        name3.at(i) = char(tolower(name3.at(i)));
    for (int i{}; i<employee.size(); i++)
    {
        string fName=employee[i].fullName.firstName, mName=employee[i].fullName.middleName, lName=employee[i].fullName.lastName;
        for(int i = 0; i<fName.length(); i++)
            fName.at(i) = char(tolower(fName.at(i)));
        for(int i = 0; i<mName.length(); i++)
            mName.at(i) = char(tolower(mName.at(i)));
        for(int i = 0; i<lName.length(); i++)
            lName.at(i) = char(tolower(lName.at(i)));
        if(name1==fName && name2==mName && name3==lName)
        {
            current_employee(1,i);
            return;
        }
    }
    cout<<"\n"<<"EMPLOYEE NOT FOUND."<<"\n";
}

void searchbyId()      //search by ID
{
    unsigned short int idNum;
    cout<<"ENTER THE ID OF EMPLOYEE YOU WANT TO FIND: "<<"\n";
    cin>>idNum;
    for (int i=0; i<employee.size(); i++)
    {
        if(employee[i].emp_Id==idNum)
        {
            current_employee(1, i);
            return;
        }
    }
    cout<<"\n"<<"EMPLOYEE NOT FOUND."<<"\n";
}
