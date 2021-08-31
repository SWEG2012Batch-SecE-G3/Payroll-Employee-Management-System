#include<iostream>
using namespace std;
#include<iomanip>
using namespace std;
 char separator    = '   ' ;
 const int nameWidth     = 15;
 const int numWidth      = 15;
 const int namee  =2;
unsigned short int employeeSize = 1, empCounter = 0;
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
    Payroll payroll;
    Address address;
    unsigned short int age;     //>65 years old
    string department;
    int dOfEmployment, mOfEmployment, yOfEmployment;     //date of employment
    string position;
    float currentSalary;
    experienceYears experienceYY;
    string gender;
    string eduLevel;
    float initialSalary, pensionSupport;     //salary
    string paymentType;     //hourly, weekly, monthly
    string typeOfEmployee;
    bool isDeleted;
}employee[namee];

void current_employee(Employee emp[]){
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
for(int i=0;i<2;i++){
    if(emp[i].age<65){
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
int main()
{

employee[0]={{1, {"Nahom", "Habtamu", "Debalkie"}}, {"0939656144", "nhabtamu@gmail.com", "Ethiopia", "AA", "1000"}, 21, "Software", 12,12,12, "Manager", 5000};
employee[1]={{2, {"Mikeyas", "Alemu", "Hasen"}}, {"0941474186", "mikeyas@gmail.com", "Ethiopia", "AA", "1000"}, 21, "Software", 12,12,12, "Employee", 10000};
current_employee(employee);



}
