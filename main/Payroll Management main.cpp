#include<iostream>
#include"arrowMenu.h"
using namespace std;
typedef unsigned short int ushort;
const ushort employeeSize = 100;
ushort empCounter = 0;
string menuArray[] = {"\tMain Menu\n\t---------",
                      "1. Display All Employee Information",
                      "2. Display All Employee's Payroll Information",
                      "3. Information Manipulation",
                      "4. Statistical Report",
                      "5. Search",
                      "6. Sorting",
                      "7. Exit"
                     };
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
} employee[employeeSize];
int main()
{
    int menuSelected = arrowMenu(menuArray, 7);
    switch(menuSelected)
    {
    case 1: //display employee information function
        break;
    case 2: //display payroll information function
        break;
    case 3: //information manipulation function
        break;
    case 4: //statistical report function
        break;
    case 5: //search function
        break;
    case 6: //sorting function
        break;
    case 7: //exit program
        return 0;
    }
}
