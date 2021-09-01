#include <iomanip>
#include<string.h>
/******************* Function Declaration *******************/
void sortEmpInfo();
void current_employee(Employee emp[]);
void insertEmployeeRecord(Employee (&employee)[10], int &empNo);
void editEmployeeRecord(Employee (&employee)[10], int empNo);
void deleteEmployeeRecord(Employee (&employee)[10], int empNo);
void searchbyId(employee lists[]);
void searchbyName(employee lists[]);

/***********        Mieraf Jejew        ***************/
void sortEmpInfo()
{
    int n=7;
    char* names[n];
    char* Min= new char ('|');
    int* index=new int[n],h,length;
    string fullname;

    for(int i=0; i<n; i++)
    {
        length=sizeof(employee[i].fullName.firstName+employee[i].fullName.middleName+employee[i].fullName.lastName);
        names[i] = new char[length + 1];
        fullname=(employee[i].fullName.firstName+employee[i].fullName.middleName+employee[i].fullName.lastName);
        fullname.copy(names[i],length);
    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            if(strcmp(Min,names[i])>=0)
            {
                strcpy(Min,names[i]);
                h=i;
            }
        }

        Min[0]='}';
        index[k]=h;
        names[h][0]='|';

    }

    for(int i=0; i<n; i++)
        cout <<i+1<<") "<<employee[index[i]].fullName.firstName<<" "<<employee[index[i]].fullName.middleName<< endl;

    for (int i = 0; i < n; i++)
    {
        delete [] names[i];
        delete [] index;
    }
    delete Min;
}
/***********        Mikeyas Alemu        ***************/
void current_employee(Employee emp[])
{
    system("mode con: cols=300 lines=30");
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
    for(int i=0; i<2; i++)
    {
        if(emp[i].age<65)
        {
            cout  <<left<< setw(nameWidth) << setfill(separator)<<emp[i].payroll.emp_Id ;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<emp[i].payroll.fullName.firstName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<emp[i].payroll.fullName.middleName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<emp[i].payroll.fullName.lastName;
            cout <<left<< setw(nameWidth) << setfill(separator)<<emp[i].age;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<emp[i].address.city;
            cout<<left << setw(nameWidth) << setfill(separator)<<emp[i].address.phoneNo;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].address.poBox;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].department;
            cout <<emp[i].dOfEmployment<<"/"<<emp[i].mOfEmployment<<"/"<<emp[i].yOfEmployment<<"\t\t";
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].position;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].currentSalary;
            cout<<endl;

        }
    }
}
/***********        Nahom Getachew        ***************/
void employee_staticReport()
{
    struct
    {
        int NoMale,NoFemale;
        int count_fixed,count_con, T_emp;
        int high,low,middle,Tsalary;
        int admin,finance,humanSource,labor,security;
        int intermediate, mid_level, senior, experience;
    } info;

    for(int i=0; i<employeeSize; i++)
    {
        if(employee[i].gender=='M')
            info.NoMale++;
        else
            info.NoFemale++;

        if(employee[i].typeOfEmployee=='F')
            info.count_fixed++;
        else
            info.count_con++;


        if(employee[i].currentSalary>=10000)
            info.high++;
        else if(employee[i].currentSalary>=5000&&employee[i].currentSalary<10000)
            info.middle++;
        else
            info.low++;
        info.Tsalary+=employee[i].currentSalary;
        info.experience=employee[i].experienceYY.currentCompany+employee[i].experienceYY.formerCompany;
        if(info.experience>=1&&info.experience<=4)
            info.intermediate++;
        else if(info.experience>=5&&info.experience<=8)
            info.mid_level++;
        else if(info.experience>=9)
            info.senior++;

        switch(employee[i].department)
        {
        case 'A':
            info.admin++;
            break;
        case 'F':
            info.finance++;
            break;
        case 'H':
            info.humanSource++;
            break;
        case 'L':
            info.labor++;
            break;
        default:
            info.security++;
        }

    }
    cout<<"The number of male Employees are: "<<info.NoMale<<endl;
    cout<<"The number of female Employees are: "<<info.NoFemale<<endl;
    cout<<"\n------------------------------------------------------\n";
    cout<<"The number of Fixed Employees are: "<<info.count_fixed<<endl;
    cout<<"The number of contractual Employees are: "<<info.count_con<<endl;
    cout<<"The total number of employees are: "<<info.count_fixed+info.count_con<<endl;
    cout<<"\n------------------------------------------------------\n";
    cout<<"The number of High paid Employees are: "<<info.high<<endl;
    cout<<"The number of Middle paid Employees are: "<<info.middle<<endl;
    cout<<"The number of Relatively low paid Employees are: "<<info.low<<endl;
    cout<<"The total amount of salary paid for all employees: "<<info.Tsalary<<endl;
    cout<<"\n------------------------------------------------------\n";
    cout<<"Employee experience with intermediate level: "<<info.intermediate<<endl;
    cout<<"Employee experience with mid_level: "<<info.mid_level<<endl;
    cout<<"Employee experience with senior/executive level: "<<info.senior<<endl;
    cout<<"\n------------------------------------------------------\n";
    cout<<"Number of Employee in administration department: "<<info.admin<<endl;
    cout<<"Number of Employee in Finance department: "<<info.finance<<endl;
    cout<<"Number of Employee in human Source department: "<<info.humanSource<<endl;
    cout<<"Number of Employee in labor department: "<<info.labor<<endl;
    cout<<"Number of Employee in security department: "<<info.security<<endl;

}

void Financial_staticReport()
{

    struct
    {
        int tax01,tax02,tax03,tax04,tax05, tax;
        int pension01,pension02,pension03,pension04,pension05, pension;
        int other01,other02,other03,other04,other05, other_expense;

    } info;

    for(int i=0; i<employeeSize; i++)
    {
        info.tax=employee[i].initialSalary*0.15;
        info.pension=employee[i].initialSalary*0.20;
        info.other_expense=employee[i].initialSalary*0.10;
        if(info.tax>=600&&info.tax<1650)
            info.tax01++;
        else if(info.tax>=1651&&info.tax<3200)
            info.tax02++;
        else if(info.tax>=3201&&info.tax<5250)
            info.tax03++;
        else if(info.tax>=5251&&info.tax<7800)
            info.tax04++;
        else if(info.tax>=7801)
            info.tax05++;

        if(info.pension>=600&&info.pension<1650)
            info.pension01++;
        else if(info.pension>=1651&&info.pension<3200)
            info.pension02++;
        else if(info.pension>=3201&&info.pension<5250)
            info.pension03++;
        else if(info.pension>=5251&&info.pension<7800)
            info.pension04++;
        else if(info.pension>=7801)
            info.pension05++;

        if(info.other_expense>=600&&info.other_expense<1650)
            info.other01++;
        else if(info.other_expense>=1651&&info.other_expense<3200)
            info.other02++;
        else if(info.other_expense>=3201&&info.other_expense<5250)
            info.other03++;
        else if(info.other_expense>=5251&&info.other_expense<7800)
            info.other04++;
        else if(info.other_expense>=7801)
            info.other05++;


    }
    cout<<"Platinum level Tax pay amount: "<<info.tax05<<endl;
    cout<<"Gold level Tax pay amount: "<<info.tax04<<endl;
    cout<<"silver level Tax pay amount: "<<info.tax03<<endl;
    cout<<"Bronth level Tax pay amount: "<<info.tax02<<endl;
    cout<<"Number 5 level Tax pay amount: "<<info.tax01<<endl;
    cout<<"\n------------------------------------------------------\n";
    cout<<"Very High pension: "<<info.pension05<<endl;
    cout<<"High pension: "<<info.pension04<<endl;
    cout<<"Middle level pension: "<<info.pension03<<endl;
    cout<<"small amount pension: "<<info.pension02<<endl;
    cout<<"Very small amount pension: "<<info.pension01<<endl;
    cout<<"\n------------------------------------------------------\n";
    cout<<"Very High for expenses: "<<info.other05<<endl;
    cout<<"High for expenses: "<<info.other04<<endl;
    cout<<"Middle for expenses: "<<info.other03<<endl;
    cout<<"Low expenses: "<<info.other02<<endl;
    cout<<"very low expenses: "<<info.other01<<endl;
}
/***********        Nahom Habtamu        ***************/
void insertEmployeeRecord(Employee (&employee)[10], int &empNo)
{
    int how;
    cout<<"How many employees are you going to insert: ";
    cin>>how;
    how = how + empNo;
    for(int i = empNo; i<how; i++)
    {
        cout<<"Employee Information"<<endl<<endl;
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
        cout<<"Address"<<endl;
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
        cout<<"Date of Employment: ";
        cin>>employee[i].dOfEmployment>>employee[i].mOfEmployment>>employee[i].yOfEmployment;
        cout<<"Salary Payment Type: ";
        cin>>employee[i].typeOfEmployee;
        cout<<"Work Experience at former company(in Years): ";
        cin>>employee[i].experienceYY.formerCompany;
        cout<<"Work Experience at current company(in Years): ";
        cin>>employee[i].experienceYY.currentCompany;
        employee[i].currentSalary = ((employee[i].experienceYY.currentCompany/salaryAdvPercent) * (salaryAdvPercent/100) * employee[i].initialSalary) + employee[i].initialSalary;
        employee[i].emp_Id = empNo + 1;
        empNo++;
        employee[i].isDeleted = false;
        cout<<"\nPayroll Information"<<endl<<endl;
        cout<<"Gross Salary: ";
        cin>>employee[i].payroll.grossPay;
        cout<<"Overtime (in years): ";
        cin>>employee[i].payroll.overtime;
        cout<<"Other expenses: ";
        cin>>employee[i].payroll.otherExpenses;
        employee[i].payroll.tax = (taxPercent/100) * employee[i].payroll.otherExpenses;
        employee[i].payroll.pension = (pensionPercent/100) * employee[i].payroll.otherExpenses;
        employee[i].payroll.netPay = employee[i].payroll.grossPay - (employee[i].payroll.overtime + employee[i].payroll.otherExpenses + employee[i].payroll.tax);

    }
}

void editEmployeeRecord(Employee (&employee)[10], int empNo)
{
    int id, ch;
    cout<<"Enter the id you're going to edit: ";
    cin>>id;
    for(int i = 0; i<empNo; i++)
    {
        if(id == employee[i].emp_Id)
        {
            cout<<"1. Name\n2. Address\n3. Department"<<endl;
            cin>>ch;
            if(ch == 1)
            {
                cout<<"Full Name"<<endl;
                cout<<"First Name: ";
                cin>>employee[i].fullName.firstName;
                cout<<"Middle Name: ";
                cin>>employee[i].fullName.middleName;
                cout<<"Last Name: ";
                cin>>employee[i].fullName.lastName;
            }
            else if(ch == 2)
            {
                cout<<"Address"<<endl;
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
            }
            else if(ch == 3)
            {
                cout<<"Job Department: ";
                cin>>employee[i].department;
            }
        }
        else
        {
            cout<<"No such employee id found"<<endl;
        }
    }
}

void deleteEmployeeRecord(Employee (&employee)[10], int empNo)
{
    int id;
    cout<<"Id: ";
    cin>>id;
    for(int i = 0; i<empNo; i++)
    {
        if(id == employee[i].emp_Id)
        {
            employee[i].isDeleted = true;
        }
        else
        {
            cout<<"No employee found"<<endl;
        }
    }
}
/***********        Namus Shukra        ***************/
void searchbyName(employee lists[])
{
    string name1,name2,name3;
    cout<<"ENTER THE NAME OF EMPLOYEE YOU WANT TO FIND: "<<"\n";
    cin>>name1>>name2>>name3;
    int num=0;
    for (int i{}; i<numEmployee; i++)
    {
        if(name1==lists[i].firstName||name2==lists[i].middleName||name3==lists[i].lastName)
        {
            num++;
        }
    }

    if(num==0)
    {
        cout<<"\n"<<"EMPLOYEE NOT FOUND."<<"\n";
    }
    else
    {
        cout<<"\n"<<"EMPLOYEE FOUND."<<"\n";
    }
}

void searchbyId(employee lists[])
{
    unsigned short int idNum;
    cout<<"ENTER THE ID OF EMPLOYEE YOU WANT TO FIND: "<<"\n";
    cin>>idNum;
    int num=0;
    for (int i{}; i<numEmployee; i++)
    {
        if(lists[i].emp_Id==idNum)
        {
            num++;
        }
    }

    if(num==0)
    {
        cout<<"\n"<<"EMPLOYEE NOT FOUND."<<"\n";
    }
    else
    {
        cout<<"\n"<<"EMPLOYEE FOUND."<<"\n";
    }
}
