#include<iostream>
#include<vector>
#include"arrowMenu.h"   //displays the menus in the form of arrow using arrow keys
using namespace std;
typedef unsigned short int ushort;
const ushort employeeSize = 100;
char displayTableScreenSize[] = "mode con: cols=300 lines=50";  //change size of console window
char displayNormalScreenSize[] = "mode con: cols=100 lines=45";
ushort employeeCounter = 0;
string menuArray[] = {"\tMain Menu(use arrow keys to navigate)\n\t---------",
                      "1. Display All Employee Information",
                      "2. Display All Employee's Payroll Information",
                      "3. Record Management",
                      "4. Statistical Report",
                      "5. Search",
                      "6. Sorting",
                      "7. Exit"
                     };
string manipulationMenu[] = {"\tRecord Management Menu\n\t---------------------",
                             "1. Insert New Employee",
                             "2. Edit Employee",
                             "3. Delete Employee",
                             "4. Back",
                            };
string searchMenu[] = {"\tSearch Menu\n\t------------",
                       "1. Search by ID",
                       "2. Search by Full Name",
                       "3. Back",
                      };
string editMenu[] = {"\tEdit Menu\n\t---------",
                     "1. Edit Full Name",
                     "2. Edit Address",
                     "3. Edit Department",
                     "4. Back"
                    };
string sortMenu[] = {"\tSorting\n\t-------",
                     "1. Sort by Name",
                     "2. Sort by ID",
                     "3. Back"
                    };
string statsMenu[] = {"\tStatistical Reports\n\t-------",
                      "1. Employee Statistics",
                      "2. Payroll Statistics",
                      "3. Back"
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
    float tax, overtime, grossPay, netPay, pension, otherExpenses;
};
struct Employee
{
    unsigned short int emp_Id;
    Name fullName;
    Address address;
    experienceYears experienceYY;
    string typeOfEmployee;
    unsigned short int age;
    string eduLevel;
    string department;
    int dOfEmployment, mOfEmployment, yOfEmployment;
    char gender;
    string position;
    float initialSalary;
    bool isDeleted;
    Payroll payroll;
};
vector<Employee> employee;
#include<fstream>
#include"employeeFunctions.h"   //contains all the functions for each activity
int main()
{
    readFromFile();
    system(displayNormalScreenSize);

mainMenuloop:
    int menuSelected = arrowMenu(menuArray, 7);
    if(menuSelected == 1) //display employee information function
    {
        system("cls");
        current_employee();
        former_Employees();
        pension_Employees();
        cout<<"\nPress any key to exit"<<endl;
        system("pause>0");
        system("cls");
        system(displayNormalScreenSize);
        goto mainMenuloop;
    }
    else if(menuSelected == 2) //display payroll information function

    {
        system("cls");
        payrolldisplay();
        cout<<"\nPress any key to exit"<<endl;
        system("pause>0");
        system("cls");
        system(displayNormalScreenSize);
        goto mainMenuloop;
    }
    else if(menuSelected==3) //record management function
    {
        system("cls");
        int manipMenu = arrowMenu(manipulationMenu, 4);
        if(manipMenu == 1)  //insert new employee
        {
            system("cls");
            insertEmployeeRecord();
            system("cls");
            goto mainMenuloop;
        }
        else if(manipMenu==2)   //edit employee
        {
            system("cls");
            editEmployeeRecord();
            system("pause>0");
            system("cls");
            goto mainMenuloop;
        }
        else if(manipMenu == 3) //delete employee
        {
            system("cls");
            deleteEmployeeRecord();
            system("pause>0");
            system("cls");
            goto mainMenuloop;
        }
        else if(manipMenu == 4)     //back to previous menu
        {
            system("cls");
            goto mainMenuloop;
        }
    }
    else if(menuSelected == 4) //statistical report function
    {
        system("cls");
statsLoop:
        int statsRetrun = arrowMenu(statsMenu, 3);
        if(statsRetrun == 1)
        {
            system("cls");
            employee_staticReport();
            cout<<"\nPress any key to exit"<<endl;
            system("pause>0");
            system("cls");
            goto statsLoop;
        }
        else if(statsRetrun == 2)
        {
            system("cls");
            financial_staticReport();
            cout<<"\nPress any key to exit"<<endl;
            system("pause>0");
            system("cls");
            goto statsLoop;
        }
        else if(statsRetrun == 3)
        {
            system("cls");
            goto mainMenuloop;
        }
    }
    else if(menuSelected==5) //search function
    {
        system("cls");
        int searchRetrun = arrowMenu(searchMenu, 3);
        if(searchRetrun == 1)   //search by ID
        {
            system("cls");
            searchbyId();
            cout<<"\nPress any key to exit"<<endl;
            system("pause>0");
            system("cls");
            system(displayNormalScreenSize);
            goto mainMenuloop;
        }
        else if(searchRetrun==2)    //search by Name
        {
            system("cls");
            searchbyName();
            cout<<"\nPress any key to exit"<<endl;
            system("pause>0");
            system("cls");
            system(displayNormalScreenSize);
            goto mainMenuloop;
        }
        else if(searchRetrun == 3)  //back to previous
        {
            system("cls");
            goto mainMenuloop;
        }
    }
    else if(menuSelected==6) //sorting function
    {
        system("cls");
        sortEmpInfo();
        cout<<"\nPress any key to exit"<<endl;
        system("pause>0");
        system("cls");
        system(displayNormalScreenSize);
        goto mainMenuloop;
    }
    else if(menuSelected==7) //exit program
        return 0;

}
