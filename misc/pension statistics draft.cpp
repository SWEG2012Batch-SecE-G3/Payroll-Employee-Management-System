//List out of the retired employees and their pension In tabular format.
#include <iostream>
#include<iomanip>
#include<string.h>
#include<stdlib.h>
using namespace std;
char separator= ' | ';
const int nameWidth = 15;
const unsigned short int employeeSize = 100, empCounter = 0;

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
    unsigned short int emp_Id;
    Name fullName;
};
struct Employee
{
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
} employee[employeeSize];
void pension ();

int main()
{

          pension();


    return 0;
}
void pension ()
 {
    cout<<left<< setw(nameWidth) << setfill(separator)<<"First Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Middle Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Last Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Gender";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Age";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Pension paid";
    cout<<endl;

   for(int i=0; i<employeeSize; i++)
    {

 if(employee[i].age>=65)
      {

            cout<<left<< setw(nameWidth) << setfill(separator)<<employee[i].fullName.firstName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<employee[i].fullName.middleName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<employee[i].fullName.lastName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<employee[i].gender;
            cout<<left<< setw(nameWidth) << setfill(separator)<<employee[i].age;
            cout<<left<< setw(nameWidth) << setfill(separator)<<employee[i].initialSalary*0.15;
            cout<<endl;
      }


    }
}
