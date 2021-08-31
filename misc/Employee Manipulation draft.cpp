#include<iostream>
using namespace std;
const unsigned short int employeeSize = 100;
unsigned short int empCounter = 0;
float salaryAdvPercent = 5, taxPercent = 15, pensionPercent = 50;
struct Address
{
    string phoneNo, email, country, city, poBox;
};
struct Name
{
    string firstName, middleName, lastName;
};
struct experienceYears
{
    unsigned short int formerCompany, currentCompany;
};
struct Payroll
{
    float overtime, otherExpenses, tax, pension, grossPay, netPay;
};
struct Employee
{
    unsigned short int emp_Id;
    Name fullName;
    Address address;
    experienceYears experienceYY;
    string gender;
    unsigned short int age;     //>65 years old
    string eduLevel;
    string department;
    int dOfEmployment, mOfEmployment, yOfEmployment;     //date of employment
    string paymentType;     //hourly, weekly, monthly
    string typeOfEmployee;
    float initialSalary, currentSalary;     //salary
    Payroll payroll;
    bool isDeleted;
} employee[employeeSize];
void display(Employee emp[], int &empNo);
void insertEmployeeRecord(Employee (&employee)[10], int &empNo)
{
    int how;
    cout<<"how many employees: ";
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
int main()
{
    int empNo=1;
    Employee employee[10];
    employee[0] = {1, {"Nahom", "Habtamu", "Debalkie"}, {"0939656144", "nhabtamu42@gmail.com", "Ethiopia", "City", "1000"}, {2, 6}, "M", 21, "Degree", "Coder",
                   2,5,2001, "Hourly", "Fixed", 5000
                  };
    int a;
mainMenu:
    cin>>a;
    system("cls");
    if(a==1)
    {
        insertEmployeeRecord(employee, empNo);
    }
    else if(a==2)
    {
        editEmployeeRecord(employee, empNo);
    }
    else if(a==3)
    {
        deleteEmployeeRecord(employee, empNo);
    }
    display(employee, empNo);
}

void display(Employee emp[], int &empNo)
{
    cout<<"ID\t\t"<<"Name\t\t"<<endl;
    for(int i = 0; i<empNo; i++)
    {
        if(!(emp[i].isDeleted))
        {
//            float a = ((int)(emp[i].experienceYY.currentCompany/salaryAdvPercent) * (salaryAdvPercent/100) * emp[i].initialSalary) + emp[i].initialSalary;
//            cout<<a<<"\t\t";
            cout<<emp[i].emp_Id<<"\t\t";
            cout<<emp[i].fullName.firstName<<" "<<
                emp[i].fullName.middleName<<" "<<emp[i].fullName.lastName<<endl;
            break;
        }
    }
}
