#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
const unsigned short int employeeSize = 100, empCounter = 0;

    struct Address{
            string phoneNo, email, country, city, poBox;
        };

    struct Name{
        string firstName, middleName, lastName;
        };
    struct experienceYears{
        unsigned short int formerCompany, currentCompany;
        };
    struct Payroll{
        unsigned short int emp_Id;
        Name fullName;
        };
    struct Employee{
        unsigned short int emp_Id;
        Name fullName;
        Address address;
        experienceYears experienceYY;
        char gender;
        unsigned short int age;     //>65 years old
        string eduLevel;
        char department;
        float initialSalary, currentSalary, pensionSupport;     //salary
        int dOfEmployment, mOfEmployment, yOfEmployment;     //date of employment
        string paymentType;     //hourly, weekly, monthly
        char typeOfEmployee;
        bool isDeleted;
   }employee[employeeSize];


void employee_staticReport();
void Financial_staticReport();

int main()
{
cout<<"Employees over all statical Report\n";
employee_staticReport();
cout<<"\n------------------------------------------------------\n";
cout<<"Employees over all Financial Report\n";
Financial_staticReport();

return 0;
}
void employee_staticReport(){

    struct{
        int NoMale,NoFemale;
        int count_fixed,count_con, T_emp;
        int high,low,middle,Tsalary;
        int admin,finance,humanSource,labor,security;
        int intermediate, mid_level, senior, experience;
    }info;

  for(int i=0;i<employeeSize;i++){
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


    switch(employee[i].department){
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
void Financial_staticReport(){

    struct{
        int tax01,tax02,tax03,tax04,tax05, tax;
        int pension01,pension02,pension03,pension04,pension05, pension;
        int other01,other02,other03,other04,other05, other_expense;

    }info;

  for(int i=0;i<employeeSize;i++){
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
