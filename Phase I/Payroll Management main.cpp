#include<iostream>
#include"arrowMenu.h"   //displays the menus in the form of arrow using arrow keys
using namespace std;
typedef unsigned short int ushort;
const ushort employeeSize = 100;
char displayTableScreenSize[] = "mode con: cols=300 lines=30";  //change size of console window
char displayNormalScreenSize[] = "mode con: cols=100 lines=35";
ushort employeeCounter = 0;
string menuArray[] = {"\tMain Menu\n\t---------",
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
    string paymentType;
    char gender;
    string position;
    float initialSalary;
    bool isDeleted;
    Payroll payroll;
} employee[employeeSize];
#include"employeeFunctions.h"   //contains all the functions for each activity

int main()
{
    system(displayNormalScreenSize);
    //initialization with random data to show the program works correctly
    //NOTE: the calculated data displayed in the initialization are not accurate, they are just prototype
    employee[employeeCounter++] = {1, {"Nahom", "Habtamu", "Debalkie"}, {"0939656144", "nhabtamu42@gmail.com", "Ethiopia", "Addis Ababa", "1000"}, {2, 6}, "Fixed", 70, "Degree", "Labor",
                                   1, 8, 1995, "Hourly", 'F', "Worker", 7000, true, {1000, 70, 10000, 9200, 300, 10000}
                                  };
    employee[employeeCounter++] = {2, {"Mieraf", "Jejew", "Mulaw"}, {"0939656144", "nhabtamu42@gmail.com", "Ethiopia", "Gondar", "1000"}, {2, 6}, "Fixed", 21, "Degree", "Finance",
                                   21, 10, 2013, "Hourly", 'M', "Head", 1000, false, {300, 10, 5000, 4100, 500, 20000}
                                  };
    employee[employeeCounter++] = {3, {"Mikeyas", "Alemu", "Hasen"}, {"0939656144", "nhabtamu42@gmail.com", "Ethiopia", "Addis Ababa", "1000"}, {2, 6}, "Fixed", 21, "Degree", "HR",
                                   23,3, 2010, "Hourly", 'M', "Worker", 3000, false, {200, 50, 7500, 5900, 200, 6000}
                                  };
    employee[employeeCounter++] = {4, {"Namus", "Shukra", "Hulkero"}, {"0939656144", "nhabtamu42@gmail.com", "Ethiopia", "Addis Ababa", "1000"}, {2, 6}, "Contractual", 21, "Degree", "Security",
                                   22,1, 2000, "Hourly", 'M', "Worker", 2500, false, {100, 30, 3500, 2000, 600, 8000}
                                  };
    employee[employeeCounter++] = {5, {"Nahom", "Getachew", "Gari"}, {"0939656144", "nhabtamu42@gmail.com", "Ethiopia", "Sebeta", "1000"}, {2, 15}, "Contractual", 21, "Degree", "Admin",
                                   13,7, 1995, "Hourly", 'F', "Worker", 7500, false, {500, 12, 15000, 13200, 100, 16000}
                                  };
mainMenuloop:
    int menuSelected = arrowMenu(menuArray, 7);
    if(menuSelected == 1) //display employee information function
    {
        system("cls");
        current_employee(employee);
        former_Employees(employee);
        system("pause>0");
        system("cls");
        system(displayNormalScreenSize);
        goto mainMenuloop;
    }
    else if(menuSelected == 2) //display payroll information function

    {
        system("cls");
        payrolldisplay(employee);
        system("pause>0");
        system("cls");
        system(displayNormalScreenSize);
        goto mainMenuloop;
    }
    else if(menuSelected==3) //information manipulation function
    {
        system("cls");
        int manipMenu = arrowMenu(manipulationMenu, 4);
        if(manipMenu == 1)  //insert new employee
        {
            system("cls");
            insertEmployeeRecord(employee);
            system("cls");
            goto mainMenuloop;
        }
        else if(manipMenu==2)   //edit employee
        {
            system("cls");
            editEmployeeRecord(employee);
            system("pause>0");
            system("cls");
            goto mainMenuloop;
        }
        else if(manipMenu == 3) //delete employee
        {
            system("cls");
            deleteEmployeeRecord(employee);
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
        employee_staticReport(employee);
        Financial_staticReport();
        system("pause>0");
        system("cls");
        goto mainMenuloop;
    }
    else if(menuSelected==5) //search function
    {
        system("cls");
        int searchRetrun = arrowMenu(searchMenu, 3);
        if(searchRetrun == 1)   //search by ID
        {
            system("cls");
            searchbyId(employee);
            system("pause>0");
            system("cls");
            system(displayNormalScreenSize);
            goto mainMenuloop;
        }
        else if(searchRetrun==2)    //search by Name
        {
            system("cls");
            searchbyName(employee);
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
        sortEmpInfo(employee);
        system("pause>0");
        system("cls");
        system(displayNormalScreenSize);
        goto mainMenuloop;
    }
    else if(menuSelected==7) //exit program
        return 0;

}
