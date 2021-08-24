#include<iostream>
using namespace std;
unsigned short int employeeSize = 100, empCounter = 0;
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
    string gender;
    unsigned short int age;     //>65 years old
    string eduLevel;
    string department;
    float initialSalary, currentSalary, pensionSupport;     //salary
    int dOfEmployment, mOfEmployment, yOfEmployment;     //date of employment
    string paymentType;     //hourly, weekly, monthly
    string typeOfEmployee;
    bool isDeleted;
}employee[employeeSize];
int main()
{

}
